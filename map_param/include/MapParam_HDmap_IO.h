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
namespace hdmap{
class MapIO{
public:	
	MapIO();
	MapIO(hdmap_proto::Map & pHDmap);

	void ReadTextFileToProtobufMap( std::string FilePath);  
	void SaveProtobufMapToTextFile( std::string SavePath); 

	void ReadBinaryFileToProtobufMap(std::string FilePath);
	void SaveProtobufMapToBinaryFile(std::string SavePath);

private:
	hdmap_proto::Map HDmap;

	void ListMap(hdmap_proto::Map & map);
	void ListHeader(const hdmap_proto::Header & header);
	void ListSections(hdmap_proto::Section & section); // TO DO

	void ListCrosswlks(hdmap_proto::CrossWalk & crosswalk);
	void ListJunctions(hdmap_proto::Junction & junction);
	void ListParkingSpaces(hdmap_proto::ParkingSpace & parkingspace);

	// TO DO
	void ListStopLines(hdmap_proto::StopLine & stopline);
	void ListSpeedBumps(hdmap_proto::SpeedBump & speedbump);
	void ListPoles(hdmap_proto::Pole & pole);
	void ListBoards(hdmap_proto::Board & board);
	void ListZones(hdmap_proto::Zone & zone);
	void ListTrafficLights(hdmap_proto::TrafficLight & traffic_light);
	void ListTrafficSigns(hdmap_proto::TrafficSign & traffic_sign);
	void ListTiles(hdmap_proto::Tile & tile);
};

} // end namespace hdmap
#endif