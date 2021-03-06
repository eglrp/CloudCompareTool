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

//Qt
#include <QFileDialog>
#include <QFileInfo>

#include <ccPickingHub.h>

#include "ccCompass.h"
#include "ccCompassDlg.h"
#include "ccCompassInfo.h"

#include "ccFitPlaneTool.h"

#include <QThread>
#include <QMessageBox>
#include "dpxProtobufWriter.h"
#include "dpxGeoEngine.h"
#include "dpxMapManager.h"
#include "dpxThreadBase.h"//
#include "dpxTraceLineTool.h"//折线工具
#include "dpxCylinderTool.h"//圆柱工具
#include "dpxPlaneTool.h"//平面工具
#include "dpxSphereTool.h"//球采集工具
#include "dpxNodeEditTool.h"//节点编辑工具
#include "dpxSelectTool.h" //选择工具

#include "dpxRoadRefLineTool.h" //道路参考线
#include "dpxRoadLineTool.h"  //道路线工具
#include "dpxRoadStopLineTool.h"//道路停止线
#include "dpxCrossWalkTool.h"//斑马线采集工具
#include "dpxMeasureTool.h"
#include "dpxTrafficSignTool.h"
#include "dpxLaneMarkingTool.h"
#include "dpxParkingSpaceTool.h"
#include "dpxJunctionTool.h"
#include "dpxLineBreakTool.h"
#include "dpxLaneMarkingCopyTool.h"
//int ccCompass::mapTo = ccGeoObject::LOWER_BOUNDARY;
const int nMsecod = 60*1000; //60 seconds per output

ccCompass::ccCompass(QObject* parent) :
	QObject( parent )
  , ccStdPluginInterface( ":/CC/plugin/qCompass/info.json" )
  , m_action( nullptr )
{
	//initialize all tools
	m_fitPlaneTool = new ccFitPlaneTool(); 					//拟合平面工具-old
	m_traceLineTool = new dpxTraceLineTool;  				//new dpxTraceLineTool();//新拓展折现工具

	m_dpxCylinderTool = new dpxCylinderTool();				//圆柱工具
	m_dpxLightPlaneTool = new dpxTrafficLightPlaneTool();	//矩形工具
	m_dpxSphereTool = new dpxSphereTool();					//球采集工具
	m_dpxNodeEditTool = new dpxNodeEditTool();				//节点编辑工具
	m_dpxSelectTool = new dpxSelectTool(); 					//选择工具

	m_dpxRoadRefLineTool = new dpxRoadRefLineTool(); 		//道路参考线工具
	m_dpxRoadLineTool = new dpxRoadLineTool(); 				//道路线工具
	m_dpxRoadStopLineTool = new dpxRoadStopLineTool();		//道路停止线工具
	m_dpxCrossWalkTool = new dpxCrossWalkTool();	//道路停止线工具
	m_dpxMeasureTool = new dpxMeasureTool();

	//5个新工具
	m_dpxSpeedBumpTool = new dpxSpeedBumpTool();
	m_dpxBoardTool = new dpxBoardTool();
	m_dpxTrafficSignTool = new dpxTrafficSignTool();
	m_dpxLaneMarkingTool = new dpxLaneMarkingToolV2();
	m_dpxParkingSpaceTool = new dpxParkingSpaceTool();
	m_dpxJunctionTool = new dpxJunctionTool();
	m_dpxLineBreakTool = new dpxLineBreakTool();
	m_dpxLaneMarkingCopyTool = new dpxLaneMarkingCopyTool();

	m_pTimer = new QTimer(this);
	connect(m_pTimer, SIGNAL(timeout()), this, SLOT(slotOnTimeOutPut()));
}

//deconstructor
ccCompass::~ccCompass()
{
	//delete all tools
	delete m_fitPlaneTool;
	delete m_traceLineTool;
	delete m_dpxCylinderTool;
	delete m_dpxLightPlaneTool;
	delete m_dpxSphereTool;
	delete m_dpxNodeEditTool;
	delete m_dpxSelectTool;
	delete m_dpxRoadRefLineTool;
	delete m_dpxRoadLineTool;
	delete m_dpxRoadStopLineTool;
	delete m_dpxCrossWalkTool;
	delete m_dpxMeasureTool;

	delete m_dpxSpeedBumpTool;
	delete m_dpxBoardTool;
	delete m_dpxTrafficSignTool;
	delete m_dpxLaneMarkingTool;
	delete m_dpxParkingSpaceTool;
	delete m_dpxJunctionTool;
	delete m_dpxLineBreakTool;
	delete m_dpxLaneMarkingCopyTool;

	if (m_dlg)
		delete m_dlg;
}

