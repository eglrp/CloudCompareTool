
#include "dpxMapCommonFunc.h"
namespace MapCommon {

bool ConfimObjType(ccHObject* pHObject,dpxObjectType eType)
{
	if(pHObject == nullptr)
		return false;

	bool bHasObjType = pHObject->hasMetaData(DPX_OBJECT_TYPE_NAME);
	if(!bHasObjType)
		return false;

	dpxObjectType tempType = dpxObjectType(pHObject->getMetaData(DPX_OBJECT_TYPE_NAME).toInt());
	if(tempType==eType)
		return true;

	return false;
}


bool  ConfimObjType(ccPolyline* pLine,dpxObjectType eType)
{
	if(pLine == nullptr)
		return false;

	bool bHasObjType = pLine->hasMetaData(DPX_OBJECT_TYPE_NAME);
	if(!bHasObjType)
		return false;

	dpxObjectType tempType = dpxObjectType(pLine->getMetaData(DPX_OBJECT_TYPE_NAME).toInt());
	if(tempType==eType)
		return true;

	return false;
}

//应该引入R树索引
bool CreateJunction(dpxMap* pMap,vector<refLineInfo> &refInfos,double dMinDis,double dMaxDis)
{
	if(pMap==nullptr)
		return false;
	int nCount = refInfos.size();
	if(nCount<1)
		return false;
	for(int i = 0;i<nCount;i++)
	{
		if(refInfos[i].m_bHasTailSet)
			continue;

		CCVector3 lastPt = refInfos[i].m_lastPt;

        for(int j=0;j < nCount;j++)
        {
			if(i == j)
				continue;

			if(!refInfos[i].m_bHasHeadSet)
			{
				CCVector3 tempfirstPt = refInfos[j].m_firstPt;
			}

			if(!refInfos[i].m_bHasTailSet)
			{
				CCVector3 templastPt = refInfos[j].m_lastPt;
			}
        }
	}
	return true;
}

double  DisTance(CCVector3 pt1,CCVector3 pt2)
{
	return sqrt(pow((pt1.x - pt2.x), 2.0) + pow((pt1.y - pt2.y), 2.0) + pow((pt1.z - pt2.z), 2.0));
}

//前JuncitonID
int  GetRefLinePreID(ccPolyline* pDPXRefLine)
{
	if(pDPXRefLine==nullptr)
		return -1;
	if(pDPXRefLine->hasMetaData(HEAD_JUNCTION_UID))
		return -1;
	return pDPXRefLine->getMetaData(HEAD_JUNCTION_UID).toInt();
}
//后JuncitonID
int  GetRefLineSucID(ccPolyline* pDPXRefLine)
{
	if(pDPXRefLine==nullptr)
		return -1;
	if(pDPXRefLine->hasMetaData(TAIL_JUNCTION_UID))
		return -1;
	return pDPXRefLine->getMetaData(TAIL_JUNCTION_UID).toInt();
}

vector<int>  GetRelatedRefID(ccPolyline* pJunctionLine)
{
	vector<int> vecIDs;
	if(pJunctionLine==nullptr)
		return  vecIDs;
	if(!pJunctionLine->hasMetaData(RELATED_REFLINE_UID))
		return  vecIDs;
    QString strValue =  pJunctionLine->getMetaData(RELATED_REFLINE_UID).toString();
    QStringList strList = strValue.split(';',QString::SkipEmptyParts);
    for(int i =0;i<strList.size();i++)
	{
		vecIDs.push_back(strList.at(i).toInt());
	}

	return  vecIDs;
}


QString getRefIDValue(const vector<int>& vecRefIDs)
{
    QString strValue = "";
    for(int i =0;i<vecRefIDs.size();i++)
    {
		if(i==0)
			strValue = QString::number(vecRefIDs[i]);
		else
			strValue = strValue+";"+QString::number(vecRefIDs[i]);
    }
	return strValue;
}

int getMaxSectionID()
{
	dpxMap* pCurrentMap = dpxGeoEngine::Instance()->GetMap();
	if(pCurrentMap==nullptr)
		return -1;
	dpxLayer* pRoadLayer = pCurrentMap->getRoadLyr();
	if(pRoadLayer==nullptr)
		return -1;
    ccHObject* pRoadRoot = pRoadLayer->getRootData();
    if(pRoadRoot==nullptr)
		return -1;

	int nMaxID = -1;
	int nSectionSize = pRoadRoot->getChildrenNumber(); //RefLine(Section)
	for(int i=0;i<nSectionSize;i++)
	{
		ccHObject* pObj = pRoadRoot->getChild(i);
		if(pObj==nullptr)
			continue;

		if(!pObj->hasMetaData(DPX_OBJECT_TYPE_NAME))
			continue;

		dpxObjectType tempType = dpxObjectType(pObj->getMetaData(DPX_OBJECT_TYPE_NAME).toInt());
		if(tempType != eObj_Section) //ID只设置给Section
			continue;

		if(!pObj->hasMetaData(DPX_UID))
			continue;

		int nID = pObj->getMetaData(DPX_UID).toInt();
		nMaxID =  nID > nMaxID ? nID : nMaxID;
	}
	return nMaxID;
}

int getMaxJunctionID()
{
	dpxMap* pCurrentMap = dpxGeoEngine::Instance()->GetMap();
	if(pCurrentMap==nullptr)
		return -1;
	dpxLayer* pJunctionLayer = pCurrentMap->getJunctionLyr();
	if(pJunctionLayer==nullptr)
		return -1;
    ccHObject* pRoot = pJunctionLayer->getRootData();
    if(pRoot==nullptr)
		return -1;

	int nMaxID = -1;
	int nJunctionSize = pRoot->getChildrenNumber(); //RefLine(Section)
	for(int i=0;i<nJunctionSize;i++)
	{
		ccHObject* pObj = pRoot->getChild(i);
		if(pObj==nullptr)
			continue;

		ccPolyline* pJunctionLine = pObj && pObj->isA(CC_TYPES::POLY_LINE) ? static_cast<ccPolyline*>(pObj) : 0;
		if(pJunctionLine==0)
			continue;

		if(!pJunctionLine->hasMetaData(DPX_OBJECT_TYPE_NAME))
			continue;

		dpxObjectType tempType = dpxObjectType(pJunctionLine->getMetaData(DPX_OBJECT_TYPE_NAME).toInt());
		if(tempType != eObj_Junction)
			continue;

		if(!pJunctionLine->hasMetaData(DPX_UID))
			continue;

		int nID = pJunctionLine->getMetaData(DPX_UID).toInt();
		nMaxID =  nID > nMaxID ? nID : nMaxID;
	}
	return nMaxID;
}

vector<ccHObject*> GetAllSection(dpxMap* pMap)
{
	vector<ccHObject*> vecResult;
	if(pMap==nullptr)
		return vecResult;
	dpxLayer* pRoadLayer = pMap->getRoadLyr();
	ccHObject* pRoadRoot = pRoadLayer->getRootData();
	if(pRoadRoot==nullptr)
		return vecResult;

	int nRefSize = pRoadRoot->getChildrenNumber(); //RefLine(Section)
	for(int i=0;i<nRefSize;i++)
	{
		ccHObject* pSection = pRoadRoot->getChild(i);
		if(pSection==nullptr)
			continue;

		if(!pSection->hasMetaData(DPX_OBJECT_TYPE_NAME))
			continue;

		dpxObjectType tempType = dpxObjectType(pSection->getMetaData(DPX_OBJECT_TYPE_NAME).toInt());
		if(tempType!=eObj_Section)
			continue;

		if(!pSection->hasMetaData(DPX_UID))
			continue;

		vecResult.push_back(pSection);
	}

	return vecResult;
}

vector<ccHObject*> GetRefLineSets(dpxMap* pMap)
{
	vector<ccHObject*> refInfos;
	if(pMap==nullptr)
		return refInfos;
	dpxLayer* pRoadLayer = pMap->getRoadLyr();
	ccHObject* pRoadRoot = pRoadLayer->getRootData();
	if(pRoadRoot==nullptr)
		return refInfos;

	int nRefSize = pRoadRoot->getChildrenNumber(); //RefLine(Section)
	for(int i=0;i<nRefSize;i++)
	{
		ccHObject* pSection = pRoadRoot->getChild(i);
		if(pSection==nullptr)
			continue;

		if(!pSection->hasMetaData(DPX_OBJECT_TYPE_NAME))
			continue;

		dpxObjectType tempType = dpxObjectType(pSection->getMetaData(DPX_OBJECT_TYPE_NAME).toInt());
		if(tempType!=eObj_Section)
			continue;

		if(!pSection->hasMetaData(DPX_UID))
			continue;

		ccHObject* pRefLineSet = MapCommon::getRefLineSet(pSection);
		if(pRefLineSet==nullptr)
			continue;

		refInfos.push_back(pRefLineSet);
	}

	return refInfos;
}


ccHObject* CreateRoadLine(vector<ccPolyline*> vecLines,bool isRefLine)
{
	if(vecLines.size()<1)
		return nullptr;

	ccColor::Rgb refLineColor REF_LINE_COLOR; //宏定义颜色
	ccColor::Rgb RoadLineColor ROAD_LINE_COLOR; //宏定义颜色

	ccHObject* pHObjec = new ccHObject(isRefLine ? "RefLineSet":"RoadLineSet");
	pHObjec->setMetaData(DPX_OBJECT_TYPE_NAME,isRefLine ? eObj_RoadRefLineSet : eObj_RoadLineSet); //记录要素类型为refLine
	for(int i = 0;i < vecLines.size();i++)
	{
		ccPolyline* pTempLine = vecLines[i];
		if(pTempLine->size()<2)
			continue;
		pTempLine->setVisible(true);
		pTempLine->setTempColor(isRefLine ? refLineColor:RoadLineColor);
		pTempLine->setMetaData(DPX_OBJECT_TYPE_NAME,isRefLine ? eObj_RoadRefLine : eObj_RoadLine); //记录要素类型为refLine
		pTempLine->setName(isRefLine ? "RefLine":"RoadLine");

		pHObjec->addChild(pTempLine);//RefLine
	}

	//补充虚线  eObj_DashedSymbol
	for(int j = 0; j<vecLines.size()-1;j++)
	{
		ccPolyline* pFirstLine = vecLines[j];
		ccPolyline* pSecondLine = vecLines[j+1];
		CCVector3* pPt1 = const_cast<CCVector3*>(pFirstLine->getPointPersistentPtr(pFirstLine->size()-1)); //前一个线段的尾点
		CCVector3* pPt2 = const_cast<CCVector3*>(pSecondLine->getPointPersistentPtr(0)); //后一个线段的头点

		ccPointCloud* poly3DVertices = new ccPointCloud("Vertices");
		poly3DVertices->setEnabled(false);

		ccPolyline* SymbolLine = new ccPolyline(poly3DVertices);
		SymbolLine->setVisible(true);

		//Add first Pt
		poly3DVertices->reserve(1);
		SymbolLine->reserve(2);
		poly3DVertices->addPoint(*pPt1);
		SymbolLine->addPointIndex(0);

		//Add second Pt
		poly3DVertices->reserve(2);
		SymbolLine->reserve(3);
		poly3DVertices->addPoint(*pPt2);
		SymbolLine->addPointIndex(1);
		SymbolLine->setTempColor(ccColor::yellow);
		//创建虚线
		SymbolLine->setDisplay(vecLines[0]->getDisplay());
		SymbolLine->setMetaData(DPX_OBJECT_TYPE_NAME,eObj_DashedSymbol);
		pHObjec->addChild(SymbolLine);//RefLine
	}

	return pHObjec;
}

ccHObject* CreateSection(vector<ccPolyline*> vecLine)
{
	ccHObject* pRefLines = CreateRoadLine(vecLine,true);
	if(pRefLines==nullptr)
		return nullptr;

	ccHObject* pSection = new ccHObject("Section");
	pSection->setMetaData(DPX_OBJECT_TYPE_NAME,eObj_Section);
	pSection->addChild(pRefLines);

	return pSection;
}

ccHObject* getRefLineSet(ccHObject* pSection)
{
	if(pSection==nullptr)
		return nullptr;
	if(!pSection->hasMetaData(DPX_OBJECT_TYPE_NAME))
		return nullptr;
	dpxObjectType eType = dpxObjectType(pSection->getMetaData(DPX_OBJECT_TYPE_NAME).toInt());
	if(eType!=eObj_Section)
		return nullptr;

	int nSize = pSection->getChildrenNumber();
	for(int i = 0; i < nSize; i++)
	{
		ccHObject* pHObject = pSection->getChild(i);
		if(!pHObject->hasMetaData(DPX_OBJECT_TYPE_NAME))
			continue;
		dpxObjectType eType = dpxObjectType(pHObject->getMetaData(DPX_OBJECT_TYPE_NAME).toInt());
		if(eType!=eObj_RoadRefLineSet)
			continue;

		return pHObject;
	}
}

//Section 获取Ref HObject
vector<ccHObject*> getRefLines(ccHObject* pSection)
{
	vector<ccHObject*> vecResults;
	ccHObject* pRefLineSet = getRefLineSet(pSection);
	if(pRefLineSet==nullptr)
		return vecResults;

	int nRefLineSize = pRefLineSet->getChildrenNumber();
	for(int j=0;j<nRefLineSize;j++)
	{
		ccHObject* pHObject = pRefLineSet->getChild(j);
		if(!pHObject->hasMetaData(DPX_OBJECT_TYPE_NAME))
			continue;
		dpxObjectType eType = dpxObjectType(pHObject->getMetaData(DPX_OBJECT_TYPE_NAME).toInt());
		if(eType!=eObj_RoadRefLine)
			continue;
		vecResults.push_back(pHObject);
	}

	return vecResults;
}

vector<ccPolyline*> getRefLinesV2(ccHObject* pSection)
{
	vector<ccPolyline*> vecResults;
	ccHObject* pRefLineSet = getRefLineSet(pSection);
	if(pRefLineSet==nullptr)
		return vecResults;

	int nRefLineSize = pRefLineSet->getChildrenNumber();
	for(int j=0;j<nRefLineSize;j++)
	{
		ccHObject* pHObject = pRefLineSet->getChild(j);
		if(!pHObject->hasMetaData(DPX_OBJECT_TYPE_NAME))
			continue;
		dpxObjectType eType = dpxObjectType(pHObject->getMetaData(DPX_OBJECT_TYPE_NAME).toInt());
		if(eType!=eObj_RoadRefLine)
			continue;
		ccPolyline* pPolyLine = ccHObjectCaster::ToPolyline(pHObject);
		if(pPolyLine==nullptr)
			continue;
		vecResults.push_back(pPolyLine);
	}

	return vecResults;
}

//Section 获取Ref HObject
vector<ccHObject*> getRoadLineSets(ccHObject* pSection)
{
	vector<ccHObject*> vecResults;
	if(pSection==nullptr)
		return vecResults;
	if(!pSection->hasMetaData(DPX_OBJECT_TYPE_NAME))
		return vecResults;
	dpxObjectType eType = dpxObjectType(pSection->getMetaData(DPX_OBJECT_TYPE_NAME).toInt());
	if(eType!=eObj_Section)
		return vecResults;

	int nSize = pSection->getChildrenNumber();
	for(int i = 0; i < nSize; i++)
	{
		ccHObject* pRoadLineSet = pSection->getChild(i);
		if(!pRoadLineSet->hasMetaData(DPX_OBJECT_TYPE_NAME))
			continue;
		dpxObjectType eType = dpxObjectType(pRoadLineSet->getMetaData(DPX_OBJECT_TYPE_NAME).toInt());
		if(eType != eObj_RoadLineSet)
			continue;

		vecResults.push_back(pRoadLineSet);
	}

	return vecResults;
}

vector<ccPolyline*>  getLinesFromLineSet(ccHObject* pLineSet)
{
	vector<ccPolyline*>  vecResults;
	if(pLineSet==nullptr)
		return vecResults;
	int nSize = pLineSet->getChildrenNumber();
	for(int j=0;j<nSize;j++)
	{
		ccHObject* pLineObj = pLineSet->getChild(j);
		if(!pLineObj->hasMetaData(DPX_OBJECT_TYPE_NAME))
			continue;
		dpxObjectType eType = dpxObjectType(pLineObj->getMetaData(DPX_OBJECT_TYPE_NAME).toInt());
		if(eType!=eObj_RoadLine && eType!=eObj_RoadRefLine)
			continue;

		ccPolyline* pPolyLine = ccHObjectCaster::ToPolyline(pLineObj);
		if(pPolyLine==nullptr)
			continue;

		vecResults.push_back(pPolyLine);
	}
}


vector<ccPolyline*>  getRoadLines(ccHObject* pRoadLineSet)
{
	vector<ccPolyline*>  vecResults;
	if(pRoadLineSet==nullptr)
		return vecResults;
	int nRoadLineSize = pRoadLineSet->getChildrenNumber();
	for(int j=0;j<nRoadLineSize;j++)
	{
		ccHObject* pRoadLineObj = pRoadLineSet->getChild(j);
		if(!pRoadLineObj->hasMetaData(DPX_OBJECT_TYPE_NAME))
			continue;
		dpxObjectType eType = dpxObjectType(pRoadLineObj->getMetaData(DPX_OBJECT_TYPE_NAME).toInt());
		if(eType!=eObj_RoadLine)
			continue;

		ccPolyline* pPolyLine = ccHObjectCaster::ToPolyline(pRoadLineObj);
		if(pPolyLine==nullptr)
			continue;

		vecResults.push_back(pPolyLine);
	}
}

ccHObject*  getRelatedLineSet(ccPolyline* pLine)
{
	ccHObject* pCCHObj =  pLine->getParent();
	if(pCCHObj==nullptr)
		return nullptr;
	if(!pCCHObj->hasMetaData(DPX_OBJECT_TYPE_NAME))
		return nullptr;
	dpxObjectType eType = dpxObjectType(pCCHObj->getMetaData(DPX_OBJECT_TYPE_NAME).toInt());
	if(eType == eObj_RoadRefLineSet || eType == eObj_RoadLineSet)
		return pCCHObj;
}

ccHObject* getRelatedSection(ccPolyline* pLine)
{
	//LineSet
	ccHObject* pCCHObj =  pLine->getParent();
	if(pCCHObj==nullptr)
		return nullptr;
	if(!pCCHObj->hasMetaData(DPX_OBJECT_TYPE_NAME))
		return nullptr;
	dpxObjectType eType = dpxObjectType(pCCHObj->getMetaData(DPX_OBJECT_TYPE_NAME).toInt());
	if(eType != eObj_RoadRefLineSet && eType != eObj_RoadLineSet)
		return nullptr;

	//Section
	ccHObject* pSection =  pCCHObj->getParent();
	if(pSection==nullptr)
		return nullptr;
	if(!pSection->hasMetaData(DPX_OBJECT_TYPE_NAME))
		return nullptr;
	dpxObjectType eType2 = dpxObjectType(pSection->getMetaData(DPX_OBJECT_TYPE_NAME).toInt());
	if(eType2 != eObj_Section)
		return nullptr;
	return pSection;
}

ccPolyline* CopyNewLine(ccPolyline* poly3D)
{
	if(poly3D==nullptr || poly3D->size()<2)
		return nullptr;

	ccPointCloud* poly3DVertices = new ccPointCloud("Vertices");
	poly3DVertices->setEnabled(false);

	ccPolyline* pTargetLine = new ccPolyline(poly3DVertices);
	pTargetLine->setVisible(true);
	pTargetLine->setDisplay(poly3D->getDisplay());
	for(int i =0;i<poly3D->size();i++)
	{
		const CCVector3* pPt =  poly3D->getPoint(i);
		//try to add one more point
		if (!poly3DVertices->reserve(poly3DVertices->size() + 1)
			||!pTargetLine->reserve(poly3DVertices->size() + 1))
		{
			ccLog::Error("Not enough memory");
			return nullptr;
		}

		poly3DVertices->addPoint(*pPt);
		pTargetLine->addPointIndex(poly3DVertices->size() - 1);
	}
	pTargetLine->addChild(poly3DVertices);
	return pTargetLine;
}

//获取线上所有点
vector<CCVector3> GetAllPoints(ccPolyline* pLine)
{
	vector<CCVector3>  vecPts;
	if(pLine==nullptr)
		return vecPts;
	for(int i = 0;i<pLine->size();i++)
	{
		vecPts.push_back(*(pLine->getPoint(i)));
	}
	return vecPts;
}
//通过点创建折线
ccPolyline* CreatLineFromPts(vector<CCVector3> vecPts)
{
	ccPointCloud* poly3DVertices = new ccPointCloud("Vertices");
	poly3DVertices->setEnabled(false);

	ccPolyline* pTargetLine = new ccPolyline(poly3DVertices);
	pTargetLine->setVisible(true);
	for(int i = 0;i < vecPts.size();i++)
	{
		//try to add one more point
		if (!poly3DVertices->reserve(poly3DVertices->size() + 1)
			||!pTargetLine->reserve(poly3DVertices->size() + 1))
		{
			ccLog::Error("Not enough memory");
			return nullptr;
		}

		poly3DVertices->addPoint(vecPts[i]);
		pTargetLine->addPointIndex(poly3DVertices->size() - 1);
	}
	pTargetLine->addChild(poly3DVertices);
	return pTargetLine;
}

bool splitLine(ccPolyline* pTargetLine,int nDeleteSegmetIndex,vector<ccPolyline*>& vecResult)
{
	if(pTargetLine==nullptr)
		return false;
	int nPtSize = pTargetLine->size();
    if(nPtSize<3) //将该线段删除
		return false;
	vector<CCVector3>  vecPts =  MapCommon::GetAllPoints(pTargetLine);
    if(nDeleteSegmetIndex==0)//删除首段——删除首个点
    {
		vector<CCVector3> vecPt1 = vecPts;
		vecPt1.erase(vecPt1.begin()+0);
		ccPolyline* pLine = MapCommon::CreatLineFromPts(vecPt1);
		if(pLine != nullptr)
			vecResult.push_back(pLine);
    }
	else if(nDeleteSegmetIndex==nPtSize-2)//删除尾端 删除尾点
	{
		vector<CCVector3> vecPt2 = vecPts;
		vecPt2.erase(vecPt2.begin()+vecPt2.size()-1);
		ccPolyline* pLine = MapCommon::CreatLineFromPts(vecPt2);
		if(pLine != nullptr)
			vecResult.push_back(pLine);
	}
	else
	{
		//折线一分为二
        //Line 1[0,nDeleteSegmetIndex]    Line2[nDeleteSegmetIndex+1,nPtSize-1]
        vector<CCVector3> vecPt1,vecPt2;
        for(int i = 0;i<=nDeleteSegmetIndex;i++)
        {
			vecPt1.push_back(vecPts[i]);
        }
        for(int j = nDeleteSegmetIndex+1;j<nPtSize;j++)
        {
			vecPt2.push_back(vecPts[j]);
        }

        ccPolyline* pLine1 = MapCommon::CreatLineFromPts(vecPt1);
		ccPolyline* pLine2 = MapCommon::CreatLineFromPts(vecPt2);
		if(pLine1 != nullptr)
			vecResult.push_back(pLine1);
		if(pLine2 != nullptr)
			vecResult.push_back(pLine2);
	}

	for(int i = 0;i<vecResult.size();i++)
		vecResult[i]->setDisplay(pTargetLine->getDisplay());

	return true;
}

//更新LineSet中的符号线
bool UpdateSymbolLine(ccHObject* pLineSet)
{
	vector<ccPolyline*>  vecLines,vecSymbolLines;
	if(pLineSet==nullptr)
		return false;
	int nSize = pLineSet->getChildrenNumber();
	for(int j=0;j<nSize;j++)
	{
		ccHObject* pLineObj = pLineSet->getChild(j);
		if(!pLineObj->hasMetaData(DPX_OBJECT_TYPE_NAME))
			continue;

		ccPolyline* pPolyLine = ccHObjectCaster::ToPolyline(pLineObj);
		if(pPolyLine==nullptr)
			continue;

		dpxObjectType eType = dpxObjectType(pLineObj->getMetaData(DPX_OBJECT_TYPE_NAME).toInt());
		if(eType == eObj_RoadLine || eType == eObj_RoadRefLine)
			vecLines.push_back(pPolyLine);
		else
			vecSymbolLines.push_back(pPolyLine);
	}
	// remove old SymbolLines
    for(int i = 0;i < vecSymbolLines.size();i++)
    {
		pLineSet->removeChild(vecSymbolLines[i]);
    }

	//add new eObj_DashedSymbol
	for(int j = 0; j<vecLines.size()-1;j++)
	{
		ccPolyline* pFirstLine = vecLines[j];
		ccPolyline* pSecondLine = vecLines[j+1];
		CCVector3* pPt1 = const_cast<CCVector3*>(pFirstLine->getPointPersistentPtr(pFirstLine->size()-1)); //前一个线段的尾点
		CCVector3* pPt2 = const_cast<CCVector3*>(pSecondLine->getPointPersistentPtr(0)); //后一个线段的头点

		//创建符号虚线
		ccPointCloud* poly3DVertices = new ccPointCloud("Vertices");
		poly3DVertices->setEnabled(false);

		ccPolyline* SymbolLine = new ccPolyline(poly3DVertices);
		SymbolLine->setVisible(true);

		//Add first Pt
		poly3DVertices->reserve(1);
		SymbolLine->reserve(2);
		poly3DVertices->addPoint(*pPt1);
		SymbolLine->addPointIndex(0);

		//Add second Pt
		poly3DVertices->reserve(2);
		SymbolLine->reserve(3);
		poly3DVertices->addPoint(*pPt2);
		SymbolLine->addPointIndex(1);
		SymbolLine->setTempColor(ccColor::yellow);

		SymbolLine->setMetaData(DPX_OBJECT_TYPE_NAME,eObj_DashedSymbol);
		SymbolLine->setDisplay(vecLines[0]->getDisplay());
		pLineSet->addChild(SymbolLine);//RefLine
	}
}


}// nameSpace MapCommon

