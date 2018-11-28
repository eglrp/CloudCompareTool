
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
	dpxLayer* getTrafficLightLyr();
	dpxLayer* getTrafficSignLyr();
	dpxLayer* getOtherLry();
	dpxLayer* getCrossWalkLyr();//斑马线
	dpxLayer* getStopLineLyr();//停止线
	dpxLayer* getParkingSpaceLyr();//停车位
	dpxLayer* getSpeedbumpsLyr();//减速带
	dpxLayer* getBoardLyr(); //其它面状
	dpxLayer* getJunctionLyr(); //其它面状
	dpxLayer* getLaneMarkingLyr(); //路面标识

	dpxLayer* getLyrFormType(dpxLayerType eType);
protected:
	dpxMap(){}


protected:
	LayerVec m_vecLrys;
	QString m_strMapName;//图层名称
	QString m_strMapID;
	ccHObject* m_MapRootData;//图层数据的跟结点
};

#endif
