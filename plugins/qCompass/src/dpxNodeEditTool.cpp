//by duans

#include <QApplication>
#include <QMainWindow>
#include <QMessageBox>
#include <QDateTime>
#include <QDir>

#include "dpxNodeEditTool.h"
#include "ccBBox.h"

#include "GenericIndexedCloudPersist.h"

#include "../../qCC/dpxFramework/dpxSnapHelper.h"

using namespace CCLib;
dpxNodeEditTool::dpxNodeEditTool()
{
	m_polyTipVertices = new ccPointCloud("Tip vertices");
	m_polyTipVertices->reserve(3);
	m_polyTipVertices->addPoint(CCVector3(0, 0, 0));
	m_polyTipVertices->addPoint(CCVector3(1, 1, 1));
	m_polyTipVertices->addPoint(CCVector3(2, 2, 2));
	m_polyTipVertices->setEnabled(false);

	m_polyTip = new ccPolyline(m_polyTipVertices);
	m_polyTip->setForeground(true);
	m_polyTip->setTempColor(ccColor::green);
	m_polyTip->set2DMode(true);
	m_polyTip->reserve(3);
	m_polyTip->addPointIndex(0, 3);
	m_polyTip->setWidth(1); //'1' is equivalent to the default line size
	m_polyTip->addChild(m_polyTipVertices);

	//捕捉到节点
	m_VNodeInfo.clear();
}

dpxNodeEditTool::~dpxNodeEditTool()
{
}

//called when the tool is set to active (for initialization)
void dpxNodeEditTool::toolActivated()
{
	m_window->setCursor(Qt::CrossCursor);
	m_window->addToOwnDB(m_polyTip);
	m_window->setUnclosable(true);
	dpxSnapHelper::Instance()->ClearShowObject();
}

void dpxNodeEditTool::toolDisactivated()
{
	//移除所有的对象
	dpxSnapHelper::Instance()->ClearShowObject();
	m_window->removeFromOwnDB(m_polyTip);
}

//右键事件
void dpxNodeEditTool::onMouseRightClick(int x,int y)
{
	if(m_window==nullptr)
		return;
	//在合适的位置添加节点 //必须是选中的线才能加节点
	dpxNearestLine nearestInfo;
	bool bFind = getNearestLineInfo(x,y,nearestInfo);
	if(bFind==false)
		return;

	ccGenericPointCloud* pTargetCloud = nullptr;
	int nPloudPtIndex=-1;
	CCVector3 newPickPt;
	if(!m_window->pickNearestPt(x,y,pTargetCloud,nPloudPtIndex,newPickPt))
	{
		ccLog::Warning("鼠标右键加点无法找到捕捉点");
		return;
	}

	//add Point  Index:nsegNum+1 Pt:newPickPt
	int nsegNum = nearestInfo.m_nSegNum;
	ccPolyline* pLine = nearestInfo.m_pLine;
	if(pLine==nullptr || pLine==0)
		return;
	if(nsegNum<0||nsegNum>pLine->size()-2)
		return;

	GenericIndexedCloudPersist* ploudPersist = const_cast<GenericIndexedCloudPersist*>(pLine->getAssociatedCloud());
	ChunkedPointCloud* pChunkedPointCloud = dynamic_cast<ChunkedPointCloud*>(ploudPersist);
	if(pChunkedPointCloud==nullptr)
		return;
	//先加点到线的尾部，类似正常采集，再类似与冒泡法替换到插入的位置
	if (   !pChunkedPointCloud->reserve(pChunkedPointCloud->size() + 1)
		|| !pLine->reserve(pChunkedPointCloud->size() + 1))
	{
		ccLog::Error("Not enough memory");
		return;
	}

	pChunkedPointCloud->addPoint(newPickPt);
	pLine->addPointIndex(pChunkedPointCloud->size()-1);

	//类似与冒泡法 替换到插入的位置
	for(int i=pLine->size()-1;i>nsegNum+1;i--)
		pLine->swap(i,i-1);

	m_window->redraw(false, false);
}

