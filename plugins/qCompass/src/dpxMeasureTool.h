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

#ifndef _DPX_MEASURE_TOOL_HEADER_
#define _DPX_MEASURE_TOOL_HEADER_

//qCC_db

#include "dpxPickAndEditTool.h"
//量测工具

class dpxMeasureTool : public dpxPickAndEditTool
{
public:
	dpxMeasureTool();
	virtual ~dpxMeasureTool();

	virtual void toolActivated();
	virtual void toolDisactivated();

	void onMouseLeftClick(int x,int y) {}

	void onMouseRightClick(int x,int y) {}
	//called when a point in a point cloud gets picked while this tool is active
	void pointPicked(ccHObject* insertPoint, unsigned itemIdx, ccPointCloud* cloud, const CCVector3& P,int x=0,int y=0) override;
};

#endif
