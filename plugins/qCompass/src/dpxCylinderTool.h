//class name:dpxCylinder
//brif:圆柱采集工具
//

#ifndef _DPX_CYLINDER_TOOL_HEADER_
#define _DPX_CYLINDER_TOOL_HEADER_

//qCC_db
#include <ccHObject.h>
#include <ccGenericGLDisplay.h>


#include "ccTool.h"
#include "ccTrace.h"

class ccPolyline;
class ccPointCloud;
class ccGLWindow;
class ccPickingHub;

/*
Tool used to digitise traces
*/
class dpxCylinderTool :
	public ccTool
{
public:
	dpxCylinderTool();
	virtual ~dpxCylinderTool();

	//called when the tool is set to active (for initialization)
	void toolActivated() override;

	//called when the tool is disactivated by a tool change or similar
	void toolDisactivated() override;

	//called when a point in a point cloud gets picked while this tool is active
	void pointPicked(ccHObject* insertPoint, unsigned itemIdx, ccPointCloud* cloud, const CCVector3& P,int x=0,int y=0) override;
	//鼠标移动事件
	void onMouseMove(int x, int y, Qt::MouseButtons buttons) override;

	//右键事件
	void onMouseRightClick(int x,int y) override;

	//called when a new selection is made
	void onNewSelection(const ccHObject::Container& selectedEntities) override;

	//called when "Return" or "Space" is pressed, or the "Accept Button" is clicked
	void accept() override;

	//called when the "Escape" is pressed, or the "Cancel" button is clicked
	void cancel() override;

	//if this returns true, the undo button is enabled in the gui
	bool canUndo() override;

	//called when the undo button is clicked
	void undo() override;

	//
	void exportLine();

	//void handlePickedItem(ccHObject*, unsigned, int, int, const CCVector3&);
	//void addPointToPolyline(int x, int y);
	void updatePolyLineTip(int x, int y, Qt::MouseButtons buttons);


	//inherited from ccOverlayDialog
	void resetLine() { restart(true); }
	void restart(bool reset);

protected:
	//finishes and finalises the trace currently being digitised to

	//! 2D polyline (for the currently edited part)
	ccPolyline* m_polyTip;
	//! 2D polyline vertices
	ccPointCloud* m_polyTipVertices;

	//! 3D polyline
	ccPolyline* m_poly3D;
	//! 3D polyline vertices
	ccPointCloud* m_poly3DVertices;


	//! Current process state
	bool m_done;

	//by duans 采集的线都挂在该节点上，使得所有线放一个节点上
	ccHObject* m_pPickRoot;

	ccGLWindow* m_associatedWin;

	//CCVector3 m_firstPt,m_secondPt;
	bool m_bSetRootData;
};

#endif