void ccCompass::onNewSelection(const ccHObject::Container& selectedEntities)
{
	//disable the main plugin icon if no entity is loaded
	m_action->setEnabled(m_app && m_app->dbRootObject() && m_app->dbRootObject()->getChildrenNumber() != 0);

	if (!m_dlg)
	{
		return; //not initialized yet - ignore callback
	}

	if (m_activeTool)
	{
		m_activeTool->onNewSelection(selectedEntities); //pass on to the active tool
	}
}

//Submit the action to launch ccCompass to CC
void ccCompass::getActions(QActionGroup& group)
{
	//default action (if it has not been already created, it's the moment to do it)
	if (!m_action) //this is the action triggered by clicking the "Compass" button in the plugin menu
	{
		//here we use the default plugin name, description and icon,
		//but each action can have its own!
		m_action = new QAction(getName(), this);
		m_action->setToolTip(getDescription());
		m_action->setIcon(getIcon());

		//connect appropriate signal
		QObject::connect(m_action, SIGNAL(triggered()), this, SLOT(doAction())); //this binds the m_action to the ccCompass::doAction() function
	}
	group.addAction(m_action);

	m_app->dispToConsole("[ccCompass] ccCompass plugin initialized successfully.", ccMainAppInterface::STD_CONSOLE_MESSAGE);

}

