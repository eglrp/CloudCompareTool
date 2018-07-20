

#ifndef _DPX_HDMAP_ROAD_STOP_LINE_TOOL_HEADER_
#define _DPX_HDMAP_ROAD_STOP_LINE_TOOL_HEADER_

//qCC_db
#include <ccHObject.h>
#include <ccGenericGLDisplay.h>

#include "dpxTraceLineTool.h"

//停止线需要连接两个roadLine或一个refLine和RoadLine的断点

/*
Tool used to digitise traces
*/
class dpxRoadStopLineTool : public dpxTraceLineTool
{
public:
	dpxRoadStopLineTool();
	virtual ~dpxRoadStopLineTool();
public:
	//重写基类原因：摁快捷键盘时，需要切换线拷贝的功能，
	//点击refLine 拷贝形成车道线
	virtual void onMouseLeftClick(int x,int y);

	//只支持单击节点生成停止线
	virtual void pointPicked(ccHObject* insertPoint, unsigned itemIdx, ccPointCloud* cloud, const CCVector3& P,int x=0,int y=0);

	//因为鼠标要点击线的节点，要在采集模式下又能显示捕捉到到线到节点  需要同时具备采集和捕捉两种状态的效果
	virtual void onMouseMove(int x, int y, Qt::MouseButtons buttons);
private:
	bool  m_bHasSelectOne;
};

#endif
