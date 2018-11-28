//by duans

#include <QApplication>
#include <QMainWindow>
#include <QMessageBox>
#include <QDateTime>
#include <QDir>

#include "dpxPlaneToolBase.h"
#include "ccCompass.h"
#include "dpxAlgorithmFun.h"
#include "dpxGeoEngine.h"
#include "../../qCC/dpxFramework/dpxSelectionManager.h"

dpxPlaneToolBase::dpxPlaneToolBase()
	: dpxPickAndEditTool()
{
	m_pPickRoot = new ccHObject("Plane");
	m_pPickRoot->setMetaData(DPX_LAYER_TYPE_NAME,0);
	m_pAssistWin = nullptr;
	m_nCreateType = 0; //0代表拟合到方式1：代表采集到方式

	m_strccHobjectName = "PlaneObj";
	m_eCurObjType = eObj_TrafficLight;//默认初始采集到是红绿灯
	m_strImageName = ":/CC/plugin/qCompass/images/RedGreen.png";
	m_eTargetLayerType = eOT_TrafficLight;
}


dpxPlaneToolBase::~dpxPlaneToolBase()
{
	if (m_poly3D)
		delete m_poly3D;

	if(m_pAssistWin)
		delete m_pAssistWin;

	m_pAssistWin = nullptr;
}

//called when the tool is set to active (for initialization)
void dpxPlaneToolBase::toolActivated()
{
	if(m_pAssistWin==nullptr)
	{
		m_pAssistWin = new dpxPlaneAssistDlg(this);
		m_pAssistWin->HideCombobox();//要素类型不再选择
	}

	if(!m_pAssistWin->isVisible())
		m_pAssistWin->show();

	bool bsetRefRoot = false;
	vector<ccHObject*> vecObjs = dpxSelectionManager::Instance()->getSelections();
	if(vecObjs.size()==1)
	{
		ccHObject* pHObj = vecObjs[0];
        if(pHObj->hasMetaData(DPX_OBJECT_TYPE_NAME))
        {
			int index = pHObj->getMetaData(DPX_OBJECT_TYPE_NAME).toInt();
			if(dpxObjectType(index) == eObj_RoadRefLine)
			{
				//生成的RoadLine挂在RefLine节点下
				m_pPickRoot = pHObj;
				bsetRefRoot = true;
			}
        }
	}
	if(!bsetRefRoot)
	{
		//若添加了地图，采集到地图中去
		dpxMap* pMap = dpxGeoEngine::Instance()->GetMap();
		if(pMap!=nullptr)
		{
			dpxLayer* pTargetLyr = pMap->getLyrFormType(m_eTargetLayerType);
			if(pTargetLyr!=nullptr && pTargetLyr->getRootData()!=nullptr)
				m_pPickRoot = pTargetLyr->getRootData();
		}
	}

	QObject::connect(m_pAssistWin, SIGNAL(sigTypeChange(int)), this, SLOT(slotChangeType(int)));
	QObject::connect(m_pAssistWin, SIGNAL(sigObjTypeChange(int)), this, SLOT(slotObjTypeChangeType(int)));

	dpxPickAndEditTool::toolActivated();
}


void dpxPlaneToolBase::toolDisactivated()
{
	if(m_pAssistWin != nullptr && m_pAssistWin->isVisible())
		m_pAssistWin->hide();

	QObject::disconnect(m_pAssistWin, SIGNAL(sigTypeChange(int)), this, SLOT(slotChangeType(int)));
	QObject::disconnect(m_pAssistWin, SIGNAL(sigObjTypeChange(int)), this, SLOT(slotObjTypeChangeType(int)));

	dpxPickAndEditTool::toolDisactivated();
}

//采集方法发生变化
void dpxPlaneToolBase::slotChangeType(int nType)
{
	m_nCreateType = nType;
}

