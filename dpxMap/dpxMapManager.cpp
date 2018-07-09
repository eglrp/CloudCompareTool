
#include "dpxMapManager.h"
#include "dpxMapDefine.h"

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

//定制的HDMap内容
dpxMap* dpxMapManager::createHDMap()
{
	vector<QString> vecLryNames;
	vecLryNames.push_back(ROAD_LAYER_NAME); 		//道路
	vecLryNames.push_back(LIGHT_LAYER_NAME); 		//路灯
	vecLryNames.push_back(INDICATOR_LAYER_NAME);	//指示牌
	vecLryNames.push_back(OTHER_NAME);				//其它

	dpxMap* pMap = new dpxMap(HDMAP_NAME);
	pMap->SetType(eOT_Map);
	//道路层
	dpxLayer* pRoadLry = new dpxLayer(ROAD_LAYER_NAME);
	pRoadLry->SetType(eOT_Road);

	//路灯杆层
	dpxLayer* pLightLry = new dpxLayer(LIGHT_LAYER_NAME);
	pLightLry->SetType(eOT_Light);

	//指示牌
	dpxLayer* pIndicatorLry = new dpxLayer(INDICATOR_LAYER_NAME);
	pIndicatorLry->SetType(eOT_Indicator);

	//其它
	dpxLayer* pOtherLry = new dpxLayer(OTHER_NAME);
	pOtherLry->SetType(eOT_Other);

	//地图添加图层
	pMap->AddLayer(pRoadLry);
	pMap->AddLayer(pLightLry);
	pMap->AddLayer(pIndicatorLry);
	pMap->AddLayer(pOtherLry);

	//创建地图文档
	createMapDoc(HDMAP_NAME,vecLryNames);

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
