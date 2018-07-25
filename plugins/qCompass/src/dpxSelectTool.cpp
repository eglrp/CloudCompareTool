//by duans

#include <QApplication>
#include <QMainWindow>
#include <QMessageBox>
#include <QDateTime>

#include "dpxSelectTool.h"
#include "ccCylinder.h"
#include "dpxAlgorithmFun.h"

dpxSelectTool::dpxSelectTool()
	: dpxNodeEditTool()
{
}

dpxSelectTool::~dpxSelectTool()
{
}

void dpxSelectTool::onMouseReleaseEvent(int x,int y)
{
	if(m_window==nullptr)
		return;

	if(m_VNodeInfo.m_pLine==nullptr || m_VNodeInfo.m_nNodeIndex==-1)
		return;

	ccPolyline* pLine = m_VNodeInfo.m_pLine;
	int nIndex = m_VNodeInfo.m_nNodeIndex;

	if(nIndex>pLine->size()-1)
		return;
	if(!m_bMoveNode)//是否是拖拽节点模式
		return;

	ccGenericPointCloud* pTargetCloud = nullptr;
	int nPloudPtIndex=-1;
	CCVector3 newPickPt;
	if(!m_window->pickNearestPt(x,y,pTargetCloud,nPloudPtIndex,newPickPt))
	{
		ccLog::Warning("释放鼠标无法捕捉点");
		return;
	}

	CCVector3* modefyPt = const_cast<CCVector3*>(pLine->getPointPersistentPtr(nIndex));
	*modefyPt = newPickPt;

	m_bMoveNode = false;
	pLine->invalidateBoundingBox();
	m_polyTip->setEnabled(false);
	m_window->redraw(false, true);

	dpxSelectionManager::Instance()->redrawSelectionSet();
}

//鼠标右键事件
void dpxSelectTool::onMouseRightClick(int x,int y)
{
	dpxNodeEditTool::onMouseRightClick(x,y);
	dpxSelectionManager::Instance()->redrawSelectionSet();
}
//双击删除节点事件
void dpxSelectTool::onLeftDoubleClick(int x,int y)
{
	dpxNodeEditTool::onLeftDoubleClick(x,y);
	dpxSelectionManager::Instance()->redrawSelectionSet();
}

//左键事件  是否选中线节点，若选中则记录
void dpxSelectTool::onMouseLeftClick(int x,int y)
{
	m_VNodeInfo.clear();
		//duans
	bool bPushCtrlKey = false;
	if (QApplication::keyboardModifiers() == Qt::ControlModifier)
		bPushCtrlKey = true;

	//获取最近的线与点
	dpxNearestLine nearestInfo1;
	if(getNearestLineInfo(x,y,nearestInfo1))//获取临近线
	{
		if(nearestInfo1.m_pLine==nullptr || nearestInfo1.m_pLine==0)
			return;

		bool bHasInselect = dpxSelectionManager::Instance()->isInSelectSet(nearestInfo1.m_pLine);
        if(bHasInselect && !bPushCtrlKey)
        {
			dpxSelectionManager::Instance()->RemoveSelection(nearestInfo1.m_pLine);//摁Ctrl添加多个
        }
        else
        {
			dpxSelectionManager::Instance()->AddObject2Selection(nearestInfo1.m_pLine,!bPushCtrlKey);//摁Ctrl添加多个
        }
		dpxSelectionManager::Instance()->redrawSelectionSet();
	}
	else//若没选中线则清空选择集
	{
		dpxSelectionManager::Instance()->ClearSelection();//清空
		dpxSelectionManager::Instance()->redrawSelectionSet();
		return;
	}

	//获取最近的线与点
	dpxNearestLine nearestInfo;
	bool bFind = getNearestLineInfo(x,y,nearestInfo,true);//获取节点
	if(!bFind)
		return;

	if(nearestInfo.m_pLine==nullptr || nearestInfo.m_pLine==0)
		return;
	//结点判断
	ccPolyline* pLine = nearestInfo.m_pLine;
	double dDistance = nearestInfo.m_dDistance;
	double dSegRatio = nearestInfo.m_dSegRatio;
	int nSegNum = nearestInfo.m_nSegNum;
	CCVector3 nearPt = nearestInfo.m_nearestPt;

	if(dDistance<SNAP_TOL_VALUE)
	{
		m_VNodeInfo.m_pLine = pLine;
		m_VNodeInfo.m_nNodeIndex = nSegNum;
	}
}