//采集的地物类型发生变化
void dpxPlaneToolBase::slotObjTypeChangeType(int nObjType)
{
	m_eCurObjType = dpxObjectType(nObjType);
}

//右键可取消两个点时的状态
void dpxPlaneToolBase::onMouseRightClick(int x,int y)
{
	if(m_nToolState)//编辑状体
		return;
	//if the 3D polyline doesn't exist yet, we create it
	if (!m_poly3D || !m_poly3DVertices)
		return;

	int nSize = m_poly3DVertices->size();
	//多点时必须采集>4  三点时==3
	if((m_nCreateType==0&&nSize<4) || (m_nCreateType==1&&nSize<3))
	{
		m_pPickRoot->removeChild(m_poly3D);
		m_polyTip->setEnabled(false);
		m_poly3D = 0;
		m_poly3DVertices = 0;
		m_nToolState=1;//采集状态结束，默认编辑状态
		return;
	}

	if(m_nCreateType==0)//多点拟合
	{
		//Fit plane!
		double rms = 0.0; //output for rms
		ccFitPlane* pPlane = ccFitPlane::Fit(m_poly3DVertices, &rms);
		AddPlaneToData(pPlane);

		m_polyTip->setEnabled(false);
		m_poly3D = 0;
		m_poly3DVertices = 0;
		m_nToolState=1;//采集状态结束，默认编辑状态
	}

}

