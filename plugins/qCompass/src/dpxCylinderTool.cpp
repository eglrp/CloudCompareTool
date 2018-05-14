//by duans

#include <QApplication>
#include <QMainWindow>
#include <QMessageBox>
#include <QDateTime>

#include "dpxCylinderTool.h"
#include "ccCompass.h"
#include "ccCylinder.h"
#include "ccCone.h"
#include "dpxAlgorithmFun.h"


dpxCylinderTool::dpxCylinderTool()
	: ccTool(),m_polyTip(0)
	, m_polyTipVertices(0)
	, m_poly3D(0)
	, m_poly3DVertices(0)
	, m_done(false)
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

	m_pPickRoot = new ccHObject("Cylinder");
	//validButton->setEnabled(false);
}


dpxCylinderTool::~dpxCylinderTool()
{
	if (m_polyTip)
		delete m_polyTip;

	if (m_poly3D)
		delete m_poly3D;
}

//called when the tool is set to active (for initialization)
void dpxCylinderTool::toolActivated()
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

void dpxCylinderTool::toolDisactivated()
{
	accept(); //accept any changes
	m_associatedWin->removeFromOwnDB(m_polyTip);
	//m_associatedWin->removeFromOwnDB(m_pPickRoot);
	//m_associatedWin->removeFromOwnDB(m_pPickRoot);
}

void dpxCylinderTool::onMouseMove(int x, int y, Qt::MouseButtons buttons)
{
	//ccLog::Warning(QString::number(x));
	int i = 0;
	updatePolyLineTip(x,y,buttons);
}

void dpxCylinderTool::onMouseRightClick(int x,int y)
{
	if (!m_poly3D || (QApplication::keyboardModifiers() & Qt::ControlModifier)) //CTRL + right click = panning
	{
		return;
	}

	unsigned vertCount = m_poly3D->size();
	if (vertCount < 2)
	{
		//discard this polyline
		resetLine();
	}
	else
	{
		m_poly3D->enableTempColor(false);
		m_poly3D->setDisplay(m_associatedWin); //just in case

		m_poly3D = 0;
		m_poly3DVertices = 0;

		resetLine(); //to update the GUI
	}
}

