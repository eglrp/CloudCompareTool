
#include "dpxZebraCrossLineTool.h"


dpxZebraCrossLineTool::dpxZebraCrossLineTool()
	: dpxTraceLineTool()
{
	m_pPickRoot = new ccHObject("ZebraCross Lines");
	m_pPickRoot->setMetaData(DPX_LAYER_TYPE_NAME,0);
}


dpxZebraCrossLineTool::~dpxZebraCrossLineTool()
{
}

void dpxZebraCrossLineTool::toolActivated()
{
	//若添加了地图，采集到地图中去
	dpxLayer* pZebraLineLyr = dpxGeoEngine::Instance()->getZebraLineLry();
	if(pZebraLineLyr!=nullptr && pZebraLineLyr->getRootData()!=nullptr)
		m_pPickRoot = pZebraLineLyr->getRootData();

	dpxPickAndEditTool::toolActivated();
}


void dpxZebraCrossLineTool::pointPicked(ccHObject* insertPoint, unsigned itemIdx, ccPointCloud* cloud, const CCVector3& P,int x/*=0*/,int y/*=0*/)
{
	if(m_nToolState==1)//编辑状体
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
		m_poly3D->addChild(m_poly3DVertices);
		m_poly3D->setWidth(1);

		ccColor::Rgb zebaLineColor ZEBAR_CROSS_LINE_COLOR; //宏定义颜色 斑马线
		m_poly3D->setTempColor(zebaLineColor);
		m_poly3D->setMetaData(DPX_OBJECT_TYPE_NAME,eObj_ZebraCrossingLine); //记录要素类型为ZebraCross
		m_poly3D->setName("ZebraCrossLine");

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
}
