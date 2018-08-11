
#include "dpxProtobufWriter.h"
#include <ccHObjectCaster.h>
#include "dpxMapDefine.h"
//#include "../mapparam/proto/map.pb.h"
//using namespace hdmap_proto;
dpxProtobufWriter::dpxProtobufWriter()
{
}

dpxProtobufWriter::~dpxProtobufWriter()
{
}

void dpxProtobufWriter::outPutMap(dpxMap* pMap)
{
	if(pMap==nullptr || pMap==0)
		return ;

	//hdmap_proto::Map *pProtoMap = new hdmap_proto::Map();
	//pProtoMap->add_roads();

//	pMap->get
//	dpxGeoEngine->getLightLyr()
//
//	ccPolyline* pLine = pObj && pObj->isA(CC_TYPES::POLY_LINE) ? static_cast<ccPolyline*>(pObj) : 0;
//	if(pLine!=0 && pLine != nullptr)
//	{
//		dpxObjectType eType = eObj_Unknown;
//		bool bHasObjType = pLine->hasMetaData(DPX_OBJECT_TYPE_NAME);
//		if(bHasObjType)
//            eType = dpxObjectType(pLine->getMetaData(DPX_OBJECT_TYPE_NAME).toInt());
//
//		if(eType==eObj_RoadRefLine) //道路线
//		{
//			ExportLine(pLine,eType);
//		}
//		else if(eType==eObj_RoadLine ) //RoadLine(Lane)
//		{
//			ExportLine(pLine,eType);
//		}
//		else if(eType==eObj_RoadStopLine) //StopLine
//		{
//			ExportLine(pLine,eType);
//		}
//		else if(eType==eObj_ZebraCrossingLine) //Zebra Line
//		{
//			ExportLine(pLine,eType);
//		}
//		else if(eType==eObj_OfficeLight_pole) //圆柱特征
//		{
//			ExportOfficeLightPole(pLine,eType);
//		}
//		else if(eType==eObj_OfficeLight || eType==eObj_Indication_OnRoad || eType==eObj_Indication_InSpace) //Plane
//		{
//			ExportPlane(pLine,eType);
//		}
//		else
//		{
//			//...
//		}
//	}
//
//	int nSize = pObj->getChildrenNumber();
//	if(nSize>0)
//	{
//		for(int i=0;i<nSize;i++)
//		{
//			ccHObject* pChildObj = pObj->getChild(i);
//			Export_Recursion2XML(pChildObj);
//		}
//	}
	return ;
}
