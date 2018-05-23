//by duans

#include <QApplication>
#include <QMainWindow>
#include <QMessageBox>
#include <QDateTime>
#include <QDir>

#include "dpxPlaneTool.h"
#include "ccCompass.h"
#include "dpxAlgorithmFun.h"


dpxPlaneTool::dpxPlaneTool()
	: ccTool(),m_polyTip(0)
	, m_polyTipVertices(0)
	, m_poly3D(0)
	, m_poly3DVertices(0)
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
}


dpxPlaneTool::~dpxPlaneTool()
{
	if (m_polyTip)
		delete m_polyTip;

	if (m_poly3D)
		delete m_poly3D;
}

//called when the tool is set to active (for initialization)
void dpxPlaneTool::toolActivated()
{
	m_associatedWin =m_window;

	assert(m_polyTip);
	assert(!m_poly3D);

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

	//duans
	m_associatedWin->addToOwnDB(m_pPickRoot);

	//m_associatedWin->setPickingMode(ccGLWindow::NO_PICKING);
	m_associatedWin->setInteractionMode(	ccGLWindow::TRANSFORM_CAMERA()
										|	ccGLWindow::INTERACT_SIG_RB_CLICKED
										|	ccGLWindow::INTERACT_CTRL_PAN
										|	ccGLWindow::INTERACT_SIG_MOUSE_MOVED);
	m_associatedWin->setCursor(Qt::CrossCursor);

	restart(true);
}

void dpxPlaneTool::toolDisactivated()
{
	accept(); //accept any changes
	m_associatedWin->removeFromOwnDB(m_polyTip);
}

void dpxPlaneTool::onMouseMove(int x, int y, Qt::MouseButtons buttons)
{
	//ccLog::Warning(QString::number(x));
	int i = 0;
	updatePolyLineTip(x,y,buttons);
}

void dpxPlaneTool::onMouseRightClick(int x,int y)
{
	if (!m_poly3D || (QApplication::keyboardModifiers() & Qt::ControlModifier)) //CTRL + right click = panning
		return;

	m_poly3D = 0;
	m_poly3DVertices = 0;

	resetLine(); //to update the GUI

}

//called when a point in a point cloud gets picked while this tool is active
//pointPicked(pi.entity, pi.itemIndex, pi.clickPoint.x(), pi.clickPoint.y(), pi.P3D); //map straight to pointPicked function
void dpxPlaneTool::pointPicked(ccHObject* insertPoint, unsigned itemIdx, ccPointCloud* cloud, const CCVector3& P,int x/*=0*/,int y/*=0*/)
{
	if (!m_associatedWin)
	{
		assert(false);
		return;
	}
	if (!insertPoint)
		return;

	//if the 3D polyline doesn't exist yet, we create it
	if (!m_poly3D || !m_poly3DVertices)
	{
		m_poly3DVertices = new ccPointCloud();
		m_poly3DVertices->setEnabled(false);
		m_poly3DVertices->setDisplay(m_associatedWin);

		m_poly3D = new ccPolyline(m_poly3DVertices);
		m_poly3D->setTempColor(ccColor::green);
		m_poly3D->set2DMode(false);
		m_poly3D->addChild(m_poly3DVertices);
		m_poly3D->setWidth(1);

		//insertPoint->addChild(m_poly3D);
		m_pPickRoot->addChild(m_poly3D);
	}

	int nSize = m_poly3DVertices->size();
	if(nSize==0||nSize==1)//两点形成圆柱的轴线
	{
		//try to add one more point
		if (!m_poly3DVertices->reserve(m_poly3DVertices->size() + 1)
			||!m_poly3D->reserve(m_poly3DVertices->size() + 1))
		{
			ccLog::Error("Not enough memory");
			return;
		}

		m_poly3DVertices->addPoint(P);
		//m_firstPt = P;
		ccLog::Warning("P1 X:"+QString::number(P.x)+" Y:"+QString::number(P.y)+" Z:"+QString::number(P.z));
		m_poly3D->addPointIndex(m_poly3DVertices->size() - 1);

		//we replace the first point of the tip by this new point
		{
			QPointF pos2D = m_associatedWin->toCenteredGLCoordinates(x, y);
			CCVector3 P2D(	static_cast<PointCoordinateType>(pos2D.x()),
							static_cast<PointCoordinateType>(pos2D.y()),
							0);

			CCVector3* firstTipPoint = const_cast<CCVector3*>(m_polyTipVertices->getPointPersistentPtr(0));
			*firstTipPoint = P2D;
		}
	}
	else if(nSize ==2)//构造平面
	{
		CCVector3 PtA = *(m_poly3DVertices->getPoint(0));
		CCVector3 PtB = *(m_poly3DVertices->getPoint(1));
		CCVector3 PtC = P;
//		//P
//		CCVector3 ptP(AB[0]*dRadio+PtA.x,AB[1]*dRadio+PtA.y,AB[2]*dRadio+PtA.z);
		CCVector3 ptP  = dpxAlgorithmFun::PointProjectionToLine(PtA,PtB,PtC);
		CCVector3 ptQ(PtA.x-ptP.x+PtC.x,PtA.y-ptP.y+PtC.y,PtA.z-ptP.z+PtC.z);

		//四个点A P C Q
		ccPointCloud* pCloud  = new ccPointCloud("Plane Cloud");
		ccPolyline* Modefypoly3D = new ccPolyline(pCloud);
		pCloud->reserve(4);
		pCloud->addPoint(PtA);
		Modefypoly3D->addPointIndex(0);
		pCloud->addPoint(ptP);
		Modefypoly3D->addPointIndex(1);
		pCloud->addPoint(PtC);
		Modefypoly3D->addPointIndex(2);
		pCloud->addPoint(ptQ);
		Modefypoly3D->addPointIndex(3);

		Modefypoly3D->setTempColor(ccColor::red);
		Modefypoly3D->set2DMode(false);
		Modefypoly3D->addChild(pCloud);
		Modefypoly3D->setWidth(1);
		Modefypoly3D->setDisplay(m_associatedWin);

		m_pPickRoot->removeChild(m_poly3D);
		m_pPickRoot->addChild(Modefypoly3D);

		//Fit plane!
		double rms = 0.0; //output for rms
		ccFitPlane* pPlane = ccFitPlane::Fit(pCloud, &rms);
		if (pPlane) //valid fit
		{
			//make plane to add to display
			pPlane->setVisible(true);
			pPlane->setSelectionBehavior(ccHObject::SELECTION_IGNORED);
			pPlane->setDisplay(m_app->getActiveGLWindow());
			QImage* pImage = new QImage(":/CC/plugin/qCompass/images/RedGreen.png");
<<<<<<< HEAD
=======
			//QImage* pImage = new QImage("/home/ds/3rdPart/CloudCompareTool/qCC/images/RedGreen.png");
>>>>>>> 6e2bb27058cc3b930f7571bff0e8ffec5ff5da5c
			if(pImage)
			{
				pPlane->setAsTexture(*pImage);
			}
<<<<<<< HEAD
			CCVector3 vNormal = pPlane->getNormal();
			QString strNormal = QString::number(vNormal.x).append(" ").append(QString::number(vNormal.y)).append(" ").append(QString::number(vNormal.z));
			Modefypoly3D->setMetaData("Normal",strNormal);
=======
>>>>>>> 6e2bb27058cc3b930f7571bff0e8ffec5ff5da5c
			m_pPickRoot->addChild(pPlane);
		}

		m_polyTip->setEnabled(false);
		//关闭采集
		onMouseRightClick(0,0);
	}

	m_associatedWin->redraw(false, false);
}

