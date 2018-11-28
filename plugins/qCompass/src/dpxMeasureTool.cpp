
#include <QApplication>
#include <QMainWindow>
#include <QMessageBox>

#include "dpxMeasureTool.h"
#include "dpxGeoEngine.h"


dpxMeasureTool::dpxMeasureTool()
{
	m_nToolState = 0;
	m_pPickRoot = new ccHObject("UnKnown");
}


dpxMeasureTool::~dpxMeasureTool()
{
	if (m_polyTip)
		delete m_polyTip;

	if (m_poly3D)
		delete m_poly3D;

	if(m_pPickRoot)
		delete m_pPickRoot;
}

void dpxMeasureTool::toolActivated()
{
	m_nToolState = 0;//编辑状态
	m_pPickRoot->removeAllChildren();
	m_window->addToOwnDB(m_pPickRoot);
	m_window->setCursor(Qt::CrossCursor);
	m_poly3D = 0;
	m_poly3DVertices = 0;
	dpxNodeEditTool::toolActivated();
}

void dpxMeasureTool::toolDisactivated()
{
	m_window->removeFromOwnDB(m_pPickRoot);
	dpxNodeEditTool::toolDisactivated();
}

void dpxMeasureTool::pointPicked(ccHObject* insertPoint, unsigned itemIdx, ccPointCloud* cloud, const CCVector3& P,int x/*=0*/,int y/*=0*/)
{
	//if the 3D polyline doesn't exist yet, we create it
	if (!m_poly3D || !m_poly3DVertices)
	{
		m_poly3DVertices = new ccPointCloud("Vertices");
		m_poly3DVertices->setEnabled(false);
		m_poly3DVertices->setDisplay(m_window);

		m_poly3D = new ccPolyline(m_poly3DVertices);
		m_poly3D->setTempColor(ccColor::yellow);
		m_poly3D->set2DMode(false);
		m_poly3D->addChild(m_poly3DVertices);
		m_poly3D->setWidth(1);

		m_pPickRoot->removeAllChildren();
		m_pPickRoot->addChild(m_poly3D);
	}

	//try to add one more point
	if (	!m_poly3DVertices->reserve(m_poly3DVertices->size() + 1)
		||	!m_poly3D->reserve(m_poly3DVertices->size() + 1))
	{
		ccLog::Error("Not enough memory");
		return;
	}


	m_poly3DVertices->addPoint(P);
	m_poly3D->addPointIndex(m_poly3DVertices->size() - 1);

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
	unsigned vertCount = m_poly3D->size();
	if(vertCount==2)
	{
		CCVector3 pt1 = *(m_poly3D->getPoint(0));
		CCVector3 pt2 = *(m_poly3D->getPoint(1));
		double dDis = sqrt(pow((pt1.x - pt2.x), 2.0) + pow((pt1.y - pt2.y), 2.0) + pow((pt1.z - pt2.z), 2.0));
		m_poly3DVertices = 0;
		m_poly3D = 0;
		QString strDis = QString::number(dDis);
		QString strInfo = "Dstance Is [ " + strDis + " ]  ";
		QMessageBox::warning(0,"DisTance",strInfo);
	}
	return;
}

