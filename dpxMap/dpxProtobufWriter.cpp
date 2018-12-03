
#include "dpxProtobufWriter.h"
#include <ccHObjectCaster.h>
#include <ccPlane.h>
#include <QDateTime>
#include "dpxMapDefine.h"
#include "dpxMapCommonFunc.h"

dpxProtobufWriter::dpxProtobufWriter()
{
}

dpxProtobufWriter::~dpxProtobufWriter()
{
}

bool dpxProtobufWriter::outPutMap(dpxMap* pMap,const QString& strOutFile)
{
	if(pMap==nullptr || pMap==0)
		return false;

	//----------------1:mapHeader-------------------------
	hdmap_proto::Map* pProtoMap = new hdmap_proto::Map();
	SettingMapHeader(pProtoMap->mutable_header()); //HeadInfo

	//----------------2:Section--------------------------
	OutPutSection(pMap,pProtoMap);

	//----------------3:OutPut independence--------------
	OutPutOtherAll(pMap,pProtoMap);

	//-------------4 保存文档 文本与二进制各输出一份-----------
	hdmap_op::MapIO mapIO(*pProtoMap);
	std::string strFileName = strOutFile.toStdString();
	mapIO.saveProtobufMapToTextFile(strFileName);
	std::string strFile2 = strFileName + "v2";
	mapIO.saveProtobufMapToBinaryFile(strFile2);

	return true;
}

bool dpxProtobufWriter::addRefLaneInfo(ccHObject* pRefLineSet,hdmap_proto::Lane* pRefLane)
{
	int nID = 0;
	if(pRefLineSet->hasMetaData(DPX_UID))
		nID = pRefLineSet->getMetaData(DPX_UID).toInt();
	//id 必须添加
	hdmap_proto::Id* id = pRefLane->mutable_id();
	pRefLane->set_function(hdmap_proto::Lane_LaneFunction_CITY_DRIVING);
	id->set_id(0);
	id->set_name("refLane_Ids");

	//每个线段转换后添加到Section
	vector<ccPolyline*> vecLines = dpxMapCommonFunc::getLinesFromLineSet(pRefLineSet);
	for(int i = 0;i<vecLines.size();i++)
	{
		ccPolyline* pLine = vecLines[i];
		hdmap_proto::CurveLine* pCurveLine = pRefLane->add_lines();
		ccLine2ProtoCurveLine(pLine,pCurveLine);
	}

	return true;
}

bool dpxProtobufWriter::addRoadLaneInfo(ccHObject* pRoadLineSet,hdmap_proto::Lane* pRoadLane,int nID)
{
	//id 必须添加
	hdmap_proto::Id* id = pRoadLane->mutable_id();
	pRoadLane->set_function(hdmap_proto::Lane_LaneFunction_CITY_DRIVING);
	id->set_id(nID);
	id->set_name("roadLane_ids");

	//每个线段转换后添加到Section
	vector<ccPolyline*> vecLines = dpxMapCommonFunc::getLinesFromLineSet(pRoadLineSet);
	for(int i = 0;i<vecLines.size();i++)
	{
		ccPolyline* pLine = vecLines[i];
		hdmap_proto::CurveLine* pCurveLine = pRoadLane->add_lines();
		ccLine2ProtoCurveLine(pLine,pCurveLine);
	}
	return true;
}

void dpxProtobufWriter::ccLine2ProtoCurveLine(ccPolyline* pCCLine,hdmap_proto::CurveLine* pCurveLine)
{
	if(pCurveLine==nullptr)
		return;
	int nPtCount = pCCLine->size();
	for(int iPt = 0;iPt < nPtCount;iPt++)
	{
		hdmap_proto::Vector3d* pProtoPt =  pCurveLine->add_points();
		const CCVector3* pCCpt = pCCLine->getPoint(iPt);
		pProtoPt->set_x(pCCpt->x);
		pProtoPt->set_y(pCCpt->y);
		pProtoPt->set_z(pCCpt->z);

		//------------------------old------------------------//

//		hdmap_proto::Vector3d* pPt = new hdmap_proto::Vector3d();
//		hdmap_proto::Vector3d* pPrePt = new hdmap_proto::Vector3d();
//		hdmap_proto::Vector3d* pSucPt = new hdmap_proto::Vector3d();
//		//pRefLine坐标构造prefLane

//		hdmap_proto::CurveControl* pControl = pCurveLine->add_controls();
//		const CCVector3* pt1 = pCCLine->getPoint(iPt);
//		createPtotoPt(*pt1,pPt);

//		if(iPt==0) //首点
//		{
//			const CCVector3* pt2 = pCCLine->getPoint(iPt+1);
//			CCVector3 cSucPt = getCtrlPercentPt(*pt1,*pt2);
//			createPtotoPt(cSucPt,pSucPt);
//			pControl->set_allocated_point(pPt);
//			pControl->set_allocated_suc_point(pSucPt);
//		}
//		else if(iPt == nPtCount-1)//尾点
//		{
//			const CCVector3* pt0 = pCCLine->getPoint(iPt-1);
//			CCVector3 cPrePt = getCtrlPercentPt(*pt0,*pt1);
//			createPtotoPt(cPrePt,pPrePt);
//			pControl->set_allocated_point(pPt);
//			pControl->set_allocated_pre_point(pPrePt);
//		}
//		else //中间点
//		{
//			const CCVector3* pt0 = pCCLine->getPoint(iPt-1);
//			CCVector3 cPrePt = getCtrlPercentPt(*pt0,*pt1);
//			createPtotoPt(cPrePt,pPrePt);
//
//			const CCVector3* pt2 = pCCLine->getPoint(iPt+1);
//			CCVector3 cSucPt = getCtrlPercentPt(*pt1,*pt2);
//			createPtotoPt(cSucPt,pSucPt);
//
//			pControl->set_allocated_point(pPt);
//			pControl->set_allocated_pre_point(pPrePt);
//			pControl->set_allocated_suc_point(pSucPt);
//		}
	}
}

