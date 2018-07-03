//by duans

#include <QApplication>
#include <QMainWindow>
#include <QMessageBox>
#include <QDateTime>
#include <QDir>

#include "dpxPlaneTool.h"
#include "ccCompass.h"
#include "dpxAlgorithmFun.h"


dpxPlaneTool::dpxPlaneTool()
	: dpxNodeEditTool()
	, m_poly3D(0)
	, m_poly3DVertices(0)
{
	m_pPickRoot = new ccHObject("Plane");
}


dpxPlaneTool::~dpxPlaneTool()
{
	if (m_poly3D)
		delete m_poly3D;
}

//called when the tool is set to active (for initialization)
void dpxPlaneTool::toolActivated()
{
	if (!m_window)
	{
		ccLog::Warning("[Trace Polyline Tool] No associated window!");
		return ;
	}
	//duans
	m_window->addToOwnDB(m_pPickRoot);
	m_window->setCursor(Qt::CrossCursor);
	m_poly3D = 0;
	m_poly3DVertices = 0;
	dpxNodeEditTool::toolActivated();
}

void dpxPlaneTool::toolDisactivated()
{
	//finish trace
	if (m_window && m_pPickRoot)
		m_window->removeFromOwnDB(m_pPickRoot);

	if (m_app->getMainWindow() && m_pPickRoot)
		m_app->addToDB(m_pPickRoot);

	m_poly3D = 0;
	m_poly3DVertices = 0;

	dpxNodeEditTool::toolDisactivated();
}

void dpxPlaneTool::onMouseMove(int x, int y, Qt::MouseButtons buttons)
{
	if (!m_window)
	{
		assert(false);
		return;
	}

	if(m_nToolState==0)//采集状态
	{
		if (!m_poly3DVertices || m_poly3DVertices->size() == 0 || m_poly3DVertices->size() >2)
			return;

		assert(m_polyTip && m_polyTipVertices && m_polyTipVertices->size() == 3);

		//we replace the last point by the new one
		{
			QPointF pos2D = m_window->toCenteredGLCoordinates(x, y);
			CCVector3 P2D(	static_cast<PointCoordinateType>(pos2D.x()),
							static_cast<PointCoordinateType>(pos2D.y()),
							0);

			CCVector3* Middle = const_cast<CCVector3*>(m_polyTipVertices->getPointPersistentPtr(1));
			*Middle = P2D;
		}

		{
			const CCVector3* P3D = m_poly3DVertices->getPoint(m_poly3DVertices->size() - 1);
			ccGLCameraParameters camera;
			m_window->getGLCameraParameters(camera);

			CCVector3d A2D;
			camera.project(*P3D, A2D);

			CCVector3 vec3(static_cast<PointCoordinateType>(A2D.x - camera.viewport[2] / 2), //we convert A2D to centered coordinates (no need to apply high DPI scale or anything!)
						   static_cast<PointCoordinateType>(A2D.y - camera.viewport[3] / 2),
							0);
			CCVector3* firstP = const_cast<CCVector3*>(m_polyTipVertices->getPointPersistentPtr(0));
			CCVector3* lastP = const_cast<CCVector3*>(m_polyTipVertices->getPointPersistentPtr(2));
			*firstP = vec3;
			*lastP = vec3;
		}

		m_polyTip->setEnabled(true);
		m_window->redraw(true, false);
	}
	else//编辑状态直接采用基类
	{
		return dpxNodeEditTool::onMouseMove(x,y,buttons);
	}
}

//鼠标左键事件
void dpxPlaneTool::onMouseLeftClick(int x,int y)
{
	m_VNodeInfo.clear();
	m_nToolState=0;//采集状体
	//获取最近的线与点
	dpxNearestLine nearestInfo;
	bool bFind = getNearestLineInfo(x,y,nearestInfo,true);
	if(!bFind)
		return;

	if(nearestInfo.m_pLine==nullptr)
		return;
	//结点判断
	ccPolyline* pLine = nearestInfo.m_pLine;
	double dDistance = nearestInfo.m_dDistance;
	int nSegNum = nearestInfo.m_nSegNum;
	if(dDistance<SNAP_TOL_VALUE)
	{
		m_VNodeInfo.m_pLine = pLine;
		m_VNodeInfo.m_nNodeIndex = nSegNum;
		m_nToolState = 1;//若点击的时节点，则为编辑状态
	}
}

