
//by duans 2018.10.12
#ifndef _DPX_MAP_COMMON_FUNC_H_
#define _DPX_MAP_COMMON_FUNC_H_
#pragma once

#include "dpxMapDefine.h"
#include "ccHObject.h"
#include "ccPolyline.h"
#include "dpxMapManager.h"

namespace  MapCommon
{
	//判断线的标记类型
	bool DPX_MAP_API ConfimObjType(ccPolyline* pLine,dpxObjectType eType);

	//创建连接Junction
	bool DPX_MAP_API CreateJunction(dpxMap* pMap,vector<refLineInfo> &refInfos,double dMinDis,double dMaxDis);

	//两点的距离
	double  DPX_MAP_API DisTance(CCVector3 pt1,CCVector3 pt2);

	//前JuncitonID
	int  GetRefLinePreID(ccPolyline* pDPXRefLine);
	//后JuncitonID
	int  GetRefLineSucID(ccPolyline* pDPXRefLine);

	vector<int>  GetRelatedRefID(ccPolyline* pJunctionLine);

	QString getRefIDValue(const vector<int>& vecRefIDs);
};


#endif
