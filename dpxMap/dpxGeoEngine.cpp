
#include "dpxGeoEngine.h"

dpxGeoEngine* dpxGeoEngine::Instance()
{
	static dpxGeoEngine instance;
	return &instance;
}

dpxGeoEngine::dpxGeoEngine()
{
	m_pMap = nullptr;
	m_bCanDelete = true;
}

void dpxGeoEngine::slotObjDelete()
{
	emit sigObjDelete();
}

void dpxGeoEngine::slotMapChanged()
{
	emit sigMapChanged();
}

void dpxGeoEngine::slotMapNameChanged()
{
	emit sigMapNameChanged();
}

void dpxGeoEngine::slotLayerNameChanged(const QString& strLryID)
{
	emit sigLayerNameChanged(strLryID);
}

void dpxGeoEngine::slotLayerVisibleChanged(const QString& strLryID)
{
	emit sigLayerVisibleChanged(strLryID);
}

void dpxGeoEngine::slotLayerEditableChanged(const QString& strLryID)
{
	emit sigLayerEditableChanged(strLryID);
}

void dpxGeoEngine::slotFeatureGeomteryChanged(const QString& strLayerID, int nFeatureID)
{
	emit sigFeatureGeomteryChanged(strLayerID,nFeatureID);
}

void dpxGeoEngine::slotFeatureAttributeChanged(const QString& strLayerID, int nFeatureID)
{
	emit sigFeatureAttributeChanged(strLayerID,nFeatureID);
}

void dpxGeoEngine::setCanDelete(bool bCanDelete)
{
	m_bCanDelete = bCanDelete;
}

bool dpxGeoEngine::getCanDelete()
{
	return m_bCanDelete;
}
