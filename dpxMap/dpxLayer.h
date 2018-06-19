
//by duans 2018.6.14
#ifndef _DPX_LAYER_H_
#define _DPX_LAYER_H_
#pragma once

#include "dpxMap_IO.h"
#include "ccHObject.h"
#include <QUuid>
/*
* dpxLayer
*/

enum DPX_MAP_API dpxLayerType
{
	eLT_Unknown,	//未知
	eLT_Point,		//点
	eLT_Line,		//线
	eLT_Polygon,	//面
	eLT_Label,		//文字
	eLT_solid		//立体
};

typedef std::vector<ccHObject*> HObjectVec;
class  DPX_MAP_API dpxLayer
{
public:
	dpxLayer(QString sName,QString sLyrID);
	dpxLayer(QString sName);
	virtual ~dpxLayer();

 public:
	//图层名称
	virtual QString getLayerName();
	virtual void setLayerName(QString sName);

	//UUID设置
	virtual void setLayerID(QString sId);
	virtual QString getLayerID();

	//增删改查
	//只能访问根节点数据，不能编辑
	virtual  ccHObject* getRootData();
	//增要素
	virtual bool AddFeature(ccHObject* pFeature);
	virtual bool AddFeatures(HObjectVec vFeatures);
	//删要素
	virtual bool DeleteAllFeatures();
	virtual void deleteFeature(ccHObject* pFeature);
	virtual void deleteFeatures(HObjectVec vFeatures);

	//查要素
	virtual unsigned getChildrenNumber() const;
	virtual ccHObject* getChild(unsigned childPos) const;
	virtual ccHObject* find(unsigned uniqueID);

protected://工厂创建
	dpxLayer(){}
protected:
	//dpxLayerType m_eLyrType;//图层类型
	QString m_strName;//图层名称
	QString m_strLryID; //UUID
	ccHObject* m_lyrRootData;//图层数据的跟结点
};
typedef std::vector<dpxLayer*> LayerVec;

#endif
