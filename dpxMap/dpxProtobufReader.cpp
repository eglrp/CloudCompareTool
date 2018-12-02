
#include "dpxProtobufReader.h"
#include <ccHObjectCaster.h>

#include <ccPointCloud.h>
#include <GenericIndexedCloudPersist.h>
#include <ccPolyline.h>
#include <ccPlane.h>
#include <ccCylinder.h>
#include <QDateTime>
#include "dpxMapDefine.h"
#include "dpxMapCommonFunc.h"
using namespace CCLib;
dpxProtobufReader::dpxProtobufReader()
{
}

dpxProtobufReader::~dpxProtobufReader()
{
}

bool dpxProtobufReader::ImportMap(dpxMap* pMap,const QString& strImportFile)
{
	if(pMap==nullptr || pMap==0)
		return false;
	std::string strFileName = strImportFile.toStdString();
	//----------------1:mapHeader-------------------------
	hdmap_proto::Map protoMap;
	hdmap_op::MapIO mapIO(protoMap);
	mapIO.readTextFileToProtobufMap(strFileName);

	//-----------------2:Section--------------------------
	int nSectionSize = protoMap.sections_size();
	ccLog::Warning("section number =" + QString::number(nSectionSize));
	for(int i= 0;i<nSectionSize;i++)
	{
		hdmap_proto::Section* pSection =  protoMap.mutable_sections(i);
		OutPutSection(pSection,pMap);
	}

	//----------------3:OutPut independence---------------
	ImportOtherAll(protoMap,pMap);
	return true;
}


