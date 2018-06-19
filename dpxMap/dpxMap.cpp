
#include "dpxMap.h"

dpxMap::dpxMap(QString strMapName,QString strMapID)
	: m_strMapName(strMapName),
	  m_strMapID(strMapID)
{
	m_vecLrys.clear();
}

dpxMap::dpxMap(QString strMapName)
	: m_strMapName(strMapName)
{
	m_strMapID = QUuid::createUuid().toString();
	m_vecLrys.clear();
}

dpxMap::~dpxMap()
{
}

void dpxMap::setMapId(const QString& strId)
{
	m_strMapID = strId;
}

const QString& dpxMap::getMapId() const
{
	return m_strMapID;
}

void dpxMap::setMapName(const QString& strMapName)
{
	m_strMapName = strMapName;
}

const QString& dpxMap::getMapName() const
{
    return m_strMapName;
}

LayerVec dpxMap::GetAllLayers()
{
	return m_vecLrys;
}

int  dpxMap::GetLayerCount()
{
	return m_vecLrys.size();
}
void dpxMap::AddLayer(dpxLayer* pLayer)
{
	m_vecLrys.push_back(pLayer);
}

void dpxMap::RemoveLayer(dpxLayer* pLayer)
{
	LayerVec::iterator itor = find(m_vecLrys.begin(),m_vecLrys.end(),pLayer); //查找3
    if (itor == m_vecLrys.end()) //没找到
		return;
	m_vecLrys.erase(itor);
}

void dpxMap::RemoveAllLayers()
{
	LayerVec vecLrys;
	m_vecLrys.swap(vecLrys);
}