//Called by CC when the plugin should be activated - sets up the plugin and then calls startMeasuring()
void ccCompass::doAction()
{
	assert(m_app);

	//首次启动 自动加载地图HDMap
    static bool bLoadMap = false;
    if(!bLoadMap)
    {
		//m_app->getMainWindow()->db();
		MainWindow* pMainWindow = MainWindow::TheInstance();
		ccDBRoot* pDBRootModel  = pMainWindow->db();
		if(pDBRootModel==nullptr)
			return ;

		pDBRootModel->addHDMap();
		bLoadMap = true;
    }

    //工具的初始化
	m_traceLineTool->initializeTool(m_app);
	m_fitPlaneTool->initializeTool(m_app);
	m_dpxCylinderTool->initializeTool(m_app);
	m_dpxLightPlaneTool->initializeTool(m_app);
	m_dpxSphereTool->initializeTool(m_app);
	m_dpxNodeEditTool->initializeTool(m_app);
	m_dpxSelectTool->initializeTool(m_app);

	m_dpxRoadRefLineTool->initializeTool(m_app);
	m_dpxRoadLineTool->initializeTool(m_app);
	m_dpxRoadStopLineTool->initializeTool(m_app);
	m_dpxCrossWalkTool->initializeTool(m_app);
	m_dpxMeasureTool->initializeTool(m_app);

	m_dpxSpeedBumpTool->initializeTool(m_app);
	m_dpxBoardTool->initializeTool(m_app);
	m_dpxTrafficSignTool->initializeTool(m_app);
	m_dpxLaneMarkingTool->initializeTool(m_app);
	m_dpxParkingSpaceTool->initializeTool(m_app);
	m_dpxJunctionTool->initializeTool(m_app);
	m_dpxLineBreakTool->initializeTool(m_app);
	m_dpxLaneMarkingCopyTool->initializeTool(m_app);

	//check valid window
	if (!m_app->getActiveGLWindow())
	{
		m_app->dispToConsole("[ccCompass] Could not find valid 3D window.", ccMainAppInterface::ERR_CONSOLE_MESSAGE);
		return;
	}

	//bind gui
	if (!m_dlg)
	{
		//bind GUI events
		m_dlg = new ccCompassDlg(m_app->getMainWindow());

		//general
		ccCompassDlg::connect(m_dlg->closeButton, SIGNAL(clicked()), this, SLOT(onClose()));
		ccCompassDlg::connect(m_dlg->undoButton, SIGNAL(clicked()), this, SLOT(onUndo()));

		//modes
		ccCompassDlg::connect(m_dlg->compassMode, SIGNAL(clicked()), this, SLOT(enableMeasureMode()));

		//tools
		ccCompassDlg::connect(m_dlg->pickModeButton, SIGNAL(clicked()), this, SLOT(setPick()));
		//ccCompassDlg::connect(m_dlg->pairModeButton, SIGNAL(clicked()), this, SLOT(setLineation()));
		ccCompassDlg::connect(m_dlg->planeModeButton, SIGNAL(clicked()), this, SLOT(setPlane()));
		//ccCompassDlg::connect(m_dlg->traceModeButton, SIGNAL(clicked()), this, SLOT(setTrace()));
		ccCompassDlg::connect(m_dlg->PolyLineButton, SIGNAL(clicked()), this, SLOT(setTraceLine()));
		ccCompassDlg::connect(m_dlg->CylinderButton, SIGNAL(clicked()), this, SLOT(setCylinderTool()));
		ccCompassDlg::connect(m_dlg->planeToolButton, SIGNAL(clicked()), this, SLOT(setLightPlaneTool()));
		ccCompassDlg::connect(m_dlg->sphereToolButton, SIGNAL(clicked()), this, SLOT(setSphereTool()));
		ccCompassDlg::connect(m_dlg->NodeEditButton, SIGNAL(clicked()), this, SLOT(setNodeEditTool()));
		ccCompassDlg::connect(m_dlg->SelectButton, SIGNAL(clicked()), this, SLOT(setSelectTool()));
		ccCompassDlg::connect(m_dlg->RoadRefLineButton, SIGNAL(clicked()), this, SLOT(setRoadRefLineTool()));
		ccCompassDlg::connect(m_dlg->RoadLineButton, SIGNAL(clicked()), this, SLOT(setRoadLineTool()));
		ccCompassDlg::connect(m_dlg->RoadStopLineButton, SIGNAL(clicked()), this, SLOT(setRoadStopLineTool()));
		ccCompassDlg::connect(m_dlg->CrossWalkButton, SIGNAL(clicked()), this, SLOT(setCrossWalkTool()));
		ccCompassDlg::connect(m_dlg->MeasureButton, SIGNAL(clicked()), this, SLOT(setMeasureTool()));

		ccCompassDlg::connect(m_dlg->SpeedBumpButton, SIGNAL(clicked()), this, SLOT(setSpeedBumpTool()));
		ccCompassDlg::connect(m_dlg->BoardButton, SIGNAL(clicked()), this, SLOT(setBoardTool()));
		ccCompassDlg::connect(m_dlg->TrafficSignButton, SIGNAL(clicked()), this, SLOT(setTrafficSignTool()));
		ccCompassDlg::connect(m_dlg->LaneMarkingButton, SIGNAL(clicked()), this, SLOT(setLaneMarkingTool()));
		ccCompassDlg::connect(m_dlg->ParkingSpaceButton, SIGNAL(clicked()), this, SLOT(setParkingSpaceTool()));
		ccCompassDlg::connect(m_dlg->JunctionButton, SIGNAL(clicked()), this, SLOT(setJunctionTool()));
		ccCompassDlg::connect(m_dlg->LineBreakButton, SIGNAL(clicked()), this, SLOT(setLineBreakTool()));
		ccCompassDlg::connect(m_dlg->LaneMarkingCopy, SIGNAL(clicked()), this, SLOT(setLaneMarkingCopyTool()));



		//传出 by duans
		ccCompassDlg::connect(m_dlg, SIGNAL(sigKeyPress(int)), this, SLOT( slotKeyPress(int)));
	}

	m_dlg->linkWith(m_app->getActiveGLWindow());

	//start in measure mode
	enableMeasureMode();

	//trigger selection changed
	onNewSelection(m_app->getSelectedEntities());

	//begin measuring
	startMeasuring();

	m_pTimer->start(nMsecod); // 60 seconds
}

//Begin measuring
bool ccCompass::startMeasuring()
{
	//check valid gl window
	if (!m_app->getActiveGLWindow())
	{
		//invalid pointer error
		m_app->dispToConsole("Error: ccCompass could not find the Cloud Compare window. Abort!", ccMainAppInterface::ERR_CONSOLE_MESSAGE);
		return false;
	}

	//setup listener for mouse events
	m_app->getActiveGLWindow()->installEventFilter(this);

	//refresh window
	m_app->getActiveGLWindow()->redraw(true, false);

	//start GUI
	m_app->registerOverlayDialog(m_dlg, Qt::TopRightCorner);
	m_dlg->start();

	//activate active tool
	if (m_activeTool)
	{
		m_activeTool->toolActivated();
	}

	return true;
}

