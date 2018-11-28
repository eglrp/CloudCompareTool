
#include "dpxCrossWalkTool.h"
#include <QMessageBox>


dpxCrossWalkTool::dpxCrossWalkTool()
{
	m_pPickRoot = new ccHObject("CrossWalk Lines");
	m_pPickRoot->setMetaData(DPX_LAYER_TYPE_NAME,0);
	m_nCreateType = 0; //0代表拟合到方式1：代表采集到方式
	m_pAssistWin=nullptr;
	m_pBorderLine=nullptr;
	m_pBorderPlane=nullptr;
}


dpxCrossWalkTool::~dpxCrossWalkTool()
{
	if (m_poly3D)
		delete m_poly3D;
}

void dpxCrossWalkTool::toolActivated()
{
	//若添加了地图，采集到地图中去
	dpxMap* pMap = dpxGeoEngine::Instance()->GetMap();
	if(pMap!=nullptr)
	{
		dpxLayer* pZebraLineLyr = pMap->getCrossWalkLyr();
		if(pZebraLineLyr!=nullptr && pZebraLineLyr->getRootData()!=nullptr)
			m_pPickRoot = pZebraLineLyr->getRootData();
	}

	if(m_pAssistWin==nullptr)
	{
		m_pAssistWin = new dpxPlaneAssistDlg(this);
		m_pAssistWin->HideCombobox();
	}

	if(!m_pAssistWin->isVisible())
		m_pAssistWin->show();

	//AssistWin
	QObject::connect(m_pAssistWin, SIGNAL(sigTypeChange(int)), this, SLOT(slotChangeType(int)));

	dpxPickAndEditTool::toolActivated();
}

//采集方法发生变化
void dpxCrossWalkTool::slotChangeType(int nType)
{
	m_nCreateType = nType;
	if(m_nCreateType==0)
		ccLog::Warning("大于4个点拟合");
	else
		ccLog::Warning("3个点构造矩形");
}


void dpxCrossWalkTool::toolDisactivated()
{
	if(m_pAssistWin != nullptr && m_pAssistWin->isVisible())
		m_pAssistWin->hide();

	QObject::disconnect(m_pAssistWin, SIGNAL(sigTypeChange(int)), this, SLOT(slotChangeType(int)));

	dpxPickAndEditTool::toolDisactivated();
}

void dpxCrossWalkTool::setCrossWalkBorder(ccPolyline* pPoly3D,ccFitPlane* pPlane)
{
	if(pPlane == nullptr || pPoly3D==nullptr)
		return;
	QString strRelateID = QUuid::createUuid().toString();
	pPlane->setVisible(true);
	pPlane->setSelectionBehavior(ccHObject::SELECTION_IGNORED);
	pPlane->setDisplay(m_window);
	pPlane->setMetaData(DPX_RELATED_PLANE_UID,strRelateID);

	CCVector3 vNormal = pPlane->getNormal();
	QString strNormal = QString::number(vNormal.x).append(" ").append(QString::number(vNormal.y)).append(" ").append(QString::number(vNormal.z));
	pPoly3D->setMetaData(DPX_NORMAL,strNormal);//法向量
	pPoly3D->setMetaData(DPX_RELATED_PLANE_UID,strRelateID);//关联的ID
	pPoly3D->setMetaData(DPX_OBJECT_TYPE_NAME,eObj_CrossWalkLine); //地物类型
	pPoly3D->addChild(pPlane);
}

void dpxCrossWalkTool::slotDeleteObj()
{
    //删除后的响应
	m_VNodeInfo.clear();

	m_pBorderLine = 0;
	m_pBorderPlane = 0;
	ccLog::Warning("delete Obj Success");
}


