
#include <QApplication>
#include <QMainWindow>
#include <QMessageBox>

#include "dpxRoadStopLineTool.h"
#include "dpxGeoEngine.h"

dpxRoadStopLineTool::dpxRoadStopLineTool()
{
	m_bHasSelectOne = false;
}

dpxRoadStopLineTool::~dpxRoadStopLineTool()
{
}

bool isObjValid(ccHObject* pObj)
{
	if(pObj==nullptr)
		return false;

    if(!pObj->hasMetaData(DPX_OBJECT_TYPE_NAME))
        return false;

	dpxObjectType eType = dpxObjectType(pObj->getMetaData(DPX_OBJECT_TYPE_NAME).toInt());
    if(eType != eObj_RoadRefLine && eType != eObj_RoadLine)
        return false;

	return true;
}

//鼠标左键事件
void dpxRoadStopLineTool::onMouseLeftClick(int x,int y)
{
    m_nToolState=0;//采集状态
    //获取最近的线与点
    dpxNearestLine nearestInfo;
    bool bFind = getNearestLineInfo(x,y,nearestInfo,true,isObjValid); //点击到线必须是 RefLine  RoadLine  不会选中刚采集到stopLine
    if(!bFind)
        return;

    ccPolyline* pLine = nearestInfo.m_pLine;
    if(pLine==nullptr || pLine==0)
        return;

    //结点判断
    double dDistance = nearestInfo.m_dDistance;
    if(dDistance>SNAP_TOL_VALUE)
		return ;

	CCVector3 Pt = nearestInfo.m_nearestPt;

	if(!m_bHasSelectOne) //添加第一个点
	{
		m_poly3DVertices = new ccPointCloud("Vertices");
		m_poly3DVertices->setEnabled(false);
		m_poly3DVertices->setDisplay(m_window);

		m_poly3D = new ccPolyline(m_poly3DVertices);
		m_poly3D->addChild(m_poly3DVertices);
		m_poly3D->setName("stopLine");
		m_poly3D->setWidth(2);
		ccColor::Rgb stopLineColor STOP_LINE_COLOR; //宏定义颜色
		m_poly3D->setTempColor(stopLineColor);
		m_poly3D->setMetaData(DPX_OBJECT_TYPE_NAME,eObj_RoadStopLine); //记录要素类型为StopLine


		m_pPickRoot = pLine; //点击到第一条线作为reodLine stopLine挂其下面
		m_pPickRoot->addChild(m_poly3D);
		//try to add one more point
		if ( !m_poly3DVertices->reserve(m_poly3DVertices->size() + 1)
			|| !m_poly3D->reserve(m_poly3DVertices->size() + 1))
			return;

		m_poly3DVertices->addPoint(Pt);
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

		m_bHasSelectOne = true;
	}
    else if(m_bHasSelectOne)//添加第二个点
	{
		if(pLine==m_pPickRoot) //若两次点击到为同一条线，则点击无效
			return;

		if (!m_poly3DVertices->reserve(m_poly3DVertices->size() + 1)
			||!m_poly3D->reserve(m_poly3DVertices->size() + 1))
			return;

		m_poly3DVertices->addPoint(Pt);
		m_poly3D->addPointIndex(m_poly3DVertices->size()-1);

		m_poly3DVertices = 0;
		m_poly3D = 0;
		m_polyTip->setEnabled(false);
		m_bHasSelectOne = false;
	}
}

//重写基础类的原因：鼠标采集时既要能够有动态线，又得支持线节点的捕捉
void dpxRoadStopLineTool::onMouseMove(int x, int y, Qt::MouseButtons buttons)
{
	if (!m_poly3DVertices || m_poly3DVertices->size() == 0)
		return dpxNodeEditTool::onMouseMove(x,y,buttons);  //在基类上拓展

	assert(m_polyTip && m_polyTipVertices && m_polyTipVertices->size() == 3);

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

	//else//编辑状态直接采用基类
	return dpxNodeEditTool::onMouseMove(x,y,buttons);//在基类上拓展
}

void dpxRoadStopLineTool::pointPicked(ccHObject* insertPoint, unsigned itemIdx, ccPointCloud* cloud, const CCVector3& P,int x/*=0*/,int y/*=0*/)
{
   return ;
}