//Exits measuring
bool ccCompass::stopMeasuring()
{
	//remove click listener
	if (m_app->getActiveGLWindow())
	{
		m_app->getActiveGLWindow()->removeEventFilter(this);
	}

	//reset gui
	cleanupBeforeToolChange();

	//stop picking
	stopPicking();

	//set active tool to null (avoids tools "doing stuff" when the gui isn't shown)
	m_activeTool = nullptr;

	//remove overlay GUI
	if (m_dlg)
	{
		m_dlg->stop(true);
		m_app->unregisterOverlayDialog(m_dlg);
	}
	//forget last measurement
	if (m_activeTool)
	{
		m_activeTool->cancel();
		m_activeTool->toolDisactivated();
	}

	//redraw
	if (m_app->getActiveGLWindow())
	{
		m_app->getActiveGLWindow()->redraw(true, false);
	}

	return true;
}

//registers this plugin with the picking hub
bool ccCompass::startPicking()
{
	if (m_picking) //already picking... don't need to add again
		return true;

	//activate "point picking mode"
	if (!m_app->pickingHub())  //no valid picking hub
	{
		m_app->dispToConsole("[ccCompass] Could not retrieve valid picking hub. Measurement aborted.", ccMainAppInterface::ERR_CONSOLE_MESSAGE);
		return false;
	}

	if (!m_app->pickingHub()->addListener(this, true, true))
	{
		m_app->dispToConsole("Another tool is already using the picking mechanism. Stop it first", ccMainAppInterface::ERR_CONSOLE_MESSAGE);
		return false;
	}

	m_picking = true;
	return true;
}

//removes this plugin from the picking hub
void  ccCompass::stopPicking()
{
	//stop picking
	if (m_app->pickingHub())
	{
		m_app->pickingHub()->removeListener(this);
	}

	m_picking = false;
}


//This function is called when a point is picked (through the picking hub)
void ccCompass::onItemPicked(const ccPickingListener::PickedItem& pi)
{
	pointPicked(pi.entity, pi.itemIndex, pi.clickPoint.x(), pi.clickPoint.y(), pi.P3D); //map straight to pointPicked function
}

//Process point picks
void ccCompass::pointPicked(ccHObject* entity, unsigned itemIdx, int x, int y, const CCVector3& P)
{
	if (!entity) //null pick
	{
		return;
	}

	//no active tool (i.e. picking mode) - set selected object as active
	if (!m_activeTool)
	{
		m_app->setSelectedInDB(entity, true);
		return;
	}

	//find relevant node to add data to
	ccHObject* parentNode = nullptr;

	if (parentNode != nullptr) //could not get insert point for some reason
	{
		parentNode->setEnabled(true);
	}

	//ensure what we are writing too is visible (avoids confusion if it is turned off...)

	//call generic "point-picked" function of active tool
	m_activeTool->pointPicked(parentNode, itemIdx, entity, P,x,y);

	//have we picked a point cloud?
	if (entity->isKindOf(CC_TYPES::POINT_CLOUD))
	{
		//get point cloud
		ccPointCloud* cloud = static_cast<ccPointCloud*>(entity); //cast to point cloud

		if (!cloud)
		{
			ccLog::Warning("[Item picking] Shit's fubar (Picked point is not in pickable entities DB?)!");
			return;
		}

		//pass picked point, cloud & insert point to relevant tool
		m_activeTool->pointPicked(parentNode, itemIdx, cloud, P,x,y);
	}

	//redraw
	m_app->updateUI();
	m_app->getActiveGLWindow()->redraw();
}

//快捷键的传入
void ccCompass::slotKeyPress(int nKey)
{
	if(m_activeTool==nullptr)
		return ;

	m_activeTool->onKeyPress(nKey);
}