//CCVector3 dpxProtobufWriter::getCtrlPercentPt(CCVector3 pt1,CCVector3 pt2)
//{
//	CCVector3 TargetPt;
//	CCVector3 Normal(pt2.x-pt1.x,pt2.y-pt1.y,pt2.z-pt1.z);
//	TargetPt.x = pt1.x + DPX_CTRL_PERCENT * Normal.x;
//	TargetPt.y = pt1.y + DPX_CTRL_PERCENT * Normal.y;
//	TargetPt.z = pt1.z + DPX_CTRL_PERCENT * Normal.z;
//	return TargetPt;
//}



bool dpxProtobufWriter::addStopLineInfo(ccPlane* pPlane,hdmap_proto::StopLine* pStopLine,int nID)
{
	hdmap_proto::Id* id = pStopLine->mutable_id();
	id->set_id(nID);
	id->set_name("StopLine_ids");
	hdmap_proto::Polygon* pPolygon = pStopLine->mutable_border();

	CCVector3 vecNormal = pPlane->getNormal();
	vector<CCVector3> vecPts = pPlane->get4CornerPts();
	for(int i = 0;i<vecPts.size();i++)
	{
		hdmap_proto::Vector3d* pPt = pPolygon->add_points();
		pPt->set_x(vecPts[i].x);
		pPt->set_y(vecPts[i].y);
		pPt->set_z(vecPts[i].z);
	}

	return true;
}


bool dpxProtobufWriter::addPoleInfo(ccPolyline* pDPXLine,hdmap_proto::Pole* pPole,float fRadius,int nID)
{
	const CCVector3* ccFirst = pDPXLine->getPoint(0);
	const CCVector3* ccSecond = pDPXLine->getPoint(1);

	hdmap_proto::Id* id = pPole->mutable_id();
	id->set_id(nID);
	id->set_name("Pole_ids");

	hdmap_proto::Cylinder* pCylinder = pPole->mutable_body();
	pCylinder->set_radius(fRadius);

	hdmap_proto::Vector3d* pStart =pCylinder->add_points();
	pStart->set_x(ccFirst->x);
	pStart->set_y(ccFirst->y);
	pStart->set_z(ccFirst->z);

	hdmap_proto::Vector3d* pEnd =pCylinder->add_points();
	pEnd->set_x(ccSecond->x);
	pEnd->set_y(ccSecond->y);
	pEnd->set_z(ccSecond->z);

	return true;
}

bool dpxProtobufWriter::addOfficLightInfo(ccPlane* pPlane,hdmap_proto::TrafficLight* pTrafficLight,int nID)
{
	hdmap_proto::Id* id = pTrafficLight->mutable_id();
	id->set_id(nID);
	id->set_name("TrafficLight_ids");
	hdmap_proto::Polygon* pPolygon = pTrafficLight->mutable_pborder();

	CCVector3 vecNormal = pPlane->getNormal();
	vector<CCVector3> vecPts = pPlane->get4CornerPts();
	for(int i = 0;i<vecPts.size();i++)
	{
		hdmap_proto::Vector3d* pPt = pPolygon->add_points();
		pPt->set_x(vecPts[i].x);
		pPt->set_y(vecPts[i].y);
		pPt->set_z(vecPts[i].z);
	}
	 return true;
}

