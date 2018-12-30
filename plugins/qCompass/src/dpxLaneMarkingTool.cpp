//by duans
#include "dpxLaneMarkingTool.h"
#include "dpxGeoEngine.h"
#include <ccFitPlane.h>
#include <QMessageBox>
#include <dpxToolCommonFun.h>
#include "dpxAlgorithmFun.h"
#include "../../qCC/dpxFramework/dpxSelectionManager.h"
#include <ccFacet.h>
dpxLaneMarkingTool::dpxLaneMarkingTool()
{
	m_pPickRoot = new ccHObject("LaneMarking");
	m_pPickRoot->setMetaData(DPX_LAYER_TYPE_NAME,0);
	m_pAssistWin = nullptr;
	m_nCreateType = 0; //0代表拟合到方式1：代表采集到方式
	//特殊定制
	m_strccHobjectName = "LaneMarkingPlane";
	m_eCurObjType = eObj_LaneMarking;//默认初始采集到是红绿灯
	m_strImageName = ":/CC/images/LaneMarkingIcon.png";
	m_eTargetLayerType = eOT_LaneMarking;
}

//----------------------------dpxLaneMarkingToolV2-----------------------------//
dpxLaneMarkingToolV2::dpxLaneMarkingToolV2()
	: dpxPickAndEditTool()
{
	m_bSetRefLine = false;
}


dpxLaneMarkingToolV2::~dpxLaneMarkingToolV2()
{
	if (m_polyTip)
		delete m_polyTip;

	if (m_poly3D)
		delete m_poly3D;
}

bool dpxLaneMarkingToolV2::CheckSelectRefLine()
{
	m_bSetRefLine = false;
	m_pPickRoot = nullptr;
    vector<ccHObject*> vecObjs = dpxSelectionManager::Instance()->getSelections();
    do
    {
        if(vecObjs.size()<1)
            break;
        ccHObject* pHObj = vecObjs[0];
        if(!pHObj->hasMetaData(DPX_OBJECT_TYPE_NAME))
            break;

        int index = pHObj->getMetaData(DPX_OBJECT_TYPE_NAME).toInt();
        if(dpxObjectType(index) != eObj_RoadRefLine)
            break;

        //生成的RoadLine挂在RefLine节点下
		ccPolyline* pLine = ccHObjectCaster::ToPolyline(pHObj);
		if(pLine==nullptr)
			break;

        ccHObject* pSection = dpxMapCommonFunc::getRelatedSection(pLine);
        if(pSection==nullptr)
			break;

		m_pPickRoot = pSection;
		m_bSetRefLine= true;

    }while(0);

	if(!m_bSetRefLine)
	{
		//若添加了地图，采集到地图中去
		dpxMap* pMap = dpxGeoEngine::Instance()->GetMap();
		if(pMap!=nullptr)
		{
			dpxLayer* pTargetLyr = pMap->getLyrFormType(eOT_LaneMarking);
			if(pTargetLyr!=nullptr && pTargetLyr->getRootData()!=nullptr)
			{
				m_pPickRoot = pTargetLyr->getRootData();
				m_bSetRefLine = true;
			}

		}
	}

	if(!m_bSetRefLine)
	{
		QMessageBox::warning(nullptr,"waring","Has no  Root Hobj");
	}
	return true;
}

void dpxLaneMarkingToolV2::toolActivated()
{
	if(!CheckSelectRefLine())
		return;
	dpxPickAndEditTool::toolActivated();
}


void dpxLaneMarkingToolV2::onLeftDoubleClick(int x,int y)
{
	if(m_nToolState==1)//编辑状体
	{
        dpxNodeEditTool::onLeftDoubleClick(x,y);//删除节点功能
	}
}

