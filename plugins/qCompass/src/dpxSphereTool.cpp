//by duans

#include <QApplication>
#include <QMainWindow>
#include <QMessageBox>
#include <QDateTime>

#include "dpxSphereTool.h"
#include "ccCompass.h"
#include "dpxAlgorithmFun.h"
#include <ccSphere.h>



dpxSphereTool::dpxSphereTool()
	: ccTool(),m_polyTip(0)
	, m_polyTipVertices(0)
{
	m_polyTipVertices = new ccPointCloud("Tip vertices");
	m_polyTipVertices->reserve(2);
	m_polyTipVertices->addPoint(CCVector3(0, 0, 0));
	m_polyTipVertices->addPoint(CCVector3(1, 1, 1));
	m_polyTipVertices->setEnabled(false);

	m_polyTip = new ccPolyline(m_polyTipVertices);
	m_polyTip->setForeground(true);
	m_polyTip->setTempColor(ccColor::green);
	m_polyTip->set2DMode(true);
	m_polyTip->reserve(2);
	m_polyTip->addPointIndex(0, 2);
	m_polyTip->setWidth(1); //'1' is equivalent to the default line size
	m_polyTip->addChild(m_polyTipVertices);

	m_pPickRoot = new ccHObject("Plane");
	m_bHasSetFirstPt = false;
}


dpxSphereTool::~dpxSphereTool()
{
	if (m_polyTip)
		delete m_polyTip;
}

//called when the tool is set to active (for initialization)
void dpxSphereTool::toolActivated()
{
	m_associatedWin =m_window;

	assert(m_polyTip);

	QDateTime current_time =QDateTime::currentDateTime();
	QString sCurrentTime =current_time.toString("hh:mm:ss");
	//m_pPickRoot = new ccHObject("Cylinder_"+sCurrentTime);
	if (!m_associatedWin)
	{
		ccLog::Warning("[Trace Polyline Tool] No associated window!");
		return ;
	}

	m_associatedWin->setUnclosable(true);
	m_associatedWin->addToOwnDB(m_polyTip);
	m_polyTip->setEnabled(false);

	//duans
	m_associatedWin->addToOwnDB(m_pPickRoot);

	//m_associatedWin->setPickingMode(ccGLWindow::NO_PICKING);
	m_associatedWin->setInteractionMode(	ccGLWindow::TRANSFORM_CAMERA()
										|	ccGLWindow::INTERACT_SIG_RB_CLICKED
										|	ccGLWindow::INTERACT_CTRL_PAN
										|	ccGLWindow::INTERACT_SIG_MOUSE_MOVED);
	m_associatedWin->setCursor(Qt::CrossCursor);

	resetLine();
}

void dpxSphereTool::toolDisactivated()
{
	accept(); //accept any changes
	m_associatedWin->removeFromOwnDB(m_polyTip);
}

void dpxSphereTool::onMouseMove(int x, int y, Qt::MouseButtons buttons)
{
	//ccLog::Warning(QString::number(x));
	int i = 0;
	updatePolyLineTip(x,y,buttons);
}

