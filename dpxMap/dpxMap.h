
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

	virtual  ccHObject* getRootData();
	void setMapId(const QString& strId);
	const QString& getMapId() const;
	void setMapName(const QString& strMapName);
	const QString& getMapName() const;

	LayerVec GetAllLayers();
	int  GetLayerCount();
	bool AddLayer(dpxLayer* pLayer);
	bool RemoveLayer(dpxLayer* pLayer);//
	bool RemoveAllLayers();//


public:
	//--------HDmap特定图层的获取------
	dpxLayer* getRoadLyr();
	dpxLayer* getLightLyr();
	dpxLayer* getIndicatorLry();
	dpxLayer* getOtherLry();
	dpxLayer* getZebraLineLry();//斑马线层

protected:
	dpxMap(){}

	dpxLayer* getLyrFormType(dpxLayerType eType);
protected:
	LayerVec m_vecLrys;
	QString m_strMapName;//图层名称
	QString m_strMapID;
	ccHObject* m_MapRootData;//图层数据的跟结点
};

#endif