bool dpxProtobufReader::OutPutSection(hdmap_proto::Section* pSection,dpxMap* pMap)
{
	if(pSection==nullptr || pMap==nullptr)
		return false;

	dpxLayer* pRoadLyr = pMap->getRoadLyr();
	if(pRoadLyr==nullptr)
		return false;

	//----------------------refLine------------------
	if(!pSection->has_refline())
		return false;
	//RefLine
	hdmap_proto::Lane* reflane = pSection->mutable_refline();
	if(reflane==nullptr)
		return false;
	int nCurveLineSize = reflane->lines_size();
	vector<ccPolyline*> vecRefLines;
	for(int i =0;i<nCurveLineSize;i++)
	{
		 hdmap_proto::CurveLine* pCurveLine = reflane->mutable_lines(i);
		 ccPointCloud* p3DVertices = new ccPointCloud("Vertices");
		 ccPolyline* pCCRefLine  = new ccPolyline(p3DVertices);

		 if(!ProtoLane2CCLine(pCurveLine,p3DVertices,pCCRefLine))
			continue;
		vecRefLines.push_back(pCCRefLine);
	}

	ccHObject* pSectionObj = dpxMapCommonFunc::CreateSection(vecRefLines);
	if(pSectionObj==nullptr)
		return false;

	int nPreSize = pSection->pred_indices_size();
	if(nPreSize>0)
	{
		int nPreID = pSection->pred_indices(0);
		pSectionObj->setMetaData(HEAD_JUNCTION_UID,nPreID);
	}
	int nSucID = pSection->succ_indices_size();
	if(nSucID>0)
	{
		int nSucID = reflane->succ_indices(0);
		pSectionObj->setMetaData(TAIL_JUNCTION_UID,nSucID);
	}

	pRoadLyr->AddFeature(pSectionObj);

	//---------------------------------------------------------

	//----------------------RoadLane------------------------
	int nCommonLaneSize =  pSection->lanes_size();
	for(int i = 0;i<nCommonLaneSize;i++)
	{
		hdmap_proto::Lane* pCommonLane =  pSection->mutable_lanes(i);
		int nCurveLineSize = pCommonLane->lines_size();
		vector<ccPolyline*> vecRoadLines;
		for(int i =0;i<nCurveLineSize;i++)
		{
			hdmap_proto::CurveLine* pCurveLine = pCommonLane->mutable_lines(i);
			ccPointCloud* p3DVertices = new ccPointCloud("Vertices");
			ccPolyline* pRoadLine  = new ccPolyline(p3DVertices);

			if(!ProtoLane2CCLine(pCurveLine,p3DVertices,pRoadLine))
				continue;
			vecRoadLines.push_back(pRoadLine);
		}
		ccHObject* pRoadLineSet = dpxMapCommonFunc::CreateRoadLine(vecRoadLines,false);
		if(pRoadLineSet!=nullptr)
			pSectionObj->addChild(pRoadLineSet);
	}

	//---------------StopLane----------------------//
	int nStopLaneSize = pSection->stoplines_size();
	for(int i =0;i<nStopLaneSize;i++)
	{
		hdmap_proto::StopLine* pStopLine = pSection->mutable_stoplines(i);
		if(pStopLine==nullptr)
			continue;

		ccPointCloud* p3DVertices = new ccPointCloud("Vertices");
		ccPolyline* pCCStopLine  = new ccPolyline(p3DVertices);
		if(!AddStopLineInfor(pStopLine,p3DVertices,pCCStopLine))
			continue;
		pSectionObj->addChild(pCCStopLine);
	}

	//--------------Poles-----------------------//
	int nSize = pSection->poles_size();
	for(int i =0;i<nSize;i++)
	{
		hdmap_proto::Pole* pPole = pSection->mutable_poles(i);
		if(pPole==nullptr)
			continue;

		ccPointCloud* p3DVertices = new ccPointCloud("Vertices");
		ccPolyline* pCCPoleLine  = new ccPolyline(p3DVertices);
		if(!AddPoleInfor(pPole,p3DVertices,pCCPoleLine))
			continue;
		pSectionObj->addChild(pCCPoleLine);
	}

	//---------------------
	int ntlSize = pSection->traffic_lights_size();
	for(int i =0;i<ntlSize;i++)
	{
		hdmap_proto::TrafficLight* ptrafficLight = pSection->mutable_traffic_lights(i);
		if(ptrafficLight==nullptr)
			continue;

		ccPointCloud* p3DVertices = new ccPointCloud("Vertices");
		ccPolyline* pCCPlaneLine  = new ccPolyline(p3DVertices);
		if(!AddtrafficLightInfor(ptrafficLight,p3DVertices,pCCPlaneLine))
			continue;
		pSectionObj->addChild(pCCPlaneLine);
	}

	int nSignlSize = pSection->traffic_signs_size();
	for(int i =0;i<nSignlSize;i++)
	{
		hdmap_proto::TrafficSign* ptrafficSign = pSection->mutable_traffic_signs(i);
		if(ptrafficSign==nullptr)
			continue;

		ccPointCloud* p3DVertices = new ccPointCloud("Vertices");
		ccPolyline* pCCPlaneLine  = new ccPolyline(p3DVertices);
		if(!AddtrafficSignInfor(ptrafficSign,p3DVertices,pCCPlaneLine))
			continue;
		pSectionObj->addChild(pCCPlaneLine);
	}
	//Speedbump
	int nSpeedbumpSize = pSection->speedbumps_size();
	for(int i =0;i<nSpeedbumpSize;i++)
	{
		hdmap_proto::SpeedBump* pSpeedBump = pSection->mutable_speedbumps(i);
		if(pSpeedBump==nullptr)
			continue;

		ccPointCloud* p3DVertices = new ccPointCloud("Vertices");
		ccPolyline* pCCPlaneLine  = new ccPolyline(p3DVertices);
		if(!AddSpeedbumpInfor(pSpeedBump,p3DVertices,pCCPlaneLine))
			continue;
		pSectionObj->addChild(pCCPlaneLine);
	}

	//Board
	int nBoardSize = pSection->boards_size();
	for(int i =0;i<nBoardSize;i++)
	{
		hdmap_proto::Board* pBoard = pSection->mutable_boards(i);
		if(pBoard==nullptr)
			continue;

		ccPointCloud* p3DVertices = new ccPointCloud("Vertices");
		ccPolyline* pCCPlaneLine  = new ccPolyline(p3DVertices);
		if(!AddBoardInfor(pBoard,p3DVertices,pCCPlaneLine))
			continue;
		pSectionObj->addChild(pCCPlaneLine);
	}

	//lane_markings
	int nLaneMarkingSize = pSection->lane_markings_size();
	for(int i =0;i<nLaneMarkingSize;i++)
	{
		hdmap_proto::LaneMarking* pLaneMarking = pSection->mutable_lane_markings(i);
		if(pLaneMarking==nullptr)
			continue;

		ccPointCloud* p3DVertices = new ccPointCloud("Vertices");
		ccPolyline* pCCPlaneLine  = new ccPolyline(p3DVertices);
		if(!AddLaneMarkingInfor(pLaneMarking,p3DVertices,pCCPlaneLine))
			continue;
		pCCPlaneLine->setName("LaneMarking");
		pSectionObj->addChild(pCCPlaneLine);
	}
	return true;
}

