

#ifndef _DPX_HDMAP_ROAD_REF_LINE_TOOL_HEADER_
#define _DPX_HDMAP_ROAD_REF_LINE_TOOL_HEADER_

//qCC_db
#include <ccHObject.h>
#include <ccGenericGLDisplay.h>

#include "dpxTraceLineTool.h"

class ccPolyline;
class ccPointCloud;
class ccGLWindow;
class ccPickingHub;


/*
Tool used to digitise traces
*/
class dpxRoadRefLineTool : public dpxTraceLineTool
{
public:
	dpxRoadRefLineTool();
	virtual ~dpxRoadRefLineTool();
public:
//	virtual void toolActivated();
//	virtual void toolDisactivated();
//
//	//重写基类原因：摁快捷键盘时，需要切换线拷贝的功能，
//	//点击refLine 拷贝形成车道线
//	virtual void onMouseLeftClick(int x,int y);

	//在折线采集基础上，更改线的颜色、类型属性，并加到选择集中
	virtual void onMouseRightClick(int x,int y);

	//键盘事件
	virtual void onKeyPress(int key);
};

#endif
