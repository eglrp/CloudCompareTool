#ifndef MAPPARAM_HDMAP_IO_H
#define MAPPARAM_HDMAP_IO_H
#include "map.pb.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fcntl.h>
#include <fstream>
#include <cstdio>
#include <google/protobuf/text_format.h>
#include <google/protobuf/io/zero_copy_stream_impl.h>

using namespace std;
using namespace hdmap_proto;
namespace hdmap_op {
class MapIO {
public:
  MapIO() {}
  MapIO(hdmap_proto::Map &map) : map_(map) {}

  bool readTextFileToProtobufMap(std::string &file_path);  
  bool saveProtobufMapToTextFile(std::string &save_path); 

  bool readBinaryFileToProtobufMap(std::string &file_path);
  bool saveProtobufMapToBinaryFile(std::string &save_path);

  std::string toString();
private:
  hdmap_proto::Map map_;
};

} // end namespace hdmap_op
#endif