void dpxLaneMarkingToolV2::onMouseRightClick(int x,int y)
{
	if(m_nToolState==1)//编辑状体
	{
        dpxNodeEditTool::onMouseRightClick(x,y);//添加节点功能
        return;
	}

	if (!m_poly3D || (QApplication::keyboardModifiers() & Qt::ControlModifier)) //CTRL + right click = panning
		return;

	unsigned vertCount = m_poly3D->size();
	if (vertCount < 2)
	{
		if (m_polyTip)
			m_polyTip->setEnabled(false);
		m_pPickRoot->removeChild(m_poly3D); //只有一个点不保存
	}
	else
	{
		m_poly3D->setMetaData(DPX_OBJECT_TYPE_NAME,eObj_LaneMarking); //记录要素类型为refLine
		m_poly3D->setName("LaneMarking");
		m_nToolState = 1;//右键停止采集，转为编辑状态

		ccFitPlane* pFitPlane = ccFitPlane::Fit(m_poly3DVertices,0);
		if(pFitPlane!=nullptr && pFitPlane->get4CornerPts().size()==4)
		{
			//if the 3D polyline doesn't exist yet, we create it
			ccPointCloud* poly3DVertices = new ccPointCloud("Vertices");
			poly3DVertices->setEnabled(false);
			poly3DVertices->setDisplay(m_window);
			ccPolyline* poly3D = new ccPolyline(poly3DVertices);
			poly3D->setTempColor(ccColor::green);
			poly3D->set2DMode(false);
			poly3D->addChild(poly3DVertices);
			poly3D->setWidth(1);

			CCVector3  VecNormal = pFitPlane->getNormal();
			CCVector3 pt0 = pFitPlane->get4CornerPts().at(0);
			//折线的点投影到拟合平面上，保证在一个平面才合理
			int nSize = m_poly3D->size();
			for(int i = 0;i<nSize;i++)
			{
				CCVector3 ptTarget = *(m_poly3D->getPoint(i));
				CCVector3 ptModefyPt = dpxAlgorithmFun::Project2Plane(VecNormal,pt0,ptTarget); //

				poly3DVertices->reserve(poly3DVertices->size() + 1);
				poly3D->reserve(poly3DVertices->size() + 1);

				poly3DVertices->addPoint(ptModefyPt);
				poly3D->addPointIndex(poly3DVertices->size() - 1);
			}

			if(poly3D->size()>2)
				poly3D->setClosed(true);

			poly3D->setTempColor(ccColor::white);
			poly3D->setMetaData(DPX_OBJECT_TYPE_NAME,eObj_LaneMarking); //记录要素类型为refLine
			poly3D->setName("LaneMarking");

			m_pPickRoot->removeChild(m_poly3D);
			m_pPickRoot->addChild(poly3D);
		}
	}

	m_poly3D = 0;
	m_poly3DVertices = 0;
	m_polyTip->setEnabled(false);
	m_window->removeFromOwnDB(m_pPickRoot);
	m_app->addToDB(m_pPickRoot);
}