bool dpxProtobufReader::AddLaneMarkingInfor(hdmap_proto::LaneMarking* pLaneMarking,ccPointCloud* p3DVertices,ccPolyline* pCCLine)
{
	if(pLaneMarking==nullptr || p3DVertices==nullptr || pCCLine==nullptr)
		return false;
	if(!pLaneMarking->has_border())
		return false;

	hdmap_proto::Polygon* pPolygon = pLaneMarking->mutable_border();
	if(pPolygon == nullptr)
		return false;

	if(p3DVertices==nullptr || pCCLine==nullptr)
		return false;

	int BorderSize = pPolygon->points_size();
	for(int i = 0;i<BorderSize;i++)
	{
		hdmap_proto::Vector3d pt = pPolygon->points(i);
		CCVector3 ccPt;
		ccPt.x = pt.x();
		ccPt.y = pt.y();
		ccPt.z = pt.z();

		p3DVertices->reserve(p3DVertices->size()+1);
		pCCLine->reserve(p3DVertices->size()+1);

		p3DVertices->addPoint(ccPt);
		pCCLine->addPointIndex(i);
	}
	if(BorderSize>2)
		pCCLine->setClosed(true);
	pCCLine->setMetaData(DPX_OBJECT_TYPE_NAME,eObj_LaneMarking); //地物类型
	return true;
}

bool dpxProtobufReader::AddBoardInfor(hdmap_proto::Board* pBoard,ccPointCloud* p3DVertices,ccPolyline* pCCLine)
{
	if(pBoard==nullptr || p3DVertices==nullptr || pCCLine==nullptr)
		return false;
	if(!pBoard->has_border())
		return false;

	hdmap_proto::Polygon* pPolygon = pBoard->mutable_border();
	if(pPolygon ==nullptr)
		return false;
	if(!CreateBorderLine(pPolygon,p3DVertices,pCCLine))
		return false;

	pCCLine->setMetaData(DPX_OBJECT_TYPE_NAME,eObj_Board); //地物类型
	return true;
}

bool dpxProtobufReader::AddSpeedbumpInfor(hdmap_proto::SpeedBump* pSpeedBump,ccPointCloud* p3DVertices,ccPolyline* pCCLine)
{
	if(pSpeedBump==nullptr || p3DVertices==nullptr || pCCLine==nullptr)
		return false;
	if(!pSpeedBump->has_border())
		return false;

	hdmap_proto::Polygon* pPolygon = pSpeedBump->mutable_border();
	if(pPolygon ==nullptr)
		return false;
	if(!CreateBorderLine(pPolygon,p3DVertices,pCCLine) )
		return false;

	pCCLine->setMetaData(DPX_OBJECT_TYPE_NAME,eObj_SpeedBump); //地物类型
	return true;
}


bool dpxProtobufReader::AddtrafficSignInfor(hdmap_proto::TrafficSign*ptrafficSign,ccPointCloud* p3DVertices,ccPolyline* pCCSignLine)
{
	if(ptrafficSign==nullptr || p3DVertices==nullptr || pCCSignLine==nullptr)
		return false;
	if(!ptrafficSign->has_pborder())
		return false;

	hdmap_proto::Polygon* pPolygon = ptrafficSign->mutable_pborder();
	if(pPolygon==nullptr)
		return false;
	if(!CreateBorderLine(pPolygon,p3DVertices,pCCSignLine))
		return false;

	pCCSignLine->setMetaData(DPX_OBJECT_TYPE_NAME,eObj_TrafficSign); //地物类型
	return true;
}


