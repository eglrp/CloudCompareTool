//class name:dpxCylinder
//brif:平面采集工具
//

#ifndef _dpx_NodeEdit_Tool_
#define _dpx_NodeEdit_Tool_

//qCC_db
#include "dpxEditTool.h"
#include "ccPolyline.h"
#include "ccGLWindow.h"
#include "ccSphere.h"
#include "dpxAlgorithmFun.h"
//#include "ccTrace.h"

/*
Tool used to digitise traces
*/
class dpxNodeEditTool : public dpxEditTool
{
public:
	dpxNodeEditTool();
	virtual ~dpxNodeEditTool();

public:
		//called when the tool is set to active (for initialization)
	virtual void toolActivated();
	//called when the tool is disactivated by a tool change or similar
	virtual void toolDisactivated();
	//called when a point in a point cloud gets picked while this tool is active
	virtual void pointPicked(ccHObject* insertPoint, unsigned itemIdx, ccPointCloud* cloud, const CCVector3& P,int x=0,int y=0);
	//鼠标移动事件
	virtual void onMouseMove(int x, int y, Qt::MouseButtons buttons);
	//右键事件
	virtual void onMouseRightClick(int x,int y);

protected:

	//! 2D polyline (for the currently edited part)
	ccPolyline* m_polyTip;
	//! 2D polyline vertices
	ccPointCloud* m_polyTipVertices;
	//by duans 采集的线都挂在该节点上，使得所有线放一个节点上
	ccHObject* m_pPickRoot;
	//finishes and finalises the trace currently being digitised to
	ccGLWindow* m_associatedWin;

	ccSphere* m_pSphere;
	ccHObject* m_pSelectShowRoot;
};

#endif
