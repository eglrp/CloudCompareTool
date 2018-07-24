
#ifndef _ZEBRA_CROSS_LINE_TOOL_HEADER_
#define _ZEBRA_CROSS_LINE_TOOL_HEADER_

//qCC_db
#include <ccHObject.h>

#include "dpxPickAndEditTool.h"

/*
//斑马线工具
*/
class dpxZebraCrossLineTool : public dpxTraceLineTool
{
public:
	dpxZebraCrossLineTool();
	virtual ~dpxZebraCrossLineTool();

	virtual void toolActivated();
};

#endif