bool dpxProtobufReader::AddtrafficLightInfor(hdmap_proto::TrafficLight*ptrafficLight,ccPointCloud* p3DVertices,ccPolyline* pCCPoleLine)
{
	if(ptrafficLight==nullptr || p3DVertices==nullptr || pCCPoleLine==nullptr)
		return false;

	if(!ptrafficLight->has_pborder())
		return false;

	hdmap_proto::Polygon* pPolygon = ptrafficLight->mutable_pborder();
	if(pPolygon ==nullptr)
		return false;
	if(!CreateBorderLine(pPolygon,p3DVertices,pCCPoleLine))
		return false;

	pCCPoleLine->setMetaData(DPX_OBJECT_TYPE_NAME,eObj_TrafficLight); //地物类型
	return true;
}

//输出其余信息
bool dpxProtobufReader::ImportOtherAll(hdmap_proto::Map& protoMap,dpxMap* pMap)
{
	if(pMap==nullptr)
		return false;
	//stopLines
	dpxLayer* pStopLineLyr = pMap->getStopLineLyr();
	if(pStopLineLyr!=nullptr)
	{
		int nStopLineSize = protoMap.stoplines_size();
		for(int i = 0;i<nStopLineSize;i++)
		{
			ccHObject* pStopLineRootObj = pStopLineLyr->getRootData();
			hdmap_proto::StopLine* pStopLine = protoMap.mutable_stoplines(i);
			if(pStopLine==nullptr)
				continue;

			ccPointCloud* p3DVertices = new ccPointCloud("Vertices");
			ccPolyline* pCCStopLine  = new ccPolyline(p3DVertices);
			if(!AddStopLineInfor(pStopLine,p3DVertices,pCCStopLine))
				continue;
			pStopLineRootObj->addChild(pCCStopLine);
		}
	}

	//CrossWalks
	dpxLayer* pCrossLyr = pMap->getCrossWalkLyr();
	if(pCrossLyr!=nullptr)
	{
		ccHObject* pCWRootObj = pCrossLyr->getRootData();
		AddCrossWalks(protoMap,pCWRootObj);
	}

	//Lights  Pole
	dpxLayer* pLightLyr = pMap->getTrafficLightLyr();
	if(pLightLyr!=nullptr)
	{
		ccHObject* pLRootObj = pLightLyr->getRootData();
		//--------------Poles-----------------------//
		int nSize = protoMap.poles_size();
		for(int i =0;i<nSize;i++)
		{
			hdmap_proto::Pole* pPole = protoMap.mutable_poles(i);
			if(pPole==nullptr)
				continue;

			ccPointCloud* p3DVertices = new ccPointCloud("Vertices");
			ccPolyline* pCCPoleLine  = new ccPolyline(p3DVertices);
			if(!AddPoleInfor(pPole,p3DVertices,pCCPoleLine))
				continue;
			pLRootObj->addChild(pCCPoleLine);
		}
	}

	//trafficSign  面状指示牌
	dpxLayer* pIndicatorLry = pMap->getTrafficSignLyr();
	if(pIndicatorLry!=nullptr)
	{
		ccHObject* pLRootObj = pIndicatorLry->getRootData();

		int nSignlSize = protoMap.traffic_signs_size();
		for(int i =0;i<nSignlSize;i++)
		{
			hdmap_proto::TrafficSign* ptrafficSign = protoMap.mutable_traffic_signs(i);
			if(ptrafficSign==nullptr)
				continue;

			ccPointCloud* p3DVertices = new ccPointCloud("Vertices");
			ccPolyline* pCCPlaneLine  = new ccPolyline(p3DVertices);
			if(!AddtrafficSignInfor(ptrafficSign,p3DVertices,pCCPlaneLine))
				continue;
			pLRootObj->addChild(pCCPlaneLine);
		}
	}
	//trafficSign  面状指示牌
	dpxLayer* pSpeedbumpsLry = pMap->getSpeedbumpsLyr();
	if(pSpeedbumpsLry!=nullptr)
	{
		ccHObject* pRootObj = pSpeedbumpsLry->getRootData();
		//Speedbump
		int nSpeedbumpSize = protoMap.speedbumps_size();
		for(int i =0;i<nSpeedbumpSize;i++)
		{
			hdmap_proto::SpeedBump* pSpeedBump = protoMap.mutable_speedbumps(i);
			if(pSpeedBump==nullptr)
				continue;

			ccPointCloud* p3DVertices = new ccPointCloud("Vertices");
			ccPolyline* pCCPlaneLine  = new ccPolyline(p3DVertices);
			if(!AddSpeedbumpInfor(pSpeedBump,p3DVertices,pCCPlaneLine))
				continue;
			pRootObj->addChild(pCCPlaneLine);
		}
	}

	dpxLayer* pBoardLry = pMap->getBoardLyr();
	if(pBoardLry!=nullptr)
	{
		ccHObject* pRootObj = pBoardLry->getRootData();
		int nBoardSize = protoMap.boards_size();
		for(int i =0;i<nBoardSize;i++)
		{
			hdmap_proto::Board* pBoard = protoMap.mutable_boards(i);
			if(pBoard==nullptr)
				continue;

			ccPointCloud* p3DVertices = new ccPointCloud("Vertices");
			ccPolyline* pCCPlaneLine  = new ccPolyline(p3DVertices);
			if(!AddBoardInfor(pBoard,p3DVertices,pCCPlaneLine))
				continue;
			pRootObj->addChild(pCCPlaneLine);
		}
	}

	//ParkingSpace
	dpxLayer* pParkingSpaceLyr = pMap->getParkingSpaceLyr();
	if(pParkingSpaceLyr!=nullptr)
	{
		ccHObject* pRootObj = pParkingSpaceLyr->getRootData();
		AddParkingSpace(protoMap,pRootObj);
	}

	return 	true;
}

