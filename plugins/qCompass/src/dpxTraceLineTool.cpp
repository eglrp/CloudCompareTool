
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
	: dpxPickAndEditTool()
{
	m_pPickRoot = new ccHObject("Pick Lines");
}


dpxTraceLineTool::~dpxTraceLineTool()
{
	if (m_polyTip)
		delete m_polyTip;

	if (m_poly3D)
		delete m_poly3D;
}


void dpxTraceLineTool::toolDisactivated()
{
	m_segmentParams.clear();
	dpxPickAndEditTool::toolDisactivated();
}

void dpxTraceLineTool::onLeftDoubleClick(int x,int y)
{
	if(m_nToolState)//编辑状体
	{
        dpxNodeEditTool::onLeftDoubleClick(x,y);
	}
}

void dpxTraceLineTool::onMouseRightClick(int x,int y)
{
	if(m_nToolState)//编辑状体
	{
        dpxNodeEditTool::onMouseRightClick(x,y);
	}
	else//采集状态
	{
		if (!m_poly3D || (QApplication::keyboardModifiers() & Qt::ControlModifier)) //CTRL + right click = panning
			return;

		unsigned vertCount = m_poly3D->size();
		if (vertCount < 2)
		{
			if (m_polyTip)
				m_polyTip->setEnabled(false);

			m_segmentParams.clear();
			m_poly3D = 0;
			m_poly3DVertices = 0;
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
			m_poly3D->setDisplay(m_window); //just in case
			m_poly3D = 0;
			m_segmentParams.clear();
			m_poly3DVertices = 0;
			m_nToolState = 1;//右键停止采集，转为编辑状态
		}
		m_polyTip->setEnabled(false);
		m_window->removeFromOwnDB(m_pPickRoot);
		m_app->addToDB(m_pPickRoot);
	}
}

void dpxTraceLineTool::pointPicked(ccHObject* insertPoint, unsigned itemIdx, ccPointCloud* cloud, const CCVector3& P,int x/*=0*/,int y/*=0*/)
{
	if(m_nToolState)//编辑状体
		return;

	if (!m_window)
	{
		assert(false);
		return;
	}

	//if the 3D polyline doesn't exist yet, we create it
	if (!m_poly3D || !m_poly3DVertices)
	{
		m_poly3DVertices = new ccPointCloud("Vertices");
		m_poly3DVertices->setEnabled(false);
		m_poly3DVertices->setDisplay(m_window);

		m_poly3D = new ccPolyline(m_poly3DVertices);
		m_poly3D->setTempColor(ccColor::green);
		m_poly3D->set2DMode(false);
		m_poly3D->addChild(m_poly3DVertices);
		m_poly3D->setWidth(1);

		m_segmentParams.clear(); //just in case
		m_pPickRoot->addChild(m_poly3D);
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
	m_segmentParams.push_back(SegmentGLParams(m_window, x, y));

	//we replace the first point of the tip by this new point
	{
		QPointF pos2D = m_window->toCenteredGLCoordinates(x, y);
		CCVector3 P2D(	static_cast<PointCoordinateType>(pos2D.x()),
						static_cast<PointCoordinateType>(pos2D.y()),
						0);

		CCVector3* firstTipPoint = const_cast<CCVector3*>(m_polyTipVertices->getPointPersistentPtr(0));
		*firstTipPoint = P2D;
		m_polyTip->setEnabled(false); //don't need to display it for now
	}

	m_window->redraw(false, false);
}

void dpxTraceLineTool::onMouseMove(int x, int y, Qt::MouseButtons buttons)
{
	if (!m_window)
	{
		assert(false);
		return;
	}

	if(m_nToolState==0)//采集状态
	{
		if (!m_poly3DVertices || m_poly3DVertices->size() == 0)
			return;

		assert(m_polyTip && m_polyTipVertices && m_polyTipVertices->size() == 3);

		//we replace the last point by the new one
		{
			QPointF pos2D = m_window->toCenteredGLCoordinates(x, y);
			CCVector3 P2D(	static_cast<PointCoordinateType>(pos2D.x()),
							static_cast<PointCoordinateType>(pos2D.y()),
							0);

			CCVector3* Middle = const_cast<CCVector3*>(m_polyTipVertices->getPointPersistentPtr(1));
			*Middle = P2D;
		}

		{
			const CCVector3* P3D = m_poly3DVertices->getPoint(m_poly3DVertices->size() - 1);
			ccGLCameraParameters camera;
			m_window->getGLCameraParameters(camera);

			CCVector3d A2D;
			camera.project(*P3D, A2D);

			CCVector3 vec3(static_cast<PointCoordinateType>(A2D.x - camera.viewport[2] / 2), //we convert A2D to centered coordinates (no need to apply high DPI scale or anything!)
						   static_cast<PointCoordinateType>(A2D.y - camera.viewport[3] / 2),
							0);
			CCVector3* firstP = const_cast<CCVector3*>(m_polyTipVertices->getPointPersistentPtr(0));
			CCVector3* lastP = const_cast<CCVector3*>(m_polyTipVertices->getPointPersistentPtr(2));
			*firstP = vec3;
			*lastP = vec3;
		}

		m_polyTip->setEnabled(true);
		m_window->redraw(true, false);
	}
	else//编辑状态直接采用基类
	{
		return dpxNodeEditTool::onMouseMove(x,y,buttons);
	}
}

ccPolyline* dpxTraceLineTool::polylineOverSampling(unsigned steps) const
{
	if (!m_poly3D || !m_poly3DVertices || m_segmentParams.size() != m_poly3DVertices->size())
	{
		assert(false);
		return 0;
	}

	if (steps <= 1)
		return 0;

	ccHObject::Container clouds;
	m_window->getSceneDB()->filterChildren(clouds, true, CC_TYPES::POINT_CLOUD, false, m_window);
	ccHObject::Container meshes;
	m_window->getSceneDB()->filterChildren(meshes, true, CC_TYPES::MESH, false, m_window);

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
				if (!cloud->isDisplayedIn(m_window))
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
				if (!mesh->isDisplayedIn(m_window))
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
