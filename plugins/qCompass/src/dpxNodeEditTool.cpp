//by duans

#include <QApplication>
#include <QMainWindow>
#include <QMessageBox>
#include <QDateTime>
#include <QDir>

#include "dpxNodeEditTool.h"
#include "ccBBox.h"


#include "../../qCC/dpxFramework/dpxSnapHelper.h"
dpxNodeEditTool::dpxNodeEditTool()
{
}

dpxNodeEditTool::~dpxNodeEditTool()
{
}

//called when the tool is set to active (for initialization)
void dpxNodeEditTool::toolActivated()
{
	m_associatedWin = m_window;
	m_associatedWin->setCursor(Qt::CrossCursor);

	//移动的球
	m_pSphere = new ccSphere("new");
	dpxSnapHelper::Instance()->ClearShowObject();
}

void dpxNodeEditTool::toolDisactivated()
{
	//移除所有的对象
	dpxSnapHelper::Instance()->ClearShowObject();
}

	//右键事件
void dpxNodeEditTool::onMouseRightClick(int x,int y)
{
}

void dpxNodeEditTool::onMouseMove(int x, int y, Qt::MouseButtons buttons)
{
	int pickWidth_pix = 1;//默认值

	if (!m_associatedWin)
	{
		assert(false);
		return;
	}

	if (buttons != Qt::NoButton)
		return;

	//获取Camea
	ccGLCameraParameters camera;
	m_associatedWin->getGLCameraParameters(camera);
	double maxRadius = pickWidth_pix * camera.pixelSize / 2;
	ccLog::Warning(QString::number(maxRadius));

	//鼠标点垂直与屏幕的射线
	CCVector3 rayAxis, rayOrigin;
	if(!getCurrentRay(camera,x,y,rayAxis,rayOrigin))
		return;
	//建立射线
	Ray<PointCoordinateType> ray(rayAxis, rayOrigin);

	//搜索边区域
	CCVector3 margin(0, 0, 0);
	double maxFOV_rad = 0;
	if (camera.perspective)
	{
		maxFOV_rad = 0.002 * pickWidth_pix; //empirical conversion from pixels to FOV angle (in radians)
	}
	else
	{
		maxRadius = pickWidth_pix * camera.pixelSize / 2;
		ccLog::Warning(QString::number(maxRadius));
		margin = CCVector3(1, 1, 1) * static_cast<PointCoordinateType>(maxRadius);
	}

	//清空原有效果图形
	dpxSnapHelper::Instance()->ClearShowObject();

	dpxNearestLine nearestInfo;
	bool bFindNearestLine = false;
	//鼠标的移动事件
	ccHObject::Container vecHObjs;
	dpxSnapHelper::Instance()->FindAllObjs(vecHObjs);//默认找到所有的线
	for(int i =0;i<vecHObjs.size();i++)
	{
		ccBBox box = vecHObjs[i]->getOwnBB();
		//vecHObjs[i]->setTempColor(ccColor::green);
		if (!AABB<PointCoordinateType>(box.minCorner()-margin,box.maxCorner() + margin).intersects(ray))
			continue;

		bFindNearestLine = true;
		ccPolyline* pLine = ccHObjectCaster::ToPolyline(vecHObjs[i]);
		if(pLine==nullptr)
			continue;

		double dDistance,dSegRatio;
		int nSegNum;
		CCVector3 nearestPt;
		dpxAlgorithmFun::DistanceLineToRay(pLine,rayAxis,rayOrigin,dDistance,nSegNum,dSegRatio,nearestPt);
		if(dDistance < nearestInfo.m_dDistance)
		{
			nearestInfo.m_pLine = pLine;
			nearestInfo.m_dDistance = dDistance;
			nearestInfo.m_dSegRatio = dSegRatio;
			nearestInfo.m_nSegNum = nSegNum;
			nearestInfo.m_nearestPt = nearestPt;
		}
	}

	if(!bFindNearestLine)
	{
		m_associatedWin->redraw(false, false); //只刷新2D
		return;
	}

	ccPolyline* pNearestLine = nearestInfo.m_pLine;
	int nSize = pNearestLine->size();
	for(int i=0;i<nSize;i++)
	{
		const CCVector3* pPoint = pNearestLine->getPoint(i);
			//一个移动的小球
		ccGLMatrix transM ;
		CCVector3 vecTrans(pPoint->x,pPoint->y,pPoint->z);
		transM.setTranslation(vecTrans);

		//-----------------------以下方法可行-------------------------------//
		ccSphere* pSphere = new ccSphere(0.1,&transM,"Sphere",4);
		pSphere->setSelectionBehavior(ccHObject::SELECTION_IGNORED);
		pSphere->setDisplay(m_associatedWin);
		pSphere->setTempColor(ccColor::red);
		pSphere->setVisible(true);
		pSphere->setEnabled(true);
		dpxSnapHelper::Instance()->AddTempShowObject(pSphere,false);
	}
	//一个移动的小球，鼠标最近的线
	ccGLMatrix transM ;
	CCVector3 vecTrans(nearestInfo.m_nearestPt.x,nearestInfo.m_nearestPt.y,nearestInfo.m_nearestPt.z);
	transM.setTranslation(vecTrans);

	m_pSphere = new ccSphere(maxRadius,&transM,"nearestPt",12);
	m_pSphere->setSelectionBehavior(ccHObject::SELECTION_IGNORED);
	m_pSphere->setDisplay(m_associatedWin);
	m_pSphere->setTempColor(ccColor::red);
	m_pSphere->setVisible(true);
	m_pSphere->setEnabled(true);
	dpxSnapHelper::Instance()->AddTempShowObject(m_pSphere,false);

	m_associatedWin->redraw(false, false); //只刷新2D
}

//called when a point in a point cloud gets picked while this tool is active
//pointPicked(pi.entity, pi.itemIndex, pi.clickPoint.x(), pi.clickPoint.y(), pi.P3D); //map straight to pointPicked function
void dpxNodeEditTool::pointPicked(ccHObject* insertPoint, unsigned itemIdx, ccPointCloud* cloud, const CCVector3& P,int x/*=0*/,int y/*=0*/)
{
	if (!m_associatedWin)
	{
		assert(false);
		return;
	}
	if (!insertPoint)
		return;

	m_associatedWin->redraw(false, false);
}