bool dpxProtobufReader::AddParkingSpace(hdmap_proto::Map& protoMap,ccHObject* pFatherObj)
{
	int nParkingSpaces = protoMap.parking_spaces_size();
	for(int i = 0;i<nParkingSpaces;i++)
	{
		hdmap_proto::ParkingSpace* pParkingSpace = protoMap.mutable_parking_spaces(i);
		if(pParkingSpace==nullptr)
			continue;

		ccPointCloud* pBorder3DVertices = new ccPointCloud("Vertices");
		ccPolyline* pBorderLine  = new ccPolyline(pBorder3DVertices);
		pBorderLine->setMetaData(DPX_OBJECT_TYPE_NAME,eObj_ParkingSpace); //地物类型

		int nParkingSpace = pParkingSpace->parking_slots_size();

		for(int j =0;j<nParkingSpace;j++)
		{
			hdmap_proto::ParkingSlot* pParkingSlot = pParkingSpace->mutable_parking_slots(j);
			hdmap_proto::Polygon* pPolygon = pParkingSlot->mutable_border();
			if(pPolygon==nullptr)
				continue;

			ccPointCloud* p3DVertices = new ccPointCloud("Vertices");
			ccPolyline* pInnerLine  = new ccPolyline(p3DVertices);
			pInnerLine->setName("ParkingSpace InnerLine");
			if(!CreateBorderLine(pPolygon,p3DVertices,pInnerLine))
				continue;
			pBorderLine->addChild(pInnerLine);
		}

		pFatherObj->addChild(pBorderLine);
	}

	return true;
}

