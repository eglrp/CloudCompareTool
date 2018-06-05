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