bool dpxProtobufWriter::addLanemarkingInfo(ccPolyline* pPolygonLine,hdmap_proto::LaneMarking* pLaneMarking,int nID)
{
	if(pPolygonLine==nullptr || pLaneMarking ==nullptr)
		return false;

	hdmap_proto::Id* id = pLaneMarking->mutable_id();
	id->set_id(nID);
	id->set_name("LaneMarking_ids");
	hdmap_proto::Polygon* pPolygon = pLaneMarking->mutable_border();
	for(int i = 0;i < pPolygonLine->size();i++)
	{
		CCVector3* LinePt = const_cast<CCVector3*>(pPolygonLine->getPointPersistentPtr(i));
		hdmap_proto::Vector3d* pPt = pPolygon->add_points();
		pPt->set_x(LinePt->x);
		pPt->set_y(LinePt->y);
		pPt->set_z(LinePt->z);
	}
    return true;
}

bool dpxProtobufWriter::addBoardInfo(ccPlane* pPlane,hdmap_proto::Board* pBoard,int nID)
{
	hdmap_proto::Id* id = pBoard->mutable_id();
	id->set_id(nID);
	id->set_name("Board_ids");
	hdmap_proto::Polygon* pPolygon = pBoard->mutable_border();

	CCVector3 vecNormal = pPlane->getNormal();
	vector<CCVector3> vecPts = pPlane->get4CornerPts();
	for(int i = 0;i<vecPts.size();i++)
	{
		hdmap_proto::Vector3d* pPt = pPolygon->add_points();
		pPt->set_x(vecPts[i].x);
		pPt->set_y(vecPts[i].y);
		pPt->set_z(vecPts[i].z);
	}
    return true;
}


bool dpxProtobufWriter::addSpeedBumpInfo(ccPlane* pPlane,hdmap_proto::SpeedBump* pSpeedBump,int nID)
{
	hdmap_proto::Id* id = pSpeedBump->mutable_id();
	id->set_id(nID);
	id->set_name("SpeedBump_ids");
	hdmap_proto::Polygon* pPolygon = pSpeedBump->mutable_border();

	CCVector3 vecNormal = pPlane->getNormal();
	vector<CCVector3> vecPts = pPlane->get4CornerPts();
	for(int i = 0;i<vecPts.size();i++)
	{
		hdmap_proto::Vector3d* pPt = pPolygon->add_points();
		pPt->set_x(vecPts[i].x);
		pPt->set_y(vecPts[i].y);
		pPt->set_z(vecPts[i].z);
	}
    return true;
}


bool dpxProtobufWriter::addOfficSignInfo(ccPlane* pPlane,hdmap_proto::TrafficSign* pTrafficSign,int nID)
{
	hdmap_proto::Id* id = pTrafficSign->mutable_id();
	id->set_id(nID);
	id->set_name("TrafficSign_ids");
	if(!pTrafficSign->has_pborder())
		return false;
	hdmap_proto::Polygon* pPolygon = pTrafficSign->mutable_pborder();

	CCVector3 vecNormal = pPlane->getNormal();
	vector<CCVector3> vecPts = pPlane->get4CornerPts();
	for(int i = 0;i<vecPts.size();i++)
	{
		hdmap_proto::Vector3d* pPt = pPolygon->add_points();
		pPt->set_x(vecPts[i].x);
		pPt->set_y(vecPts[i].y);
		pPt->set_z(vecPts[i].z);
	}
    return true;
}

bool dpxProtobufWriter::addParkingSpaceInfo(ccPolyline* pDPXLine,hdmap_proto::ParkingSpace* pParkingSpace,int nID)
{
	if(pDPXLine==nullptr || pParkingSpace==nullptr)
		return false;

	vector<CCVector3> vecBorderPts;
	if(!getRelatedPlaneBorderPts(pDPXLine,vecBorderPts))
		return false;

	hdmap_proto::Id* id = pParkingSpace->mutable_id();
	id->set_id(nID);
	id->set_name("ParkingSpace_ids");

	//Line
	ccHObject::Container vecHObjs;
	pDPXLine->filterChildren(vecHObjs,false,CC_TYPES::POLY_LINE);
	for(int i =0;i<vecHObjs.size();i++)
	{
		ccPolyline* pLine = ccHObjectCaster::ToPolyline(vecHObjs[i]);
		if(pLine==nullptr)
			continue;

		vector<CCVector3> vecPonPts;
		if(!getRelatedPlaneBorderPts(pLine,vecPonPts))
			continue;
		hdmap_proto::ParkingSlot* pParkingSlot = pParkingSpace->add_parking_slots();
		hdmap_proto::Polygon* pPolygon = pParkingSlot->mutable_border();
		for(int j = 0;j<vecPonPts.size();j++)
		{
			hdmap_proto::Vector3d* points = pPolygon->add_points();
			points->set_x(vecPonPts[j].x);
			points->set_y(vecPonPts[j].y);
			points->set_z(vecPonPts[j].z);
		}
	}
	return true;
}


