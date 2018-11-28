
#include "dpxMapManager.h"
#include "dpxMapDefine.h"
#include <QFileDialog>
#include <QMessageBox>
#include <ccPolyline.h>
#include <ccPlane.h>
#include <ccHObjectCaster.h>
#include "dpxMapDefine.h"
#include "dpxProtobufWriter.h"
#include "dpxProtobufReader.h"
#include "dpxMapCommonFunc.h"

dpxMapManager::dpxMapManager()
{
	m_pWriter = new dpxProtobufWriter();
	m_pReader = new dpxProtobufReader();
}

dpxMapManager::~dpxMapManager()
{
	delete m_pWriter;
	m_pWriter = nullptr;
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

	return pMap;
}

//定制的HDMap内容
dpxMap* dpxMapManager::createHDMap()
{
	vector<QString> vecLryNames;
	vecLryNames.push_back(ROAD_LAYER_NAME); 		//道路
	vecLryNames.push_back(LIGHT_LAYER_NAME); 		//路灯
	vecLryNames.push_back(INDICATOR_LAYER_NAME);	//指示牌
	vecLryNames.push_back(CROSS_WALK_LAYER_NAME);	//斑马线
	vecLryNames.push_back(STOP_LINE_NAME);			//停止线
	vecLryNames.push_back(SPEED_BUMP_NAME);			//减速带
	vecLryNames.push_back(PARKING_SPACE_NAME);		//停车位
	vecLryNames.push_back(BOARD_NAME);				//其它面板
	vecLryNames.push_back(JUNCTION_NAME);			//连接
	vecLryNames.push_back(OTHER_NAME);				//其它

	dpxMap* pMap = new dpxMap(HDMAP_NAME);
	//道路层
	dpxLayer* pRoadLry = new dpxLayer(ROAD_LAYER_NAME);
	pRoadLry->SetType(eOT_Road);

	//路灯杆层
	dpxLayer* pLightLry = new dpxLayer(LIGHT_LAYER_NAME);
	pLightLry->SetType(eOT_TrafficLight);

	//指示牌
	dpxLayer* pIndicatorLry = new dpxLayer(INDICATOR_LAYER_NAME);
	pIndicatorLry->SetType(eOT_TrafficSign);

	//路面标识 laneMarking
	dpxLayer* pLaneMarkingLry = new dpxLayer(LANE_MARKING_NAME);
	pLaneMarkingLry->SetType(eOT_LaneMarking);

	//人行横道
	dpxLayer* pCrossWalkLry = new dpxLayer(CROSS_WALK_LAYER_NAME);
	pCrossWalkLry->SetType(eOT_CrossWalk);

	dpxLayer* pParkingSpaceLry = new dpxLayer(PARKING_SPACE_NAME);
	pParkingSpaceLry->SetType(eOT_ParkingSpace);

	dpxLayer* pStopLineLry = new dpxLayer(STOP_LINE_NAME);
	pStopLineLry->SetType(eOT_StopLine);

	dpxLayer* pSpeedBumpLry = new dpxLayer(SPEED_BUMP_NAME);
	pSpeedBumpLry->SetType(eOT_SpeedBump);

	dpxLayer* pBoardLry = new dpxLayer(BOARD_NAME);
	pBoardLry->SetType(eOT_Board);

	dpxLayer* pJunction = new dpxLayer(JUNCTION_NAME);
	pJunction->SetType(eOT_Junction);

	//其它
	dpxLayer* pOtherLry = new dpxLayer(OTHER_NAME);
	pOtherLry->SetType(eOT_Other);

	//地图添加图层
	pMap->AddLayer(pRoadLry);
	pMap->AddLayer(pLightLry);
	pMap->AddLayer(pIndicatorLry);
	pMap->AddLayer(pLaneMarkingLry);
	pMap->AddLayer(pCrossWalkLry);
	pMap->AddLayer(pParkingSpaceLry);
	pMap->AddLayer(pStopLineLry);
	pMap->AddLayer(pSpeedBumpLry);
	pMap->AddLayer(pBoardLry);
	pMap->AddLayer(pJunction);
	pMap->AddLayer(pOtherLry);

	return pMap;
}

