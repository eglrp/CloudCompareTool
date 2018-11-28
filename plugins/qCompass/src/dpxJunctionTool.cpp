
#include <QApplication>
#include <QMainWindow>
#include <QMessageBox>

#include "dpxJunctionTool.h"
#include "ccCompass.h"
#include "dpxGeoEngine.h"
#include <ccFitPlane.h>
#include <dpxToolCommonFun.h>

dpxJunctionTool::dpxJunctionTool()
	: dpxPickAndEditTool()
{
	m_pPickRoot = new ccHObject("Pick Lines");
	m_pPickRoot->setMetaData(DPX_LAYER_TYPE_NAME,0);
}


dpxJunctionTool::~dpxJunctionTool()
{
	if (m_polyTip)
		delete m_polyTip;

	if (m_poly3D)
		delete m_poly3D;
}

void dpxJunctionTool::toolActivated()
{
	//若添加了地图，采集到地图中去
	dpxMap* pMap = dpxGeoEngine::Instance()->GetMap();
	if(pMap!=nullptr)
	{
		dpxLayer* pJunctionLyr = pMap->getJunctionLyr();
		if(pJunctionLyr!=nullptr && pJunctionLyr->getRootData()!=nullptr)
			m_pPickRoot = pJunctionLyr->getRootData();
	}

	dpxPickAndEditTool::toolActivated();
	connect(m_window, SIGNAL(leftButtonClicked(int, int)), this, SLOT(slotAddPointToPolyline(int, int)));
}

void dpxJunctionTool::slotAddPointToPolyline(int x, int y)
{
	ccLog::Warning("XXXYYY");
}

void dpxJunctionTool::onLeftDoubleClick(int x,int y)
{
	if(m_nToolState==1)//编辑状体
	{
        dpxNodeEditTool::onLeftDoubleClick(x,y);//删除节点功能
	}
}