bool dpxProtobufReader::AddCrossWalks(hdmap_proto::Map& protoMap,ccHObject* pFatherObj)
{
	int nCrossWalks = protoMap.crosswalks_size();
	for(int i = 0;i<nCrossWalks;i++)
	{
		hdmap_proto::CrossWalk* pCrossWalk = protoMap.mutable_crosswalks(i);
		if(pCrossWalk==nullptr)
			continue;

		hdmap_proto::Polygon* pPolygon = pCrossWalk->mutable_border();
		if(pPolygon==nullptr)
			continue;

		ccPointCloud* p3DVertices = new ccPointCloud("Vertices");
		ccPolyline* pBorderLine  = new ccPolyline(p3DVertices);
		pBorderLine->setName("CrossWalk Line");
		if(!CreateBorderLine(pPolygon,p3DVertices,pBorderLine))
			continue;
		pBorderLine->setMetaData(DPX_OBJECT_TYPE_NAME,eObj_CrossWalkLine); //地物类型

		int nCrossWalk = pCrossWalk->child_borders_size();
		for(int j =0;j<nCrossWalk;j++)
		{
			 hdmap_proto::Polygon* InnerPolygon = pCrossWalk->mutable_child_borders(j);
			 if(InnerPolygon==nullptr)
				continue;

			ccPointCloud* pInnerVertices = new ccPointCloud("Vertices");
			ccPolyline* pInnerLine  = new ccPolyline(p3DVertices);
			pInnerLine->setName("CrossWalk InnerPon");
			if(!CreateBorderLine(InnerPolygon,pInnerVertices,pInnerLine))
				continue;

			pBorderLine->addChild(pInnerLine);
		}

		pFatherObj->addChild(pBorderLine);
	}

	return true;
}

//Junction
bool dpxProtobufReader::AddJunctions(hdmap_proto::Map& protoMap,ccHObject* pFatherObj)
{
	int nJunctions = protoMap.junctions_size();
	for(int i = 0;i<nJunctions;i++)
	{
		hdmap_proto::Junction* pJunction = protoMap.mutable_junctions(i);
		if(pJunction==nullptr)
			continue;

		if(!pJunction->has_border())
			continue;

		if(!pJunction->has_id())
			continue;

		hdmap_proto::Polygon* pPolygon = pJunction->mutable_border();
		if(pPolygon==nullptr)
			continue;

		ccPointCloud* p3DVertices = new ccPointCloud("Vertices");
		ccPolyline* pBorderLine  = new ccPolyline(p3DVertices);
		if(!CreateBorderLine(pPolygon,p3DVertices,pBorderLine))
			continue;
		pBorderLine->setMetaData(DPX_OBJECT_TYPE_NAME,eObj_Junction); //地物类型
		pBorderLine->setName("Junction");
		pBorderLine->setColor(ccColor::green);

		//ID
		int nUID = pJunction->mutable_id()->id();
		pBorderLine->setMetaData(DPX_UID,nUID);

		//related vecRefIDs
		int nLinkSize = pJunction->link_ids_size();
		vector<int> vecLinkIDs;
		for(int i=0;i<nLinkSize;i++)
		{
			hdmap_proto::Id  ID = pJunction->link_ids(i);
			vecLinkIDs.push_back(ID.id());
		}
		pBorderLine->setMetaData(RELATED_REFLINE_UID,dpxMapCommonFunc::getRefIDValue(vecLinkIDs));
		pFatherObj->addChild(pBorderLine);
	}

	return true;
}


bool dpxProtobufReader::CreateBorderLine(hdmap_proto::Polygon* pPolygon,ccPointCloud* p3DVertices,ccPolyline* pBorderLine)
{
	if(pPolygon==nullptr || p3DVertices==nullptr || pBorderLine==nullptr)
		return false;

	int BorderSize = pPolygon->points_size();
	for(int i = 0;i<BorderSize;i++)
	{
		hdmap_proto::Vector3d pt = pPolygon->points(i);
		CCVector3 ccPt;
		ccPt.x = pt.x();
		ccPt.y = pt.y();
		ccPt.z = pt.z();

		p3DVertices->reserve(p3DVertices->size()+1);
		pBorderLine->reserve(p3DVertices->size()+1);

		p3DVertices->addPoint(ccPt);
		pBorderLine->addPointIndex(i);
	}
	double rms = 0.0; //output for rms
	ccPlane* pBorderPlane = ccPlane::Fit(p3DVertices, &rms);
	if(pBorderPlane==nullptr)
		return false;
	QString strRelateID = QUuid::createUuid().toString();
	pBorderPlane->setVisible(true);
	pBorderPlane->setSelectionBehavior(ccHObject::SELECTION_IGNORED);
	pBorderPlane->setMetaData(DPX_RELATED_PLANE_UID,strRelateID);

	CCVector3 vNormal = pBorderPlane->getNormal();
	QString strNormal = QString::number(vNormal.x).append(" ").append(QString::number(vNormal.y)).append(" ").append(QString::number(vNormal.z));
	pBorderLine->setMetaData(DPX_NORMAL,strNormal);//法向量
	pBorderLine->setMetaData(DPX_RELATED_PLANE_UID,strRelateID);//关联的ID
	pBorderLine->addChild(pBorderPlane);
	return true;
}

