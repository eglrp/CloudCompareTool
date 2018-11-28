
#include "dpxMap.h"

dpxMap::dpxMap(QString strMapName,QString strMapID)
	: m_strMapName(strMapName),
	  m_strMapID(strMapID)
{
	m_vecLrys.clear();
	m_MapRootData = new ccHObject(strMapName);
	m_MapRootData->setMetaData(DPX_LAYER_TYPE_NAME,eOT_Map);//自动转换成数字
}

dpxMap::dpxMap(QString strMapName)
	: m_strMapName(strMapName)
{
	m_strMapID = QUuid::createUuid().toString();
	m_vecLrys.clear();
	m_MapRootData = new ccHObject(strMapName);
	m_MapRootData->setMetaData(DPX_LAYER_TYPE_NAME,eOT_Map);//自动转换成数字
}

dpxMap::~dpxMap()
{
}

ccHObject* dpxMap::getRootData()
{
	return m_MapRootData;
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
	if (itor == m_vecLrys.end()) //没找到
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

dpxLayer* dpxMap::getLyrFormType(dpxLayerType eType)
{
	for(int i =0;i<m_vecLrys.size();i++)
	{
		if(m_vecLrys[i]!=nullptr && m_vecLrys[i]->GetType()==eType)
			return m_vecLrys[i];
	}
	return nullptr;
}
//道路层
dpxLayer* dpxMap::getRoadLyr()
{
	return getLyrFormType(eOT_Road);
}
//路灯层
dpxLayer* dpxMap::getTrafficLightLyr()
{
	return getLyrFormType(eOT_TrafficLight);
}
//指示牌层
dpxLayer* dpxMap::getTrafficSignLyr()
{
	return getLyrFormType(eOT_TrafficSign);
}
//获取其它层
dpxLayer* dpxMap::getOtherLry()
{
	return getLyrFormType(eOT_Other);
}

dpxLayer* dpxMap::getCrossWalkLyr()
{
	return getLyrFormType(eOT_CrossWalk);
}

dpxLayer* dpxMap::getStopLineLyr()
{
	return getLyrFormType(eOT_StopLine);
}
dpxLayer* dpxMap::getParkingSpaceLyr()
{
	return getLyrFormType(eOT_ParkingSpace);
}
dpxLayer* dpxMap::getSpeedbumpsLyr()
{
	return getLyrFormType(eOT_SpeedBump);
}
dpxLayer* dpxMap::getBoardLyr()
{
	return getLyrFormType(eOT_Board);
}
dpxLayer* dpxMap::getJunctionLyr()
{
	return getLyrFormType(eOT_Junction);
}
dpxLayer* dpxMap::getLaneMarkingLyr()
{
	return getLyrFormType(eOT_LaneMarking);
}

