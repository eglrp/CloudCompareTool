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

#include <QApplication>
#include <QMainWindow>
#include <QMessageBox>

#include "dpxTraceLineTool.h"
#include "ccCompass.h"

dpxTraceLineTool::SegmentGLParams::SegmentGLParams(ccGenericGLDisplay* display, int x , int y)
{
	if (display)
	{
		display->getGLCameraParameters(params);
		QPointF pos2D = display->toCornerGLCoordinates(x, y);
		clickPos = CCVector2d(pos2D.x(), pos2D.y());
	}
}

dpxTraceLineTool::dpxTraceLineTool()
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

	//validButton->setEnabled(false);
	m_pPickLinesRoot = new ccHObject("Pick Lines");
}


dpxTraceLineTool::~dpxTraceLineTool()
{
	if (m_polyTip)
		delete m_polyTip;

	if (m_poly3D)
		delete m_poly3D;
}

//called when the tool is set to active (for initialization)
void dpxTraceLineTool::toolActivated()
{
	m_associatedWin =m_window;
	//try "pick-up" selected trace
	//onNewSelection(m_app->getSelectedEntities());
	assert(m_polyTip);
	assert(!m_poly3D);

	if (!m_associatedWin)
	{
		ccLog::Warning("[Trace Polyline Tool] No associated window!");
		return ;
	}

	m_associatedWin->setUnclosable(true);
	m_associatedWin->addToOwnDB(m_polyTip);

	//duans
	m_associatedWin->addToOwnDB(m_pPickLinesRoot);

	m_associatedWin->setInteractionMode(	ccGLWindow::TRANSFORM_CAMERA()
										|	ccGLWindow::INTERACT_SIG_RB_CLICKED
										|	ccGLWindow::INTERACT_CTRL_PAN
										|	ccGLWindow::INTERACT_SIG_MOUSE_MOVED);
	m_associatedWin->setCursor(Qt::PointingHandCursor);

	restart(true);
}

void dpxTraceLineTool::toolDisactivated()
{
	accept(); //accept any changes
}

void dpxTraceLineTool::onMouseMove(int x, int y, Qt::MouseButtons buttons)
{
	//ccLog::Warning(QString::number(x));
	int i = 0;
	updatePolyLineTip(x,y,buttons);
}

void dpxTraceLineTool::onMouseRightClick(int x,int y)
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
		unsigned overSampling = static_cast<unsigned>(/*oversampleSpinBox->value()*/1);
		if (overSampling > 1)
		{
			ccPolyline* poly = polylineOverSampling(overSampling);
			if (poly)
			{
				delete m_poly3D;
				m_segmentParams.clear();
				m_poly3DVertices = 0;
				m_poly3D = poly;
			}
		}

		m_poly3D->enableTempColor(false);
		m_poly3D->setDisplay(m_associatedWin); //just in case


		m_poly3D = 0;
		m_segmentParams.clear();
		m_poly3DVertices = 0;

		resetLine(); //to update the GUI
	}
}

//called when a point in a point cloud gets picked while this tool is active
//pointPicked(pi.entity, pi.itemIndex, pi.clickPoint.x(), pi.clickPoint.y(), pi.P3D); //map straight to pointPicked function
void dpxTraceLineTool::pointPicked(ccHObject* insertPoint, unsigned itemIdx, ccPointCloud* cloud, const CCVector3& P,int x/*=0*/,int y/*=0*/)
{
	if (!m_associatedWin)
	{
		assert(false);
		return;
	}
	//若上条线采集完了，重新采集一条线

	if (!insertPoint)
	{
		//means that the mouse has been clicked but no point was found!ŝ
		return;
	}

	//if the 3D polyline doesn't exist yet, we create it
	if (!m_poly3D || !m_poly3DVertices)
	{
		m_poly3DVertices = new ccPointCloud("Vertices");
		m_poly3DVertices->setEnabled(false);
		m_poly3DVertices->setDisplay(m_associatedWin);

		m_poly3D = new ccPolyline(m_poly3DVertices);
		m_poly3D->setTempColor(ccColor::green);
		m_poly3D->set2DMode(false);
		m_poly3D->addChild(m_poly3DVertices);
//		m_poly3D->setWidth(widthSpinBox->value() < 2 ? 0 : widthSpinBox->value()); //'1' is equivalent to the default line size
		m_poly3D->setWidth(1);

		m_segmentParams.clear(); //just in case

		//insertPoint->addChild(m_poly3D);
		m_pPickLinesRoot->addChild(m_poly3D);
	}

	//try to add one more point
	if (	!m_poly3DVertices->reserve(m_poly3DVertices->size() + 1)
		||	!m_poly3D->reserve(m_poly3DVertices->size() + 1))
	{
		ccLog::Error("Not enough memory");
		return;
	}

	try
	{
		m_segmentParams.reserve(m_segmentParams.size() + 1);
	}
	catch (const std::bad_alloc&)
	{
		ccLog::Error("Not enough memory");
		return;
	}

	m_poly3DVertices->addPoint(P);
	m_poly3D->addPointIndex(m_poly3DVertices->size() - 1);
	m_segmentParams.push_back(SegmentGLParams(m_associatedWin, x, y));

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

	m_associatedWin->redraw(false, false);
}

//called when "Return" or "Space" is pressed, or the "Accept Button" is clicked or the tool is disactivated
void dpxTraceLineTool::accept()
{
	//finish trace
	if (m_associatedWin)
	{
		m_associatedWin->removeFromOwnDB(m_pPickLinesRoot);
	}
	if (m_app->getMainWindow())
	{
		m_app->addToDB(m_pPickLinesRoot);
	}
	else
	{
		assert(false);
	}

	resetLine(); //to update the GUI
}

