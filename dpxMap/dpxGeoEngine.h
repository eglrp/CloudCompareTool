
//by duans 2018.6.19
#ifndef _DPX_GEO_ENGINE_H__
#define _DPX_GEO_ENGINE_H__
#pragma once

#include "dpxMap_IO.h"
#include "dpxMap.h"
#include <QObject>
/*
* dpxMap
*/
class  DPX_MAP_API dpxGeoEngine : public QObject
{
	Q_OBJECT
public:
	static dpxGeoEngine* Instance();

public:
	void SetMap(dpxMap* pMap) {m_pMap = pMap;}
	dpxMap* GetMap() { return m_pMap;}

	//是否可删除
	void setCanDelete(bool bCanDelete);
	bool getCanDelete();

	//HDmap特定图层的获取
	dpxLayer* getRoadLyr();
	dpxLayer* getLightLyr();
	dpxLayer* getIndicatorLry();
	dpxLayer* getOtherLry();
	dpxLayer* getZebraLineLry();//斑马线层

public slots:
	void slotObjDelete(); //删除对象

    void slotMapChanged();
    void slotMapNameChanged();

    void slotLayerNameChanged(const QString& strLryID);
	void slotLayerVisibleChanged(const QString& strLryID);
	void slotLayerEditableChanged(const QString& strLryID);

	void slotFeatureGeomteryChanged(const QString& strLayerID, int nFeatureID);
	void slotFeatureAttributeChanged(const QString& strLayerID, int nFeatureID);

signals:
	void sigObjDelete();//删除对象

	void sigKeyPress(const QString& sKey);
	void sigMapChanged();
    void sigMapNameChanged();

    void sigLayerNameChanged(const QString& strLryID);
	void sigLayerVisibleChanged(const QString& strLryID);
	void sigLayerEditableChanged(const QString& strLryID);

	void sigFeatureGeomteryChanged(const QString& strLayerID, int nFeatureID);
	void sigFeatureAttributeChanged(const QString& strLayerID, int nFeatureID);

protected:
	dpxLayer* getLyrFormType(dpxLayerType eType);
//私有构造
private:
	dpxGeoEngine();
	dpxGeoEngine(const dpxGeoEngine&){}
	dpxGeoEngine& operator=(const dpxGeoEngine&){}
private:
	dpxMap* m_pMap;

	//工具激活状态下，不能轻易删除要素，不然会引起崩溃，初始化可删除
	bool m_bCanDelete;
};

#endif
