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

#include "dpxPickAndEditTool.h"
#include "ccTrace.h"

class ccPolyline;
class ccPointCloud;
class ccGLWindow;
class ccPickingHub;

/*
Tool used to digitise traces
*/
class dpxTraceLineTool : public dpxPickAndEditTool
{
public:
	dpxTraceLineTool();
	virtual ~dpxTraceLineTool();

	virtual void toolActivated();
	//called when a point in a point cloud gets picked while this tool is active
	void pointPicked(ccHObject* insertPoint, unsigned itemIdx, ccPointCloud* cloud, const CCVector3& P,int x=0,int y=0) override;

	//右键事件
	virtual void onMouseRightClick(int x,int y) override;
	virtual void onLeftDoubleClick(int x,int y);

	virtual void onMouseMove(int x, int y, Qt::MouseButtons buttons);

	//! Oversamples the active 3D polyline
	ccPolyline* polylineOverSampling(unsigned steps) const;
};

#endif