//右键事件
void dpxNodeEditTool::onLeftDoubleClick(int x,int y)
{
	//获取最近的线与点
	dpxNearestLine nearestInfo;
	bool bFind = getNearestLineInfo(x,y,nearestInfo,true);
	if(!bFind)
		return;
	//结点判断
	ccPolyline* pLine = nearestInfo.m_pLine;
	double dDistance = nearestInfo.m_dDistance;
	int nSegNum = nearestInfo.m_nSegNum;

	if(pLine==nullptr || pLine==0)
		return;

	if(dDistance>=SNAP_TOL_VALUE)
		return;

	int nSize = pLine->size();
	if(0<=nSegNum && nSegNum<nSize && nSize>1)
	{
		pLine->removePoint(nSegNum);
		pLine->invalidateBoundingBox();
		m_window->redraw(false, true);
	}
}

//左键事件  是否选中线节点，若选中则记录
void dpxNodeEditTool::onMouseLeftClick(int x,int y)
{
	m_VNodeInfo.clear();
	//获取最近的线与点
	dpxNearestLine nearestInfo;
	bool bFind = getNearestLineInfo(x,y,nearestInfo,true);
	if(!bFind)
		return;

	if(nearestInfo.m_pLine==nullptr || nearestInfo.m_pLine==0)
		return;
	//结点判断
	ccPolyline* pLine = nearestInfo.m_pLine;
	double dDistance = nearestInfo.m_dDistance;
	int nSegNum = nearestInfo.m_nSegNum;

	if(dDistance<SNAP_TOL_VALUE)
	{
		m_VNodeInfo.m_pLine = pLine;
		m_VNodeInfo.m_nNodeIndex = nSegNum;
	}
}

void dpxNodeEditTool::onMouseReleaseEvent(int x,int y)
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

	CCVector3* modefyPt = const_cast<CCVector3*>(pLine->getPointPersistentPtr(nIndex));
	*modefyPt = newPickPt;

	m_bMoveNode = false;
	pLine->invalidateBoundingBox();
	m_polyTip->setEnabled(false);
	m_window->redraw(false, true);
}

