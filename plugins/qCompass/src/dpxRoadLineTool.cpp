#include <QApplication>
#include <QMainWindow>
#include <QMessageBox>

#include "dpxRoadLineTool.h"
#include "dpxGeoEngine.h"
#include "dpxMapDefine.h"
#include "../../qCC/dpxFramework/dpxSelectionManager.h"
dpxRoadLineTool::dpxRoadLineTool()
{
    m_bSetRefLine = false;
}

dpxRoadLineTool::~dpxRoadLineTool()
{
}

void dpxRoadLineTool::toolActivated()
{
    dpxTraceLineTool::toolActivated();
    m_bSetRefLine = false;
    vector<ccHObject*> vecObjs = dpxSelectionManager::Instance()->getSelections();
    do
    {
        if(vecObjs.size()!=1)
            break;
        ccHObject* pHObj = vecObjs[0];
        if(!pHObj->hasMetaData(DPX_OBJECT_TYPE_NAME))
            break;

        int index = pHObj->getMetaData(DPX_OBJECT_TYPE_NAME).toInt();
        if(dpxObjectType(index) != eObj_RoadRefLine)
            break;

        //生成的RoadLine挂在RefLine节点下
        m_bSetRefLine= true;
        m_pPickRoot = pHObj;

    }while(0);

    if(!m_bSetRefLine)
        QMessageBox::warning(nullptr,"waring","please Select one RefLine");
}


void dpxRoadLineTool::onKeyPress(int sKey)
{
    //ccLog::Warning("dpxRoadLineTool! oh yare!!!" + QString::number(sKey));
}

void dpxRoadLineTool::onMouseRightClick(int x,int y)
{
	if(m_nToolState==1)//编辑状体
	{
        dpxNodeEditTool::onMouseRightClick(x,y);//添加节点功能
	}
	else if(m_nToolState==0)//采集状态
	{
		if (!m_poly3D || (QApplication::keyboardModifiers() & Qt::ControlModifier)) //CTRL + right click = panning
			return;

		unsigned vertCount = m_poly3D->size();
		if (vertCount < 2)
		{
			if (m_polyTip)
				m_polyTip->setEnabled(false);

			m_poly3D = 0;
			m_poly3DVertices = 0;
		}
		else
		{
			m_poly3D = 0;
			m_poly3DVertices = 0;
			m_nToolState = 1;//右键停止采集，转为编辑状态
		}
		m_polyTip->setEnabled(false);
		m_window->removeFromOwnDB(m_pPickRoot);
		m_app->addToDB(m_pPickRoot);
	}
	else if(m_nToolState==2)
	{
		//拷贝模式时右键恢复至编辑模式
	    m_nToolState=1;
		m_VNodeInfo.clear();
	}
}

//鼠标左键事件
void dpxRoadLineTool::onMouseLeftClick(int x,int y)
{
    //拷贝线时需要先点击refLine的一个节点，需要判断是否点击到了refLie节点;m_nToolState=2
    //若第一次点击已经了refLine节点，还需要采集一个点 作为刚刚refLie的节点平移的位置，在此过程再此点击鼠标，不需要进行判断状态
    if(m_nToolState == 2)
        return;

    m_VNodeInfo.clear();
    m_nToolState=0;//采集状态
    //获取最近的线与点
    dpxNearestLine nearestInfo;
    bool bFind = getNearestLineInfo(x,y,nearestInfo,true);
    if(!bFind)
        return;

    ccPolyline* pLine = nearestInfo.m_pLine;
    if(pLine==nullptr || pLine==0)
        return;

    if(!pLine->hasMetaData(DPX_OBJECT_TYPE_NAME))
        return;

    dpxObjectType eType = dpxObjectType(pLine->getMetaData(DPX_OBJECT_TYPE_NAME).toInt());
    if(eType != eObj_RoadRefLine && eType != eObj_RoadLine)
        return;
    /*
    在基类里补充拷贝状态
       0：采集状态 1：编辑状态 2：拷贝状态
    0：若鼠标没有点中refLine及roadLine节点，则采集新的roadLine
    1：若鼠标点击了选择集中roadLine的节点，则可以拖拽roadLine
    2：若鼠标点击了refLine的节点，则再点击一下点云就能把点击的refLine拷贝成新的RoadLine
    */

    ccHObject* pSelectRef = nullptr;
    if(m_bSetRefLine)
    {
        vector<ccHObject*> vecObjs = dpxSelectionManager::Instance()->getSelections();
        if(vecObjs.size()==1)
            pSelectRef = vecObjs[0];
    }
    //结点判断
    double dDistance = nearestInfo.m_dDistance;
    int nSegNum = nearestInfo.m_nSegNum;
    if(dDistance<SNAP_TOL_VALUE)
    {
        m_VNodeInfo.m_pLine = pLine;
        m_VNodeInfo.m_nNodeIndex = nSegNum;
        if(eType==eObj_RoadLine)
            m_nToolState = 1;//若点击的时节点，则为编辑状态
        else if(pLine == pSelectRef)
        {
            m_nToolState = 2;//点击的是refLine的节点，拷贝状态
            ccLog::Warning("start copy refLine");
        }

    }
}


