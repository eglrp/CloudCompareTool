//by duans

#include <QApplication>
#include <QMainWindow>
#include <QMessageBox>
#include <QDateTime>
#include <QDir>

#include "dpxPickAndEditTool.h"
#include "ccCompass.h"
#include "dpxAlgorithmFun.h"


dpxPickAndEditTool::dpxPickAndEditTool()
	: dpxNodeEditTool()
	, m_poly3D(0)
	, m_poly3DVertices(0)
{
	m_pPickRoot = new ccHObject("UnKnown");
	m_nToolState =1;
}


dpxPickAndEditTool::~dpxPickAndEditTool()
{
	if (m_poly3D)
		delete m_poly3D;
}

//called when the tool is set to active (for initialization)
void dpxPickAndEditTool::toolActivated()
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
	m_nToolState = 1;//编辑状态
}

void dpxPickAndEditTool::toolDisactivated()
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

void dpxPickAndEditTool::onMouseMove(int x, int y, Qt::MouseButtons buttons)
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
void dpxPickAndEditTool::onMouseLeftClick(int x,int y)
{
	m_VNodeInfo.clear();
	m_nToolState=0;//采集状态
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

void dpxPickAndEditTool::onMouseReleaseEvent(int x,int y)
{
	return dpxNodeEditTool::onMouseReleaseEvent(x,y);
}

//called when a point in a point cloud gets picked while this tool is active
//pointPicked(pi.entity, pi.itemIndex, pi.clickPoint.x(), pi.clickPoint.y(), pi.P3D); //map straight to pointPicked function
void dpxPickAndEditTool::pointPicked(ccHObject* insertPoint, unsigned itemIdx, ccPointCloud* cloud, const CCVector3& P,int x/*=0*/,int y/*=0*/)
{
	if(m_nToolState)//编辑状体
		return;

	if (!m_window)
	{
		assert(false);
		return;
	}
}
