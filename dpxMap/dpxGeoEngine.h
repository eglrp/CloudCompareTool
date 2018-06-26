
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

public slots:
    void slotMapChanged();
    void slotMapNameChanged();

    void slotLayerNameChanged(const QString& strLryID);
	void slotLayerVisibleChanged(const QString& strLryID);
	void slotLayerEditableChanged(const QString& strLryID);

	void slotFeatureGeomteryChanged(const QString& strLayerID, int nFeatureID);
	void slotFeatureAttributeChanged(const QString& strLayerID, int nFeatureID);

signals:
	void sigMapChanged();
    void sigMapNameChanged();

    void sigLayerNameChanged(const QString& strLryID);
	void sigLayerVisibleChanged(const QString& strLryID);
	void sigLayerEditableChanged(const QString& strLryID);

	void sigFeatureGeomteryChanged(const QString& strLayerID, int nFeatureID);
	void sigFeatureAttributeChanged(const QString& strLayerID, int nFeatureID);

protected:
//私有构造
private:
	dpxGeoEngine();
	dpxGeoEngine(const dpxGeoEngine&){}
	dpxGeoEngine& operator=(const dpxGeoEngine&){}
private:
	dpxMap* m_pMap;
};

#endif