//by duans 事件在此绑定非常重要
bool ccCompass::eventFilter(QObject* obj, QEvent* event)
{
	if(m_activeTool==nullptr)
		return false;

	//工具的鼠标事件
	QMouseEvent* mouseEvent = static_cast<QMouseEvent *>(event);
	if(mouseEvent==nullptr)
		return false;

	//duans
	bool bPushShiftKey = false;
	if (QApplication::keyboardModifiers() == Qt::ShiftModifier)
		bPushShiftKey = true;

	//void ccGLWindow::mouseDoubleClickEvent(QMouseEvent *event)
	const int x = mouseEvent->x();
	const int y = mouseEvent->y();
	Qt::MouseButtons button= mouseEvent->buttons();

	if (event->type() == QEvent::MouseButtonDblClick) //屏蔽掉显示窗口的双击事件
	{
		if (mouseEvent->buttons() == Qt::RightButton)
		{
			stopMeasuring();
			return true;
		}
		else if (mouseEvent->buttons() == Qt::LeftButton)
		{
			m_activeTool->onLeftDoubleClick(x,y);
			return true;
		}
	}//补充了鼠标移动事件
	else if (event->type() == QEvent::MouseMove)
	{
		//采集时摁着Shift键能实现视图漫游
		if(bPushShiftKey)
		{
			m_app->getActiveGLWindow()->mouseMoveEvent(mouseEvent);
		}

		m_activeTool->onMouseMove(x,y,button);
		return true;
	}
	else if (event->type() == QEvent::MouseButtonPress)
	{
		if (mouseEvent->buttons() == Qt::RightButton)
		{
			//采集时摁着Shift键能实现视图漫游
			if(bPushShiftKey)
			{
				m_app->getActiveGLWindow()->mousePressEvent(mouseEvent);
			}
			else//不摁Shift是处理工具事件
			{
				m_activeTool->onMouseRightClick(x,y);
			}
			return true;
		}
		else if(mouseEvent->buttons() == Qt::LeftButton)
		{
			m_activeTool->onMouseLeftClick(x,y);
			m_app->getActiveGLWindow()->mousePressEvent(mouseEvent);
			return true;
		}
	}
	else if (event->type() == QEvent::MouseButtonRelease)
	{
		//采集时摁着Shift键能实现视图漫游
		if(bPushShiftKey)
		{
			m_app->getActiveGLWindow()->mouseReleaseEvent(mouseEvent);
		}

		m_activeTool->onMouseReleaseEvent(x,y);
	}
	return false;
}

//exit this tool
void ccCompass::onClose()
{
	//cancel current action
	if (m_activeTool)
	{
		m_activeTool->cancel();
	}

	//finish measuring
	stopMeasuring();
}


//undo last plane
void ccCompass::onUndo()
{
	if (m_activeTool)
	{
		m_activeTool->undo();
	}
}

//called to cleanup pointers etc. before changing the active tool
void ccCompass::cleanupBeforeToolChange()
{
	//finish current tool
	if (m_activeTool)
	{
		m_activeTool->toolDisactivated();
	}

	//clear m_hiddenObjects buffer
	if (!m_hiddenObjects.empty())
	{
		for (int i : m_hiddenObjects)
		{
			ccHObject* o = m_app->dbRootObject()->find(i);
			if (o)
			{
				o->setVisible(true);
			}
		}
		m_hiddenObjects.clear();
		m_app->getActiveGLWindow()->redraw(false, false);
	}


	//uncheck/disable gui components (the relevant ones will be activated later)
	if (m_dlg)
	{
		//m_dlg->pairModeButton->setChecked(false);
		m_dlg->planeModeButton->setChecked(false);
		m_dlg->PolyLineButton->setChecked(false);
		//m_dlg->traceModeButton->setChecked(false);
		m_dlg->pickModeButton->setChecked(false);
		m_dlg->undoButton->setEnabled(false);
	}

	//check picking is engaged
	startPicking();
}

//activate lineation mode


void ccCompass::setActiveTool(ccTool* pActiveTool)
{
	//cleanup
	cleanupBeforeToolChange();

	//activate plane tool
	m_activeTool = pActiveTool;
	m_activeTool->toolActivated();

	//trigger selection changed
	onNewSelection(m_app->getSelectedEntities());

	//update GUI
	m_dlg->undoButton->setEnabled(m_activeTool->canUndo());
	m_app->getActiveGLWindow()->redraw(true, false);
}
//activate plane mode
void ccCompass::setPlane()
{
	setActiveTool(m_fitPlaneTool);
}

//activate trace mode
void ccCompass::setTraceLine()
{
	setActiveTool(m_traceLineTool);
}

void ccCompass::setCylinderTool()
{
	setActiveTool(m_dpxCylinderTool);
	//m_dlg->traceModeButton->setChecked(true);
}

void ccCompass::setLightPlaneTool()
{
	setActiveTool(m_dpxLightPlaneTool);
}

void ccCompass::setSphereTool()
{
	setActiveTool(m_dpxSphereTool);
}

void ccCompass::setNodeEditTool()
{
	setActiveTool(m_dpxNodeEditTool);
}

void ccCompass::setSelectTool()
{
	setActiveTool(m_dpxSelectTool);
}

void ccCompass::setRoadRefLineTool()
{
	setActiveTool(m_dpxRoadRefLineTool);
}

