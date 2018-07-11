
#include <QApplication>
#include <QMainWindow>
#include <QMessageBox>

#include "dpxRoadStopLineTool.h"
#include "dpxGeoEngine.h"

dpxRoadStopLineTool::dpxRoadStopLineTool()
{
}

dpxRoadStopLineTool::~dpxRoadStopLineTool()
{
}

void dpxRoadStopLineTool::toolActivated()
{
	dpxTraceLineTool::toolActivated();
}

void dpxRoadStopLineTool::toolDisactivated()
{
	dpxTraceLineTool::toolDisactivated();
}


void dpxRoadStopLineTool::onKeyPress(int sKey)
{
	ccLog::Warning("success! oh yare!!!" + QString::number(sKey));
}

//鼠标左键事件
void dpxRoadStopLineTool::onMouseLeftClick(int x,int y)
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
