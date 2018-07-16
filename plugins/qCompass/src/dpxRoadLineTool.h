/*
在基类里补充拷贝状态
	0：采集状态 1：编辑状态 2：拷贝状态
0：若鼠标没有点中refLine及roadLine节点，则采集新的roadLine
1：若鼠标点击了选择集中roadLine的节点，则可以拖拽roadLine
2：若鼠标点击了refLine的节点，则再点击一下点云就能把点击的refLine拷贝成新的RoadLine
*/

#ifndef _DPX_HDMAP_ROAD_LINE_TOOL_HEADER_
#define _DPX_HDMAP_ROAD_LINE_TOOL_HEADER_

//qCC_db
#include <ccHObject.h>
#include <ccGenericGLDisplay.h>

#include "dpxTraceLineTool.h"


/*
Tool used to digitise traces
*/
class dpxRoadLineTool : public dpxTraceLineTool
{
public:
	dpxRoadLineTool();
	virtual ~dpxRoadLineTool();
public:
	virtual void toolActivated();

	//重写基类原因：摁快捷键盘时，需要切换线拷贝的功能，
	//点击refLine 拷贝形成车道线
	virtual void onMouseLeftClick(int x,int y);

	//补充了拷贝模式下点击右键，恢复至编辑模式
	virtual void onMouseRightClick(int x,int y);

	//补充拷贝模式下，虚线不显示
	virtual void onMouseMove(int x, int y, Qt::MouseButtons buttons);

	//在dpxNodeEditTool基类下,控制不能修改refLine
	virtual void onMouseReleaseEvent(int x,int y);
	//补充拷贝状态，点一个点就拷贝线
	virtual void pointPicked(ccHObject* insertPoint, unsigned itemIdx, ccPointCloud* cloud, const CCVector3& P,int x=0,int y=0);
	//键盘事件
	virtual void onKeyPress(int key);
private:
	bool m_bSetRefLine;
};

#endif
