
//by duans 2018.6.20
#ifndef _DPX_MAP_COMMON_DEFINE_H_
#define _DPX_MAP_COMMON_DEFINE_H_
#pragma once

#include "dpxMap_IO.h"

#define DPX_GEOENGINE_IMPLEMENT(engineName) \
	dpxGeoEngine* engineName = dpxGeoEngine::Instance();\

#define HDMAP_NAME 				"HD_Map"			//地图名称
#define ROAD_LAYER_NAME 		"HD_SectionHub" 			//道路
#define LIGHT_LAYER_NAME 		"HD_Light"		   	//路灯
#define INDICATOR_LAYER_NAME 	"HD_Indicator"  	//指示牌
#define CROSS_WALK_LAYER_NAME 	"HD_CrossWalk"  	//斑马线
#define STOP_LINE_NAME 			"HD_StopLine"  		//停止线
#define SPEED_BUMP_NAME 		"HD_SpeenBump"  	//减速带
#define PARKING_SPACE_NAME 		"HD_ParkingSpace"  	//停车位
#define LANE_MARKING_NAME 		"HD_LaneMarking"  	//路面标识
#define BOARD_NAME				"HD_Board"			//其它面板
#define JUNCTION_NAME			"HD_Junction"		//Junction连接关系
#define OTHER_NAME 				"HD_Other"  		//其它

#define HEAD_JUNCTION_UID		"Head_JunctionUID"
#define TAIL_JUNCTION_UID		"Tail_JunctionUID"
#define RELATED_REFLINE_UID		"Related_RefLineUID"

//metedata key  地图及图层需要设置类型Key
#define  DPX_LAYER_TYPE_NAME  "dpxLyrType"
#define  DPX_OBJECT_TYPE_NAME  "dpxObjectType"

#define  REF_LINE_COLOR  (255,0,255)
#define  ROAD_LINE_COLOR  (255,165,0)
#define  STOP_LINE_COLOR  (160,32,240)
#define  ZEBAR_CROSS_LINE_COLOR  (255,255,255)


#define DPX_CYLINEDER_RELATED_UID  "relatedCylinderID"
#define DPX_RELATED_PLANE_UID  "relatedPlaneUID"
#define DPX_UID  "DPX_UID"
#define DPX_NORMAL  "Normal"
#define DPX_RADIUS  "dpxRadius"

#define DPX_CTRL_PERCENT  0.23 //控制点占的比例
enum DPX_MAP_API dpxLayerType
{
	eOT_Unknown,		//未知
	//容器结构
	eOT_Map,			//地图
	eOT_Layer,			//图层

	//具体类型
	eOT_Road,			//道路
	eOT_TrafficLight,	//路灯
	eOT_TrafficSign,  	//指示牌
	eOT_LaneMarking,	//路面标识
	eOT_CrossWalk,  	//斑马线
	eOT_StopLine,  		//停止线，既属于Section又属于Map
	eOT_SpeedBump,  	//减速带，既属于Section又属于Map
	eOT_ParkingSpace,	//停车位
	eOT_Board,			//其它边界
	eOT_Junction,		//连接
	eOT_Other   		//其它
	//补充..
};

enum DPX_MAP_API dpxObjectType
{
	eObj_Unknown,			//未知
	//道路线
	eObj_RoadRefLine,		//参照线
	eObj_RoadLine,			//道路
	eObj_RoadStopLine,		//停止线
	eObj_CrossWalkLine,		//斑马线

	//红绿灯柱子
	eObj_TrafficLight_pole,	//红绿灯柱子

	//面状指示牌
	eObj_TrafficLight,		//红绿灯牌
	eObj_TrafficSign,		//其它交通指示牌
	eObj_LaneMarking,		//路面标识

	eObj_SpeedBump,  		//减速带，既属于Section又属于Map
	//复杂类型
	eObj_ParkingSpace,		//停车位
	eObj_Board,				//Section的边界
	eObj_Junction,			//连接区域junction
	eObj_Section,			//Section部分
	eObj_RoadRefLineSet,	//RefLineSet
	eObj_RoadLineSet,		//Section部分
	eObj_DashedSymbol,		//虚线符号的线
	//其它
	eObj_Other   			//其它
	//补充..
};


#endif
