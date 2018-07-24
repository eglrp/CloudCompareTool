
#include "dpxMapManager.h"
#include "dpxMapDefine.h"
#include <QFileDialog>
#include <QMessageBox>
#include <ccPolyline.h>
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
	vecLryNames.push_back(ZEBRA_LINE_LAYER_NAME);	//斑马线
	vecLryNames.push_back(OTHER_NAME);				//其它

	dpxMap* pMap = new dpxMap(HDMAP_NAME);
	//道路层
	dpxLayer* pRoadLry = new dpxLayer(ROAD_LAYER_NAME);
	pRoadLry->SetType(eOT_Road);

	//路灯杆层
	dpxLayer* pLightLry = new dpxLayer(LIGHT_LAYER_NAME);
	pLightLry->SetType(eOT_Light);

	//指示牌
	dpxLayer* pIndicatorLry = new dpxLayer(INDICATOR_LAYER_NAME);
	pIndicatorLry->SetType(eOT_Indicator);

	//指示牌
	dpxLayer* pZebraLineLry = new dpxLayer(ZEBRA_LINE_LAYER_NAME);
	pZebraLineLry->SetType(eOT_ZebraLine);

	//其它
	dpxLayer* pOtherLry = new dpxLayer(OTHER_NAME);
	pOtherLry->SetType(eOT_Other);

	//地图添加图层
	pMap->AddLayer(pRoadLry);
	pMap->AddLayer(pLightLry);
	pMap->AddLayer(pIndicatorLry);
	pMap->AddLayer(pZebraLineLry);
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
//地图文档，可以用于加载
bool dpxMapManager::outPutMap(ccHObject* pMapRootData)
{
	QString strFileName=QFileDialog::getSaveFileName(nullptr, "select the location to be saved"/*, exportDir, "*.xodr"*/);
    if(strFileName.isEmpty())
        return false;

	QFile file(strFileName);
    if (!file.open(QFile::WriteOnly | QFile::Text))
    {
		QMessageBox::warning(nullptr,"waring","Error: cannot creat file");
			return false;
    }

	m_textStream.setDevice(&file);
	// QString strHead = "      X1"+"      Y1"+"      Z1"+"      X2"+"      Y2"+"      Z2"+"      Radius";
	m_textStream<< "    X1"<< "      Y1"<<"      Z1"<<"      X2"<< "      Y2"<< "      Z2"<< "      Radius"<< "\n";

   //迭代输出
	Export_Recursion(pMapRootData);
	return false;
}

void dpxMapManager::Export_Recursion(ccHObject* pObj)
{
	if(pObj == nullptr || !pObj)
		return;

	ccPolyline* pLine = pObj && pObj->isA(CC_TYPES::POLY_LINE) ? static_cast<ccPolyline*>(pObj) : 0;
	if(pLine!=0 && pLine != nullptr)
	{
		if(pLine->hasMetaData("Radius"))
		{
			QString strRadius = pObj->getMetaData("Radius").toString();
			const CCVector3* pFirst = pLine->getPoint(0);
			const CCVector3* pSecond = pLine->getPoint(1);
			m_textStream << QString::number(pFirst->x) <<"  "<<QString::number(pFirst->y) <<"  "<<QString::number(pFirst->z) <<"  "
						<<QString::number(pSecond->x) <<"  "<<QString::number(pSecond->y) <<"  "<<QString::number(pSecond->z) <<"  "
						<<strRadius<< "\n";
		}
	}

	int nSize = pObj->getChildrenNumber();
	if(nSize>0)
	{
		for(int i=0;i<nSize;i++)
		{
			ccHObject* pChildObj = pObj->getChild(i);
			Export_Recursion(pChildObj);
		}
	}
	return ;
}

//加载地图文档
dpxMap* dpxMapManager::LoadMapDoc(QString strMapFile)
{
	return nullptr;
}
