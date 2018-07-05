//class name:dpxPickAndEditTool
//brif:平面采集工具
//
//by duans 2018.7.4
#ifndef _DPX_PICK_AND_EDIT_TOOL_HEADER_
#define _DPX_PICK_AND_EDIT_TOOL_HEADER_

//qCC_db
#include <ccHObject.h>
#include <ccGenericGLDisplay.h>
#include <QImage>

#include "dpxNodeEditTool.h"

class ccPointCloud;
class ccGLWindow;
class ccPickingHub;

/*
Tool used to digitise traces
*/
class dpxPickAndEditTool :	public dpxNodeEditTool
{
public:
	dpxPickAndEditTool();
	virtual ~dpxPickAndEditTool();

	//called when the tool is set to active (for initialization)
	void toolActivated() override;

	//called when the tool is disactivated by a tool change or similar
	void toolDisactivated() override;

	//called when a point in a point cloud gets picked while this tool is active
	void pointPicked(ccHObject* insertPoint, unsigned itemIdx, ccPointCloud* cloud, const CCVector3& P,int x=0,int y=0) override;

	//鼠标左键事件
	virtual void onMouseLeftClick(int x,int y);

	virtual void onMouseMove(int x, int y, Qt::MouseButtons buttons);

	virtual void onMouseReleaseEvent(int x,int y);
	//右键事件
	virtual void onMouseRightClick(int x,int y){ }

	virtual void onLeftDoubleClick(int x,int y){ }

protected:

	//! 3D polyline
	ccPolyline* m_poly3D;
	//! 3D polyline vertices
	ccPointCloud* m_poly3DVertices;
	//by duans 采集的线都挂在该节点上，使得所有线放一个节点上
	ccHObject* m_pPickRoot;

	int m_nToolState;//tool state:pick  edit
};

#endif