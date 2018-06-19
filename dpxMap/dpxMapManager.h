
//by duans 2018.6.19
#ifndef _DPX_MAP_MANAGER_H_
#define _DPX_MAP_MANAGER_H_
#pragma once

#include "dpxMap_IO.h"
#include "dpxMap.h"

/*
* dpxMap
*/
class  DPX_MAP_API dpxMapManager
{
public:
	dpxMapManager();
	virtual ~dpxMapManager();
public:
	//创建地图
	static dpxMap* createMap(QString strMapName,std::vector<QString> vecLryNames);
	static bool createMapDoc(QString strMapName,std::vector<QString> vecLryNames);
	//地图自动保存文档
	static bool saveMapDoc(dpxMap* pMap,QString strFile);
	//加载地图
	static dpxMap* LoadMapDoc(QString strMapFile);
};

#endif