//右键可取消两个点时的状态
void dpxCrossWalkTool::onMouseRightClick(int x,int y)
{
	if(m_nToolState)//编辑状体
		return;
	//if the 3D polyline doesn't exist yet, we create it
	if (!m_poly3D || !m_poly3DVertices)
		return;

	int nSize = m_poly3DVertices->size();
	//多点时必须采集>4  三点时==3
	if((m_nCreateType==0&&nSize<4) || (m_nCreateType==1&&nSize<3))
	{
		m_pPickRoot->removeChild(m_poly3D);
		m_polyTip->setEnabled(false);
		m_poly3D = 0;
		m_poly3DVertices = 0;
		m_nToolState=1;//采集状态结束，默认编辑状态
		return;
	}

	if(m_nCreateType==0)//多点拟合
	{
		//多点拟合的方式
		double rms = 0.0; //output for rms
		ccFitPlane* pBorderPlane = ccFitPlane::Fit(m_poly3DVertices, &rms);
		setCrossWalkBorder(m_poly3D,pBorderPlane);

		m_pBorderLine = m_poly3D;
		m_pBorderPlane = pBorderPlane;

		m_polyTip->setEnabled(false);
		m_poly3D = 0;
		m_poly3DVertices = 0;
		m_nToolState=1;//采集状态结束，默认编辑状态

		m_window->removeFromOwnDB(m_pPickRoot);
		m_app->addToDB(m_pPickRoot);

		m_window->redraw(false, true);
	}
}

void dpxCrossWalkTool::onKeyPress(int sKey)
{
	//Q键清除选择集
	if(sKey == Qt::Key_S)
	{
		ccLog::Warning("KeyS");
		if(m_pBorderLine==nullptr || m_pBorderPlane==nullptr)
		{
			ccLog::Warning("BorderLine And Pane");
			return;
		}

		//内插面
		dpxCrossWalkDlg dlg;
		if(dlg.exec()!=QDialog::Accepted)
			m_window->removeFromOwnDB(m_pBorderPlane);// 临时加入

		double dWidth;
		int nCount;
		dlg.getParams(dWidth,nCount);
		std::vector<CCVector3> BorderPts = m_pBorderPlane->get4CornerPts();
		if(BorderPts.size()!=4)//补充Border获取角点失败
		{
			m_pBorderLine = 0;
			m_pBorderPlane = 0;
			m_polyTip->setEnabled(false);
			m_poly3D = 0;
			m_poly3DVertices = 0;
			m_nToolState=1;//采集状态结束，默认编辑状态
		}

		vector<ccPolyline*> vecLines = CreatePlane(dWidth,nCount,BorderPts);
		if(vecLines.size()==nCount)
		{
			for(int i = 0;i< vecLines.size();i++)
			{
				vecLines[i]->setName("CrossWalkPon");//设置名称
				m_pBorderLine->addChild(vecLines[i]);// 临时加入
			}
		}

		m_pBorderLine = 0;
		m_pBorderPlane = 0;

		m_polyTip->setEnabled(false);
		m_poly3D = 0;
		m_poly3DVertices = 0;
		m_nToolState=1;//采集状态结束，默认编辑状态
	}
}