//called when the "Escape" is pressed, or the "Cancel" button is clicked
void dpxTraceLineTool::cancel()
{

}

void dpxTraceLineTool::onNewSelection(const ccHObject::Container& selectedEntities)
{
}


//if this returns true, the undo button is enabled in the gui
bool dpxTraceLineTool::canUndo()
{
	return true; //yes - we can undo!
}

//called when the undo button is clicked
void dpxTraceLineTool::undo()
{
}

void dpxTraceLineTool::exportLine()
{
}

//arguments for compatibility with ccGlWindow::rightButtonClicked signal
void dpxTraceLineTool::updatePolyLineTip(int x, int y, Qt::MouseButtons buttons)
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

	if (!m_poly3DVertices || m_poly3DVertices->size() == 0)
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

void dpxTraceLineTool::restart(bool reset)
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

			delete m_poly3D;
			m_segmentParams.clear();
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

ccPolyline* dpxTraceLineTool::polylineOverSampling(unsigned steps) const
{
	if (!m_poly3D || !m_poly3DVertices || m_segmentParams.size() != m_poly3DVertices->size())
	{
		assert(false);
		return 0;
	}

	if (steps <= 1)
	{
		//nothing to do
		return 0;
	}

	ccHObject::Container clouds;
	m_associatedWin->getSceneDB()->filterChildren(clouds, true, CC_TYPES::POINT_CLOUD, false, m_associatedWin);
	ccHObject::Container meshes;
	m_associatedWin->getSceneDB()->filterChildren(meshes, true, CC_TYPES::MESH, false, m_associatedWin);

	if (clouds.empty() && meshes.empty())
	{
		//no entity is currently displayed?!
		assert(false);
		return 0;
	}

	unsigned n_verts = m_poly3DVertices->size();
	unsigned n_segments = m_poly3D->size() - (m_poly3D->isClosed() ? 0 : 1);
	unsigned end_size = n_segments * steps + (m_poly3D->isClosed() ? 0 : 1);

	ccPointCloud* newVertices = new ccPointCloud();
	ccPolyline* newPoly = new ccPolyline(newVertices);
	newPoly->addChild(newVertices);

	if (	!newVertices->reserve(end_size)
		||	!newPoly->reserve(end_size) )
	{
		ccLog::Warning("[ccTracePolylineTool::PolylineOverSampling] Not enough memory");
		delete newPoly;
		return 0;
	}
	newVertices->importParametersFrom(m_poly3DVertices);
	newVertices->setName(m_poly3DVertices->getName());
	newVertices->setEnabled(m_poly3DVertices->isEnabled());
	newPoly->importParametersFrom(*m_poly3D);
	newPoly->setDisplay_recursive(m_poly3D->getDisplay());

//	QProgressDialog pDlg(QString("Oversampling"), "Cancel", 0, static_cast<int>(end_size), m_associatedWin ? m_associatedWin->asWidget() : 0);
//	pDlg.show();
	//QCoreApplication::processEvents();

	for (unsigned i = 0; i < n_segments; ++i)
	{
		const CCVector3* p1 = m_poly3DVertices->getPoint(i);
		newVertices->addPoint(*p1);

		unsigned i2 = (i + 1) % n_verts;
		CCVector2d v = m_segmentParams[i2].clickPos - m_segmentParams[i].clickPos;
		v /= steps;

		for (unsigned j = 1; j < steps; j++)
		{
			CCVector2d vj = m_segmentParams[i].clickPos + v * j;

			CCVector3 nearestPoint;
			double nearestElementSquareDist = -1.0;

			//for each cloud
			for (size_t c = 0; c < clouds.size(); ++c)
			{
				ccGenericPointCloud* cloud = static_cast<ccGenericPointCloud*>(clouds[c]);
				if (!cloud->isDisplayedIn(m_associatedWin))
				{
					continue;
				}

				int nearestPointIndex = -1;
				double nearestSquareDist = 0;
				if (cloud->pointPicking(vj,
										m_segmentParams[i2].params,
										nearestPointIndex,
										nearestSquareDist,
										1,
										1,
										true))
				{
					if (nearestElementSquareDist < 0 || nearestSquareDist < nearestElementSquareDist)
					{
						nearestElementSquareDist = nearestSquareDist;
						nearestPoint = *cloud->getPoint(nearestPointIndex);
					}
				}
			}

			//for each mesh
			for (size_t m = 0; m < meshes.size(); ++m)
			{
				ccGenericMesh* mesh = static_cast<ccGenericMesh*>(meshes[m]);
				if (!mesh->isDisplayedIn(m_associatedWin))
				{
					continue;
				}

				int nearestTriIndex = -1;
				double nearestSquareDist = 0;
				CCVector3d _nearestPoint;

				if (mesh->trianglePicking(	vj,
											m_segmentParams[i2].params,
											nearestTriIndex,
											nearestSquareDist,
											_nearestPoint))
				{
					if (nearestElementSquareDist < 0 || nearestSquareDist < nearestElementSquareDist)
					{
						nearestElementSquareDist = nearestSquareDist;
						nearestPoint = CCVector3::fromArray(_nearestPoint.u);
					}
				}
			}

			if (nearestElementSquareDist >= 0)
			{
				newVertices->addPoint(nearestPoint);
			}

//			if (pDlg.wasCanceled())
//			{
//				steps = 0; //quick finish ;)
//				break;
//			}
//			pDlg.setValue(pDlg.value() + 1);
		}
	}

	//add last point
	if (!m_poly3D->isClosed())
	{
		newVertices->addPoint(*m_poly3DVertices->getPoint(n_verts - 1));
	}

	newVertices->shrinkToFit();
	newPoly->addPointIndex(0, newVertices->size());

	return newPoly;
}
