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
//	if (m_polyTip)
//		delete m_polyTip;
}

//called when the tool is set to active (for initialization)
void dpxNodeEditTool::toolActivated()
{
	m_associatedWin = m_window;

	//m_associatedWin->setPickingMode(ccGLWindow::NO_PICKING);
	m_associatedWin->setInteractionMode(	ccGLWindow::TRANSFORM_CAMERA()
										|	ccGLWindow::INTERACT_SIG_RB_CLICKED
										|	ccGLWindow::INTERACT_CTRL_PAN
										|	ccGLWindow::INTERACT_SIG_MOUSE_MOVED);
	m_associatedWin->setCursor(Qt::CrossCursor);

//
	m_pSphere = new ccSphere("new");
//	m_pSphere->setSelectionBehavior(ccHObject::SELECTION_IGNORED);
//	m_pSphere->setDisplay(m_associatedWin);
//	m_pSphere->setTempColor(ccColor::red);
//	m_pSphere->setVisible(true);
//	m_pSphere->setEnabled(false);
//
	m_associatedWin->addToOwnDB(m_pSphere);
	//dpxSnapHelper::Instance()->AddTempShowObject(m_pSphere);
}

void dpxNodeEditTool::toolDisactivated()
{
	//移除所有的对象
	//m_associatedWin->removeFromOwnDB(m_polyTip);
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
	{
		//按着鼠标左右键进行拖动
		m_associatedWin->redraw(true, false);
		return;
	}

	//获取Camea
	ccGLCameraParameters camera;
	m_associatedWin->getGLCameraParameters(camera);
	double maxRadius = pickWidth_pix * camera.pixelSize / 2;

	CCVector3 rayAxis, rayOrigin;
	if(!getCurrentRay(camera,x,y,rayAxis,rayOrigin))
		return;

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

	m_associatedWin->removeFromOwnDB(m_pSphere);
	//建立射线
	Ray<PointCoordinateType> ray(rayAxis, rayOrigin);
	//鼠标的移动事件
	ccHObject::Container vecHObjs;
	dpxSnapHelper::Instance()->FindAllObjs(vecHObjs);//默认找到所有的线
	for(int i =0;i<vecHObjs.size();i++)
	{
		ccBBox box = vecHObjs[i]->getOwnBB();
		//vecHObjs[i]->setTempColor(ccColor::green);
		if (!AABB<PointCoordinateType>(box.minCorner()-margin,box.maxCorner() + margin).intersects(ray))
			continue;

		dpxSnapHelper::Instance()->ClearShowObject();
		ccPolyline* pLine = ccHObjectCaster::ToPolyline(vecHObjs[i]);
		if(pLine==nullptr)
			continue;

		double dDistance,dSegRatio;
		int nSegNum;
		CCVector3 nearestPt;
		dpxAlgorithmFun::DistanceLineToRay(pLine,rayAxis,rayOrigin,dDistance,nSegNum,dSegRatio,nearestPt);
		//一个移动的小球

		ccGLMatrix transM ;
		CCVector3 vecTrans(nearestPt.x,nearestPt.y,nearestPt.z);
		transM.setTranslation(vecTrans);

//-----------------------以下方法可行-------------------------------//
		//重新New可以加载成功 能不能让球自动移动
		m_pSphere = new ccSphere(maxRadius,&transM);
		m_pSphere->setSelectionBehavior(ccHObject::SELECTION_IGNORED);
		m_pSphere->setDisplay(m_associatedWin);
		m_pSphere->setTempColor(ccColor::red);
		m_pSphere->setVisible(true);
		m_pSphere->setEnabled(true);
		m_associatedWin->addToOwnDB(m_pSphere);

		//dpxSnapHelper::Instance()->AddTempShowObject(m_pSphere);
		//m_associatedWin->addToOwnDB(m_pSphere);
///////////////////////////////////////////////////////////////////////////
//		ccGLMatrix oldMatrix = m_pSphere->getTransformation();
//		ccGLMatrix inverseMatrix = oldMatrix.inverse();
//		m_pSphere->setEnabled(true);
//		m_pSphere->applyGLTransformation(inverseMatrix);//new ccSphere(maxRadius,&transM);
//		m_pSphere->applyGLTransformation(transM);
//		m_pSphere->setRadius(maxRadius);
//		m_associatedWin->addToOwnDB(m_pSphere);

		break;
	}

	m_associatedWin->redraw(true, true); //只刷新2D
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



