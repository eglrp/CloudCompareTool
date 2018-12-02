
//by duans 2018.8.10
#ifndef _DPX_PROTOBUF_WRITER_H_
#define _DPX_PROTOBUF_WRITER_H_
#pragma once

#include <ccPolyline.h>
#include <ccPlane.h>

#include "dpxMapDefine.h"
#include "dpxWriter.h"

#include "../map_param/map.pb.h"
#include "../map_param/mapio.h"
using namespace hdmap_proto;

class  DPX_MAP_API dpxProtobufWriter : public dpxWriter
{
public:
	dpxProtobufWriter();
	virtual ~dpxProtobufWriter();

public:
	virtual bool outPutMap(dpxMap* pMap,const QString& strOutFile);

protected:
	//地图头Header
	bool SettingMapHeader(hdmap_proto::Header* pHead);
//	//输出Section信息
	bool OutPutSection(dpxMap* pMap,hdmap_proto::Map* protoMap);
//	//输出其余信息
	bool OutPutOtherAll(dpxMap* pMap,hdmap_proto::Map* protoMap);
//
private:
	bool addRefLaneInfo(ccHObject* pRefLineSet,hdmap_proto::Lane* pRefLane);
	bool addRoadLaneInfo(ccHObject* pRoadLineSet,hdmap_proto::Lane* pRoadLane,int nID);

	bool addStopLineInfo(ccPlane* pPlane,hdmap_proto::StopLine* pStopLine,int nID);

	bool addPoleInfo(ccPolyline* pDPXLine,hdmap_proto::Pole* pPole,float fRadius,int nID);
	bool addOfficLightInfo(ccPlane* pPlane,hdmap_proto::TrafficLight* pTrafficLight,int nID);
	bool addOfficSignInfo(ccPlane* pPlane,hdmap_proto::TrafficSign* pTrafficSign,int nID);
	bool addSpeedBumpInfo(ccPlane* pPlane,hdmap_proto::SpeedBump* pSpeedBump,int nID);
	bool addBoardInfo(ccPlane* pPlane,hdmap_proto::Board* pBoard,int nID);

	bool addLanemarkingInfo(ccPolyline* pPolygonLine,hdmap_proto::LaneMarking* pLaneMarking,int nID);
//
	bool addParkingSpaceInfo(ccPolyline* pDPXLine,hdmap_proto::ParkingSpace* pParkingSpace,int nID);
//	//斑马线信息
	bool addCrossWalkInfo(ccPolyline* pDPXLine,hdmap_proto::CrossWalk* pCrossWalk,int nID);
//
//	//Junction信息
	bool addJunctionInfo(ccPolyline* pDPXine,hdmap_proto::Junction* pJunction);

	bool getRelatedPlaneBorderPts(ccPolyline* pLine,vector<CCVector3>& vecBorderPts);
//
	void  ccLine2ProtoCurveLine(ccPolyline* pCCLine,hdmap_proto::CurveLine* pCurveLine);
//	//Ctrl比率的点
//	CCVector3 getCtrlPercentPt(CCVector3 pt1,CCVector3 pt2);
};

#endif