void dpxPlaneToolBase::onMouseReleaseEvent(int x,int y)
{
	if(m_window==nullptr)
		return;

	if(m_VNodeInfo.m_pLine==nullptr || m_VNodeInfo.m_nNodeIndex==-1)
		return;

	ccPolyline* pLine = m_VNodeInfo.m_pLine;
	int nIndex = m_VNodeInfo.m_nNodeIndex;

	if(  nIndex>pLine->size()-1)
		return;
	if(!m_bMoveNode)//是否是拖拽节点模式
		return;

	ccGenericPointCloud* pTargetCloud = nullptr;
	int nPloudPtIndex=-1;
	CCVector3 newPickPt;
	if(!m_window->pickNearestPt(x,y,pTargetCloud,nPloudPtIndex,newPickPt))
	{
		ccLog::Warning("释放鼠标无法捕捉点");
		return;
	}

	if(!pLine->hasMetaData(DPX_RELATED_PLANE_UID) || !pLine->hasMetaData(DPX_NORMAL))
		return;

	//删除旧的
	QString strUID = pLine->getMetaData(DPX_RELATED_PLANE_UID).toString();
	ccHObject::Container vecHObjs;
	dpxSnapHelper::Instance()->FindAllObjs(vecHObjs,CC_TYPES::PLANE);//旧的删除
	for(int i =0;i<vecHObjs.size();i++)
	{
		ccPlane* plane = ccHObjectCaster::ToPlane(vecHObjs[i]);
		if(plane==nullptr)
			continue;
		if(!plane->hasMetaData(DPX_RELATED_PLANE_UID))
			continue;
		QString sUID = plane->getMetaData(DPX_RELATED_PLANE_UID).toString();
		if(sUID.compare(strUID,Qt::CaseInsensitive)==0)
		{
			pLine->removeChild(plane);
		}
	}

	//更新线
	CCVector3* modefyPt = const_cast<CCVector3*>(pLine->getPointPersistentPtr(nIndex));
	*modefyPt = newPickPt;


	double rms = 0.0; //output for rms
	ccFitPlane* pNewPlane = nullptr;
	int nSize = pLine->size();
	if(pLine->size()!=4) //多点采集每次修改一个点要重新调整平面
	{
		pNewPlane = ccFitPlane::Fit(pLine->getAssociatedCloud(), &rms);
	}
	else if(pLine->size()==4) //三点采集 每次修改一个角 临近两个点也要移动才能保持矩形不变
	{
		CCVector3* Pt0 = const_cast<CCVector3*>(pLine->getPointPersistentPtr(0));
		CCVector3* Pt1 = const_cast<CCVector3*>(pLine->getPointPersistentPtr(1));
		CCVector3* Pt2 = const_cast<CCVector3*>(pLine->getPointPersistentPtr(2));
		CCVector3* Pt3 = const_cast<CCVector3*>(pLine->getPointPersistentPtr(3));
		if(nIndex==0)
		{
			CCVector3 ptP  = dpxAlgorithmFun::PointProjectionToLine(*Pt2,*Pt3,newPickPt);
			CCVector3 ptQ(Pt2->x-ptP.x+newPickPt.x,Pt2->y-ptP.y+newPickPt.y,Pt2->z-ptP.z+newPickPt.z);
			*Pt0 = newPickPt;
			*Pt3 = ptP;
			*Pt1 = ptQ;
		}
		else if(nIndex==1)
		{
			CCVector3 ptP  = dpxAlgorithmFun::PointProjectionToLine(*Pt3,*Pt2,newPickPt);
			CCVector3 ptQ(Pt3->x-ptP.x+newPickPt.x,Pt3->y-ptP.y+newPickPt.y,Pt3->z-ptP.z+newPickPt.z);
			*Pt1 = newPickPt;
			*Pt2 = ptP;
			*Pt0 = ptQ;
		}
		else if(nIndex==2)
		{
			CCVector3 ptP  = dpxAlgorithmFun::PointProjectionToLine(*Pt0,*Pt1,newPickPt);
			CCVector3 ptQ(Pt0->x-ptP.x+newPickPt.x,Pt0->y-ptP.y+newPickPt.y,Pt0->z-ptP.z+newPickPt.z);
			*Pt2 = newPickPt;
			*Pt1 = ptP;
			*Pt3 = ptQ;
		}
		else if(nIndex==3)
		{
			CCVector3 ptP  = dpxAlgorithmFun::PointProjectionToLine(*Pt1,*Pt0,newPickPt);
			CCVector3 ptQ(Pt1->x-ptP.x+newPickPt.x,Pt1->y-ptP.y+newPickPt.y,Pt1->z-ptP.z+newPickPt.z);
			*Pt3 = newPickPt;
			*Pt0 = ptP;
			*Pt2 = ptQ;
		}
		//四个点A P C Q
		ccPointCloud* pCloud  = new ccPointCloud("Plane Cloud");
		pCloud->reserve(4);
		pCloud->addPoint(*Pt0);
		pCloud->addPoint(*Pt1);
		pCloud->addPoint(*Pt2);
		pCloud->addPoint(*Pt3);

		pNewPlane = ccFitPlane::Fit(pCloud, &rms);//重新拟合平面
	}

	if (pNewPlane) //valid fit
	{
		//make plane to add to display
		pNewPlane->setVisible(true);
		pNewPlane->setSelectionBehavior(ccHObject::SELECTION_IGNORED);
		pNewPlane->setDisplay(m_window);
		QImage* pImage = new QImage(m_strImageName);
		if(pImage)
		{
			pNewPlane->setAsTexture(*pImage);
		}

		CCVector3 vNormal = pNewPlane->getNormal();
		QString strNormal = QString::number(vNormal.x).append(" ").append(QString::number(vNormal.y)).append(" ").append(QString::number(vNormal.z));
		pLine->setMetaData(DPX_NORMAL,strNormal);
		pNewPlane->setMetaData(DPX_RELATED_PLANE_UID,strUID);

		pLine->addChild(pNewPlane);
	}

	m_window->removeFromOwnDB(m_pPickRoot);
	m_app->addToDB(m_pPickRoot);


	m_polyTip->setEnabled(false);
	m_bMoveNode = false;
	pLine->invalidateBoundingBox();
	m_window->redraw(false, true);
}