void dpxRoadLineTool::pointPicked(ccHObject* insertPoint, unsigned itemIdx, ccPointCloud* cloud, const CCVector3& P,int x/*=0*/,int y/*=0*/)
{
    if(m_nToolState==1)//编辑状态不需要左键点击加点
        return;

    //if the 3D polyline doesn't exist yet, we create it
    if (!m_poly3D || !m_poly3DVertices)
    {
        m_poly3DVertices = new ccPointCloud("Vertices");
        m_poly3DVertices->setEnabled(false);
        m_poly3DVertices->setDisplay(m_window);

        m_poly3D = new ccPolyline(m_poly3DVertices);
        m_poly3D->set2DMode(false);
        m_poly3D->addChild(m_poly3DVertices);
        m_poly3D->setWidth(1);

		ccColor::Rgb roadLineColor ROAD_LINE_COLOR; //宏定义颜色
		m_poly3D->setTempColor(roadLineColor);
		m_poly3D->setMetaData(DPX_OBJECT_TYPE_NAME,eObj_RoadLine); //记录要素类型为refLine
		m_poly3D->setName("roadLine");

        m_pPickRoot->addChild(m_poly3D);
    }


    if(m_nToolState==2)//拷贝refLine
    {
		ccLog::Warning("m_nToolState==2  second pt");
        ccPolyline* pLine =  m_VNodeInfo.m_pLine;
        if(pLine==nullptr)
			return;
        int nsize = pLine->size();
        int nNode = m_VNodeInfo.m_nNodeIndex;
        //try to add one more point

        CCVector3 ptNode = *(pLine->getPoint(nNode));

        double dX_Offset = P.x - ptNode.x;
        double dY_Offset = P.y - ptNode.y;
        double dZ_Offset = P.z - ptNode.z;

        ccGLMatrix transM ;//平移矩阵
        CCVector3 vecTrans(dX_Offset,dY_Offset,dZ_Offset);
        transM.setTranslation(vecTrans);

        for(int i = 0;i<pLine->size();i++)
        {
            CCVector3 pPoint = *(pLine->getPoint(i));
            CCVector3 newPt =   transM*pPoint;

			if ( !m_poly3DVertices->reserve(m_poly3DVertices->size() + 1)
				|| !m_poly3D->reserve(m_poly3DVertices->size() + 1))
			{
				ccLog::Error("Not enough memory");
				return;
			}

			m_poly3DVertices->addPoint(newPt);
			m_poly3D->addPointIndex(m_poly3DVertices->size() - 1);
        }

        m_poly3D = 0;
        m_poly3DVertices = 0;
        m_polyTip->setEnabled(false);
        m_nToolState = 2;
    }
    else if(m_nToolState==0)//采集模式
    {
		//try to add one more point
		if (    !m_poly3DVertices->reserve(m_poly3DVertices->size() + 1)
			||    !m_poly3D->reserve(m_poly3DVertices->size() + 1))
		{
			ccLog::Error("Not enough memory");
			return;
		}


		m_poly3DVertices->addPoint(P);
		m_poly3D->addPointIndex(m_poly3DVertices->size() - 1);

		//we replace the first point of the tip by this new point
		{
			QPointF pos2D = m_window->toCenteredGLCoordinates(x, y);
			CCVector3 P2D(    static_cast<PointCoordinateType>(pos2D.x()),
							static_cast<PointCoordinateType>(pos2D.y()),
							0);

			CCVector3* firstTipPoint = const_cast<CCVector3*>(m_polyTipVertices->getPointPersistentPtr(0));
			*firstTipPoint = P2D;
			m_polyTip->setEnabled(false); //don't need to display it for now
		}
    }

    m_window->redraw(false, false);
}

void dpxRoadLineTool::onMouseMove(int x, int y, Qt::MouseButtons buttons)
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
	else if(m_nToolState==1)//编辑状态直接采用基类
	{
		return dpxNodeEditTool::onMouseMove(x,y,buttons);
	}
	else if(m_nToolState==2)//拷贝模式,
	{
		m_polyTip->setEnabled(false);
	}
}

void dpxRoadLineTool::onMouseReleaseEvent(int x,int y)
{
	if(m_window==nullptr)
		return;

	if(m_VNodeInfo.m_pLine==nullptr || m_VNodeInfo.m_nNodeIndex==-1)
		return;

	ccPolyline* pLine = m_VNodeInfo.m_pLine;
	int nIndex = m_VNodeInfo.m_nNodeIndex;

	if(nIndex>pLine->size()-1)
		return;

	if(!pLine->hasMetaData(DPX_OBJECT_TYPE_NAME))
		return;
	dpxObjectType eType = dpxObjectType(pLine->getMetaData(DPX_OBJECT_TYPE_NAME).toInt());
	if(eType != eObj_RoadLine)
		return;

	if(!m_bMoveNode)//是否是拖拽节点模式
		return;

	ccGenericPointCloud* pTargetCloud = nullptr;
	int nPloudPtIndex=-1;
	CCVector3 newPickPt;
	if(!m_window->pickNearestPt(x,y,pTargetCloud,nPloudPtIndex,newPickPt))
	{
		ccLog::Warning("释放鼠标无法捕捉点");
		return;
	}

	CCVector3* modefyPt = const_cast<CCVector3*>(pLine->getPointPersistentPtr(nIndex));
	*modefyPt = newPickPt;

	m_bMoveNode = false;
	pLine->invalidateBoundingBox();
	m_polyTip->setEnabled(false);
	m_window->redraw(false, true);
}