bool dpxMapManager::ImportMap(dpxMap* pMap,const QString& strOutFile)
{
	if(m_pReader == nullptr || pMap == nullptr)
		return false;

	if(m_pReader->ImportMap(pMap,strOutFile)) //output
	{
		ccLog::Warning("Auto output success!");
		return true;
	}
	else
	{
		ccLog::Warning("Auto output error!");
		return false;
	}
	return false;
}

bool dpxMapManager::ManMadeOutPutMap(dpxMap* pMap,const QString& strOutFile)
{
	if(m_pWriter ==nullptr || pMap == nullptr)
	{
        QMessageBox::warning(nullptr,"waring","not set Writer or map is null");
        return false;
	}
	if(m_pWriter->outPutMap(pMap,strOutFile)) //output
	{
		QMessageBox::warning(nullptr,"success","out put success!");
		return true;
	}
	else
	{
		QMessageBox::warning(nullptr,"error","output error!");
		return false;
	}
}

bool dpxMapManager::AutoOutPutMap2Protobuf(dpxMap* pMap,const QString& strOutFile)
{
	if(m_pWriter == nullptr || pMap == nullptr)
		return false;
	if(m_pWriter->outPutMap(pMap,strOutFile)) //output
	{
		ccLog::Warning("Auto output success!");
		return true;
	}
	else
	{
		ccLog::Warning("Auto output error!");
		return false;
	}
}

bool dpxMapManager::AutoCreateJunction(dpxMap* pMap)
{
	if(pMap==nullptr)
		return false;
	dpxLayer* pRoadLayer = pMap->getRoadLyr();
	ccHObject* pRoadRoot = pRoadLayer->getRootData();
	if(pRoadRoot==nullptr)
		return false;

	vector<refLineInfo> refInfos;
	int nRefSize = pRoadRoot->getChildrenNumber(); //RefLine(Section)
	for(int i=0;i<nRefSize;i++)
	{
		ccHObject* pObj = pRoadRoot->getChild(i);
		if(pObj==nullptr)
			continue;

		ccPolyline* pDPXRefLine = pObj && pObj->isA(CC_TYPES::POLY_LINE) ? static_cast<ccPolyline*>(pObj) : 0;
		if(pDPXRefLine==0)
			continue;

		if(!MapCommon::ConfimObjType(pDPXRefLine,eObj_RoadRefLine)) //如果是refLine
			continue;

		if(!pDPXRefLine->hasMetaData(DPX_UID))
			continue;

		int nPtCount = pDPXRefLine->size();
		if(nPtCount<2)
			continue;

		int nID = pDPXRefLine->getMetaData(DPX_UID).toInt();
		CCVector3 firstPt = *(pDPXRefLine->getPointPersistentPtr(0));
		CCVector3 lastPt = *(pDPXRefLine->getPointPersistentPtr(nPtCount-1));
		refLineInfo info;
		info.m_nID = nID;
		info.m_firstPt = firstPt;
		info.m_lastPt = lastPt;
		info.m_bHasHeadSet = false;
		info.m_bHasTailSet = false;
		refInfos.push_back(info);
	}

	ccLog::Warning("refInfos Size = " + QString::number(refInfos.size()));
	MapCommon::CreateJunction(pMap,refInfos,0.5,10);
}


//地图文档，可以用于加载
bool dpxMapManager::AutoOutPutMap(ccHObject* pMapRootData,const QString& strOutFile)
{
	QFile file(strOutFile);
    if (!file.open(QFile::ReadWrite | QFile::Text))
    {
		QMessageBox::warning(nullptr,"waring","Error: cannot creat file");
		return false;
    }

	m_textStream.setDevice(&file);
	m_textStream<< " Objtype "<< " Important key " << " coordinateXYZ "  << "\n";

   //迭代输出
	Export_Recursion(pMapRootData);
	file.close();

	return true;
}

