//class name:dpxCylinder
//brif:选择工具
//

#ifndef _DPX_SELECT_TOOL_HEADER_
#define _DPX_SELECT_TOOL_HEADER_

//qCC_db
#include <ccHObject.h>
#include <ccGenericGLDisplay.h>


#include "dpxNodeEditTool.h"

class ccPolyline;
class ccPointCloud;
class ccGLWindow;
class ccPickingHub;

class dpxSelectTool : public dpxNodeEditTool
{
public:
	dpxSelectTool();
	virtual ~dpxSelectTool();

	//called when a point in a point cloud gets picked while this tool is active
	void pointPicked(ccHObject* insertPoint, unsigned itemIdx, ccPointCloud* cloud, const CCVector3& P,int x=0,int y=0) override;
};

#endif
