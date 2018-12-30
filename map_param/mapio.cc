#include "mapio.h"

namespace hdmap_op {

std::string MapIO::toString() {
  std::string str;
  if (!map_.ByteSize()) {
    //std::cout << "Warning: Probobuf Map is empty!" << std::endl;
  }
  google::protobuf::TextFormat::PrintToString(map_, &str);
  return str;
}

bool MapIO::saveProtobufMapToBinaryFile(std::string &save_path){
  std::fstream output(save_path.c_str(), ios::out | ios_base::ate | ios::trunc);
  if (!output.is_open()) {
    //std::cout << "Cannot open or creat file: "<< save_path.c_str() << std::endl;
    return false;
  }
  if (!map_.SerializeToOstream(&output)) {
    //std::cout << "Failed to write hdmap_proto::Map msg." << std::endl;
    return false;
  }
  if (!map_.ByteSize()) {
    //std::cout << "Warning: Probobuf Map is empty!" << std::endl;
  }
  output.close();
  return true;
}

bool MapIO::readBinaryFileToProtobufMap(std::string &file_path){
  std::fstream input(file_path.c_str(), ios::in);
  if (!input.is_open()) {
    //std::cout << "Cannot open file: "<< file_path.c_str() << std::endl;
    return false;
  }
  if (!map_.ParseFromIstream(&input)) {
    //std::cout << "Failed to parse hdmap_proto::Map msg." << std::endl;
    return false;
  }
  input.close();

  //std::cout << toString() << std::endl;
  return true;
}

bool MapIO::saveProtobufMapToTextFile(std::string &save_path){
  //首先将protobuf输出到一个string中
  std::string p;
  if (!map_.ByteSize()) {
    std::cout << "Warning: Probobuf Map is empty!" << std::endl;
  }
  google::protobuf::TextFormat::PrintToString(map_, &p);

  //输出到文件中
  std::ofstream fout;
  fout.open(save_path.c_str(), ios::out | ios_base::ate | ios::trunc);
  if (!fout.is_open()) {
    std::cerr << "Cannot open or creat file: " << save_path << std::endl;
    return false;
  }
  fout << p << endl;
  fout.flush();
  fout.close();
  return true;
}

bool MapIO::readTextFileToProtobufMap(std::string &file_path){
  int file_descriptor = open(file_path.c_str(), O_RDONLY);
  if (file_descriptor < 0) {
    //std::cout << "Cannot open file: "<< file_path.c_str() << std::endl;
    return false;
  }
  google::protobuf::io::FileInputStream file_input(file_descriptor);
  file_input.SetCloseOnDelete(true);
  if (!google::protobuf::TextFormat::Parse(&file_input, &map_)){
   // std::cout << "Failed to parse hdmap_proto::Map msg "<< std::endl;
    return false;
  }

  //std::cout << toString() << std::endl;
  return true;
}

} // end namespace hdmap_op
