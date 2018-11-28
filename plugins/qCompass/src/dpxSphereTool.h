//class name:dpxSphereTool
//brif:球采集工具
//

#ifndef _DPX_SPHERE_TOOL_HEADER_
#define _DPX_SPHERE_TOOL_HEADER_

//qCC_db
#include <ccHObject.h>
#include <ccGenericGLDisplay.h>


#include "ccTool.h"

class ccPointCloud;
class ccGLWindow;
class ccPickingHub;

/*
Tool used to digitise traces
*/
class dpxSphereTool :
	public ccTool
{
public:
	dpxSphereTool();
	virtual ~dpxSphereTool();

	//called when the tool is set to active (for initialization)
	void toolActivated() override;

	//called when the tool is disactivated by a tool change or similar
	void toolDisactivated() override;

	//called when a point in a point cloud gets picked while this tool is active
	void pointPicked(ccHObject* insertPoint, unsigned itemIdx, ccPointCloud* cloud, const CCVector3& P,int x=0,int y=0) override;
	//鼠标移动事件
	void onMouseMove(int x, int y, Qt::MouseButtons buttons) override;

	//右键事件
	//void onMouseRightClick(int x,int y) override;

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
	void resetLine();

protected:
	//finishes and finalises the trace currently being digitised to

	//! 2D polyline (for the currently edited part)
	ccPolyline* m_polyTip;
	//! 2D polyline vertices
	ccPointCloud* m_polyTipVertices;

	//by duans 采集的线都挂在该节点上，使得所有线放一个节点上
	ccHObject* m_pPickRoot;

	bool m_bHasSetFirstPt;
	CCVector3 m_ccFirstPt;
	ccGLWindow* m_associatedWin;
};

#endif