void ccCompass::setRoadLineTool()
{
	setActiveTool(m_dpxRoadLineTool);
}

void ccCompass::setRoadStopLineTool()
{
	setActiveTool(m_dpxRoadStopLineTool);
}

//斑马线采集工具
void ccCompass::setCrossWalkTool()
{
	setActiveTool(m_dpxCrossWalkTool);
}

//量测工具
void ccCompass::setMeasureTool()
{
	setActiveTool(m_dpxMeasureTool);
}


//activate the paint tool
void ccCompass::setPick()
{
	cleanupBeforeToolChange();

	m_activeTool = nullptr; //picking tool is default - so no tool class
	stopPicking(); //let CC handle picks now

	//hide point clouds
	hideAllPointClouds(m_app->dbRootObject());

	m_dlg->pickModeButton->setChecked(true);
	m_dlg->undoButton->setEnabled(false);
	m_app->getActiveGLWindow()->redraw(true, false);
}

void ccCompass::setSpeedBumpTool()
{
	setActiveTool(m_dpxSpeedBumpTool);
}
void ccCompass::setBoardTool()
{
	setActiveTool(m_dpxBoardTool);
}
void ccCompass::setTrafficSignTool()
{
	setActiveTool(m_dpxTrafficSignTool);
}
void ccCompass::setLaneMarkingTool()
{
	setActiveTool(m_dpxLaneMarkingTool);
}
void ccCompass::setParkingSpaceTool()
{
	setActiveTool(m_dpxParkingSpaceTool);
}

void ccCompass::setJunctionTool()
{
	setActiveTool(m_dpxJunctionTool);
}

void ccCompass::setLineBreakTool()
{
	setActiveTool(m_dpxLineBreakTool);
}

void ccCompass::setLaneMarkingCopyTool()
{
	setActiveTool(m_dpxLaneMarkingCopyTool);
}
//recurse and hide visisble point clouds
void ccCompass::hideAllPointClouds(ccHObject* o)
{
	if (o->isKindOf(CC_TYPES::POINT_CLOUD) & o->isVisible())
	{
		o->setVisible(false);
		m_hiddenObjects.push_back(o->getUniqueID());
		return;
	}

	for (unsigned i = 0; i < o->getChildrenNumber(); i++)
	{
		hideAllPointClouds(o->getChild(i));
	}
}

//enter or turn off map mode
void ccCompass::enableMeasureMode() //turns on/off map mode
{
	//m_app->dispToConsole("ccCompass: Changing to Compass mode. Measurements will be stored in the \"Measurements\" folder.", ccMainAppInterface::STD_CONSOLE_MESSAGE);
	m_dlg->compassMode->setChecked(true);
	m_app->getActiveGLWindow()->redraw(true, false);

	//turn off map mode dialog
	m_app->updateOverlayDialogsPlacement();
}

void outMapFunc()
{
	static int nNumber = 0;
	dpxMap* pCurrentMap = dpxGeoEngine::Instance()->GetMap();
	if(pCurrentMap==nullptr)
	{
		ccLog::Warning("no Map Find to output");
		return;
	}

	ccHObject* rootData = pCurrentMap->getRootData();
	if(rootData==nullptr)
	{
		ccLog::Warning("no Map rootData");
		return;
	}

	QString appPath = QCoreApplication::applicationDirPath();
	QString strTempPath = appPath + "/temp/";
	QDir tempDir(strTempPath);
    if(!tempDir.exists())
    {
       bool bSuccess = tempDir.mkpath(strTempPath);//创建多级目录
       if(!bSuccess)
       {
			QMessageBox::warning(nullptr, "waring" , "please creat 'temp' dir in the exe Dir!");
			return;
       }
	}

	QString  strFile =  strTempPath+ QString::number(nNumber)+ ".Prototemp";
	QFile file(strFile);
    if(file.exists())
		file.remove();

	ccLog::Warning("output temp" + strFile);

    dpxMapManager* pManager = new dpxMapManager();
    dpxProtobufWriter* pWriter = new dpxProtobufWriter();
    pManager->setWriter(pWriter);
    pManager->AutoOutPutMap2Protobuf(pCurrentMap,strFile);

    nNumber++;
    if(nNumber>19)
		nNumber = 0;
}

void ccCompass::slotOnTimeOutPut()
{
    //out map
	dpxThreadBase* pThread = new dpxThreadBase(outMapFunc);
    pThread->start();
}