vector<ccPolyline*> dpxCrossWalkTool::CreatePlane(double& dWidth,int& nCount,std::vector<CCVector3>& BorderPts)
{
	vector<ccPolyline*> vecLines;
	if(BorderPts.size()<4)
		return vecLines;

	CCVector3 pt0 = BorderPts[0];
	CCVector3 pt1 = BorderPts[1];
	CCVector3 pt2 = BorderPts[2];
	CCVector3 pt3 = BorderPts[3];
	double dDis01 = sqrt(pow((pt0.x-pt1.x),2.0)+pow((pt0.y-pt1.y),2.0)+pow((pt0.z-pt1.z),2.0));
	double dDis12 = sqrt(pow((pt2.x-pt1.x),2.0)+pow((pt2.y-pt1.y),2.0)+pow((pt2.z-pt1.z),2.0));

	bool bSetLength = true;
	double dBorderDis = dDis01 > dDis12 ? dDis01 : dDis12;
	if( dWidth*nCount >= dBorderDis)
	{
		QMessageBox::warning(nullptr,"out of Width","out of Width");
		return vecLines;
	}

	double treansDis = (dBorderDis-dWidth*nCount)/(nCount-1) + dWidth;
	CCVector3 vNomal;

	CCVector3 ptFirst,ptSecond,ptThird,ptFourth;
	if(dDis01>dDis12)
	{
		vNomal = (pt1-pt0)/dBorderDis;

		ptFirst = pt0;
		ptSecond = pt0 + vNomal*dWidth;
		ptThird = pt3 + vNomal*dWidth;
		ptFourth = pt3;
	}
	else if(dDis12 > dDis01)
	{
		vNomal = (pt2-pt1)/dBorderDis;

		ptFirst =  pt1;
		ptSecond = pt1 + vNomal*dWidth;
		ptThird =  pt0 + vNomal*dWidth;
		ptFourth = pt0;
	}

	for(int i = 0;i < nCount;i++)
	{
		CCVector3 p0 = ptFirst 	+ treansDis*vNomal*i;
		CCVector3 p1 = ptSecond + treansDis*vNomal*i;
		CCVector3 p2 = ptThird 	+ treansDis*vNomal*i;
		CCVector3 p3 = ptFourth + treansDis*vNomal*i;

		ccPointCloud* pPointCloud = new ccPointCloud("Vertices");
		pPointCloud->reserve(4);
		ccPolyline * pPoly3D = new ccPolyline(pPointCloud);
		pPoly3D->setTempColor(ccColor::green);
		pPoly3D->reserve(pPointCloud->size() + 1);

		pPointCloud->addPoint(p0);
		pPoly3D->addPointIndex(0);

		pPointCloud->addPoint(p1);
		pPoly3D->addPointIndex(1);

		pPointCloud->addPoint(p2);
		pPoly3D->addPointIndex(2);

		pPointCloud->addPoint(p3);
		pPoly3D->addPointIndex(3);

		ccFitPlane* pPlane = ccFitPlane::Fit(pPointCloud, 0);
		if(pPlane == nullptr)
			continue;
		QString strRelateID = QUuid::createUuid().toString();
		pPlane->setVisible(true);
		pPlane->setSelectionBehavior(ccHObject::SELECTION_IGNORED);
		pPlane->setDisplay(m_window);
		pPlane->setMetaData(DPX_RELATED_PLANE_UID,strRelateID);

		CCVector3 vNormal = pPlane->getNormal();
		QString strNormal = QString::number(vNormal.x).append(" ").append(QString::number(vNormal.y)).append(" ").append(QString::number(vNormal.z));
		pPoly3D->setMetaData(DPX_NORMAL,strNormal);//法向量
		pPoly3D->setMetaData(DPX_RELATED_PLANE_UID,strRelateID);//关联的ID
		//pPoly3D->setMetaData(DPX_OBJECT_TYPE_NAME,eObj_CrossWalkLine); //地物类型

		pPoly3D->addChild(pPlane);
		vecLines.push_back(pPoly3D);
	}
	return vecLines;
}


double dpxCrossWalkTool::GetWidthFormBorderLine(ccPolyline* pInnerBorderLine)
{
	int nSize = pInnerBorderLine->size();
	if(nSize<3)
		return -1.0;
	CCVector3 pt0 = *(pInnerBorderLine->getPoint(0));
	CCVector3 pt1 = *(pInnerBorderLine->getPoint(1));
	CCVector3 pt2 = *(pInnerBorderLine->getPoint(2));
	double dDis01 = sqrt(pow((pt0.x-pt1.x),2.0)+pow((pt0.y-pt1.y),2.0)+pow((pt0.z-pt1.z),2.0));
	double dDis12 = sqrt(pow((pt2.x-pt1.x),2.0)+pow((pt2.y-pt1.y),2.0)+pow((pt2.z-pt1.z),2.0));

	return dDis01 > dDis12 ? dDis12 : dDis01;
}

