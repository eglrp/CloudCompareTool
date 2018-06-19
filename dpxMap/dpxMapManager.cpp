
#include "dpxMapManager.h"

dpxMapManager::dpxMapManager()
{
}

dpxMapManager::~dpxMapManager()
{
}

dpxMap* dpxMapManager::createMap(QString strMapName,vector<QString> vecLryNames)
{
	if(strMapName.isEmpty())
		return nullptr;
	dpxMap* pMap = new dpxMap(strMapName);
	for(int i = 0;i<vecLryNames.size();i++)
	{
		 dpxLayer* pLry = new dpxLayer(vecLryNames[i]);
		 pMap->AddLayer(pLry);
	}
	//创建地图文档
	createMapDoc(strMapName,vecLryNames);

	return pMap;
}

//地图文档，可以用于加载
bool dpxMapManager::createMapDoc(QString strMapName,vector<QString> vecLryNames)
{
	return false;
}
//地图文档，可以用于加载
bool dpxMapManager::saveMapDoc(dpxMap* pMap,QString strFile)
{
	return false;
}
//加载地图文档
dpxMap* dpxMapManager::LoadMapDoc(QString strMapFile)
{
	return nullptr;
}
