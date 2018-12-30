//by duans

#include <QApplication>
#include <QMainWindow>
#include <QMessageBox>
#include <QDateTime>

#include "dpxCylinderTool.h"
#include "ccCompass.h"
#include "ccCylinder.h"
#include "ccCone.h"
#include "dpxAlgorithmFun.h"
#include "dpxGeoEngine.h"
#include "../../qCC/dpxFramework/dpxSelectionManager.h"


dpxCylinderTool::dpxCylinderTool()
	: dpxPickAndEditTool()
{
	m_pPickRoot = new ccHObject("Cylinder");
	m_pPickRoot->setMetaData(DPX_LAYER_TYPE_NAME,0);
}


dpxCylinderTool::~dpxCylinderTool()
{
	if (m_polyTip)
		delete m_polyTip;

	if (m_poly3D)
		delete m_poly3D;
}

//called when the tool is set to active (for initialization)
void dpxCylinderTool::toolActivated()
{
	bool bsetRefRoot = false;
	vector<ccHObject*> vecObjs = dpxSelectionManager::Instance()->getSelections();
	do
    {
        if(vecObjs.size()<1)
            break;
        ccHObject* pHObj = vecObjs[0];
        if(!pHObj->hasMetaData(DPX_OBJECT_TYPE_NAME))
            break;

        int index = pHObj->getMetaData(DPX_OBJECT_TYPE_NAME).toInt();
        if(dpxObjectType(index) != eObj_RoadRefLine)
            break;

        //生成的RoadLine挂在RefLine节点下
		ccPolyline* pLine = ccHObjectCaster::ToPolyline(pHObj);
		if(pLine==nullptr)
			break;

        ccHObject* pSection = dpxMapCommonFunc::getRelatedSection(pLine);
        if(pSection==nullptr)
			break;

		m_pPickRoot = pSection;
		bsetRefRoot= true;

    }while(0);

	if(!bsetRefRoot)
	{
		//若添加了地图，采集到地图中去
		dpxMap* pMap = dpxGeoEngine::Instance()->GetMap();
		if(pMap!=nullptr)
		{
			dpxLayer* pPoleLyr = pMap->getPoleLyr();
			if(pPoleLyr!=nullptr && pPoleLyr->getRootData()!=nullptr)
				m_pPickRoot = pPoleLyr->getRootData();
		}
	}

	dpxPickAndEditTool::toolActivated();
}


void dpxCylinderTool::pointPicked(ccHObject* insertPoint, unsigned itemIdx, ccPointCloud* cloud, const CCVector3& P,int x/*=0*/,int y/*=0*/)
{
	if(m_nToolState)//编辑状体
		return;
	if (!m_window)
	{
		assert(false);
		return;
	}
	//if the 3D polyline doesn't exist yet, we create it
	if (!m_poly3D || !m_poly3DVertices)
	{
		m_poly3DVertices = new ccPointCloud();
		m_poly3DVertices->setEnabled(false);
		m_poly3DVertices->setDisplay(m_window);

		m_poly3D = new ccPolyline(m_poly3DVertices);
		m_poly3D->setTempColor(ccColor::green);
		m_poly3D->addChild(m_poly3DVertices);
		m_poly3D->setWidth(1);
		m_pPickRoot->addChild(m_poly3D);
	}

	int nSize = m_poly3DVertices->size();
	if(nSize==0)//两点形成圆柱的轴线
	{
		//try to add one more point
		if (!m_poly3DVertices->reserve(m_poly3DVertices->size() + 1)
			||!m_poly3D->reserve(m_poly3DVertices->size() + 1))
		{
			ccLog::Error("Not enough memory");
			return;
		}

		m_poly3DVertices->addPoint(P);
		m_poly3D->addPointIndex(m_poly3DVertices->size()-1);
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
	else if(nSize==1)//两点形成圆柱的轴线
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
		m_polyTip->setEnabled(false);
	}
	else if(nSize ==2)//构造圆柱
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

		CCVector3 pA = *(m_poly3D->getPoint(0));
		CCVector3 pB = *(m_poly3D->getPoint(1));

		double dRadius = dpxAlgorithmFun::DistanceOfPointToLine(pA,pB,P);
		double dHeight = sqrt(pow((pA.x-pB.x),2.0) + pow((pA.y-pB.y),2.0) + pow((pA.z-pB.z),2.0));

		//CC system Func
		QString strRelateID = QUuid::createUuid().toString();
		CCVector3 vbefore(0,0,1);
		CCVector3 vafter(pB.x-pA.x, pB.y-pA.y, pB.z-pA.z);
		ccGLMatrix transM = ccGLMatrix::FromToRotation(vbefore,dpxAlgorithmFun::NormalVec(vafter));

		CCVector3 vecTrans((pA.x+pB.x)/2,(pA.y+pB.y)/2,(pA.z+pB.z)/2);
		transM.setTranslation(vecTrans);

		QDateTime current_time =QDateTime::currentDateTime();
		QString sCurrentTime =current_time.toString("hh:mm:ss");
		m_poly3D->setName("CylinderLine_"+sCurrentTime);
		m_poly3D->setMetaData(DPX_CYLINEDER_RELATED_UID,strRelateID);//关联的ID
		m_poly3D->setMetaData(DPX_RADIUS,QString::number(dRadius));
		m_poly3D->setMetaData(DPX_OBJECT_TYPE_NAME,eObj_Pole); //地物类型

		ccCylinder* pCylinder = new ccCylinder(dRadius,dHeight,&transM,"Cylinder"+sCurrentTime,24);
		pCylinder->setMetaData(DPX_CYLINEDER_RELATED_UID,strRelateID);//关联的ID
		pCylinder->setTempColor(ccColor::cyan);
		m_poly3D->addChild(pCylinder);

		m_window->removeFromOwnDB(m_pPickRoot);
		m_app->addToDB(m_pPickRoot);
		m_polyTip->setEnabled(false);
		m_poly3D = 0;
		m_poly3DVertices = 0;
		m_nToolState=1;//采集状态结束，默认编辑状态
	}

	m_window->redraw(false, false);
}

