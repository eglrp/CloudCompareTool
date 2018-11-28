//class name:dpxCylinder
//brif:平面采集工具
//

#ifndef _DPX_PLANE_TOOL_HEADER_
#define _DPX_PLANE_TOOL_HEADER_

//qCC_db
#include <ccHObject.h>
#include "dpxPlaneToolBase.h"
#include "dpxMapDefine.h"

class dpxTrafficLightPlaneTool : public dpxPlaneToolBase
{
	Q_OBJECT
public:
	dpxTrafficLightPlaneTool();
	virtual ~dpxTrafficLightPlaneTool() {}
};

class dpxSpeedBumpTool : public dpxPlaneToolBase
{
	Q_OBJECT
public:
	dpxSpeedBumpTool();
	virtual ~dpxSpeedBumpTool() {}
};

class dpxBoardTool : public dpxPlaneToolBase
{
	Q_OBJECT
public:
	dpxBoardTool();
	virtual ~dpxBoardTool() {}
};



//  repeated SpeedBump speedbumps = 7;
//  repeated Board boards = 9;





#endif
