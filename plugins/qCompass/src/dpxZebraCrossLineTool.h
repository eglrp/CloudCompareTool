
#ifndef _ZEBRA_CROSS_LINE_TOOL_HEADER_
#define _ZEBRA_CROSS_LINE_TOOL_HEADER_

//qCC_db
#include <ccHObject.h>

#include "dpxTraceLineTool.h"

/*
//斑马线工具
*/
class dpxZebraCrossLineTool : public dpxTraceLineTool
{
public:
	dpxZebraCrossLineTool();
	virtual ~dpxZebraCrossLineTool();

	virtual void toolActivated();
	void pointPicked(ccHObject* insertPoint, unsigned itemIdx, ccPointCloud* cloud, const CCVector3& P,int x=0,int y=0);
};

#endif