ccPolyline* dpxLaneMarkingToolV2::ModefyPolyLine(ccPolyline* pOriginalLine)
{
	if(pOriginalLine==nullptr)
		return nullptr;
	//if the 3D polyline doesn't exist yet, we create it
	ccPointCloud* poly3DVertices = new ccPointCloud("Vertices");
	poly3DVertices->setEnabled(false);
	poly3DVertices->setDisplay(m_window);
	ccPolyline* poly3D = new ccPolyline(poly3DVertices);
	poly3D->set2DMode(false);
	poly3D->addChild(poly3DVertices);
	poly3D->setWidth(1);

	// rebuild Plane
	ccFitPlane* pFitPlane = ccFitPlane::Fit(pOriginalLine->getAssociatedCloud(),0);
	CCVector3  VecNormal = pFitPlane->getNormal();
	CCVector3 pt0 = pFitPlane->get4CornerPts().at(0);
	//折线的点投影到拟合平面上，保证在一个平面才合理
	int nSize = pOriginalLine->size();
	for(int i = 0;i<nSize;i++)
	{
		CCVector3 ptTarget = *(pOriginalLine->getPoint(i));
		CCVector3 ptModefyPt = dpxAlgorithmFun::Project2Plane(VecNormal,pt0,ptTarget); //

		poly3DVertices->reserve(poly3DVertices->size() + 1);
		poly3D->reserve(poly3DVertices->size() + 1);

		poly3DVertices->addPoint(ptModefyPt);
		poly3D->addPointIndex(poly3DVertices->size() - 1);
	}

	if(poly3D->size()>2)
		poly3D->setClosed(true);

	ccColor::Rgb refLineColor REF_LINE_COLOR; //宏定义颜色
	poly3D->setTempColor(refLineColor);
	poly3D->setMetaData(DPX_OBJECT_TYPE_NAME,eObj_LaneMarking); //记录要素类型为refLine
	poly3D->setName("LaneMarking");

	return poly3D;
}
//
void dpxLaneMarkingToolV2::onMouseReleaseEvent(int x,int y)
{
	if(m_window==nullptr)
		return;

	if(m_VNodeInfo.m_pLine==nullptr || m_VNodeInfo.m_nNodeIndex==-1)
		return;

	m_polyTip->setEnabled(false);

	ccPolyline* pLine = m_VNodeInfo.m_pLine;
	int nIndex = m_VNodeInfo.m_nNodeIndex;

	if( nIndex>pLine->size()-1)
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

	// reBuild Plane
	ccPolyline* pNewLine =  ModefyPolyLine(pLine);
	m_pPickRoot->addChild(pNewLine);
	m_pPickRoot->removeChild(pLine);

	m_window->removeFromOwnDB(m_pPickRoot);
	m_app->addToDB(m_pPickRoot);
	m_window->redraw(false, true);
}

////-------------------- wrong result----------------------//
//		ccShiftedObject* shifted = nullptr;
//		CCLib::GenericIndexedCloudPersist* cloud = static_cast<CCLib::GenericIndexedCloudPersist*>(m_poly3D);
//		shifted = m_poly3D;
//		if (cloud == nullptr)
//			return ;
//
//		double rms = 0.0;
//		CCVector3 C, N;
//		ccFacet* facet = ccFacet::Create(m_poly3DVertices);
//		if (!facet)
//			return;
//
//		ccHObject* pOutFace = static_cast<ccHObject*>(facet);
//		N = facet->getNormal();
//		C = facet->getCenter();
//		rms = facet->getRMS();
//
//		//manually copy shift & scale info!
//		if (shifted)
//		{
//			ccPolyline* contour = facet->getContour();
//			if (contour)
//			{
//				contour->setGlobalScale(shifted->getGlobalScale());
//				contour->setGlobalShift(shifted->getGlobalShift());
//			}
//		}
//
//		//We always consider the normal with a positive 'Z' by default!
//		if (N.z < 0.0)
//			N *= -1.0;
//		//we compute strike & dip by the way
//		PointCoordinateType dip = 0.0f;
//		PointCoordinateType dipDir = 0.0f;
//		ccNormalVectors::ConvertNormalToDipAndDipDir(N, dip, dipDir);
//
//		QString dipAndDipDirStr = ccNormalVectors::ConvertDipAndDipDirToString(dip, dipDir);
//		pOutFace->setName(dipAndDipDirStr);
//		pOutFace->applyGLTransformation_recursive(); //not yet in DB
//		pOutFace->setVisible(true);
//		pOutFace->setSelectionBehavior(ccHObject::SELECTION_FIT_BBOX);
//
//		pOutFace->setDisplay(m_window);
//		pOutFace->prepareDisplayForRefresh_recursive();
//		m_poly3D->addChild(pOutFace);

void dpxLaneMarkingToolV2::pointPicked(ccHObject* insertPoint, unsigned itemIdx, ccPointCloud* cloud, const CCVector3& P,int x/*=0*/,int y/*=0*/)
{
	if(m_nToolState==1)//编辑状体
		return;
	if(!m_bSetRefLine)
		return ;

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

