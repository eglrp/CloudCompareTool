//##########################################################################
//#                                                                        #
//#                    CLOUDCOMPARE PLUGIN: ccCompass                      #
//#                                                                        #
//#  This program is free software; you can redistribute it and/or modify  #
//#  it under the terms of the GNU General Public License as published by  #
//#  the Free Software Foundation; version 2 of the License.               #
//#                                                                        #
//#  This program is distributed in the hope that it will be useful,       #
//#  but WITHOUT ANY WARRANTY; without even the implied warranty of        #
//#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         #
//#  GNU General Public License for more details.                          #
//#                                                                        #
//#                     COPYRIGHT: Sam Thiele  2017                        #
//#                                                                        #
//##########################################################################

#ifndef _DPX_TRACE_LINE_TOOL_HEADER_
#define _DPX_TRACE_LINE_TOOL_HEADER_

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
class dpxTraceLineTool :
	public ccTool
{
public:
	dpxTraceLineTool();
	virtual ~dpxTraceLineTool();

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

	//inherited from ccOverlayDialog
	void resetLine();
	void restart(bool reset);

	//! Oversamples the active 3D polyline
	ccPolyline* polylineOverSampling(unsigned steps) const;

protected:
	//finishes and finalises the trace currently being digitised to

	//! Viewport parameters (used for picking)
	struct SegmentGLParams
	{
		SegmentGLParams() {}
		SegmentGLParams(ccGenericGLDisplay* display, int x, int y);
		ccGLCameraParameters params;
		CCVector2d clickPos;
	};


	//! 2D polyline (for the currently edited part)
	ccPolyline* m_polyTip;
	//! 2D polyline vertices
	ccPointCloud* m_polyTipVertices;

	//! 3D polyline
	ccPolyline* m_poly3D;
	//! 3D polyline vertices
	ccPointCloud* m_poly3DVertices;

	//! Viewport parameters use to draw each segment of the polyline
	std::vector<SegmentGLParams> m_segmentParams;

	//! Current process state
	bool m_done;

	//by duans 采集的线都挂在该节点上，使得所有线放一个节点上
	ccHObject* m_pPickLinesRoot;

	ccGLWindow* m_associatedWin;

};

#endif