void dpxCrossWalkTool::onMouseReleaseEvent(int x,int y)
{
	if(m_window==nullptr)
		return;

	if(m_VNodeInfo.m_pLine==nullptr || m_VNodeInfo.m_nNodeIndex==-1)
		return;

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

	if(!pLine->hasMetaData(DPX_RELATED_PLANE_UID) || !pLine->hasMetaData(DPX_NORMAL))
		return;

	//获取小面信息并移除旧的小面
	int nInnerPonCount = -1;
	double dWidth = -1.0;
	bool bShoudAddChildInnerPon = false;
	bool bHasObjType = pLine->hasMetaData(DPX_OBJECT_TYPE_NAME);
	if(bHasObjType)
	{
		dpxObjectType eType = dpxObjectType(pLine->getMetaData(DPX_OBJECT_TYPE_NAME).toInt());
		if(eType==eObj_CrossWalkLine)
		{
			ccHObject::Container LineChildren;
			pLine->filterChildren(LineChildren,false,CC_TYPES::POLY_LINE);
			nInnerPonCount = LineChildren.size();
			if(LineChildren.size()>0)
			{
				bShoudAddChildInnerPon = true;
				ccPolyline* pInnerBorderLine = ccHObjectCaster::ToPolyline(LineChildren.at(0));
				if(pInnerBorderLine!=nullptr)
					dWidth = GetWidthFormBorderLine(pInnerBorderLine);
			}
			//移除所有小面
			for(int i = 0;i<nInnerPonCount;i++)
			{
				pLine->removeChild(LineChildren.at(i));
			}
		}
	}

	//删除旧的面
	QString strUID = pLine->getMetaData(DPX_RELATED_PLANE_UID).toString();
	ccHObject::Container vecHObjs;
	dpxSnapHelper::Instance()->FindAllObjs(vecHObjs,CC_TYPES::PLANE);//旧的删除
	for(int i =0;i<vecHObjs.size();i++)
	{
		ccPlane* plane = ccHObjectCaster::ToPlane(vecHObjs[i]);
		if(plane==nullptr)
			continue;
		if(!plane->hasMetaData(DPX_RELATED_PLANE_UID))
			continue;
		QString sUID = plane->getMetaData(DPX_RELATED_PLANE_UID).toString();
		if(sUID.compare(strUID,Qt::CaseInsensitive)==0)
		{
			pLine->removeChild(plane);
		}
	}

	//更新线
	CCVector3* modefyPt = const_cast<CCVector3*>(pLine->getPointPersistentPtr(nIndex));
	*modefyPt = newPickPt;

	double rms = 0.0; //output for rms
	ccFitPlane* pNewPlane = nullptr;
	int nSize = pLine->size();
	pNewPlane = ccFitPlane::Fit(pLine->getAssociatedCloud(), &rms);
	if (pNewPlane) //valid fit
	{
		//make plane to add to display
		pNewPlane->setVisible(true);
		pNewPlane->setSelectionBehavior(ccHObject::SELECTION_IGNORED);
		pNewPlane->setDisplay(m_window);

		CCVector3 vNormal = pNewPlane->getNormal();
		QString strNormal = QString::number(vNormal.x).append(" ").append(QString::number(vNormal.y)).append(" ").append(QString::number(vNormal.z));
		pLine->setMetaData(DPX_NORMAL,strNormal);
		pNewPlane->setMetaData(DPX_RELATED_PLANE_UID,strUID);
		pLine->addChild(pNewPlane);
	}

	if(bShoudAddChildInnerPon && dWidth>0 && nInnerPonCount>0)
	{
		std::vector<CCVector3> BorderPts = pNewPlane->get4CornerPts();
		vector<ccPolyline*> vecLines = CreatePlane(dWidth,nInnerPonCount,BorderPts);
		if(vecLines.size()==nInnerPonCount)
		{
			for(int i = 0;i< vecLines.size();i++)
			{
				vecLines[i]->setName("CrossWalkPon");//设置名称
				pLine->addChild(vecLines[i]);// 临时加入
			}
		}
	}

	pLine->invalidateBoundingBox();
	m_window->removeFromOwnDB(m_pPickRoot);
	m_app->addToDB(m_pPickRoot);

	m_polyTip->setEnabled(false);
	m_bMoveNode = false;

	m_window->redraw(false, true);
}