//called when a point in a point cloud gets picked while this tool is active
//pointPicked(pi.entity, pi.itemIndex, pi.clickPoint.x(), pi.clickPoint.y(), pi.P3D); //map straight to pointPicked function
void dpxSphereTool::pointPicked(ccHObject* insertPoint, unsigned itemIdx, ccPointCloud* cloud, const CCVector3& P,int x/*=0*/,int y/*=0*/)
{
	if (!m_associatedWin)
	{
		assert(false);
		return;
	}
	if (!insertPoint)
		return;

	if(!m_bHasSetFirstPt)//两点形成圆柱的轴线
	{
		//we replace the first point of the tip by this new point
		{
			QPointF pos2D = m_associatedWin->toCenteredGLCoordinates(x, y);
			CCVector3 P2D(	static_cast<PointCoordinateType>(pos2D.x()),
							static_cast<PointCoordinateType>(pos2D.y()),
							0);

			CCVector3* firstTipPoint = const_cast<CCVector3*>(m_polyTipVertices->getPointPersistentPtr(0));
			*firstTipPoint = P2D;
		}
		m_bHasSetFirstPt = true;
		m_ccFirstPt = P;
		m_polyTip->setEnabled(true);
	}
	else if(m_bHasSetFirstPt)//构造平面
	{
		PointCoordinateType dRadius =sqrt((m_ccFirstPt.x-P.x)*(m_ccFirstPt.x-P.x) + (m_ccFirstPt.y-P.y)*(m_ccFirstPt.y-P.y)+(m_ccFirstPt.z-P.z)*(m_ccFirstPt.z-P.z));
		ccGLMatrix transM ;
		CCVector3 vecTrans(m_ccFirstPt.x,m_ccFirstPt.y,m_ccFirstPt.z);
		transM.setTranslation(vecTrans);

		ccSphere* pSphere = new ccSphere(dRadius,&transM);
		if (pSphere) //valid fit
		{
			//make plane to add to display
			pSphere->setVisible(true);
			pSphere->setSelectionBehavior(ccHObject::SELECTION_IGNORED);
			pSphere->setDisplay(m_app->getActiveGLWindow());
			m_pPickRoot->addChild(pSphere);
		}

		m_polyTip->setEnabled(false);
		//关闭采集
		onMouseRightClick(0,0);
		m_bHasSetFirstPt = false;
	}

	m_associatedWin->redraw(false, false);
}

//called when "Return" or "Space" is pressed, or the "Accept Button" is clicked or the tool is disactivated
void dpxSphereTool::accept()
{
	//finish trace
	if (m_associatedWin && m_pPickRoot)
	{
		m_associatedWin->removeFromOwnDB(m_pPickRoot);
	}
	if (m_app->getMainWindow() && m_pPickRoot)
	{
		m_app->addToDB(m_pPickRoot);
	}
	else
	{
		assert(false);
	}

	resetLine(); //to update the GUI
}

//called when the "Escape" is pressed, or the "Cancel" button is clicked
void dpxSphereTool::cancel()
{
}

void dpxSphereTool::onNewSelection(const ccHObject::Container& selectedEntities)
{
}

//if this returns true, the undo button is enabled in the gui
bool dpxSphereTool::canUndo()
{
	return true; //yes - we can undo!
}

//called when the undo button is clicked
void dpxSphereTool::undo()
{
}

void dpxSphereTool::exportLine()
{
}

//arguments for compatibility with ccGlWindow::rightButtonClicked signal
void dpxSphereTool::updatePolyLineTip(int x, int y, Qt::MouseButtons buttons)
{
	if (!m_associatedWin)
	{
		assert(false);
		return;
	}

	if(!m_bHasSetFirstPt)
		return;

	if (buttons != Qt::NoButton)
	{
		//nothing to do (just hide the tip)
		if (m_polyTip->isEnabled())
		{
			m_polyTip->setEnabled(false);
			m_associatedWin->redraw(true, false);
		}
		return;
	}

	assert(m_polyTip);

	//we replace the last point by the new one
	{
		QPointF pos2D = m_associatedWin->toCenteredGLCoordinates(x, y);
		CCVector3 P2D(	static_cast<PointCoordinateType>(pos2D.x()),
						static_cast<PointCoordinateType>(pos2D.y()),
						0);

		CCVector3* lastP = const_cast<CCVector3*>(m_polyTipVertices->getPointPersistentPtr(1));
		*lastP = P2D;
	}

	//屏幕显示投影线
	{
		const CCVector3 P3D = m_ccFirstPt;

		ccGLCameraParameters camera;
		m_associatedWin->getGLCameraParameters(camera);

		CCVector3d A2D;
		camera.project(P3D, A2D);

		CCVector3* firstP = const_cast<CCVector3*>(m_polyTipVertices->getPointPersistentPtr(0));
		*firstP = CCVector3(static_cast<PointCoordinateType>(A2D.x - camera.viewport[2] / 2), //we convert A2D to centered coordinates (no need to apply high DPI scale or anything!)
							static_cast<PointCoordinateType>(A2D.y - camera.viewport[3] / 2),
							0);

	}

	m_polyTip->setEnabled(true);
	m_associatedWin->redraw(true, false);
}

void dpxSphereTool::resetLine()
{
	if (m_polyTip)
	{
		m_polyTip->setEnabled(false);
	}
	if (m_associatedWin)
	{
		m_associatedWin->redraw(false, false);
	}
}
