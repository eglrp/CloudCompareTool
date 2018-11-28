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
namespace hdmap {
class MapIO {
public:
	MapIO();
	MapIO(hdmap_proto::Map & pHDmap);
	hdmap_proto::Map getHDmap();

	bool readTextFileToProtobufMap( std::string FilePath);  
	bool saveProtobufMapToTextFile( std::string savePath); 

	bool readBinaryFileToProtobufMap(std::string FilePath);
	bool saveProtobufMapToBinaryFile(std::string savePath);

private:
	hdmap_proto::Map HDmap;

	void listMap(hdmap_proto::Map & map);
	void listHeader(const hdmap_proto::Header & header);
	void listSections(hdmap_proto::Section & section); // TO DO

	void listCrosswlks(hdmap_proto::CrossWalk & crosswalk);
	void listJunctions(hdmap_proto::Junction & junction);
	void listParkingSpaces(hdmap_proto::ParkingSpace & parkingspace);

	// TO DO
	void listStopLines(hdmap_proto::StopLine & stopline);
	void listSpeedBumps(hdmap_proto::SpeedBump & speedbump);
	void listPoles(hdmap_proto::Pole & pole);
	void listBoards(hdmap_proto::Board & board);
	void listZones(hdmap_proto::Zone & zone);
	void listTrafficLights(hdmap_proto::TrafficLight & traffic_light);
	void listTrafficSigns(hdmap_proto::TrafficSign & traffic_sign);
	void listTiles(hdmap_proto::Tile & tile);
};

} // end namespace hdmap
#endif