//called when a point in a point cloud gets picked while this tool is active
//pointPicked(pi.entity, pi.itemIndex, pi.clickPoint.x(), pi.clickPoint.y(), pi.P3D); //map straight to pointPicked function
void dpxCrossWalkTool::pointPicked(ccHObject* insertPoint, unsigned itemIdx, ccPointCloud* cloud, const CCVector3& P,int x/*=0*/,int y/*=0*/)
{
	if(m_nToolState)//编辑状体
		return;

	if(m_nCreateType==0)
	{
		PickMutilPts(P,x,y);
	}
	else if(m_nCreateType==1)
	{
		ThreePtPick(P,x,y);
	}

	m_window->redraw(false, false);
}

//采集多个点 最后拟合平面
void  dpxCrossWalkTool::PickMutilPts(const CCVector3& P ,int x,int y)
{
//if the 3D polyline doesn't exist yet, we create it
	if (!m_poly3D || !m_poly3DVertices)
	{
		m_poly3DVertices = new ccPointCloud("Vertices");
		m_poly3DVertices->setEnabled(false);
		m_poly3DVertices->setDisplay(m_window);

		m_poly3D = new ccPolyline(m_poly3DVertices);
		m_poly3D->setName("CrossWalk Line");
		m_poly3D->setTempColor(ccColor::green);
		m_poly3D->set2DMode(false);
		m_poly3D->addChild(m_poly3DVertices);
		m_poly3D->setWidth(1);

		m_pPickRoot->addChild(m_poly3D);
	}

	//try to add one more point
	if (	!m_poly3DVertices->reserve(m_poly3DVertices->size() + 1)
		||	!m_poly3D->reserve(m_poly3DVertices->size() + 1))
		return;

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
}

//采集三个点 三点拟合平面
void  dpxCrossWalkTool::ThreePtPick(const CCVector3& P ,int x,int y)
{
	//if the 3D polyline doesn't exist yet, we create it
	if (!m_poly3D || !m_poly3DVertices)
	{
		m_poly3DVertices = new ccPointCloud();
		m_poly3DVertices->setEnabled(false);
		m_poly3DVertices->setDisplay(m_window);

		m_poly3D = new ccPolyline(m_poly3DVertices);
		m_poly3D->setTempColor(ccColor::green);
		m_poly3D->set2DMode(false);
		m_poly3D->addChild(m_poly3DVertices);
		m_poly3D->setWidth(1);

		m_pPickRoot->addChild(m_poly3D);
	}

	int nSize = m_poly3DVertices->size();
	if(nSize==0||nSize==1)
	{
		//try to add one more point
		if (!m_poly3DVertices->reserve(m_poly3DVertices->size() + 1)
			||!m_poly3D->reserve(m_poly3DVertices->size() + 1))
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
		}

		m_polyTip->setEnabled(true);
	}
	else if(nSize ==2)//构造平面
	{
		CCVector3 PtA = *(m_poly3DVertices->getPoint(0));
		CCVector3 PtB = *(m_poly3DVertices->getPoint(1));
		CCVector3 PtC = P;

		//C在AB的投影点为P 再求P的对角点Q 组成矩形
		CCVector3 ptP  = dpxAlgorithmFun::PointProjectionToLine(PtA,PtB,PtC);
		CCVector3 ptQ(PtA.x-ptP.x+PtC.x,PtA.y-ptP.y+PtC.y,PtA.z-ptP.z+PtC.z);
		//四个点A P C Q
		m_poly3DVertices->clear();
		m_poly3D->clear(true);
		m_poly3DVertices->reserve(4);
		m_poly3D->reserve(5);

		m_poly3DVertices->addPoint(PtA);
		m_poly3DVertices->addPoint(ptP);
		m_poly3DVertices->addPoint(PtC);
		m_poly3DVertices->addPoint(ptQ);

		m_poly3D->addPointIndex(0,4);

		double rms = 0.0;
		ccFitPlane* pBorderPlane = ccFitPlane::Fit(m_poly3DVertices, &rms);//重新拟合平面
		setCrossWalkBorder(m_poly3D,pBorderPlane);

		m_pBorderLine = m_poly3D;
		m_pBorderPlane = pBorderPlane;

		m_polyTip->setEnabled(false);
		m_poly3D = 0;
		m_poly3DVertices = 0;
		m_nToolState=1;//采集状态结束，默认编辑状态
	}
}
