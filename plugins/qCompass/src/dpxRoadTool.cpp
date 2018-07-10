
#include <QApplication>
#include <QMainWindow>
#include <QMessageBox>

#include "dpxRoadTool.h"
#include "dpxGeoEngine.h"

dpxRoadTool::dpxRoadTool()
{
}

dpxRoadTool::~dpxRoadTool()
{
}

void dpxRoadTool::toolActivated()
{
	dpxTraceLineTool::toolActivated();
}

void dpxRoadTool::toolDisactivated()
{
	dpxTraceLineTool::toolDisactivated();
}


void dpxRoadTool::onKeyPress(int sKey)
{
	ccLog::Warning("success! oh yare!!!");
}

//鼠标左键事件
void dpxRoadTool::onMouseLeftClick(int x,int y)
{
	m_VNodeInfo.clear();
	m_nToolState=0;//采集状态
	//获取最近的线与点
	dpxNearestLine nearestInfo;
	bool bFind = getNearestLineInfo(x,y,nearestInfo,true);
	if(!bFind)
		return;

	if(nearestInfo.m_pLine==nullptr)
		return;
	//结点判断
	ccPolyline* pLine = nearestInfo.m_pLine;
	double dDistance = nearestInfo.m_dDistance;
	int nSegNum = nearestInfo.m_nSegNum;
	if(dDistance<SNAP_TOL_VALUE)
	{
		m_VNodeInfo.m_pLine = pLine;
		m_VNodeInfo.m_nNodeIndex = nSegNum;
		m_nToolState = 1;//若点击的时节点，则为编辑状态
	}
}