void dpxPlaneTool::onMouseReleaseEvent(int x,int y)
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

	if(!pLine->hasMetaData(DPX_RELATED_UID) || !pLine->hasMetaData(DPX_NORMAL))
		return;

	//删除旧的
	QString strUID = pLine->getMetaData(DPX_RELATED_UID).toString();
	ccHObject::Container vecHObjs;
	dpxSnapHelper::Instance()->FindAllObjs(vecHObjs,CC_TYPES::PLANE);//旧的删除
	for(int i =0;i<vecHObjs.size();i++)
	{
		ccLog::Warning("遍历PLANE"+QString::number(i));
		ccPlane* plane = ccHObjectCaster::ToPlane(vecHObjs[i]);
		if(plane==nullptr)
			continue;
		if(!plane->hasMetaData(DPX_RELATED_UID))
			continue;
		QString sUID = plane->getMetaData(DPX_RELATED_UID).toString();
		if(sUID.compare(strUID,Qt::CaseInsensitive)==0)
		{
			m_pPickRoot->removeChild(plane);
			//m_app->removeFromDB(plane);
		}
	}

	//更新线
	CCVector3* modefyPt = const_cast<CCVector3*>(pLine->getPointPersistentPtr(nIndex));
	*modefyPt = newPickPt;

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
		ccLog::Warning("释放鼠标1");
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

	//Fit plane!
	double rms = 0.0; //output for rms
	ccFitPlane* pPlane = ccFitPlane::Fit(pCloud, &rms);
	if (pPlane) //valid fit
	{
		//make plane to add to display
		pPlane->setVisible(true);
		pPlane->setSelectionBehavior(ccHObject::SELECTION_IGNORED);
		pPlane->setDisplay(m_window);
		QImage* pImage = new QImage(":/CC/plugin/qCompass/images/RedGreen.png");
		if(pImage)
		{
			pPlane->setAsTexture(*pImage);
		}

		CCVector3 vNormal = pPlane->getNormal();
		QString strNormal = QString::number(vNormal.x).append(" ").append(QString::number(vNormal.y)).append(" ").append(QString::number(vNormal.z));
		pLine->setMetaData(DPX_NORMAL,strNormal);
		pPlane->setMetaData(DPX_RELATED_UID,strUID);
		m_pPickRoot->addChild(pPlane);
		m_window->removeFromOwnDB(m_pPickRoot);
		m_app->addToDB(m_pPickRoot);
	}

	m_bMoveNode = false;
	pLine->invalidateBoundingBox();
	m_polyTip->setEnabled(false);
	m_window->redraw(false, true);
}

//called when a point in a point cloud gets picked while this tool is active
//pointPicked(pi.entity, pi.itemIndex, pi.clickPoint.x(), pi.clickPoint.y(), pi.P3D); //map straight to pointPicked function
void dpxPlaneTool::pointPicked(ccHObject* insertPoint, unsigned itemIdx, ccPointCloud* cloud, const CCVector3& P,int x/*=0*/,int y/*=0*/)
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
		m_poly3D->set2DMode(false);
		m_poly3D->addChild(m_poly3DVertices);
		m_poly3D->setWidth(1);

		//insertPoint->addChild(m_poly3D);
		m_pPickRoot->addChild(m_poly3D);
	}

	int nSize = m_poly3DVertices->size();
	if(nSize==0||nSize==1)//两点形成圆柱的轴线
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

		//Fit plane!
		double rms = 0.0; //output for rms
		ccFitPlane* pPlane = ccFitPlane::Fit(m_poly3DVertices, &rms);
		QString strRelateID = QUuid::createUuid().toString();
		if (pPlane) //valid fit
		{
			//make plane to add to display
			pPlane->setVisible(true);
			pPlane->setSelectionBehavior(ccHObject::SELECTION_IGNORED);
			pPlane->setDisplay(m_window);
			pPlane->setMetaData(DPX_RELATED_UID,strRelateID);
			QImage* pImage = new QImage(":/CC/plugin/qCompass/images/RedGreen.png");
			if(pImage)
			{
				pPlane->setAsTexture(*pImage);
			}

			CCVector3 vNormal = pPlane->getNormal();
			QString strNormal = QString::number(vNormal.x).append(" ").append(QString::number(vNormal.y)).append(" ").append(QString::number(vNormal.z));
			m_poly3D->setMetaData(DPX_NORMAL,strNormal);//法向量
			m_poly3D->setMetaData(DPX_RELATED_UID,strRelateID);//关联的ID
			m_pPickRoot->addChild(pPlane);
		}

		m_window->removeFromOwnDB(m_pPickRoot);
		m_app->addToDB(m_pPickRoot);
		m_polyTip->setEnabled(false);
		m_poly3D = 0;
		m_poly3DVertices = 0;
		m_nToolState=1;//采集状态结束，默认编辑状态
	}

	m_window->redraw(false, false);
}

//called when "Return" or "Space" is pressed, or the "Accept Button" is clicked or the tool is disactivated
void dpxPlaneTool::accept()
{
}

//called when the "Escape" is pressed, or the "Cancel" button is clicked
void dpxPlaneTool::cancel()
{
}

void dpxPlaneTool::onNewSelection(const ccHObject::Container& selectedEntities)
{
}

//if this returns true, the undo button is enabled in the gui
bool dpxPlaneTool::canUndo()
{
	return true; //yes - we can undo!
}

//called when the undo button is clicked
void dpxPlaneTool::undo()
{
}

void dpxPlaneTool::exportLine()
{
}