void dpxNodeEditTool::onMouseMove(int x, int y, Qt::MouseButtons buttons)
{
	if (buttons == Qt::LeftButton)
	{
		//节点拖动
		ccPolyline* pLine = m_VNodeInfo.m_pLine;
		int nIndex = m_VNodeInfo.m_nNodeIndex;
        if(pLine==nullptr)
			return;
		ccLog::Warning(QString::number(nIndex));
		if(nIndex<0|| nIndex>pLine->size()-1)
		{
			ccLog::Warning("error node index");
			return;
		}
		ccGLCameraParameters camera;
		m_window->getGLCameraParameters(camera);

		CCVector3d First2D,Last2D;

		if(nIndex==0)//拖动首节点效果
		{
			const CCVector3* pFirst = pLine->getPoint(nIndex+1);
			const CCVector3* pLast = pLine->getPoint(nIndex+1);
			camera.project(*pFirst, First2D);
			camera.project(*pLast, Last2D);
		}
		else if (nIndex==pLine->size()-1) //拖动尾节点效果
		{
			const CCVector3* pFirst = pLine->getPoint(nIndex-1);
			const CCVector3* pLast = pLine->getPoint(nIndex-1);
			camera.project(*pFirst, First2D);
			camera.project(*pLast, Last2D);
		}
		else //中间节点
		{
			const CCVector3* pFirst = pLine->getPoint(nIndex-1);
			const CCVector3* pLast = pLine->getPoint(nIndex+1);
			camera.project(*pFirst, First2D);
			camera.project(*pLast, Last2D);
		}

		CCVector3* firstPt = const_cast<CCVector3*>(m_polyTipVertices->getPointPersistentPtr(0));
		*firstPt = CCVector3(static_cast<PointCoordinateType>(First2D.x - camera.viewport[2] / 2), //we convert A2D to centered coordinates (no need to apply high DPI scale or anything!)
							static_cast<PointCoordinateType>(First2D.y - camera.viewport[3] / 2),
							0);

		CCVector3* middlePt = const_cast<CCVector3*>(m_polyTipVertices->getPointPersistentPtr(1));
		QPointF pos2D = m_window->toCenteredGLCoordinates(x, y);
		CCVector3 P2D(	static_cast<PointCoordinateType>(pos2D.x()),
						static_cast<PointCoordinateType>(pos2D.y()),
						0);
		*middlePt = P2D;

		CCVector3* LastPt = const_cast<CCVector3*>(m_polyTipVertices->getPointPersistentPtr(2));
		*LastPt = CCVector3(static_cast<PointCoordinateType>(Last2D.x - camera.viewport[2] / 2), //we convert A2D to centered coordinates (no need to apply high DPI scale or anything!)
							static_cast<PointCoordinateType>(Last2D.y - camera.viewport[3] / 2),
							0);
		m_polyTip->setEnabled(true);
		m_bMoveNode = true;
		m_window->redraw(false, false); //只刷新2D
	}
	else //显示捕捉效果
	{
		m_polyTip->setEnabled(false);
		//获取Camea
		ccGLCameraParameters camera;
		m_window->getGLCameraParameters(camera);
		double maxRadius =  camera.pixelSize / 2;

		//清空捕捉效果
		dpxSnapHelper::Instance()->ClearShowObject();
		//获取最近的线与点
		dpxNearestLine nearestInfo;
		bool bFind = getNearestLineInfo(x, y,nearestInfo);
		if(!bFind)
		{
			m_window->redraw(false, false); //只刷新2D
			return;
		}
		else //添加显示效果
		{
			ccPolyline* pNearestLine = nearestInfo.m_pLine;
			if(pNearestLine==nullptr||pNearestLine==0)
				return;
			int nSize = pNearestLine->size();
			for(int i=0;i<nSize;i++)
			{
				const CCVector3* pPoint = pNearestLine->getPoint(i);
				//一个移动的小球
				ccGLMatrix transM ;
				CCVector3 vecTrans(pPoint->x,pPoint->y,pPoint->z);
				transM.setTranslation(vecTrans);

				//-----------------------以下方法可行-------------------------------//
				ccSphere* pSphere = new ccSphere(0.12,&transM,"Sphere",4);
				pSphere->setSelectionBehavior(ccHObject::SELECTION_IGNORED);
				pSphere->setDisplay(m_window);
				pSphere->setTempColor(ccColor::magenta); //orange
				pSphere->setVisible(true);
				pSphere->setEnabled(true);
				dpxSnapHelper::Instance()->AddTempShowObject(pSphere,false);
			}
			//一个移动的小球，在最近的线的点
			if(0)
			{
				ccGLMatrix transM;
				CCVector3 vecTrans(nearestInfo.m_nearestPt.x,nearestInfo.m_nearestPt.y,nearestInfo.m_nearestPt.z);
				transM.setTranslation(vecTrans);

				ccSphere* pMoveSphere = new ccSphere(maxRadius,&transM,"nearestPt",6);
				pMoveSphere->setSelectionBehavior(ccHObject::SELECTION_IGNORED);
				pMoveSphere->setDisplay(m_window);
				pMoveSphere->setTempColor(ccColor::magenta);
				pMoveSphere->setVisible(true);
				pMoveSphere->setEnabled(true);
				dpxSnapHelper::Instance()->AddTempShowObject(pMoveSphere,false);
			}
			m_window->redraw(false, false); //只刷新2D
		}//捕捉效果
	}
}

void dpxNodeEditTool::pointPicked(ccHObject* insertPoint, unsigned itemIdx, ccPointCloud* cloud, const CCVector3& P,int x/*=0*/,int y/*=0*/)
{
	return;
}



