//by duans

#include <QApplication>
#include <QMainWindow>
#include <QMessageBox>
#include <QDateTime>
#include <QDir>

#include "dpxLineBreakTool.h"
#include "ccBBox.h"
#include "GenericIndexedCloudPersist.h"
#include "../../qCC/dpxFramework/dpxSnapHelper.h"
#include "../../qCC/dpxFramework/dpxSelectionManager.h"

using namespace CCLib;
dpxLineBreakTool::dpxLineBreakTool()
{
}

dpxLineBreakTool::~dpxLineBreakTool()
{
}

bool isObjValid(ccHObject* pObj)
{
	if(pObj==nullptr)
		return false;

    if(!pObj->hasMetaData(DPX_OBJECT_TYPE_NAME))
        return false;

	dpxObjectType eType = dpxObjectType(pObj->getMetaData(DPX_OBJECT_TYPE_NAME).toInt());
    if(eType != eObj_RoadRefLine && eType != eObj_RoadLine)
        return false;

	return true;
}


//左键事件  是否选中线节点，若选中则记录
void dpxLineBreakTool::onMouseLeftClick(int x,int y)
{
	//获取最近的线与点
	dpxNearestLine nearestInfo;
	bool bIsNodeEdit = false;
	bool bFindNode = getNearestLineInfo(x,y,nearestInfo,true,isObjValid);
	if(bFindNode)//点击的若是节点，可以进行节点编辑
	{
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
			bIsNodeEdit = true;
		}
	}

	if(bIsNodeEdit)
		return;

	//打断线段，一分为二
	dpxNearestLine nearestInfoV2;
	bool bFindSegment = getNearestLineInfo(x,y,nearestInfoV2,false,isObjValid);
	if(!bFindSegment)
		return ;

	if(nearestInfoV2.m_pLine==nullptr || nearestInfoV2.m_pLine==0)
		return;
	//结点判断
	ccPolyline* pLine = nearestInfoV2.m_pLine;
	double dDistance = nearestInfoV2.m_dDistance;
	int nSegNum = nearestInfoV2.m_nSegNum;
	if(dDistance>SNAP_TOL_VALUE)  //删除线段，直线一分为二
		return;

	ccHObject* pLineSet = dpxMapCommonFunc::getRelatedLineSet(pLine);
	ccHObject* pSection = dpxMapCommonFunc::getRelatedSection(pLine);
	if(pLineSet == nullptr || pSection == nullptr)
		return;

	//清掉选择集
	dpxSelectionManager::Instance()->ClearSelection();

	vector<ccPolyline*> vecSplitLines;
	if(!dpxMapCommonFunc::splitLine(pLine,nSegNum,vecSplitLines))
		return;

	vector<ccPolyline*> vecLines = dpxMapCommonFunc::getLinesFromLineSet(pLineSet);
	ccLog::Warning("old Line size ====:"+QString::number(vecLines.size()));
	vector<ccPolyline*> vecNewLines;
	for(int i = 0 ;i < vecLines.size();i++)
	{
		if(vecLines[i] == pLine) //被打断的段提替成打断后的几段
		{
			vecNewLines.insert(vecNewLines.end(),vecSplitLines.begin(),vecSplitLines.end());
		}
		else //其余段保留
		{
			ccPolyline* pNewLine = dpxMapCommonFunc::CopyNewLine(vecLines[i]);
			vecNewLines.push_back(pNewLine);
		}
	}
	bool bIsRefLine = dpxMapCommonFunc::ConfimObjType(pLine,eObj_RoadRefLine);
    ccHObject* pNewLineSet = dpxMapCommonFunc::CreateRoadLine(vecNewLines,bIsRefLine);

    //移除旧的LineSet 添加新的折线
    pSection->removeChild(pLineSet);
    pSection->addChild(pNewLineSet);
    pNewLineSet->setDisplay(m_window);

	m_window->removeFromOwnDB(pSection);
	m_app->addToDB(pSection);
}


//鼠标右键事件
void dpxLineBreakTool::onMouseRightClick(int x,int y)
{
	if(m_window==nullptr)
		return;
	//在合适的位置添加节点 //必须是选中的线才能加节点
	dpxNearestLine nearestInfo;
	bool bFind = getNearestLineInfo(x,y,nearestInfo);
	if(bFind==false)
		return;

	ccGenericPointCloud* pTargetCloud = nullptr;
	int nPloudPtIndex=-1;
	CCVector3 newPickPt;
	if(!m_window->pickNearestPt(x,y,pTargetCloud,nPloudPtIndex,newPickPt))
	{
		ccLog::Warning("鼠标右键加点无法找到捕捉点");
		return;
	}

	//add Point  Index:nsegNum+1 Pt:newPickPt
	int nsegNum = nearestInfo.m_nSegNum;
	ccPolyline* pLine = nearestInfo.m_pLine;
	if(pLine==nullptr || pLine==0)
		return;
	bool bRefLine = dpxMapCommonFunc::ConfimObjType(pLine,eObj_RoadRefLine);
	bool bRoadLine = dpxMapCommonFunc::ConfimObjType(pLine,eObj_RoadLine);
	if(!bRefLine && !bRoadLine) //只能给RoadLine和RefLine加点
		return;

	if(nsegNum<0||nsegNum>pLine->size()-2)
		return;

	GenericIndexedCloudPersist* ploudPersist = const_cast<GenericIndexedCloudPersist*>(pLine->getAssociatedCloud());
	ChunkedPointCloud* pChunkedPointCloud = dynamic_cast<ChunkedPointCloud*>(ploudPersist);
	if(pChunkedPointCloud==nullptr)
		return;
	//先加点到线的尾部，类似正常采集，再类似与冒泡法替换到插入的位置
	if (   !pChunkedPointCloud->reserve(pChunkedPointCloud->size() + 1)
		|| !pLine->reserve(pChunkedPointCloud->size() + 1))
	{
		ccLog::Error("Not enough memory");
		return;
	}

	pChunkedPointCloud->addPoint(newPickPt);
	pLine->addPointIndex(pChunkedPointCloud->size()-1);

	//类似与冒泡法 替换到插入的位置
	for(int i=pLine->size()-1;i>nsegNum+1;i--)
		pLine->swap(i,i-1);

	m_window->redraw(false, false);
}

void dpxLineBreakTool::onMouseReleaseEvent(int x,int y)
{
	if(m_window==nullptr)
		return;

	if(m_VNodeInfo.m_pLine==nullptr || m_VNodeInfo.m_nNodeIndex==-1)
		return;

	ccPolyline* pLine = m_VNodeInfo.m_pLine;
	int nIndex = m_VNodeInfo.m_nNodeIndex;

	if(  nIndex>pLine->size()-1)
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
	//更新符号线的几何
	ccHObject* pLineSet = dpxMapCommonFunc::getRelatedLineSet(pLine);
	if(pLineSet!=nullptr)
	{
		dpxMapCommonFunc::UpdateSymbolLine(pLineSet);//更新LineSet中的符号线
	}

	m_polyTip->setEnabled(false);
	m_window->removeFromOwnDB(pLineSet);
	m_app->addToDB(pLineSet);
	m_window->redraw(false, true);
}