bool dpxProtobufReader::AddPoleInfor(hdmap_proto::Pole* pPole,ccPointCloud* p3DVertices,ccPolyline* pBorderLine)
{
	if(pPole==nullptr || p3DVertices==nullptr || pBorderLine==nullptr)
		return false;

	if(!pPole->has_body())
		return false;

	hdmap_proto::Cylinder* pProtoCyliner = pPole->mutable_body();
	if(pProtoCyliner==nullptr)
		return false;

	double dRadius = pProtoCyliner->radius();
	int nSize = pProtoCyliner->points_size();
	if(nSize<2 || dRadius<0)
		return false;

    hdmap_proto::Vector3d pt1 = pProtoCyliner->points(0);
    hdmap_proto::Vector3d pt2 = pProtoCyliner->points(1);

	CCVector3 ptFirst(pt1.x(),pt1.y(),pt1.z());
	CCVector3 ptSecond(pt2.x(),pt2.y(),pt2.z());

	CCVector3 RDisPt;
	getRDisPt(ptFirst,ptSecond,dRadius,RDisPt);

	p3DVertices->reserve(3);
	pBorderLine->reserve(4);
	p3DVertices->addPoint(ptFirst);
	pBorderLine->addPointIndex(0);
	p3DVertices->addPoint(ptSecond);
	pBorderLine->addPointIndex(1);
	p3DVertices->addPoint(RDisPt);
	pBorderLine->addPointIndex(2);
	//缺个点
	double dHeight = sqrt(pow((ptFirst.x-ptSecond.x),2.0) + pow((ptFirst.y-ptSecond.y),2.0) + pow((ptFirst.z-ptSecond.z),2.0));

	//CC system Func
	QString strRelateID = QUuid::createUuid().toString();
	CCVector3 vbefore(0,0,1);
	CCVector3 vafter(ptSecond.x-ptFirst.x, ptSecond.y-ptFirst.y, ptSecond.z-ptFirst.z);
	vafter/=vafter.normd();
	ccGLMatrix transM = ccGLMatrix::FromToRotation(vbefore,vafter);

	CCVector3 vecTrans((ptFirst.x+ptSecond.x)/2,(ptFirst.y+ptSecond.y)/2,(ptFirst.z+ptSecond.z)/2);
	transM.setTranslation(vecTrans);

	QDateTime current_time =QDateTime::currentDateTime();
	QString sCurrentTime =current_time.toString("hh:mm:ss");
	pBorderLine->setName("CylinderLine_"+sCurrentTime);
	pBorderLine->setMetaData(DPX_CYLINEDER_RELATED_UID,strRelateID);//关联的ID
	pBorderLine->setMetaData(DPX_RADIUS,QString::number(dRadius));
	pBorderLine->setMetaData(DPX_OBJECT_TYPE_NAME,eObj_TrafficLight_pole); //地物类型

	ccCylinder* pCylinder = new ccCylinder(dRadius,dHeight,&transM,"Cylinder"+sCurrentTime,24);
	pCylinder->setMetaData(DPX_CYLINEDER_RELATED_UID,strRelateID);//关联的ID
	pCylinder->setTempColor(ccColor::cyan);
	pBorderLine->addChild(pCylinder);

	return true;
}

