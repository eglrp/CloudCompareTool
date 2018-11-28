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
		if(nearestInfo.m_pLine==nullptr || nearestInfo.m_pLine==0)
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

	ccHObject* pLineSet = dpxToolCommonFun::getRelatedLineSet(pLine);
	ccHObject* pSection = dpxToolCommonFun::getRelatedSection(pLine);
	if(pLineSet == nullptr || pSection == nullptr)
		return;

	//清掉选择集
	dpxSelectionManager::Instance()->ClearSelection();

	vector<ccPolyline*> vecSplitLines;
	if(!dpxToolCommonFun::splitLine(pLine,nSegNum,vecSplitLines))
		return;

	vector<ccPolyline*> vecLines = dpxToolCommonFun::getLinesFromLineSet(pLineSet);
	vector<ccPolyline*> vecNewLines;
	for(int i = 0 ;i < vecLines.size();i++)
	{
		if(vecLines[i] == pLine)
		{
			vecNewLines.insert(vecNewLines.end(),vecSplitLines.begin(),vecSplitLines.end());
		}
		vecNewLines.push_back(vecLines[i]);
	}
	bool bIsRefLine = dpxToolCommonFun::ConfimObjType(pLine,eObj_RoadRefLine);
    ccHObject* pNewLineSet = dpxToolCommonFun::CreateRoadLine(vecNewLines,bIsRefLine);

    pSection->removeChild(pLineSet);
    pSection->addChild(pNewLineSet);

	m_window->removeFromOwnDB(pSection);
	m_app->addToDB(pSection);

}















