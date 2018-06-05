//class name:dpxCylinder
//brif:平面采集工具
//

#ifndef _DPX_EDIT_TOOL_HEADER_
#define _DPX_EDIT_TOOL_HEADER_

//qCC_db

#include "ccTool.h"
//#include "ccTrace.h"

/*
Tool used to digitise traces
*/
class dpxEditTool :	public ccTool
{
public:
	dpxEditTool();
	virtual ~dpxEditTool();

	//brif:鼠标位置作为起点，获取垂直与屏幕的射线
	//camera:当前相机
	//x:鼠标x 像素坐标
	//y:鼠标y 像素坐标
	//rayAxis:垂直于屏幕的射线方向向量
	//rayOrigin:射线的起点，世界坐标系
	bool getCurrentRay(ccGLCameraParameters camera,int x,int y,CCVector3& rayAxis,CCVector3& rayOrigin);
};

#endif