bool dpxProtobufWriter::addCrossWalkInfo(ccPolyline* pDPXLine,hdmap_proto::CrossWalk* pCrossWalk,int nID)
{
	if(pDPXLine==nullptr || pCrossWalk==nullptr)
		return false;

	vector<CCVector3> vecBorderPts;
	if(!getRelatedPlaneBorderPts(pDPXLine,vecBorderPts))
		return false;

	hdmap_proto::Id* id = pCrossWalk->mutable_id();
	id->set_id(nID);
	id->set_name("CrossWalk_ids");

	//Border
	hdmap_proto::Polygon* border = pCrossWalk->mutable_border();
	for(int i =0;i<vecBorderPts.size();i++)
	{
		hdmap_proto::Vector3d* points = border->add_points();
		points->set_x(vecBorderPts[i].x);
		points->set_y(vecBorderPts[i].y);
		points->set_z(vecBorderPts[i].z);
	}

	//Line
	ccHObject::Container vecHObjs;
	pDPXLine->filterChildren(vecHObjs,false,CC_TYPES::POLY_LINE);
	for(int i =0;i<vecHObjs.size();i++)
	{
		ccPolyline* pLine = ccHObjectCaster::ToPolyline(vecHObjs[i]);
		if(pLine==nullptr)
			continue;

		vector<CCVector3> vecPonPts;
		if(!getRelatedPlaneBorderPts(pLine,vecPonPts))
			continue;
		hdmap_proto::Polygon* pInnerBoard = pCrossWalk->add_child_borders();
		for(int j = 0;j<vecPonPts.size();j++)
		{
			hdmap_proto::Vector3d* points = pInnerBoard->add_points();
			points->set_x(vecPonPts[j].x);
			points->set_y(vecPonPts[j].y);
			points->set_z(vecPonPts[j].z);
		}
	}
	return true;
}

bool dpxProtobufWriter::addJunctionInfo(ccPolyline* pDPXine,hdmap_proto::Junction* pJunction)
{
	if(pDPXine==nullptr || pJunction==nullptr)
		return false;

	int nID = pDPXine->getMetaData(DPX_UID).toInt();
	hdmap_proto::Id* pID = pJunction->mutable_id();
	pID->set_id(nID);
	pID->set_name("UID");


	vector<CCVector3> vecPonPts;
	if(!getRelatedPlaneBorderPts(pDPXine,vecPonPts))
		return false;
	hdmap_proto::Polygon* pPolygon = pJunction->mutable_border();
	for(int j = 0;j<vecPonPts.size();j++)
	{
		hdmap_proto::Vector3d* points = pPolygon->add_points();
		points->set_x(vecPonPts[j].x);
		points->set_y(vecPonPts[j].y);
		points->set_z(vecPonPts[j].z);
	}

	vector<int>  vecIDs =  dpxMapCommonFunc::GetRelatedRefID(pDPXine);
	for(int i=0;i<vecIDs.size();i++)
	{
		hdmap_proto::Id* pIds = pJunction->add_link_ids();
		pIds->set_id(vecIDs[i]);
		pIds->set_name("RelatedRefID");
	}

	return true;
}


bool dpxProtobufWriter::getRelatedPlaneBorderPts(ccPolyline* pLine,vector<CCVector3>& vecBorderPts)
{
	if(pLine == nullptr)
		return false;

	if(!pLine->hasMetaData(DPX_RELATED_PLANE_UID) || !pLine->hasMetaData(DPX_NORMAL))
		return false;
	//删除旧的
	QString strUID = pLine->getMetaData(DPX_RELATED_PLANE_UID).toString();
	ccHObject::Container vecHObjs;
	pLine->filterChildren(vecHObjs,false,CC_TYPES::PLANE);
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
			vecBorderPts = plane->get4CornerPts();
			return true;
		}
	}
	return false;
}


