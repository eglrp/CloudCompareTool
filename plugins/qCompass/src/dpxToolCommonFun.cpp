//by duans

#include "dpxToolCommonFun.h"
#include "RayAndBox.h"
#include <ccHObjectCaster.h>
#include "dpxGeoEngine.h"

std::vector<ccPolyline*> dpxToolCommonFun::getRoadLFromRefL(ccPolyline* pRefLine)
{
	std::vector<ccPolyline*> vecResult;
	if(pRefLine==nullptr)
		return vecResult;

	ccHObject::Container vecHObjs;
	pRefLine->filterChildren(vecHObjs,false,CC_TYPES::POLY_LINE);
	for(int i = 0;i<vecHObjs.size();i++)
	{
		ccPolyline* pPolyLine = ccHObjectCaster::ToPolyline(vecHObjs[i]);
		if(pPolyLine==nullptr)
			continue;
		if(!ConfimObjType(pPolyLine,eObj_RoadLine))
			continue;
		vecResult.push_back(pPolyLine);
	}

	return vecResult;
}

bool dpxToolCommonFun::ConfimObjType(ccPolyline* pLine,dpxObjectType eType)
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

int dpxToolCommonFun::getMaxSectionID()
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

int dpxToolCommonFun:: getMaxJunctionID()
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

vector<ccHObject*> dpxToolCommonFun::GetAllSection(dpxMap* pMap)
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

vector<ccHObject*> dpxToolCommonFun::GetRefLineSets(dpxMap* pMap)
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

		ccHObject* pRefLineSet = dpxToolCommonFun::getRefLineSet(pSection);
		if(pRefLineSet==nullptr)
			continue;

		refInfos.push_back(pRefLineSet);
	}

	return refInfos;
}


ccHObject* dpxToolCommonFun::CreateRoadLine(vector<ccPolyline*> vecLines,bool isRefLine)
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
		CCVector3* pPt1 = const_cast<CCVector3*>(pFirstLine->getPointPersistentPtr(pFirstLine->size()-1));
		CCVector3* pPt2 = const_cast<CCVector3*>(pSecondLine->getPointPersistentPtr(pSecondLine->size()-1));

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
		pHObjec->addChild(SymbolLine);//RefLine
	}

	return pHObjec;
}

ccHObject* dpxToolCommonFun::CreateSection(vector<ccPolyline*> vecLine)
{
	ccHObject* pRefLines = CreateRoadLine(vecLine,true);
	if(pRefLines==nullptr)
		return nullptr;

	ccHObject* pSection = new ccHObject("Section");
	pSection->setMetaData(DPX_OBJECT_TYPE_NAME,eObj_Section);
	pSection->addChild(pRefLines);

	return pSection;
}

ccHObject* dpxToolCommonFun::getRefLineSet(ccHObject* pSection)
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
vector<ccHObject*> dpxToolCommonFun::getRefLines(ccHObject* pSection)
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

vector<ccPolyline*> dpxToolCommonFun::getRefLinesV2(ccHObject* pSection)
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
vector<ccHObject*> dpxToolCommonFun::getRoadLineSets(ccHObject* pSection)
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

vector<ccPolyline*>  dpxToolCommonFun::getRoadLines(ccHObject* pRoadLineSet)
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

ccPolyline* CopyNewLine(ccPolyline* pLine)
{

}

//判断选择集中的refLine是否属于同一个RefLineSet
//通过refLine找到其对应的Section