//右键可取消两个点时的状态
void dpxCylinderTool::onMouseRightClick(int x,int y)
{
	if(m_nToolState)//编辑状体
		return;
	//if the 3D polyline doesn't exist yet, we create it
	if (!m_poly3D || !m_poly3DVertices)
		return;

	int nSize = m_poly3DVertices->size();
	if(nSize<3)
	{
		m_pPickRoot->removeChild(m_poly3D);
		m_polyTip->setEnabled(false);
		m_poly3D = 0;
		m_poly3DVertices = 0;
		m_nToolState=1;//采集状态结束，默认编辑状态
	}
}

void dpxCylinderTool::onMouseReleaseEvent(int x,int y)
{
	if(m_window==nullptr)
		return;

	if(m_VNodeInfo.m_pLine==nullptr || m_VNodeInfo.m_nNodeIndex==-1)
		return;

	ccPolyline* pLine = m_VNodeInfo.m_pLine;
	int nIndex = m_VNodeInfo.m_nNodeIndex;

	if( nIndex>pLine->size()-1)
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

	if(!pLine->hasMetaData(DPX_CYLINEDER_RELATED_UID))
		return;

	//删除旧的
	QString strUID = pLine->getMetaData(DPX_CYLINEDER_RELATED_UID).toString();
	ccHObject::Container vecHObjs;
	dpxSnapHelper::Instance()->FindAllObjs(vecHObjs,CC_TYPES::CYLINDER);//旧的删除
	for(int i =0;i<vecHObjs.size();i++)
	{
		ccLog::Warning("遍历PLANE"+QString::number(i));
		ccCylinder* pCylinder = ccHObjectCaster::ToCylinder(vecHObjs[i]);
		if(pCylinder==nullptr)
			continue;
		if(!pCylinder->hasMetaData(DPX_CYLINEDER_RELATED_UID))
			continue;
		QString sUID = pCylinder->getMetaData(DPX_CYLINEDER_RELATED_UID).toString();
		if(sUID.compare(strUID,Qt::CaseInsensitive)==0)
		{
			pLine->removeChild(pCylinder);
		}
	}

	CCVector3* Pt0 = const_cast<CCVector3*>(pLine->getPointPersistentPtr(0));
	CCVector3* Pt1 = const_cast<CCVector3*>(pLine->getPointPersistentPtr(1));
	CCVector3* Pt2 = const_cast<CCVector3*>(pLine->getPointPersistentPtr(2));

	if(nIndex==0)
		*Pt0 =newPickPt;
	else if(nIndex==1)
		*Pt1 =newPickPt;
	else if(nIndex==2)
		*Pt2 =newPickPt;
	else
		return;

	double dRadius = dpxAlgorithmFun::DistanceOfPointToLine(*Pt0,*Pt1,*Pt2);
	double dHeight = sqrt(pow((Pt0->x-Pt1->x),2.0) + pow((Pt0->y-Pt1->y),2.0) + pow((Pt0->z-Pt1->z),2.0));
	QDateTime current_time =QDateTime::currentDateTime();
	QString sCurrentTime =current_time.toString("hh:mm:ss");
	pLine->setName("Line_"+sCurrentTime);
	pLine->setMetaData(DPX_RADIUS,QString::number(dRadius));

	CCVector3 vbefore(0,0,1);
	CCVector3 vafter(Pt1->x-Pt0->x, Pt1->y-Pt0->y, Pt1->z-Pt0->z);
	ccGLMatrix transM = ccGLMatrix::FromToRotation(vbefore,dpxAlgorithmFun::NormalVec(vafter));

	CCVector3 vecTrans((Pt0->x+Pt1->x)/2,(Pt0->y+Pt1->y)/2,(Pt0->z+Pt1->z)/2);
	transM.setTranslation(vecTrans);

	ccCylinder* pCylinder = new ccCylinder(dRadius,dHeight,&transM,"Cylinder"+sCurrentTime,24);
	pCylinder->setMetaData(DPX_CYLINEDER_RELATED_UID,strUID);//关联的ID
	pLine->addChild(pCylinder);
	m_window->removeFromOwnDB(m_pPickRoot);
	m_app->addToDB(m_pPickRoot);

	m_bMoveNode = false;
	pLine->invalidateBoundingBox();
	m_polyTip->setEnabled(false);
	m_window->redraw(false, true);
}