//called when a point in a point cloud gets picked while this tool is active
//pointPicked(pi.entity, pi.itemIndex, pi.clickPoint.x(), pi.clickPoint.y(), pi.P3D); //map straight to pointPicked function
void dpxCylinderTool::pointPicked(ccHObject* insertPoint, unsigned itemIdx, ccPointCloud* cloud, const CCVector3& P,int x/*=0*/,int y/*=0*/)
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
	if(nSize==0)//两点形成圆柱的轴线
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
			m_polyTip->setEnabled(false); //don't need to display it for now
		}
	}
	else if(nSize==1)//两点形成圆柱的轴线
	{
		//try to add one more point
		if (!m_poly3DVertices->reserve(m_poly3DVertices->size() + 1)
			||!m_poly3D->reserve(m_poly3DVertices->size() + 1))
		{
			ccLog::Error("Not enough memory");
			return;
		}

		m_poly3DVertices->addPoint(P);
		//m_secondPt = P;
		ccLog::Warning("P2 X:"+QString::number(P.x)+" Y:"+QString::number(P.y)+" Z:"+QString::number(P.z));
		m_poly3D->addPointIndex(m_poly3DVertices->size() - 1);

		m_polyTip->setEnabled(false);
	}
	else if(nSize ==2)//构造圆柱
	{
		CCVector3 pA = *(m_poly3D->getPoint(0));
		CCVector3 pB = *(m_poly3D->getPoint(1));

		ccLog::Warning("P3 X:"+QString::number(P.x)+" Y:"+QString::number(P.y)+" Z:"+QString::number(P.z));
		double dRadius = dpxAlgorithmFun::DistanceOfPointToLine(pA,pB,P);
		double dHeight = sqrt(pow((pA.x-pB.x),2.0) + pow((pA.y-pB.y),2.0) + pow((pA.z-pB.z),2.0));
		ccLog::Warning("dRadius:"+QString::number(dRadius));
		ccLog::Warning("dHeight:"+QString::number(dHeight));

//		//my func
//		CCVector3 vbefore(0,0,1);
//		CCVector3 vafter(pB.x-pA.x, pB.y-pA.y, pB.z-pA.z);
//
//		double* rotat = dpxAlgorithmFun::rotateMatrix(vbefore,vafter);
//		//平移矩阵参数
//		double* trans = dpxAlgorithmFun::translateMatrix((pA.x+pB.x)/2,(pA.y+pB.y)/2,(pA.z+pB.z)/2);
//		//旋转矩阵
//		ccGLMatrix rotatMatrx(rotat);
//		//平移矩阵
//		ccGLMatrix transMatrx(trans);
//		//平移加旋转变换
//		ccGLMatrix transM = transMatrx * rotatMatrx;
//
//		//转换后的误差统计
//		CCVector3 TopResult = transM * CCVector3(0,0,dHeight/2);
//		ccLog::Warning("X offset:"+QString::number(TopResult.x-pB.x));
//		ccLog::Warning("Y offset:"+QString::number(TopResult.y-pB.y));
//		ccLog::Warning("Z offset:"+QString::number(TopResult.z-pB.z));
//
//		CCVector3 BottomResult = transM * CCVector3(0,0,-dHeight/2);
//		ccLog::Warning("X offset:"+QString::number(BottomResult.x-pA.x));
//		ccLog::Warning("Y offset:"+QString::number(BottomResult.y-pA.y));
//		ccLog::Warning("Z offset:"+QString::number(BottomResult.z-pA.z));

		//CC system Func
///////////////////////////////////////////////
		CCVector3 vbefore(0,0,1);
		CCVector3 vafter(pB.x-pA.x, pB.y-pA.y, pB.z-pA.z);
		ccGLMatrix transM = ccGLMatrix::FromToRotation(vbefore,dpxAlgorithmFun::NormalVec(vafter));
		CCVector3 vecTrans((pA.x+pB.x)/2,(pA.y+pB.y)/2,(pA.z+pB.z)/2);
		transM.setTranslation(vecTrans);
		//转换后的误差统计
		CCVector3 TopResult = transM * CCVector3(0,0,dHeight/2);
		ccLog::Warning("X offset:"+QString::number(TopResult.x-pB.x));
		ccLog::Warning("Y offset:"+QString::number(TopResult.y-pB.y));
		ccLog::Warning("Z offset:"+QString::number(TopResult.z-pB.z));

		CCVector3 BottomResult = transM * CCVector3(0,0,-dHeight/2);
		ccLog::Warning("X offset:"+QString::number(BottomResult.x-pA.x));
		ccLog::Warning("Y offset:"+QString::number(BottomResult.y-pA.y));
		ccLog::Warning("Z offset:"+QString::number(BottomResult.z-pA.z));
///////////////////////////////////////////////


		QDateTime current_time =QDateTime::currentDateTime();
		QString sCurrentTime =current_time.toString("hh:mm:ss");
		m_poly3D->setName("Line_"+sCurrentTime);
		m_poly3D->setMetaData("Radius",QString::number(dRadius));

		ccCylinder* pCylinder = new ccCylinder(dRadius,dHeight,&transM,"Cylinder"+sCurrentTime,24);
		//ccCone * pCone = new ccCone(dRadius,dRadius,dHeight,0,0,&transM,"Cylinder"+sCurrentTime,24);
		m_pPickRoot->addChild(pCylinder);

		//关闭采集
		onMouseRightClick(0,0);
	}

	m_associatedWin->redraw(false, false);
}

//called when "Return" or "Space" is pressed, or the "Accept Button" is clicked or the tool is disactivated
void dpxCylinderTool::accept()
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
void dpxCylinderTool::cancel()
{
}

void dpxCylinderTool::onNewSelection(const ccHObject::Container& selectedEntities)
{
}

//if this returns true, the undo button is enabled in the gui
bool dpxCylinderTool::canUndo()
{
	return true; //yes - we can undo!
}

//called when the undo button is clicked
void dpxCylinderTool::undo()
{
}

void dpxCylinderTool::exportLine()
{
}

//arguments for compatibility with ccGlWindow::rightButtonClicked signal
void dpxCylinderTool::updatePolyLineTip(int x, int y, Qt::MouseButtons buttons)
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

	if (!m_poly3DVertices || m_poly3DVertices->size() == 0 || m_poly3DVertices->size() >1)
	{
		//there should be at least one point already picked!
		return;
	}

	if (m_done)
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

	//just in case (e.g. if the view has been rotated or zoomed)
	//we also update the first vertex position!
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

void dpxCylinderTool::restart(bool reset)
{
	if (m_poly3D)
	{
		if (reset)
		{
			if (m_associatedWin)
			{
				//discard this polyline
				m_associatedWin->removeFromOwnDB(m_poly3D);
			}
			if (m_polyTip)
			{
				//hide the tip
				m_polyTip->setEnabled(false);
			}

			//delete m_poly3D;
			//m_segmentParams.clear();
			//delete m_poly3DVertices;
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
	m_done = false;
}