//called when "Return" or "Space" is pressed, or the "Accept Button" is clicked or the tool is disactivated
void dpxPlaneTool::accept()
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
void dpxPlaneTool::cancel()
{
}

void dpxPlaneTool::onNewSelection(const ccHObject::Container& selectedEntities)
{
}

//if this returns true, the undo button is enabled in the gui
bool dpxPlaneTool::canUndo()
{
	return true; //yes - we can undo!
}

//called when the undo button is clicked
void dpxPlaneTool::undo()
{
}

void dpxPlaneTool::exportLine()
{
}

//arguments for compatibility with ccGlWindow::rightButtonClicked signal
void dpxPlaneTool::updatePolyLineTip(int x, int y, Qt::MouseButtons buttons)
{
	if (!m_associatedWin)
	{
		assert(false);
		return;
	}

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

	if (!m_poly3DVertices || m_poly3DVertices->size() == 0 || m_poly3DVertices->size() >2)
	{
		return;
	}

	assert(m_polyTip && m_polyTipVertices && m_polyTipVertices->size() == 2);

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
		const CCVector3* P3D = m_poly3DVertices->getPoint(m_poly3DVertices->size() - 1);

		ccGLCameraParameters camera;
		m_associatedWin->getGLCameraParameters(camera);

		CCVector3d A2D;
		camera.project(*P3D, A2D);

		CCVector3* firstP = const_cast<CCVector3*>(m_polyTipVertices->getPointPersistentPtr(0));
		*firstP = CCVector3(static_cast<PointCoordinateType>(A2D.x - camera.viewport[2] / 2), //we convert A2D to centered coordinates (no need to apply high DPI scale or anything!)
							static_cast<PointCoordinateType>(A2D.y - camera.viewport[3] / 2),
							0);

	}

	m_polyTip->setEnabled(true);
	m_associatedWin->redraw(true, false);
}

void dpxPlaneTool::restart(bool reset)
{
	if (m_poly3D)
	{
		if (reset)
		{
			if (m_polyTip)
			{
				m_polyTip->setEnabled(false);
			}

			m_poly3D = 0;
			m_poly3DVertices = 0;
		}
		else
		{
			if (m_polyTip)
			{
				//show the tip
				m_polyTip->setEnabled(true);
			}
		}
	}

	if (m_associatedWin)
	{
		m_associatedWin->redraw(false, false);
	}
}