//QString dpxPlaneToolBase::getImageName()
//{
//	if(m_eCurObjType==eObj_TrafficLight)
//		return ":/CC/plugin/qCompass/images/RedGreen.png";
//	else if(m_eCurObjType==eObj_Indication_OnRoad)
//		return   ":/CC/plugin/qCompass/images/OnRoadIndication.png";
//	else if (m_eCurObjType==eObj_Indication_InSpace)
//		return  ":/CC/plugin/qCompass/images/InSpaceIndication.png";
//	else
//		return "";
//}

//QString dpxPlaneToolBase::getObjectName()
//{
//	if(m_eCurObjType==eObj_TrafficLight)
//		return "OfficeLight";
//	else if(m_eCurObjType==eObj_Indication_OnRoad)
//		return   "IndicationOnRoad";
//	else if (m_eCurObjType==eObj_Indication_InSpace)
//		return  "IndicationInSpace";
//	else
//		return "";
//}

void dpxPlaneToolBase::AddPlaneToData(ccFitPlane* pPlane)
{
	QString strRelateID = QUuid::createUuid().toString();
	if (pPlane) //valid fit
	{
		//make plane to add to display
		pPlane->setVisible(true);
		pPlane->setSelectionBehavior(ccHObject::SELECTION_IGNORED);
		pPlane->setDisplay(m_window);
		pPlane->setMetaData(DPX_RELATED_PLANE_UID,strRelateID);
		QImage* pImage = new QImage(m_strImageName);
		if(pImage)
		{
			pPlane->setAsTexture(*pImage);
		}

		CCVector3 vNormal = pPlane->getNormal();
		QString strNormal = QString::number(vNormal.x).append(" ").append(QString::number(vNormal.y)).append(" ").append(QString::number(vNormal.z));
		m_poly3D->setMetaData(DPX_NORMAL,strNormal);//法向量
		m_poly3D->setMetaData(DPX_RELATED_PLANE_UID,strRelateID);//关联的ID
		m_poly3D->setMetaData(DPX_OBJECT_TYPE_NAME,m_eCurObjType); //地物类型
		m_poly3D->setName(m_strccHobjectName);//设置名称
		m_poly3D->addChild(pPlane);
	}

	m_window->removeFromOwnDB(m_pPickRoot);
	m_app->addToDB(m_pPickRoot);
}

//called when a point in a point cloud gets picked while this tool is active
//pointPicked(pi.entity, pi.itemIndex, pi.clickPoint.x(), pi.clickPoint.y(), pi.P3D); //map straight to pointPicked function
void dpxPlaneToolBase::pointPicked(ccHObject* insertPoint, unsigned itemIdx, ccPointCloud* cloud, const CCVector3& P,int x/*=0*/,int y/*=0*/)
{
	if(m_nToolState)//编辑状体
		return;

	if(m_nCreateType==0)
	{
		PickMutilPts(P,x,y);
	}
	else if(m_nCreateType==1)
	{
		ThreePtPick(P,x,y);
	}

	m_window->redraw(false, false);
}

//采集多个点 最后拟合平面
void  dpxPlaneToolBase::PickMutilPts(const CCVector3& P ,int x,int y)
{
//if the 3D polyline doesn't exist yet, we create it
	if (!m_poly3D || !m_poly3DVertices)
	{
		m_poly3DVertices = new ccPointCloud("Vertices");
		m_poly3DVertices->setEnabled(false);
		m_poly3DVertices->setDisplay(m_window);

		m_poly3D = new ccPolyline(m_poly3DVertices);
		m_poly3D->setTempColor(ccColor::green);
		m_poly3D->set2DMode(false);
		m_poly3D->addChild(m_poly3DVertices);
		m_poly3D->setWidth(1);

		m_pPickRoot->addChild(m_poly3D);
	}

	//try to add one more point
	if (	!m_poly3DVertices->reserve(m_poly3DVertices->size() + 1)
		||	!m_poly3D->reserve(m_poly3DVertices->size() + 1))
	{
		ccLog::Error("Not enough memory");
		return;
	}


	m_poly3DVertices->addPoint(P);
	m_poly3D->addPointIndex(m_poly3DVertices->size() - 1);

	//we replace the first point of the tip by this new point
	{
		QPointF pos2D = m_window->toCenteredGLCoordinates(x, y);
		CCVector3 P2D(	static_cast<PointCoordinateType>(pos2D.x()),
						static_cast<PointCoordinateType>(pos2D.y()),
						0);

		CCVector3* firstTipPoint = const_cast<CCVector3*>(m_polyTipVertices->getPointPersistentPtr(0));
		*firstTipPoint = P2D;
		m_polyTip->setEnabled(false); //don't need to display it for now
	}
}