void dpxJunctionTool::onMouseRightClick(int x,int y)
{
	if(m_nToolState==1)//编辑状体
	{
        dpxNodeEditTool::onMouseRightClick(x,y);//添加节点功能
        return;
	}

	if (!m_poly3D || (QApplication::keyboardModifiers() & Qt::ControlModifier)) //CTRL + right click = panning
		return;

	unsigned vertCount = m_poly3D->size();
	while(1)
	{
		if (vertCount < 2)
		{
			if (m_polyTip)
				m_polyTip->setEnabled(false);
			m_pPickRoot->removeChild(m_poly3D); //只有一个点不保存
			break;
		}
		else
		{
			//viewing parameters
			ccGLCameraParameters camera;
			m_window->getGLCameraParameters(camera);
			const double half_w = camera.viewport[2] / 2.0;
			const double half_h = camera.viewport[3] / 2.0;

			std::vector<CCVector2> vecRangeVertices;
			for(int i = 0;i < vertCount ;i++)
			{
				CCVector3 P3D = *(m_poly3D->getPoint(i));
				CCVector3d Q2D;
				camera.project(P3D, Q2D);

				CCVector2 P2D(static_cast<PointCoordinateType>(Q2D.x-half_w),
								static_cast<PointCoordinateType>(Q2D.y-half_h));
				vecRangeVertices.push_back(P2D);
			}

			dpxMap* pCurrentMap = dpxGeoEngine::Instance()->GetMap();
			vector<ccHObject*>  vecSections = dpxToolCommonFun::GetAllSection(pCurrentMap);

			ccPointCloud* vertices3D = new ccPointCloud("Vertices");
			int nMaxJunctionId = dpxToolCommonFun::getMaxJunctionID();
			vector<int> vecHeadIds,vecTailIds,vecRefIDs;
			for(int j=0;j<vecSections.size();j++)
			{
				ccHObject* pSection = vecSections[j];
				vector<ccPolyline*> vecRefLines = dpxToolCommonFun::getRefLinesV2(pSection);
				int nSize = vecRefLines.size();
				if(nSize<1)
					continue;

				CCVector3 ptFirst3D = *(vecRefLines[0]->getPoint(0));
				CCVector3 ptLast3D = *(vecRefLines[nSize-1]->getPoint(vecRefLines[nSize-1]->size()-1));
				CCVector2 ptFirst2D = GetScreen2D(ptFirst3D,camera);
				CCVector2 ptLast2D = GetScreen2D(ptLast3D,camera);

				bool  bFirstIn = dpxAlgorithmFun::isPointInsidePoly(ptFirst2D,vecRangeVertices);
				bool  bLastIn = dpxAlgorithmFun::isPointInsidePoly(ptLast2D,vecRangeVertices);
				if(!bFirstIn && !bLastIn)
					continue;
				int nID = getUID(pSection);
				if(nID==-1)
					continue;
				vecRefIDs.push_back(nID);

				//RefLine及其下属的RoadLine首尾节点都加入
				vector<ccHObject*> vecRoadLineSet = dpxToolCommonFun::getRoadLineSets(pSection); //RoadLineSet  severl
				if(bFirstIn)//头部进入区域
				{
					vecHeadIds.push_back(j);
					vertices3D->reserve(vertices3D->size()+1);
					vertices3D->addPoint(ptFirst3D);
					for(int temp=0;temp<vecRoadLineSet.size();temp++)
					{
						ccHObject* pRoadLineSet = vecRoadLineSet[temp];  //取首点
						vector<ccPolyline*> vecLines = dpxToolCommonFun::getRoadLines(pRoadLineSet);
						if(vecLines.size()<1)
							continue;

						vertices3D->reserve(vertices3D->size()+1);
						vertices3D->addPoint(*(vecLines[0]->getPoint(0)));
					}
				}

				if(bLastIn)//尾部进入区域
				{
					vecTailIds.push_back(j);
					vertices3D->reserve(vertices3D->size()+1);
					vertices3D->addPoint(ptLast3D);
					for(int temp=0;temp<vecRoadLineSet.size();temp++)
					{
						ccHObject* pRoadLineSet = vecRoadLineSet[temp];  //取首点
						vector<ccPolyline*> vecLines = dpxToolCommonFun::getRoadLines(pRoadLineSet);
						 int nSize = vecLines.size();
							continue;

						vertices3D->reserve(vertices3D->size()+1);
						vertices3D->addPoint(*(vecLines[nSize-1]->getPoint(vecLines[nSize-1]->size()-1)));
					}
				}
			}
			double rms = 0.0; //output for rms
			ccFitPlane* pPlane = ccFitPlane::Fit(vertices3D, &rms);
			if(pPlane!=nullptr)
			{
				QString strRelateID = QUuid::createUuid().toString();
				pPlane->setDisplay(m_window);
				pPlane->setMetaData(DPX_RELATED_PLANE_UID,strRelateID);

				ccPointCloud* poly3DVertices = new ccPointCloud("Vertices");
				poly3DVertices->setEnabled(false);
				poly3DVertices->setDisplay(m_window);

				ccPolyline* poly3D = new ccPolyline(poly3DVertices);
				poly3D->setTempColor(ccColor::green);
				poly3D->setMetaData(DPX_RELATED_PLANE_UID,strRelateID);//关联的ID
				poly3D->set2DMode(false);
				poly3D->addChild(m_poly3DVertices);
				poly3D->setWidth(1);
				poly3D->setName("Junction");
				poly3D->setMetaData(DPX_UID,nMaxJunctionId+1);
				//related vecRefIDs
				poly3D->setMetaData(RELATED_REFLINE_UID,getRefIDValue(vecRefIDs));
				poly3D->addChild(pPlane);
				m_pPickRoot->addChild(poly3D);
				for(int m=0;m<vecHeadIds.size();m++)
				{
					if(vecHeadIds[m]>vecSections.size()-1)
						continue;
					ccHObject* ptemp = vecSections[vecHeadIds[m]];
					ptemp->setMetaData(HEAD_JUNCTION_UID,nMaxJunctionId+1);
				}
				for(int n=0;n<vecTailIds.size();n++)
				{
					if(vecTailIds[n]>vecSections.size()-1)
						continue;
					ccHObject* ptemp = vecSections[vecTailIds[n]];
					ptemp->setMetaData(TAIL_JUNCTION_UID,nMaxJunctionId+1);
				}
			}
			break;
		}
	}

	m_pPickRoot->removeChild(m_poly3D);
	m_poly3D = 0;
	m_poly3DVertices = 0;
	m_nToolState = 0;
	m_polyTip->setEnabled(false);
	m_window->removeFromOwnDB(m_pPickRoot);
	m_app->addToDB(m_pPickRoot);
}

int dpxJunctionTool::getUID(ccHObject* pHObject)
{
	if(pHObject==nullptr)
		return -1;
	if(!pHObject->hasMetaData(DPX_UID))
		return -1;

	return pHObject->getMetaData(DPX_UID).toInt();
}

void dpxJunctionTool::pointPicked(ccHObject* insertPoint, unsigned itemIdx, ccPointCloud* cloud, const CCVector3& P,int x/*=0*/,int y/*=0*/)
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
		m_poly3D->setTempColor(ccColor::green);
		m_poly3D->set2DMode(false);
		m_poly3D->addChild(m_poly3DVertices);
		m_poly3D->setWidth(1);

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
	if(m_poly3D->size()>2)
		m_poly3D->setClosed(true);

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


QString dpxJunctionTool::getRefIDValue(const vector<int>& vecRefIDs)
{
    QString strValue = "";
    for(int i =0;i<vecRefIDs.size();i++)
    {
		if(i==0)
			strValue = QString::number(vecRefIDs[i]);
		else
			strValue = strValue+";"+QString::number(vecRefIDs[i]);
    }
	return strValue;
}

CCVector2 dpxJunctionTool::GetScreen2D(CCVector3 pt3D,ccGLCameraParameters camera)
{
	const double half_w = camera.viewport[2] / 2.0;
	const double half_h = camera.viewport[3] / 2.0;
	CCVector3d Q2D;
	camera.project(pt3D, Q2D);
	CCVector2 P2D(static_cast<PointCoordinateType>(Q2D.x-half_w),
					static_cast<PointCoordinateType>(Q2D.y-half_h));
	return P2D;
}
