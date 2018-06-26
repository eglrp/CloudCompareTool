//by duans

#include <QApplication>
#include <QMainWindow>
#include <QMessageBox>
#include <QDateTime>
#include <QDir>

#include "dpxEditTool.h"

dpxEditTool::dpxEditTool()
{
}

dpxEditTool::~dpxEditTool()
{
}

bool dpxEditTool::getCurrentRay(ccGLCameraParameters camera,int x,int y,CCVector3& rayAxis,CCVector3& rayOrigin)
{
	//获取Camea
	y = camera.viewport[3] - 1 - y; //屏幕坐标转成左下角00

	//0 0 0投影 用于射线
	CCVector3d clickPosd(x, y, 0.0);
	CCVector3d X(0, 0, 0);
	if (!camera.unproject(clickPosd, X))
	{
		ccLog::Warning("can unproject x y 0");
		return false;
	}
	////0 0 0投影  用于射线
	CCVector3d clickPosd2(x, y, 1.0);
	CCVector3d Y(0, 0, 0);
	if (!camera.unproject(clickPosd2, Y))
	{
		ccLog::Warning("can unproject Mouse x y 1");
		return false;
	}

	rayAxis = CCVector3::fromArray((Y-X).u);
	rayOrigin = CCVector3::fromArray(X.u);

	rayAxis.normalize(); //normalize afterwards as the local transformation may have a scale != 1
	return true;
}

bool dpxEditTool::getNearestLineInfo(int x, int y,dpxNearestLine& nearestInfo,bool bNodeSnap/*=false*/)
{
	int pickWidth_pix = 1;//默认值
	if (m_window==nullptr)
	{
		assert(false);
		return false;
	}
	//获取Camea
	ccGLCameraParameters camera;
	m_window->getGLCameraParameters(camera);
	double maxRadius = pickWidth_pix * camera.pixelSize / 2;
	//鼠标点垂直与屏幕的射线
	CCVector3 rayAxis, rayOrigin;
	if(!getCurrentRay(camera,x,y,rayAxis,rayOrigin))
		return false;
	//建立射线
	Ray<PointCoordinateType> ray(rayAxis, rayOrigin);

	//搜索边区域
	CCVector3 margin(maxRadius, maxRadius, maxRadius);
	bool bFindNearestLine = false;
	//鼠标的移动事件
	ccHObject::Container vecHObjs;
	dpxSnapHelper::Instance()->FindAllObjs(vecHObjs);//默认找到所有的线
	for(int i =0;i<vecHObjs.size();i++)
	{
		ccHObject* pObj =  vecHObjs[i];
		if(pObj==nullptr)
			continue;
		ccBBox box = pObj->getOwnBB();
		//vecHObjs[i]->setTempColor(ccColor::green);
		if (!AABB<PointCoordinateType>(box.minCorner()-margin,box.maxCorner() + margin).intersects(ray))
			continue;

		bFindNearestLine = true;
		ccPolyline* pLine = ccHObjectCaster::ToPolyline(pObj);
		if(pLine==nullptr)
			continue;

		double dDistance,dSegRatio;
		int nSegNum;
		CCVector3 nearestPt;
		if(!bNodeSnap)//最近点
		{
			dpxAlgorithmFun::DistanceLineToRay(pLine,rayAxis,rayOrigin,dDistance,nSegNum,dSegRatio,nearestPt);
		}
		else //找节点
		{
			dpxAlgorithmFun::DistanceLineNodeToRay(pLine,rayAxis,rayOrigin,dDistance,nSegNum,dSegRatio,nearestPt);
		}

		if(dDistance < nearestInfo.m_dDistance)
		{
			nearestInfo.m_pLine = pLine;
			nearestInfo.m_dDistance = dDistance;
			nearestInfo.m_nSegNum = nSegNum;
			nearestInfo.m_dSegRatio = dSegRatio;
			nearestInfo.m_nearestPt = nearestPt;
			ccLog::Warning("find Node");
		}
	}

	return bFindNearestLine;
}
