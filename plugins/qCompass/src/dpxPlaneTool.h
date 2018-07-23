//class name:dpxCylinder
//brif:平面采集工具
//

#ifndef _DPX_PLANE_TOOL_HEADER_
#define _DPX_PLANE_TOOL_HEADER_

//qCC_db
#include <ccHObject.h>
#include <ccGenericGLDisplay.h>
#include <QImage>
#include <QObject>

#include "dpxPickAndEditTool.h"
#include "dpxPlaneAssistDlg.h"


#define DPX_RELATED_UID  "relatedUID"
#define DPX_NORMAL  "Normal"
/*
Tool used to digitise traces
*/

class dpxPlaneTool : public dpxPickAndEditTool
{
	Q_OBJECT
public:
	dpxPlaneTool();
	virtual ~dpxPlaneTool();
public:
	virtual void toolActivated();
	virtual void toolDisactivated();
	//called when a point in a point cloud gets picked while this tool is active
	void pointPicked(ccHObject* insertPoint, unsigned itemIdx, ccPointCloud* cloud, const CCVector3& P,int x=0,int y=0) override;

	virtual void onMouseReleaseEvent(int x,int y);
	virtual void onMouseRightClick(int x,int y);

protected:
	void  PtFitPlane();
	void  PickMutilPts(const CCVector3& P ,int x,int y);
	void  ThreePtPick(const CCVector3& P ,int x,int y);

protected slots:
	void slotChangeType(int nType);


private:
	dpxPlaneAssistDlg* m_pAssistWin;
	int m_nCreateType; //是用采集还是用拟合到方式生成
};

#endif
