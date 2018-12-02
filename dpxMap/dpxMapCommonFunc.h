
//by duans 2018.10.12
#ifndef _DPX_MAP_COMMON_FUNC_H_
#define _DPX_MAP_COMMON_FUNC_H_
#pragma once

#include "dpxMapDefine.h"
#include "ccHObject.h"
#include "ccPolyline.h"
#include "dpxMapManager.h"
#include "RayAndBox.h"
#include "ccPointCloud.h"
#include <ccHObjectCaster.h>
#include "dpxGeoEngine.h"

namespace  dpxMapCommonFunc
{
	//创建连接Junction
	bool DPX_MAP_API CreateJunction(dpxMap* pMap,vector<refLineInfo> &refInfos,double dMinDis,double dMaxDis);

	//两点的距离
	double  DPX_MAP_API DisTance(CCVector3 pt1,CCVector3 pt2);

	//前JuncitonID
	int  DPX_MAP_API GetRefLinePreID(ccHObject* pSectionObj);
	//后JuncitonID
	int  DPX_MAP_API GetRefLineSucID(ccHObject* pSectionObj);

	vector<int> DPX_MAP_API GetRelatedRefID(ccPolyline* pJunctionLine);

	QString DPX_MAP_API getRefIDValue(const vector<int>& vecRefIDs);

	bool DPX_MAP_API ConfimObjType(ccHObject* pHObject,dpxObjectType eType);
	bool DPX_MAP_API ConfimObjType(ccPolyline* pLine,dpxObjectType eType);

	int DPX_MAP_API getMaxSectionID();
	int DPX_MAP_API getMaxJunctionID();

	//获取所有Section
	vector<ccHObject*> DPX_MAP_API GetAllSection(dpxMap* pMap);
	//获取refLineSet
	vector<ccHObject*> DPX_MAP_API GetRefLineSets(dpxMap* pMap);

	vector<ccHObject*> DPX_MAP_API getRoadLineSets(ccHObject* pSection); //RoadLineSet  severl

	ccHObject* DPX_MAP_API getRefLineSet(ccHObject* pSection); //One
	vector<ccHObject*> DPX_MAP_API getRefLines(ccHObject* pSection);//
	vector<ccPolyline*> DPX_MAP_API getRefLinesV2(ccHObject* pSection);//

	vector<ccPolyline*> DPX_MAP_API  getLinesFromLineSet(ccHObject* pLineSet);
	vector<ccPolyline*>  DPX_MAP_API getRoadLines(ccHObject* pRoadLineSet);

	//创建RoadLine结构
	ccHObject*  DPX_MAP_API CreateRoadLine(vector<ccPolyline*> vecLines,bool isRefLine);
	ccHObject* DPX_MAP_API CreateSection(vector<ccPolyline*> vecLine);

	//由一个道路线获取上层的节点 LineSet和Section
	ccHObject*  DPX_MAP_API getRelatedLineSet(ccPolyline* pLine);
	ccHObject*  DPX_MAP_API getRelatedSection(ccPolyline* pLine);
	//复制一跟线
	ccPolyline* DPX_MAP_API CopyNewLine(ccPolyline* poly3D);

	//获取线上所有点
	vector<CCVector3> DPX_MAP_API GetAllPoints(ccPolyline* pLine);
	//通过点创建折线
	ccPolyline* DPX_MAP_API CreatLineFromPts(vector<CCVector3> vecPts);

	bool DPX_MAP_API splitLine(ccPolyline* pTargetLine,int nDeleteSegmetIndex,vector<ccPolyline*>& vecResult);

	//更新LineSet中的符号线
	bool DPX_MAP_API UpdateSymbolLine(ccHObject* pLineSet);
};


#endif
