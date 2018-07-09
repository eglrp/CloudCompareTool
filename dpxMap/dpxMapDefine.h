
//by duans 2018.6.20
#ifndef _DPX_MAP_COMMON_H__
#define _DPX_MAP_COMMON_H__
#pragma once

#include "dpxMap_IO.h"
//#include "dpxGeoEngine.h"

#define DPX_GEOENGINE_IMPLEMENT(engineName) \
	dpxGeoEngine* engineName = dpxGeoEngine::Instance();\

#define HDMAP_NAME 				"HD_Map"			//地图名称
#define ROAD_LAYER_NAME 		"HD_Road" 			//道路
#define LIGHT_LAYER_NAME 		"HD_Light"		   	//路灯
#define INDICATOR_LAYER_NAME 	"HD_Indicator"  	//指示牌
#define OTHER_NAME 	"HD_Other"  		//其它

//metedata key  地图及图层需要设置类型Key
#define  DPX_TYPE_NAME  "dpxType"






/*
* dpxMapCommon
*/

#endif
