//by duans
#include "dpxTrafficSignTool.h"


dpxTrafficSignTool::dpxTrafficSignTool()
{
	m_pPickRoot = new ccHObject("TrafficSign");
	m_pPickRoot->setMetaData(DPX_LAYER_TYPE_NAME,0);
	m_pAssistWin = nullptr;
	m_nCreateType = 0; //0代表拟合到方式1：代表采集到方式

	//特殊定制
	m_strccHobjectName = "TrafficSignPlane";
	m_eCurObjType = eObj_TrafficSign;//默认初始采集到是红绿灯
	m_strImageName = ":/CC/images/TrafficSign.png";
	m_eTargetLayerType = eOT_TrafficSign;
}

