
#include "dpxMapCommonFunc.h"
namespace MapCommon {

bool  ConfimObjType(ccPolyline* pLine,dpxObjectType eType)
{
	if(pLine == nullptr)
		return false;

	bool bHasObjType = pLine->hasMetaData(DPX_OBJECT_TYPE_NAME);
	if(!bHasObjType)
		return false;

	dpxObjectType tempType = dpxObjectType(pLine->getMetaData(DPX_OBJECT_TYPE_NAME).toInt());
	if(tempType==eType)
		return true;

	return false;
}

//应该引入R树索引
bool CreateJunction(dpxMap* pMap,vector<refLineInfo> &refInfos,double dMinDis,double dMaxDis)
{
	if(pMap==nullptr)
		return false;
	int nCount = refInfos.size();
	if(nCount<1)
		return false;
	for(int i = 0;i<nCount;i++)
	{
		if(refInfos[i].m_bHasTailSet)
			continue;

		CCVector3 lastPt = refInfos[i].m_lastPt;

        for(int j=0;j < nCount;j++)
        {
			if(i == j)
				continue;

			if(!refInfos[i].m_bHasHeadSet)
			{
				CCVector3 tempfirstPt = refInfos[j].m_firstPt;
			}

			if(!refInfos[i].m_bHasTailSet)
			{
				CCVector3 templastPt = refInfos[j].m_lastPt;
			}
        }
	}
	return true;
}

double  DisTance(CCVector3 pt1,CCVector3 pt2)
{
	return sqrt(pow((pt1.x - pt2.x), 2.0) + pow((pt1.y - pt2.y), 2.0) + pow((pt1.z - pt2.z), 2.0));
}

//前JuncitonID
int  GetRefLinePreID(ccPolyline* pDPXRefLine)
{
	if(pDPXRefLine==nullptr)
		return -1;
	if(pDPXRefLine->hasMetaData(HEAD_JUNCTION_UID))
		return -1;
	return pDPXRefLine->getMetaData(HEAD_JUNCTION_UID).toInt();
}
//后JuncitonID
int  GetRefLineSucID(ccPolyline* pDPXRefLine)
{
	if(pDPXRefLine==nullptr)
		return -1;
	if(pDPXRefLine->hasMetaData(TAIL_JUNCTION_UID))
		return -1;
	return pDPXRefLine->getMetaData(TAIL_JUNCTION_UID).toInt();
}

vector<int>  GetRelatedRefID(ccPolyline* pJunctionLine)
{
	vector<int> vecIDs;
	if(pJunctionLine==nullptr)
		return  vecIDs;
	if(!pJunctionLine->hasMetaData(RELATED_REFLINE_UID))
		return  vecIDs;
    QString strValue =  pJunctionLine->getMetaData(RELATED_REFLINE_UID).toString();
    QStringList strList = strValue.split(';',QString::SkipEmptyParts);
    for(int i =0;i<strList.size();i++)
	{
		vecIDs.push_back(strList.at(i).toInt());
	}

	return  vecIDs;
}


QString getRefIDValue(const vector<int>& vecRefIDs)
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

}// nameSpace MapCommon

