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

#ifndef CC_TOOL_HEADER
#define CC_TOOL_HEADER

#include <QObject>

#include <ccHObject.h>
#include <ccPointCloud.h>
#include <ccMainAppInterface.h>
#include <ccGLWindow.h>

/*
Template class that defining the basic functionality of qCompass "tools".
*/
class ccTool : public QObject
{
	Q_OBJECT
public:

	virtual ~ccTool()
	{
	}

	void initializeTool(ccMainAppInterface* app)
	{
		m_app = app; //store copy of app
		m_window = m_app->getActiveGLWindow();
	}

	//called when the tool is set to active (for initialization)
	virtual void toolActivated() { }

	//called when the tool is set to disactive (for cleanup)
	virtual void toolDisactivated() { }

	//called when a point in a point cloud gets picked while this tool is active
	virtual void pointPicked(ccHObject* insertPoint, unsigned itemIdx, ccHObject* pickedObject, const CCVector3& P,int x=0,int y=0) { }

	//called when a point in a point cloud gets picked while this tool is active
	virtual void pointPicked(ccHObject* insertPoint, unsigned itemIdx, ccPointCloud* cloud, const CCVector3& P,int x=0,int y=0) { }

	//called when the selection is changed while this tool is active
	virtual void onNewSelection(const ccHObject::Container& selectedEntities) { }

	//by duans
	virtual void onMouseMove(int x, int y, Qt::MouseButtons buttons) { }
	//鼠标右键单击
	virtual void onMouseRightClick(int x,int y) { }
	//鼠标左单击
	virtual void onMouseLeftClick(int x,int y) { }
	//鼠标释放
	virtual void onMouseReleaseEvent(int x,int y) { }
	//鼠标双击
	virtual void onLeftDoubleClick(int x,int y) {}
	//键盘摁下
	virtual void onKeyPress(int key)  {}
	//键盘释放
	//virtual void onKeyRelease(int key) {}

	//called when "Return" or "Space" is pressed, or the "Accept Button" is clicked
	virtual void accept() { }

	//called when the "Escape" is pressed, or the "Cancel" button is clicked
	virtual void cancel() { }

	//if this returns true, the undo button is enabled in the gui
	virtual bool canUndo() { return false; }

	//called when the undo button is clicked
	virtual void undo()	{ }

	virtual QString GetToolName() { return "";}

	virtual QMainWindow* getMainWindow()
	{
		if(m_app!=nullptr)
			return m_app->getMainWindow();
		return nullptr;
	}

protected:

	ccTool() :
		m_app( nullptr )
	  , m_window( nullptr )
	{
	}

	//link to the main plugin interface
	ccMainAppInterface* m_app;

	//link to the active openGLWindow
	ccGLWindow*  m_window;
};

#endif
