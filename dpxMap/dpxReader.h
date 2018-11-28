
//by duans 2018.6.14
#ifndef _DPX_READER_H_
#define _DPX_READER_H_
#pragma once

#include "dpxMap.h"
class  DPX_MAP_API dpxReader
{
public:
	dpxReader() { }
	virtual ~dpxReader() { }

public:
	//输出Map
	virtual bool ImportMap(dpxMap* pMap,const QString& strImportFile) = 0;
};

#endif
