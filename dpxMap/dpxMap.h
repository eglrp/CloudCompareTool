
//by duans 2018.6.14
#ifndef _DPX_MAP_H_
#define _DPX_MAP_H_
#pragma once

#include "dpxMap_IO.h"
#include "dpxLayer.h"
using namespace std;
/*
* dpxMap
*/
class  DPX_MAP_API dpxMap
{
public:
	dpxMap(QString strMapName,QString strMapID);
	dpxMap(QString strMapName);
	virtual ~dpxMap();
public:
	void setMapId(const QString& strId);
	const QString& getMapId() const;
	void setMapName(const QString& strMapName);
	const QString& getMapName() const;

	LayerVec GetAllLayers();
	int  GetLayerCount();
	void AddLayer(dpxLayer* pLayer);
	void RemoveLayer(dpxLayer* pLayer);//
	void RemoveAllLayers();//

protected:
	dpxMap(){}
protected:
	LayerVec m_vecLrys;
	QString m_strMapName;//图层名称
	QString m_strMapID;
};

#endif