//采集三个点 三点拟合平面
void  dpxPlaneToolBase::ThreePtPick(const CCVector3& P ,int x,int y)
{
	//if the 3D polyline doesn't exist yet, we create it
	if (!m_poly3D || !m_poly3DVertices)
	{
		m_poly3DVertices = new ccPointCloud();
		m_poly3DVertices->setEnabled(false);
		m_poly3DVertices->setDisplay(m_window);

		m_poly3D = new ccPolyline(m_poly3DVertices);
		m_poly3D->setTempColor(ccColor::green);
		m_poly3D->set2DMode(false);
		m_poly3D->addChild(m_poly3DVertices);
		m_poly3D->setWidth(1);

		m_pPickRoot->addChild(m_poly3D);
	}

	int nSize = m_poly3DVertices->size();
	if(nSize==0||nSize==1)
	{
		//try to add one more point
		if (!m_poly3DVertices->reserve(m_poly3DVertices->size() + 1)
			||!m_poly3D->reserve(m_poly3DVertices->size() + 1))
		{
			ccLog::Error("Not enough memory");
			return;
		}

		m_poly3DVertices->addPoint(P);
		m_poly3D->addPointIndex(m_poly3DVertices->size() - 1);

		//we replace the first point of the tip by this new point
		{
			QPointF pos2D = m_window->toCenteredGLCoordinates(x, y);
			CCVector3 P2D(	static_cast<PointCoordinateType>(pos2D.x()),
							static_cast<PointCoordinateType>(pos2D.y()),
							0);

			CCVector3* firstTipPoint = const_cast<CCVector3*>(m_polyTipVertices->getPointPersistentPtr(0));
			*firstTipPoint = P2D;
		}

		m_polyTip->setEnabled(true);
	}
	else if(nSize ==2)//构造平面
	{
		CCVector3 PtA = *(m_poly3DVertices->getPoint(0));
		CCVector3 PtB = *(m_poly3DVertices->getPoint(1));
		CCVector3 PtC = P;

		//C在AB的投影点为P 再求P的对角点Q 组成矩形
		CCVector3 ptP  = dpxAlgorithmFun::PointProjectionToLine(PtA,PtB,PtC);
		CCVector3 ptQ(PtA.x-ptP.x+PtC.x,PtA.y-ptP.y+PtC.y,PtA.z-ptP.z+PtC.z);
		//四个点A P C Q
		m_poly3DVertices->clear();
		m_poly3D->clear(true);
		m_poly3DVertices->reserve(4);
		m_poly3D->reserve(5);

		m_poly3DVertices->addPoint(PtA);
		m_poly3DVertices->addPoint(ptP);
		m_poly3DVertices->addPoint(PtC);
		m_poly3DVertices->addPoint(ptQ);

		m_poly3D->addPointIndex(0,4);

		double rms = 0.0;
		ccFitPlane* pPlane = ccFitPlane::Fit(m_poly3DVertices, &rms);//重新拟合平面
		AddPlaneToData(pPlane);

		m_polyTip->setEnabled(false);
		m_poly3D = 0;
		m_poly3DVertices = 0;
		m_nToolState=1;//采集状态结束，默认编辑状态
	}
}
