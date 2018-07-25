
//by duans 2018.6.19
#ifndef _DPX_MAP_MANAGER_H_
#define _DPX_MAP_MANAGER_H_
#pragma once

#include "dpxMap_IO.h"
#include "dpxMap.h"
#include "ccPolyline.h"
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
	dpxMap* createMap(QString strMapName,std::vector<QString> vecLryNames);
	bool createMapDoc(QString strMapName,std::vector<QString> vecLryNames);

	//定制HDMap图层
	dpxMap* createHDMap(); //创建HDMap
	//地图自动保存文档
	bool saveMapDoc(dpxMap* pMap,QString strFile);
	//加载地图
	dpxMap* LoadMapDoc(QString strMapFile);

	bool outPutMap(ccHObject* pMapRootData);

protected:
	void Export_Recursion(ccHObject* pObj);

	void ExportPlane(ccPolyline* pLine,int eType);
	void ExportLine(ccPolyline* pLine,int eType);
	void ExportOfficeLightPole(ccPolyline* pLine,int eType);

private:
	QTextStream m_textStream;
};

#endif
