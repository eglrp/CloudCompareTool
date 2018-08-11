
//by duans 2018.8.10
#ifndef _DPX_PROTOBUF_WRITER_H_
#define _DPX_PROTOBUF_WRITER_H_
#pragma once


#include "dpxMapDefine.h"
#include "dpxWriter.h"


class  DPX_MAP_API dpxProtobufWriter : public dpxWriter
{
public:
	dpxProtobufWriter();
	virtual ~dpxProtobufWriter();

protected:
	virtual void outPutMap(dpxMap* pMap);

};

#endif
