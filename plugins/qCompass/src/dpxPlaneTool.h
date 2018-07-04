//class name:dpxCylinder
//brif:平面采集工具
//

#ifndef _DPX_PLANE_TOOL_HEADER_
#define _DPX_PLANE_TOOL_HEADER_

//qCC_db
#include <ccHObject.h>
#include <ccGenericGLDisplay.h>
#include <QImage>


#include "dpxPickAndEditTool.h"

class ccPointCloud;
class ccGLWindow;
class ccPickingHub;
#define DPX_RELATED_UID  "relatedUID"
#define DPX_NORMAL  "Normal"
/*
Tool used to digitise traces
*/
class dpxPlaneTool : public dpxPickAndEditTool
{
public:
	dpxPlaneTool();
	virtual ~dpxPlaneTool();
public:
	//called when a point in a point cloud gets picked while this tool is active
	void pointPicked(ccHObject* insertPoint, unsigned itemIdx, ccPointCloud* cloud, const CCVector3& P,int x=0,int y=0) override;

	virtual void onMouseReleaseEvent(int x,int y);
};

#endif
