
//by duans 2018.6.14
#ifndef _DPX_WRITER_H_
#define _DPX_WRITER_H_
#pragma once

#include "dpxMap.h"
class  DPX_MAP_API dpxWriter
{
public:
	dpxWriter() { }
	virtual ~dpxWriter() { }

public:
	//输出Map
	virtual bool outPutMap(dpxMap* pMap,const QString& strOutFile) = 0;
};

#endif