//输出 Section
bool dpxProtobufWriter::OutPutSection(dpxMap* pMap,hdmap_proto::Map* protoMap)
{
	//Section部分就是RoadLayer中的
	dpxLayer* pRoadLayer = pMap->getRoadLyr();
	if(pRoadLayer==nullptr)
		return false;

	ccHObject* pRootData = pRoadLayer->getRootData();
	if(pRootData==nullptr)
		return false;
	int nSectionSize = pRootData->getChildrenNumber();
	int nSectionID = -1;
	for(int i =0;i < nSectionSize;i++)
	{
		ccHObject* pSectionObj = pRootData->getChild(i);
		if(pSectionObj==nullptr)
			continue;

		if(!dpxMapCommonFunc::ConfimObjType(pSectionObj,eObj_Section)) //如果是refLine
			continue;

		hdmap_proto::Section* pSection = protoMap->add_sections();
		if(pSection==nullptr)
			continue;

		ccHObject* pRefLineSetObj = dpxMapCommonFunc::getRefLineSet(pSectionObj);
		if(pRefLineSetObj==nullptr)
			continue;

		nSectionID++;
		{ 	//id 必须添加
			hdmap_proto::Id* id = pSection->mutable_id();
			id->set_id(nSectionID);
			id->set_name("Section_ids");
		}

		//add  refLineSet
		hdmap_proto::Lane* pRefLane = pSection->mutable_refline();
		addRefLaneInfo(pRefLineSetObj,pRefLane); //add Lane info

		int  nHeadID = dpxMapCommonFunc::GetRefLinePreID(pSectionObj);
		int  nSucID = dpxMapCommonFunc::GetRefLineSucID(pSectionObj);
		if(nHeadID>-1)
			pSection->add_pred_indices(nHeadID);
		if(nSucID>-1)
			pSection->add_succ_indices(nSucID);

		//----------------------------------------//
		int nRoadID = 0;
		int nStopLineID = -1;
		int nPoleID = -1;
		int nTrafficLightID = -1;
		int nTrafficSignID = -1;
		int nSpeedBumpID = -1;
		int nBorderID = -1;
		int nLanemarking = -1;
		//遍历Selection下的元素
		int ntempSize = pSectionObj->getChildrenNumber();
		for(int nTemp=0;nTemp<ntempSize;nTemp++)
		{
			ccHObject* pUnknownObj = pSectionObj->getChild(nTemp);
			if(!pUnknownObj->hasMetaData(DPX_OBJECT_TYPE_NAME))
				continue;

			ccPolyline* pUnknownLine = ccHObjectCaster::ToPolyline(pUnknownObj);
			dpxObjectType eType = dpxObjectType(pUnknownObj->getMetaData(DPX_OBJECT_TYPE_NAME).toInt());
			if(eType==eObj_RoadLineSet)
			{
				//road
				nRoadID ++;//从1开始
				hdmap_proto::Lane* pRoadLane = pSection->add_lanes();
				addRoadLaneInfo(pUnknownObj,pRoadLane,nRoadID); //改成Obj
			}
			else if(eType==eObj_RoadStopLine)
			{
				if(pUnknownLine==nullptr || !pUnknownLine->hasMetaData(DPX_RELATED_PLANE_UID))
					continue;

				QString strUID = pUnknownLine->getMetaData(DPX_RELATED_PLANE_UID).toString();
				ccHObject::Container vecHObjs;
				pUnknownLine->filterChildren(vecHObjs,true,CC_TYPES::PLANE);
				for(int i =0;i<vecHObjs.size();i++)
				{
					ccPlane* pPlane = ccHObjectCaster::ToPlane(vecHObjs[i]);
					if(pPlane==nullptr)
						continue;
					if(pPlane->get4CornerPts().size()!=4)
						continue;
					if(!pPlane->hasMetaData(DPX_RELATED_PLANE_UID))
						continue;

					QString sUID = pPlane->getMetaData(DPX_RELATED_PLANE_UID).toString();
					if(sUID.compare(strUID,Qt::CaseInsensitive)==0)//
					{
						nStopLineID++;
						hdmap_proto::StopLine* pStopLine = pSection->add_stoplines();
						addStopLineInfo(pPlane,pStopLine,nStopLineID);
						break;
					}
				}
			}
			else if(eType==eObj_TrafficLight_pole) //红绿灯柱子 圆柱体
			{
				if(pUnknownLine==nullptr || pUnknownLine->size()<3)
					continue;
				if(!pUnknownLine->hasMetaData(DPX_RADIUS))
					continue;
				float radius = pUnknownLine->getMetaData(DPX_RADIUS).toString().toFloat();
				if(radius<0)
					continue;

				nPoleID++;
				hdmap_proto::Pole* pPole = pSection->add_poles();
				addPoleInfo(pUnknownLine,pPole,radius,nPoleID);
			}
			else if(eType==eObj_TrafficLight) //面
			{
				if(pUnknownLine==nullptr || !pUnknownLine->hasMetaData(DPX_RELATED_PLANE_UID))
					continue;

				QString strUID = pUnknownLine->getMetaData(DPX_RELATED_PLANE_UID).toString();
				ccHObject::Container vecHObjs;
				pUnknownLine->filterChildren(vecHObjs,true,CC_TYPES::PLANE);
				for(int i =0;i<vecHObjs.size();i++)
				{
					ccPlane* pPlane = ccHObjectCaster::ToPlane(vecHObjs[i]);
					if(pPlane==nullptr)
						continue;
					if(pPlane->get4CornerPts().size()!=4)
						continue;
					if(!pPlane->hasMetaData(DPX_RELATED_PLANE_UID))
						continue;

					QString sUID = pPlane->getMetaData(DPX_RELATED_PLANE_UID).toString();
					if(sUID.compare(strUID,Qt::CaseInsensitive)==0)//
					{
						nTrafficLightID++;
						hdmap_proto::TrafficLight* pTrafficLight = pSection->add_traffic_lights();
						addOfficLightInfo(pPlane,pTrafficLight,nTrafficLightID);
					}
				}
			}
			else if(eType==eObj_TrafficSign)
			{
				if(pUnknownLine==nullptr || !pUnknownLine->hasMetaData(DPX_RELATED_PLANE_UID))
					continue;
				QString strUID = pUnknownLine->getMetaData(DPX_RELATED_PLANE_UID).toString();
				ccHObject::Container vecHObjs;
				pUnknownLine->filterChildren(vecHObjs,true,CC_TYPES::PLANE);
				for(int i =0;i<vecHObjs.size();i++)
				{
					ccPlane* pPlane = ccHObjectCaster::ToPlane(vecHObjs[i]);
					if(pPlane==nullptr)
							continue;
					if(pPlane->get4CornerPts().size()!=4)
						continue;
					if(!pPlane->hasMetaData(DPX_RELATED_PLANE_UID))
						continue;
					QString sUID = pPlane->getMetaData(DPX_RELATED_PLANE_UID).toString();
					if(sUID.compare(strUID,Qt::CaseInsensitive)==0)//
					{
						nTrafficSignID++;
						hdmap_proto::TrafficSign* pTrafficSign = pSection->add_traffic_signs();
						addOfficSignInfo(pPlane,pTrafficSign,nTrafficSignID);
					}
				}
			}
			else if(eType==eObj_SpeedBump)
			{
				if(pUnknownLine==nullptr || !pUnknownLine->hasMetaData(DPX_RELATED_PLANE_UID))
					continue;
				QString strUID = pUnknownLine->getMetaData(DPX_RELATED_PLANE_UID).toString();
				ccHObject::Container vecHObjs;
				pUnknownLine->filterChildren(vecHObjs,true,CC_TYPES::PLANE);
				for(int i =0;i<vecHObjs.size();i++)
				{
					ccPlane* pPlane = ccHObjectCaster::ToPlane(vecHObjs[i]);
					if(pPlane==nullptr)
						continue;
					if(pPlane->get4CornerPts().size()!=4)
						continue;
					if(!pPlane->hasMetaData(DPX_RELATED_PLANE_UID))
						continue;
					QString sUID = pPlane->getMetaData(DPX_RELATED_PLANE_UID).toString();
					if(sUID.compare(strUID,Qt::CaseInsensitive)==0)//
					{
						nSpeedBumpID++;
						hdmap_proto::SpeedBump* pSpeedBump = pSection->add_speedbumps();
						addSpeedBumpInfo(pPlane,pSpeedBump,nSpeedBumpID);
					}
				}
			}
			else if(eType==eObj_Board)
			{
				if(pUnknownLine==nullptr || !pUnknownLine->hasMetaData(DPX_RELATED_PLANE_UID))
					continue;
				QString strUID = pUnknownLine->getMetaData(DPX_RELATED_PLANE_UID).toString();
				ccHObject::Container vecHObjs;
				pUnknownLine->filterChildren(vecHObjs,true,CC_TYPES::PLANE);
				for(int i =0;i<vecHObjs.size();i++)
				{
					ccPlane* pPlane = ccHObjectCaster::ToPlane(vecHObjs[i]);
					if(pPlane==nullptr)
						continue;
					if(pPlane->get4CornerPts().size()!=4)
						continue;
					if(!pPlane->hasMetaData(DPX_RELATED_PLANE_UID))
						continue;
					QString sUID = pPlane->getMetaData(DPX_RELATED_PLANE_UID).toString();
					if(sUID.compare(strUID,Qt::CaseInsensitive)==0)//
					{
						nBorderID++;
						hdmap_proto::Board* pBoard = pSection->add_boards();
						addBoardInfo(pPlane,pBoard,nBorderID);
					}
				}
			}
			else if(eType==eObj_LaneMarking)
			{
				if(pUnknownLine==nullptr)
					continue;
				nLanemarking++;
				hdmap_proto::LaneMarking* pLaneMarking = pSection->add_lane_markings();
				addLanemarkingInfo(pUnknownLine,pLaneMarking,nLanemarking);
			}
		}
	}
	return true;
}

