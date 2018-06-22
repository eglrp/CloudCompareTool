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
//#include "ccTrace.h"
struct NodeInfo
{
	ccPolyline* m_pLine;
	int m_nNodeIndex;
	void clear()
	{
		m_pLine==nullptr;
		m_nNodeIndex=-1;
	}
	NodeInfo() {clear();}
};
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
	//鼠标左键事件
	virtual void onMouseLeftClick(int x,int y);
	//鼠标右键事件
	virtual void onMouseRightClick(int x,int y);

	virtual void onMouseReleaseEvent(int x,int y);

	virtual void onLeftDoubleClick(int x,int y);
protected:

	//! 2D polyline (for the currently edited part)
	ccPolyline* m_polyTip;
	//! 2D polyline vertices
	ccPointCloud* m_polyTipVertices;

	NodeInfo m_VNodeInfo;
	bool m_bMoveNode;
};

#endif
