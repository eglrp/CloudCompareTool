//class name:dpxCylinder
//brif:平面采集工具
//

#ifndef _DPX_LANE_MARKING_TOOL_HEADER_
#define _DPX_LANE_MARKING_TOOL_HEADER_

//qCC_db
#include <ccHObject.h>
#include "dpxPlaneToolBase.h"
#include "dpxMapDefine.h"
#include "dpxPickAndEditTool.h"

class dpxLaneMarkingTool : public dpxPlaneToolBase
{
	Q_OBJECT
public:
	dpxLaneMarkingTool();
	virtual ~dpxLaneMarkingTool() {}
};

//采用多边形
class dpxLaneMarkingToolV2 : public dpxPickAndEditTool
{
	Q_OBJECT
public:
	dpxLaneMarkingToolV2();
	virtual ~dpxLaneMarkingToolV2();

	virtual void toolActivated();


	void pointPicked(ccHObject* insertPoint, unsigned itemIdx, ccPointCloud* cloud, const CCVector3& P,int x=0,int y=0) override;

	//右键事件
	virtual void onMouseRightClick(int x,int y) override;
	virtual void onLeftDoubleClick(int x,int y);

	virtual void onMouseReleaseEvent(int x,int y) override;
	ccPolyline* ModefyPolyLine(ccPolyline* pOriginalLine);

protected:
	bool CheckSelectRefLine();
	bool m_bSetRefLine;
};

#endif