//-----------------output nomarl txt----------------------------//
void dpxMapManager::Export_Recursion(ccHObject* pObj)
{
	if(pObj == nullptr || !pObj)
		return;

	ccPolyline* pLine = pObj && pObj->isA(CC_TYPES::POLY_LINE) ? static_cast<ccPolyline*>(pObj) : 0;
	if(pLine!=0 && pLine != nullptr)
	{
		dpxObjectType eType = eObj_Unknown;
		bool bHasObjType = pLine->hasMetaData(DPX_OBJECT_TYPE_NAME);
		if(bHasObjType)
            eType = dpxObjectType(pLine->getMetaData(DPX_OBJECT_TYPE_NAME).toInt());

		if(eType==eObj_RoadRefLine || eType==eObj_RoadLine || eType==eObj_RoadStopLine || eType==eObj_CrossWalkLine) //道路线
		{
			ExportLine(pLine,eType);
		}
		else if(eType==eObj_TrafficLight_pole) //圆柱特征
		{
			ExportOfficeLightPole(pLine,eType);
		}
		else if(eType==eObj_TrafficLight || eType==eObj_TrafficSign) //Plane
		{
			ExportPlane(pLine,eType);
		}
		else
		{
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

void dpxMapManager::ExportPlane(ccPolyline* pLine,int eType)
{
	m_textStream << " Objtype " <<  QString::number(eType);
	if(pLine==nullptr || pLine==0)
		return;
	//
	QString strUID = pLine->getMetaData(DPX_RELATED_PLANE_UID).toString();
	ccHObject::Container vecHObjs;
	pLine->filterChildren(vecHObjs,true,CC_TYPES::PLANE);
	for(int i =0;i<vecHObjs.size();i++)
	{
		ccPlane* plane = ccHObjectCaster::ToPlane(vecHObjs[i]);
		if(plane==nullptr)
			continue;
		if(plane->get4CornerPts().size()!=4)
			continue;
		if(!plane->hasMetaData(DPX_RELATED_PLANE_UID))
			continue;
		QString sUID = plane->getMetaData(DPX_RELATED_PLANE_UID).toString();
		if(sUID.compare(strUID,Qt::CaseInsensitive)==0)//
		{
			CCVector3 vecNormal = plane->getNormal();
			m_textStream << " Normal:"<< " ( " << QString::number(vecNormal.x) <<"  "<<QString::number(vecNormal.y) <<"  "<<QString::number(vecNormal.z) << " ) ";
			vector<CCVector3> vecPts = plane->get4CornerPts();
			for(int i = 0;i<vecPts.size();i++)
			{
				CCVector3  pPt = vecPts.at(i);
				outPtCoordinate(pPt);
			}
		}
	}

	m_textStream << "\n";
}

void dpxMapManager::ExportLine(ccPolyline* pLine,int eType)
{
	m_textStream << " Objtype " <<  QString::number(eType) ;
	for(int i = 0;i<pLine->size();i++)
	{
		const CCVector3*  pPt = pLine->getPoint(i);
		outPtCoordinate(*pPt);
	}
	m_textStream << "\n";
}

void dpxMapManager::ExportOfficeLightPole(ccPolyline* pLine,int eType)
{
	QString strRadius = pLine->getMetaData("Radius").toString();
	const CCVector3* pFirst = pLine->getPoint(0);
	const CCVector3* pSecond = pLine->getPoint(1);

	m_textStream << " Objtype " <<  QString::number(eType)  << " Radius " << strRadius;
	outPtCoordinate(*pFirst);
	outPtCoordinate(*pSecond);
	m_textStream << "\n";
}

void dpxMapManager::outPtCoordinate(CCVector3 pt)
{
	m_textStream
		<< " ( " <<
	QString::number(pt.x) <<" "<<
	QString::number(pt.y) <<" "<<
	QString::number(pt.z)
		<< " ) ";
}
