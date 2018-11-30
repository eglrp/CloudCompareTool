
//by duans 2018.8.10
#ifndef _DPX_PROTOBUF_READER_H_
#define _DPX_PROTOBUF_READER_H_
#pragma once

#include <ccPolyline.h>
#include <ccPlane.h>

#include "dpxMapDefine.h"
#include "dpxReader.h"

#include "../map_param/map.pb.h"
#include "../map_param/mapio.h"
using namespace hdmap_proto;

class  DPX_MAP_API dpxProtobufReader : public dpxReader
{
public:
	dpxProtobufReader();
	virtual ~dpxProtobufReader();

public:
	virtual bool ImportMap(dpxMap* pMap,const QString& strImportFile);
protected:
	//输出Section信息
//	bool OutPutSection(hdmap_proto::Section* pSection,dpxMap* pMap);
//	//输出其余信息
//	bool ImportOtherAll(hdmap_proto::Map& protoMap,dpxMap* pMap);
	//CrossWalks斑马线
	bool AddCrossWalks(hdmap_proto::Map& protoMap,ccHObject* pFatherObj);
//	//Junction路口
//	bool AddJunctions(hdmap_proto::Map& protoMap,ccHObject* pFatherObj);
//	//停车位
	bool AddParkingSpace(hdmap_proto::Map& protoMap,ccHObject* pFatherObj);
//	//设置refLine的几何和属性信息
//	bool AddRefLineInfor(hdmap_proto::Lane* reflane,ccPointCloud* p3DVertices,ccPolyline* pCCRefLine);
//	//添加RoadLines
//	bool AddRoadLines(hdmap_proto::Section* pSection,ccHObject* pFatherObj);
//	//添加StopLines
//	bool AddStopLineInfor(hdmap_proto::StopLine* pStopLine,ccPointCloud* p3DVertices,ccPolyline* pCCStopLine);
	//添加Poles
	bool AddPoleInfor(hdmap_proto::Pole* pPole,ccPointCloud* p3DVertices,ccPolyline* pBorderLine);
	bool AddtrafficLightInfor(hdmap_proto::TrafficLight*ptrafficLight,ccPointCloud* p3DVertices,ccPolyline* pCCPoleLine);
	bool AddtrafficSignInfor(hdmap_proto::TrafficSign*ptrafficSign,ccPointCloud* p3DVertices,ccPolyline* pCCSignLine);

	bool AddSpeedbumpInfor(hdmap_proto::SpeedBump* pSpeedBump,ccPointCloud* p3DVertices,ccPolyline* pCCLine);
	bool AddBoardInfor(hdmap_proto::Board* pBoard,ccPointCloud* p3DVertices,ccPolyline* pCCLine);

	bool AddLaneMarkingInfor(hdmap_proto::LaneMarking* pLaneMarking,ccPointCloud* p3DVertices,ccPolyline* pCCLine);
private:

	bool CreateBorderLine(hdmap_proto::Polygon* pPolygon,ccPointCloud* p3DVertices,ccPolyline* pBorderLine);
//	bool getPtsFromSegment(hdmap_proto::LineSegment* pSegment,CCVector3& ptFirst,CCVector3& ptSecond);
	void getRDisPt(CCVector3 ptFirst,CCVector3 ptSecond,double dDis,CCVector3& RDisPt);//求取圆柱曲面上一个点
//	//把ProtoLane的控制点信息转成CCLine
//	bool ProtoLane2CCLine(hdmap_proto::Lane* pLane,ccPointCloud* p3DVertices,ccPolyline* pLine);
//	bool ConfimObjType(ccPolyline* pLine,dpxObjectType eType);
};

#endif
