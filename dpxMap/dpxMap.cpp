
#include "dpxMap.h"

dpxMap::dpxMap(QString strMapName,QString strMapID)
	: m_strMapName(strMapName),
	  m_strMapID(strMapID)
{
	m_vecLrys.clear();
	m_MapRootData = new ccHObject(strMapName);

	SetType(eOT_Map);
}

dpxMap::dpxMap(QString strMapName)
	: m_strMapName(strMapName)
{
	m_strMapID = QUuid::createUuid().toString();
	m_vecLrys.clear();
	m_MapRootData = new ccHObject(strMapName);

	SetType(eOT_Map);
}

dpxMap::~dpxMap()
{
}

ccHObject* dpxMap::getRootData()
{
	return m_MapRootData;
}

void dpxMap::SetType(dpxObjectType eType)
{
	m_MapRootData->setMetaData(DPX_TYPE_NAME,eType);//自动转换成数字
}

dpxObjectType dpxMap::GetType()
{
	if(!m_MapRootData->hasMetaData(DPX_TYPE_NAME))
		return dpxObjectType::eOT_Unknown;

	return dpxObjectType(m_MapRootData->getMetaData(DPX_TYPE_NAME).toInt());//自动转换成数字
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
bool dpxMap::AddLayer(dpxLayer* pLayer)
{
	if(pLayer==nullptr)
        return false;

	ccHObject* pLyrData = pLayer->getRootData();
	if(pLyrData==nullptr)
		return false;

	if(!m_MapRootData->isAncestorOf(pLyrData))
	{
		if(!m_MapRootData->addChild(pLyrData))//几何添加成功的话，加上图层信息
			return false;
	}

	LayerVec::iterator itor = find(m_vecLrys.begin(),m_vecLrys.end(),pLayer); //查找3
	if (itor != m_vecLrys.end()) //没找到
		m_vecLrys.push_back(pLayer);

	return true;
}

bool dpxMap::RemoveLayer(dpxLayer* pLayer)
{
	if(pLayer==nullptr || pLayer->getRootData()==nullptr)
		return false;
	LayerVec::iterator itor = find(m_vecLrys.begin(),m_vecLrys.end(),pLayer); //查找3
    if (itor != m_vecLrys.end()) //没找到
		return false;

	m_MapRootData->removeChild(pLayer->getRootData());
	m_vecLrys.erase(itor);
	return true;
}

bool dpxMap::RemoveAllLayers()
{
	LayerVec vecLrys;
	m_vecLrys.swap(vecLrys);
 	m_MapRootData->removeAllChildren();
 	return true;
}
