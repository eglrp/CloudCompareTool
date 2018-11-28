//##########################################################################

#ifndef _DPX_JUNCTION_TOOL_HEADER_
#define _DPX_JUNCTION_TOOL_HEADER_

#include "dpxPickAndEditTool.h"


class dpxJunctionTool : public dpxPickAndEditTool
{
	Q_OBJECT
public:
	dpxJunctionTool();
	virtual ~dpxJunctionTool();

	virtual void toolActivated();
	//called when a point in a point cloud gets picked while this tool is active
	void pointPicked(ccHObject* insertPoint, unsigned itemIdx, ccPointCloud* cloud, const CCVector3& P,int x=0,int y=0) override;

	//右键事件
	virtual void onMouseRightClick(int x,int y) override;
	virtual void onLeftDoubleClick(int x,int y);

public slots:
	void slotAddPointToPolyline(int x, int y);

protected:
	CCVector2 GetScreen2D(CCVector3 pt3D,ccGLCameraParameters camera);
	int getUID(ccHObject* pHObject);
	QString getRefIDValue(const vector<int>& vecRefIDs);
};

#endif
