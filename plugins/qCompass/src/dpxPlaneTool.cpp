//by duans
#include "dpxPlaneTool.h"

dpxTrafficLightPlaneTool::dpxTrafficLightPlaneTool()
{
	m_pPickRoot = new ccHObject("TrafficLight");
	m_pPickRoot->setMetaData(DPX_LAYER_TYPE_NAME,0);
	m_pAssistWin = nullptr;
	m_nCreateType = 0; //0代表拟合到方式1：代表采集到方式

	//特殊定制
	m_strccHobjectName = "TrafficLightPlane";
	m_eCurObjType = eObj_TrafficLight;//默认初始采集到是红绿灯
	m_strImageName = ":/CC/plugin/qCompass/images/RedGreen.png";
	m_eTargetLayerType = eOT_TrafficLight;
}


dpxSpeedBumpTool::dpxSpeedBumpTool()
{
	m_pPickRoot = new ccHObject("SpeedBump");
	m_pPickRoot->setMetaData(DPX_LAYER_TYPE_NAME,0);
	m_pAssistWin = nullptr;
	m_nCreateType = 0; //0代表拟合到方式1：代表采集到方式

	//特殊定制
	m_strccHobjectName = "SpeedBumpPlane";
	m_eCurObjType = eObj_SpeedBump;//默认初始采集到是红绿灯
	m_strImageName = ":/CC/images/SpeedBump.png";
	m_eTargetLayerType = eOT_SpeedBump;
}

dpxBoardTool::dpxBoardTool()
{
	m_pPickRoot = new ccHObject("Board");
	m_pPickRoot->setMetaData(DPX_LAYER_TYPE_NAME,0);
	m_pAssistWin = nullptr;
	m_nCreateType = 0; //0代表拟合到方式1：代表采集到方式

	//特殊定制
	m_strccHobjectName = "BoardPlane";
	m_eCurObjType = eObj_Board;
	m_strImageName = ":/CC/images/White.png";
	m_eTargetLayerType = eOT_Board;
}

