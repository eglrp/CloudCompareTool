
//by duans 2018.6.19
#ifndef _DPX_MAP_MANAGER_H_
#define _DPX_MAP_MANAGER_H_
#pragma once

#include "dpxMap_IO.h"
#include "dpxMap.h"
#include "ccPolyline.h"
#include "dpxWriter.h"
#include "dpxReader.h"

struct  refLineInfo
{
	int m_nID;
	CCVector3 m_firstPt;
	CCVector3 m_lastPt;
	bool m_bHasHeadSet;
	bool m_bHasTailSet;
	refLineInfo()
	{
		m_bHasHeadSet = false;
		m_bHasTailSet = false;
	}
};
/*
* dpxMap
*/
class  DPX_MAP_API dpxMapManager
{
public:
	dpxMapManager();
	virtual ~dpxMapManager();
public:
	//创建地图
	dpxMap* createMap(QString strMapName,std::vector<QString> vecLryNames);
	//定制HDMap图层
	dpxMap* createHDMap(); //创建HDMap

	//设置输出的Writer 可拓展不同格式的输出
	void setWriter(dpxWriter* pWriter) { m_pWriter = pWriter;}
	dpxWriter* getWriter()	{return m_pWriter;}

	void setReader(dpxReader* pReader) { m_pReader = pReader;}
	dpxReader* getReader()	{return m_pReader;}

	bool ImportMap(dpxMap* pMap,const QString& strOutFile);
	//手动输出
	bool ManMadeOutPutMap(dpxMap* pMap,const QString& strOutFile);
	//自动输出
	bool AutoOutPutMap2Protobuf(dpxMap* pMap,const QString& strOutFile);
	bool AutoOutPutMap(ccHObject* pMapRootData,const QString& strOutFile);

	//自动构建Junction
	bool AutoCreateJunction(dpxMap* pMap);
protected:
	void Export_Recursion(ccHObject* pObj);
	void ExportPlane(ccPolyline* pLine,int eType);
	void ExportLine(ccPolyline* pLine,int eType);
	void ExportOfficeLightPole(ccPolyline* pLine,int eType);

	void outPtCoordinate(CCVector3 pt);

private:
	QTextStream m_textStream;
	dpxWriter* m_pWriter;
	dpxReader* m_pReader;
};

#endif
