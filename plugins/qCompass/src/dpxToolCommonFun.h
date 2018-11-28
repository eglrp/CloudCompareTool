//class name:dpxToolCommonFun
//brif:通用功能函数
//by duans

#ifndef _DPX_TOOL_COMMON_Fun_HEADER_
#define _DPX_TOOL_COMMON_Fun_HEADER_

#include "math.h"
#include <CCGeom.h>
#include <ccPolyline.h>
#include <ccPointCloud.h>
#include <dpxGeoEngine.h>
#include <dpxMapDefine.h>
#include <dpxMap.h>
using namespace std;
class dpxToolCommonFun
{
public:
	static std::vector<ccPolyline*> getRoadLFromRefL(ccPolyline* pRefLine);
	static bool ConfimObjType(ccPolyline* pLine,dpxObjectType eType);
	static int getMaxSectionID();
	static int getMaxJunctionID();

	//获取所有Section
	static vector<ccHObject*> GetAllSection(dpxMap* pMap);
	//获取refLineSet
	static vector<ccHObject*> GetRefLineSets(dpxMap* pMap);

	static vector<ccHObject*> getRoadLineSets(ccHObject* pSection); //RoadLineSet  severl

	static ccHObject* getRefLineSet(ccHObject* pSection); //One
	static vector<ccHObject*> getRefLines(ccHObject* pSection);//
	static vector<ccPolyline*> getRefLinesV2(ccHObject* pSection);//

	static vector<ccPolyline*>  getLinesFromLineSet(ccHObject* pLineSet);
	static vector<ccPolyline*>  getRoadLines(ccHObject* pRoadLineSet);

	//创建RoadLine结构
	static ccHObject* CreateRoadLine(vector<ccPolyline*> vecLines,bool isRefLine);
	static ccHObject* CreateSection(vector<ccPolyline*> vecLine);

	//由一个道路线获取上层的节点 LineSet和Section
	static ccHObject*  getRelatedLineSet(ccPolyline* pLine);
	static ccHObject*  getRelatedSection(ccPolyline* pLine);
	//复制一跟线
	static ccPolyline* CopyNewLine(ccPolyline* poly3D);

	//获取线上所有点
	static vector<CCVector3> GetAllPoints(ccPolyline* pLine);
	//通过点创建折线
	static ccPolyline* CreatLineFromPts(vector<CCVector3> vecPts);

	static bool splitLine(ccPolyline* pTargetLine,int nDeleteSegmetIndex,vector<ccPolyline*>& vecResult);
};

#endif
