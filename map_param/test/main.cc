
#include "map.pb.h"
#include "MapParam_HDmap_IO.h"

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



void InitialHDmap_proto(hdmap_proto::Map & HDmap)

{
	// ************  Set head  ************************************  

	hdmap_proto::Header* head = HDmap.mutable_header();
	head->set_version("1.0");
	head->set_date("30-6-2018");
	head->set_projection("NavNet");
	hdmap_proto::Point* low = head->mutable_low();
	low->set_x(0.1); 
	low->set_y(0.1);
	low->set_z(0.1);
	hdmap_proto::Point* high = head->mutable_high();
	high->set_x(0.2); 
	high->set_y(0.2);
	high->set_z(0.2);



// ************  Set crosswalks  ************************************

	hdmap_proto::CrossWalk* crosswalks = HDmap.add_crosswalks();
	hdmap_proto::Id* id = crosswalks->mutable_id();
	id->set_id(10);
	id->set_name("crosswalk_ids");

	hdmap_proto::Id* tile_ids = crosswalks->add_tile_ids();
	tile_ids->set_id(0);
	tile_ids->set_name("A crosswalk");
	tile_ids = crosswalks->add_tile_ids();
	tile_ids->set_id(1);
	tile_ids->set_name("B crosswalk");

	crosswalks->set_name("No.1 streat ZhongGuanCun");

	hdmap_proto::Polygon* border = crosswalks->mutable_border();
	hdmap_proto::Point* points = border->add_points();
	points->set_x(0.);
	points->set_y(0.);
	points->set_z(0.);
	points = border->add_points();
	points->set_x(4.);
	points->set_y(4.);
	points->set_z(4.);

	hdmap_proto::Polygon* lines = crosswalks->add_lines();
	points = lines->add_points();
	points->set_x(1.);
	points->set_y(2.);
	points->set_z(3.);
	points = lines->add_points();
	points->set_x(1.12);
	points->set_y(2.12);
	points->set_z(3.12);

// ************  Set junctions  ************************************
	hdmap_proto::Junction* junction = HDmap.add_junctions();
	id = junction->mutable_id();
	id->set_id(11);
	id->set_name("junction_ids");

	tile_ids = junction->add_tile_ids();
	tile_ids->set_id(0);
	tile_ids->set_name("A junc");

	tile_ids = junction->add_tile_ids();
	tile_ids->set_id(1);
	tile_ids->set_name("B junc");

	hdmap_proto::Polygon * polygon = junction->mutable_polygon();
	points = polygon->add_points();
	points->set_x(1.6);
	points->set_y(2.6);
	points->set_z(3.6);
	points = polygon->add_points();
	points->set_x(1.8);
	points->set_y(2.8);
	points->set_z(3.8);


// ************  Set parkingspaces  ************************************
	
	hdmap_proto::ParkingSpace* parkingspace = HDmap.add_parkingspaces();
	id = parkingspace->mutable_id();
	id->set_id(12);
	id->set_name("parkingspace_ids");

    tile_ids = parkingspace->add_tile_ids();
	tile_ids->set_id(0);
	tile_ids->set_name("A parkingspace");

	tile_ids = parkingspace->add_tile_ids();
	tile_ids->set_id(1);
	tile_ids->set_name("B parkingspace");

	hdmap_proto::ParkingSlot * parkingslot = parkingspace->add_parkingslots();
	id = parkingslot->mutable_id();
	id->set_id(01);
	id->set_name("A001");
	polygon = parkingslot->mutable_polygon();
	points = polygon->add_points();
	points->set_x(1.6);
	points->set_y(2.6);
	points->set_z(3.6);
	points = polygon->add_points();
	points->set_x(1.8);
	points->set_y(2.8);
	points->set_z(3.8);

}

int main(void) 
{ 
	hdmap_proto::Map HDmap;
	InitialHDmap_proto(HDmap);
	std::cout<< "initial OK" <<std::endl;
    hdmap::MapIO test(HDmap);
    std::cout<< "***************************** below is TXT file ***********************" <<std::endl;
    test.SaveProtobufMapToTextFile("./HDmapTXT") ;
    test.ReadTextFileToProtobufMap("./HDmapTXT") ;

 //    std::cout<< "***************************** below is Binary file ***********************" <<std::endl;
	// test.SaveProtobufMapToBinaryFile("./HDmapBinary");
	// test.ReadBinaryFileToProtobufMap("./HDmapBinary");


	return 0; 
}