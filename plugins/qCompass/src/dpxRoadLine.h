/*
在基类里补充拷贝状态
	0：采集状态 1：编辑状态 2：拷贝状态
0：若鼠标没有点中refLine及roadLine节点，则采集新的roadLine
1：若鼠标点击了选择集中roadLine的节点，则可以拖拽roadLine
2：若鼠标点击了refLine的节点，则再点击一下点云就能把点击的refLine拷贝成新的RoadLine
*/

#ifndef _DPX_HDMAP_ROAD_LINE_HEADER_
#define _DPX_HDMAP_ROAD_LINE_HEADER_

//qCC_db
#include <ccHObject.h>
#include <ccGenericGLDisplay.h>
#include "dpxTraceLineTool.h"

/*
Tool used to digitise traces
*/
class dpxRoadLine
{
public:
	dpxRoadLine() {}
	virtual ~dpxRoadLine() {}
public:
	//点击refLine 拷贝形成车道线
	virtual void AddPoint(int x,int y) = 0;

	//补充了拷贝模式下点击右键，恢复至编辑模式
	virtual void DeletePoint(int x,int y) = 0;

	//补充拷贝模式下，虚线不显示
	virtual void  MovePoint(int x, int y) = 0;
protected:
	//std::vector<ccPolyLine*> m_vecPolyLines;
};

#endif