void dpxProtobufReader::getRDisPt(CCVector3 ptFirst,CCVector3 ptSecond,double dDis,CCVector3& RDisPt)
{
	 if(ptFirst.x==ptSecond.x && ptSecond.y==ptSecond.y)
	 {
		CCVector3 vec(0,0,1);
		RDisPt = ptSecond+dDis*vec;
	 }
	 else if(ptFirst.x==ptSecond.x)
	 {
		RDisPt.y = ptSecond.y;
		RDisPt.z = ptSecond.z;
		RDisPt.z = sqrt(dDis) + ptSecond.y;
	 }
	 else
	 {
		float Xab = ptSecond.x - ptFirst.x;
		float Yab = ptSecond.y - ptFirst.y;
		float Ybc = sqrt( dDis*dDis/(Yab*Yab/(Xab*Xab)+1));

		RDisPt.y = Ybc + ptSecond.y;
		RDisPt.x = -Yab/Xab * Ybc + ptSecond.x;
		RDisPt.z = RDisPt.z;
	 }
	return ;
}



bool dpxProtobufReader::AddStopLineInfor(hdmap_proto::StopLine* pStopLine,ccPointCloud* p3DVertices,ccPolyline* pCCStopLine)
{
	if(pStopLine==nullptr)
		return false;
	if(!pStopLine->has_border())
		return false;

	hdmap_proto::Polygon* pPolygon = pStopLine->mutable_border();
	if(pPolygon==nullptr)
		return false;

	int nPtSize = pPolygon->points_size();
	if(nPtSize<4)
		return false;

	p3DVertices->reserve(nPtSize);
	pCCStopLine->reserve(nPtSize+1);

	for(int i =0;i<nPtSize;i++)
	{
		//addPt
		CCVector3 ccpt;
		hdmap_proto::Vector3d pt = pPolygon->points(i);
		ccpt.x = pt.x();
		ccpt.y = pt.y();
		ccpt.z = pt.z();
		p3DVertices->addPoint(ccpt);
		pCCStopLine->addPointIndex(i);
	}

	QString strRelateID = QUuid::createUuid().toString();
	double rms = 0.0;
	ccPlane* pPlane = ccPlane::Fit(p3DVertices, &rms);//重新拟合平面
	if (pPlane) //valid fit
	{
		//make plane to add to display
		pPlane->setVisible(true);
		pPlane->setSelectionBehavior(ccHObject::SELECTION_IGNORED);
		pPlane->setMetaData(DPX_RELATED_PLANE_UID,strRelateID);
		QImage* pImage = new QImage("");
		if(pImage)
			pPlane->setAsTexture(*pImage);

		CCVector3 vNormal = pPlane->getNormal();
		QString strNormal = QString::number(vNormal.x).append(" ").append(QString::number(vNormal.y)).append(" ").append(QString::number(vNormal.z));
		pCCStopLine->setMetaData(DPX_NORMAL,strNormal);//法向量
		pCCStopLine->setMetaData(DPX_RELATED_PLANE_UID,strRelateID);//关联的ID
		pCCStopLine->setMetaData(DPX_OBJECT_TYPE_NAME,eObj_RoadStopLine); //地物类型
		pCCStopLine->setName("stopline");//设置名称
		pCCStopLine->addChild(pPlane);
	}

	//Attribute
	ccColor::Rgb stopLineColor STOP_LINE_COLOR; //宏定义颜色
	pCCStopLine->setTempColor(stopLineColor);
	pCCStopLine->setMetaData(DPX_OBJECT_TYPE_NAME,eObj_RoadStopLine); //记录要素类型为StopLine

	return true;
}

 bool dpxProtobufReader::ProtoLane2CCLine(hdmap_proto::CurveLine* pCurveLine,ccPointCloud* p3DVertices,ccPolyline* pLine)
 {
	int nPtSize = pCurveLine->points_size();
	if(nPtSize<1)
		return false;

	p3DVertices->reserve(nPtSize+1);
	pLine->reserve(nPtSize+2);

	for(int i = 0;i < nPtSize; i++)
	{
		hdmap_proto::Vector3d protoPt = pCurveLine->points(i);

		CCVector3 ccPt;
		ccPt.x = protoPt.x();
		ccPt.y = protoPt.y();
		ccPt.z = protoPt.z();
		p3DVertices->addPoint(ccPt);
		pLine->addPointIndex(i);
	}
	return true;
 }

