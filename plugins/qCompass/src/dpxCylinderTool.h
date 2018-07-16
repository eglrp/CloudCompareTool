//class name:dpxCylinder
//brif:圆柱采集工具
//

#ifndef _DPX_CYLINDER_TOOL_HEADER_
#define _DPX_CYLINDER_TOOL_HEADER_

//qCC_db
#include <ccHObject.h>
#include <ccGenericGLDisplay.h>


#include "dpxPickAndEditTool.h"

#define DPX_CYLINEDER_RELATED_UID  "relatedCylinderID"

class ccPolyline;
class ccPointCloud;
class ccGLWindow;
class ccPickingHub;

/*
Tool used to digitise traces
*/
class dpxCylinderTool :	public dpxPickAndEditTool
{
public:
	dpxCylinderTool();
	virtual ~dpxCylinderTool();

	virtual void toolActivated();
	//called when a point in a point cloud gets picked while this tool is active
	void pointPicked(ccHObject* insertPoint, unsigned itemIdx, ccPointCloud* cloud, const CCVector3& P,int x=0,int y=0) override;
	virtual void onMouseReleaseEvent(int x,int y);

	//右键取消正在采集的线
	virtual void onMouseRightClick(int x,int y);
};

#endif