//输出其余信息
bool dpxProtobufWriter::OutPutOtherAll(dpxMap* pMap,hdmap_proto::Map* protoMap)
{
	LayerVec pVecLyrs = pMap->GetAllLayers();
	int nStopLineID = -1;
	int nTrafficLightID = -1;
	int nTrafficSignID = -1;
	int nPoleID = -1;

	int nCrossWalkID = -1;	//
	int nSpeedBumpID = -1;
	int nBorderID = -1;
	int nParkingSpace = -1;

	for(int i = 0;i<pVecLyrs.size();i++)
	{
		dpxLayer* pLyr = pVecLyrs[i] ;
		 if(pLyr==nullptr || pLyr->GetType()== eOT_Road)
			continue;
		ccHObject* pRootData = pLyr->getRootData();
		int nNumber = pRootData->getChildrenNumber();
		for(int i = 0;i<nNumber;i++)
		{
			ccHObject* pObj =  pRootData->getChild(i);
			if(!pObj->hasMetaData(DPX_OBJECT_TYPE_NAME))
				continue;

			ccPolyline* pUnknownLine = pObj && pObj->isA(CC_TYPES::POLY_LINE) ? static_cast<ccPolyline*>(pObj) : 0;
			if(pUnknownLine==0)
				continue;

			dpxObjectType eType = dpxObjectType(pObj->getMetaData(DPX_OBJECT_TYPE_NAME).toInt());
			if(eType==eObj_RoadStopLine)
			{
				if(!pUnknownLine->hasMetaData(DPX_RELATED_PLANE_UID))
					continue;

				QString strUID = pUnknownLine->getMetaData(DPX_RELATED_PLANE_UID).toString();
				ccHObject::Container vecHObjs;
				pUnknownLine->filterChildren(vecHObjs,true,CC_TYPES::PLANE);
				for(int i =0;i<vecHObjs.size();i++)
				{
					ccPlane* pPlane = ccHObjectCaster::ToPlane(vecHObjs[i]);
					if(pPlane==nullptr)
						continue;
					if(!pPlane->hasMetaData(DPX_RELATED_PLANE_UID))
						continue;

					QString sUID = pPlane->getMetaData(DPX_RELATED_PLANE_UID).toString();
					if(sUID.compare(strUID,Qt::CaseInsensitive)==0)//
					{
						nStopLineID++;
						hdmap_proto::StopLine* pStopLine = protoMap->add_stoplines();
						addStopLineInfo(pPlane,pStopLine,nStopLineID);
						break;
					}
				}
			}
			if(eType==eObj_CrossWalkLine)
			{
				nCrossWalkID++;
				hdmap_proto::CrossWalk* pCrossWalk = protoMap->add_crosswalks();
				addCrossWalkInfo(pUnknownLine,pCrossWalk,nCrossWalkID);
			}
			else if(eType==eObj_TrafficLight_pole) //红绿灯柱子 圆柱体
			{
				if(pUnknownLine->size()<3)
					continue;
				if(!pUnknownLine->hasMetaData(DPX_RADIUS))
					continue;
				float radius = pUnknownLine->getMetaData(DPX_RADIUS).toString().toFloat();
				if(radius<0)
					continue;

				nPoleID++;
				hdmap_proto::Pole* pPole = protoMap->add_poles();
				addPoleInfo(pUnknownLine,pPole,radius,nPoleID);
			}
			else if(eType==eObj_TrafficLight) //面
			{
				if(!pUnknownLine->hasMetaData(DPX_RELATED_PLANE_UID))
					continue;

				QString strUID = pUnknownLine->getMetaData(DPX_RELATED_PLANE_UID).toString();
				ccHObject::Container vecHObjs;
				pUnknownLine->filterChildren(vecHObjs,true,CC_TYPES::PLANE);
				for(int i =0;i<vecHObjs.size();i++)
				{
					ccPlane* pPlane = ccHObjectCaster::ToPlane(vecHObjs[i]);
					if(pPlane==nullptr)
						continue;
					if(!pPlane->hasMetaData(DPX_RELATED_PLANE_UID))
						continue;

					QString sUID = pPlane->getMetaData(DPX_RELATED_PLANE_UID).toString();
					if(sUID.compare(strUID,Qt::CaseInsensitive)==0)//
					{
						nTrafficLightID++;
						hdmap_proto::TrafficLight* pTrafficLight = protoMap->add_traffic_lights();
						addOfficLightInfo(pPlane,pTrafficLight,nTrafficLightID);
					}
				}
			}
			else if(eType==eObj_TrafficSign )
			{
				if(!pUnknownLine->hasMetaData(DPX_RELATED_PLANE_UID))
					continue;
				QString strUID = pUnknownLine->getMetaData(DPX_RELATED_PLANE_UID).toString();
				ccHObject::Container vecHObjs;
				pUnknownLine->filterChildren(vecHObjs,true,CC_TYPES::PLANE);
				for(int i =0;i<vecHObjs.size();i++)
				{
					ccPlane* pPlane = ccHObjectCaster::ToPlane(vecHObjs[i]);
					if(pPlane==nullptr)
							continue;
					if(!pPlane->hasMetaData(DPX_RELATED_PLANE_UID))
						continue;
					QString sUID = pPlane->getMetaData(DPX_RELATED_PLANE_UID).toString();
					if(sUID.compare(strUID,Qt::CaseInsensitive)==0)//
					{
						nTrafficSignID++;
						hdmap_proto::TrafficSign* pTrafficSign = protoMap->add_traffic_signs();
						addOfficSignInfo(pPlane,pTrafficSign,nTrafficSignID);
					}
				}
			}
			else if(eType==eObj_SpeedBump)
			{
				if(!pUnknownLine->hasMetaData(DPX_RELATED_PLANE_UID))
					continue;
				QString strUID = pUnknownLine->getMetaData(DPX_RELATED_PLANE_UID).toString();
				ccHObject::Container vecHObjs;
				pUnknownLine->filterChildren(vecHObjs,true,CC_TYPES::PLANE);
				for(int i =0;i<vecHObjs.size();i++)
				{
					ccPlane* pPlane = ccHObjectCaster::ToPlane(vecHObjs[i]);
					if(pPlane==nullptr)
						continue;
					if(!pPlane->hasMetaData(DPX_RELATED_PLANE_UID))
						continue;
					QString sUID = pPlane->getMetaData(DPX_RELATED_PLANE_UID).toString();
					if(sUID.compare(strUID,Qt::CaseInsensitive)==0)//
					{
						nSpeedBumpID++;
						hdmap_proto::SpeedBump* pSpeedBump = protoMap->add_speedbumps();
						addSpeedBumpInfo(pPlane,pSpeedBump,nSpeedBumpID);
					}
				}
			}
			else if(eType==eObj_Board)
			{
				if(!pUnknownLine->hasMetaData(DPX_RELATED_PLANE_UID))
					continue;
				QString strUID = pUnknownLine->getMetaData(DPX_RELATED_PLANE_UID).toString();
				ccHObject::Container vecHObjs;
				pUnknownLine->filterChildren(vecHObjs,true,CC_TYPES::PLANE);
				for(int i =0;i<vecHObjs.size();i++)
				{
					ccPlane* pPlane = ccHObjectCaster::ToPlane(vecHObjs[i]);
					if(pPlane==nullptr)
						continue;
					if(!pPlane->hasMetaData(DPX_RELATED_PLANE_UID))
						continue;
					QString sUID = pPlane->getMetaData(DPX_RELATED_PLANE_UID).toString();
					if(sUID.compare(strUID,Qt::CaseInsensitive)==0)//
					{
						nBorderID++;
						hdmap_proto::Board* pBoard = protoMap->add_boards();
						addBoardInfo(pPlane,pBoard,nBorderID);
					}
				}
			}
			else if(eType==eObj_ParkingSpace)
			{
				if(!pUnknownLine->hasMetaData(DPX_RELATED_PLANE_UID))
					continue;
				nParkingSpace++;
				hdmap_proto::ParkingSpace* pParkingSpace = protoMap->add_parking_spaces();
				addParkingSpaceInfo(pUnknownLine,pParkingSpace,nParkingSpace);
			}
			else if(eType==eObj_Junction)
			{
				if(!pUnknownLine->hasMetaData(DPX_RELATED_PLANE_UID))
					continue;
				hdmap_proto::Junction* pJunction = protoMap->add_junctions();
				addJunctionInfo(pUnknownLine,pJunction);
			}
		}
	}
	return true;
}


bool dpxProtobufWriter::SettingMapHeader(hdmap_proto::Header* pHead)
{
	// ************  Set head  ************************************
	if(pHead==nullptr)
		return false;

	pHead->set_version("1.0");

	QDateTime current_time =QDateTime::currentDateTime();
	QString sCurrentTime =current_time.toString("yyyy.MM.dd hh:mm:ss");
	pHead->set_date(sCurrentTime.toStdString());
	pHead->set_projection("NavNet");

	hdmap_proto::Vector3d* low = pHead->mutable_low();
	low->set_x(0.1);
	low->set_y(0.1);
	low->set_z(0.1);
	hdmap_proto::Vector3d* high = pHead->mutable_high();
	high->set_x(0.2);
	high->set_y(0.2);
	high->set_z(0.2);

	return true;
}




