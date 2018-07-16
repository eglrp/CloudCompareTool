
//by duans 2018.6.20
#ifndef _DPX_MAP_COMMON_DEFINE_H_
#define _DPX_MAP_COMMON_DEFINE_H_
#pragma once

#include "dpxMap_IO.h"

#define DPX_GEOENGINE_IMPLEMENT(engineName) \
	dpxGeoEngine* engineName = dpxGeoEngine::Instance();\

#define HDMAP_NAME 				"HD_Map"			//地图名称
#define ROAD_LAYER_NAME 		"HD_Road" 			//道路
#define LIGHT_LAYER_NAME 		"HD_Light"		   	//路灯
#define INDICATOR_LAYER_NAME 	"HD_Indicator"  	//指示牌
#define OTHER_NAME 				"HD_Other"  		//其它

//metedata key  地图及图层需要设置类型Key
#define  DPX_LAYER_TYPE_NAME  "dpxLyrType"
#define  DPX_OBJECT_TYPE_NAME  "dpxObjectType"

#define  REF_LINE_COLOR  (255,0,255)
#define  ROAD_LINE_COLOR  (255,165,0)
#define  STOP_LINE_COLOR  (160,32,240)
enum DPX_MAP_API dpxLayerType
{
	eOT_Unknown,	//未知

	//容器结构
	eOT_Map,		//地图
	eOT_Layer,		//图层

	//具体类型
	eOT_Road,		//道路
	eOT_Light,		//路灯
	eOT_Indicator,  //指示牌
	eOT_Other   	//其它
	//补充..
};

enum DPX_MAP_API dpxObjectType
{
	eObj_Unknown,	//未知

	//具体类型
	eObj_RoadRefLine,	//参照线
	eObj_RoadLine,		//道路
	eObj_RoadStopLine,	//路灯

	eObj_Other   		//其它
	//补充..
};


#endif
