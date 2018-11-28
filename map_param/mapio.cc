
#include "mapio.h"
namespace hdmap {

MapIO::MapIO(){
	
}



MapIO::MapIO(hdmap_proto::Map & pHDmap): HDmap(pHDmap){

}


hdmap_proto::Map MapIO::getHDmap(){
	return HDmap;
}

bool MapIO::saveProtobufMapToBinaryFile(std::string savePath){
	std::fstream output(savePath.c_str(), ios::out | ios_base::ate | ios::trunc);
	if(!output.is_open()){
		std::cout << "Cannot open or creat file: "<< savePath.c_str() << std::endl;
		return false;
	}
	if (!HDmap.SerializeToOstream(&output)) { 
		std::cout << "Failed to write hdmap_proto::Map msg." << std::endl; 
		return false; 
	}
	if (!HDmap.ByteSize()){
		std::cout << "Warning: Probobuf Map is empty!" << std::endl; 
	}
	output.close();
	return true;
}

bool MapIO::readBinaryFileToProtobufMap(std::string FilePath){
	std::fstream input(FilePath.c_str(), ios::in );
	if(!input.is_open()){
		std::cout << "Cannot open file: "<< FilePath.c_str() << std::endl;
		return false;
	}
	if (!HDmap.ParseFromIstream(&input)){ 
		std::cout << "Failed to parse hdmap_proto::Map msg." << std::endl; 
		return false; 
	}
  input.close();
  listMap(HDmap);
  return true;
}

bool MapIO::saveProtobufMapToTextFile(std::string savePath){
	//首先将protobuf输出到一个string中
	std::string p;
	if (!HDmap.ByteSize()){
		std::cout << "Warning: Probobuf Map is empty!" << std::endl; 
	}
	google::protobuf::TextFormat::PrintToString(HDmap, &p);
	
	//输出到文件中
	ofstream fout;
	fout.open(savePath.c_str(), ios::out | ios_base::ate | ios::trunc);
	if (!fout.is_open()){
			fprintf(stderr, "open %s fail\n", "./HDmap.txt");
			return false;
	}
	fout << p << endl;
	fout.flush();
	fout.close();
	return true;
}



bool MapIO::readTextFileToProtobufMap(std::string FilePath){
	int fileDescriptor = open(FilePath.c_str(), O_RDONLY);
	if( fileDescriptor < 0 ){
    std::cout << "Cannot open file: "<< FilePath.c_str() << std::endl;
		return false;
	}
	google::protobuf::io::FileInputStream fileInput(fileDescriptor);
	fileInput.SetCloseOnDelete( true );
	if (!google::protobuf::TextFormat::Parse(&fileInput, &HDmap)){
		std::cout << "Failed to parse hdmap_proto::Map msg "<< std::endl;
		return false;
	}else{
		listMap(HDmap);
		return true;
	}
	
}

void MapIO::listMap(hdmap_proto::Map & map){  
	//  header
	if(map.has_header()){
		listHeader(map.header());
	}

	// crosswalk
	for(int i = 0; i < map.crosswalks_size(); ++i){
		hdmap_proto::CrossWalk crosswalk = map.crosswalks(i);
		listCrosswlks(crosswalk);
	}

	// junctions
	for(int i = 0; i < map.junctions_size(); ++i){
		hdmap_proto::Junction junction = map.junctions(i);
		listJunctions(junction);
	}

	// parkingspaces
	for(int i = 0; i < map.parkingspaces_size(); ++i){
		hdmap_proto::ParkingSpace parkingspace = map.parkingspaces(i);
		listParkingSpaces(parkingspace);
	}
	// Road

	// Tile

} 



void MapIO::listHeader(const hdmap_proto::Header & header){
	std::cout<< std::endl<< "header {" << std::endl;
	if(header.has_version()){
		std::cout<< "version : "<< header.version() << std::endl;
	}
	if(header.has_date()){
		std::cout<< "date : "<< header.date()<< std::endl;
	}
	if(header.has_projection()){
		std::cout<< "projection : "<< header.projection()<< std::endl;
	}
	if(header.has_low()){
		hdmap_proto::Point low = header.low();
		std::cout<< "low : x = "<<low.x() << " y = " << low.y() << " z = " << low.z() << std::endl;
	}
	if(header.has_high()){
		hdmap_proto::Point high = header.high();
		std::cout<< "high : x = "<<high.x() << " y = " << high.y() << " z = " << high.z() << std::endl;
	}
	std::cout<<"}"<<std::endl<<std::endl;
}

void MapIO::listCrosswlks(hdmap_proto::CrossWalk & crosswalk){
	std::cout<< std::endl<< "crosswalks {" << std::endl;
	if(crosswalk.has_id()){
		std::cout<< "id : "<< std::endl;
		hdmap_proto::Id* id = crosswalk.mutable_id();
		if(id->has_id())
			std::cout<< "  id : "<< id->id()<< std::endl;
		if(id->has_name())
			std::cout<< "  name : "<< id->name()<< std::endl;
	}

	for(int i = 0; i < crosswalk.tile_ids_size(); ++i){
		std::cout<< "tile_ids : "<< std::endl;
		hdmap_proto::Id tile_id = crosswalk.tile_ids(i);
		if(tile_id.has_id())
			std::cout<< "  id : "<< tile_id.id()<< std::endl;
		if(tile_id.has_name())
			std::cout<< "  name : "<< tile_id.name()<< std::endl;
	}
    
  if(crosswalk.has_name())
		std::cout<< "  name : "<< crosswalk.name() << std::endl;

	if(crosswalk.has_border()){
		std::cout<< "border : "<< std::endl;
		hdmap_proto::Polygon border = crosswalk.border();
		for(int j = 0; j < border.points_size(); ++j){
			hdmap_proto::Point point = border.points(j);
			std::cout<< "  points : x = "<<point.x() << " y = " << point.y() << " z = " << point.z() << std::endl;
		}    	
	}
	for(int j = 0; j < crosswalk.lines_size(); ++j){
		std::cout<< "lines : "<< std::endl;    	
		hdmap_proto::Polygon line = crosswalk.lines(j);
		for(int i = 0; i < line.points_size(); ++i){
			hdmap_proto::Point point = line.points(i);
			std::cout<< "  points : x = "<<point.x() << " y = " << point.y() << " z = " << point.z() << std::endl;
		}    	
	}

	std::cout<<"}"<<std::endl<<std::endl;
}



void MapIO::listJunctions(hdmap_proto::Junction & junction){
	std::cout<< std::endl<< "junctions {" << std::endl;
	if(junction.has_id()){
		std::cout<< "id : "<< std::endl;
		hdmap_proto::Id* id = junction.mutable_id();
		if(id->has_id())
			std::cout<< "  id : "<< id->id()<< std::endl;
		if(id->has_name())
			std::cout<< "  name : "<< id->name()<< std::endl;
	}

	for(int i = 0; i < junction.tile_ids_size(); ++i){
		std::cout<< "tile_ids : "<< std::endl;
		hdmap_proto::Id tile_id = junction.tile_ids(i);
		if(tile_id.has_id())
			std::cout<< "  id : "<< tile_id.id()<< std::endl;
		if(tile_id.has_name())
			std::cout<< "  name : "<< tile_id.name()<< std::endl;
	}

	if(junction.has_polygon()){
		std::cout<< "polygon : "<< std::endl;
		hdmap_proto::Polygon polygon = junction.polygon();
		for(int i = 0; i < polygon.points_size(); ++i){
			hdmap_proto::Point point = polygon.points(i);
			std::cout<< "  points : x = "<<point.x() << " y = " << point.y() << " z = " << point.z() << std::endl;
		} 
	}
	std::cout<<"}"<<std::endl<<std::endl;
}



void MapIO::listParkingSpaces(hdmap_proto::ParkingSpace & parkingspace){
	std::cout<< std::endl<< "parkingspaces {" << std::endl;
	if(parkingspace.has_id()){
		std::cout<< "id : "<< std::endl;
		hdmap_proto::Id* id = parkingspace.mutable_id();
		if(id->has_id())
			std::cout<< "  id : "<< id->id()<< std::endl;
		if(id->has_name())
			std::cout<< "  name : "<< id->name()<< std::endl;
	}

	for(int i = 0; i < parkingspace.tile_ids_size(); ++i){
		std::cout<< "tile_ids : "<< std::endl;
		hdmap_proto::Id tile_id = parkingspace.tile_ids(i);
		if(tile_id.has_id())
			std::cout<< "  id : "<< tile_id.id()<< std::endl;
		if(tile_id.has_name())
			std::cout<< "  name : "<< tile_id.name()<< std::endl;
	}

	for(int i = 0; i < parkingspace.parkingslots_size(); ++i){
		std::cout<< "parkingslot : "<< std::endl;
		hdmap_proto::ParkingSlot parkingslot = parkingspace.parkingslots(i);

		if(parkingslot.has_id()){
			std::cout<< "id : "<< std::endl;
			hdmap_proto::Id* id = parkingslot.mutable_id();
			if(id->has_id())
				std::cout<< "  id : "<< id->id()<< std::endl;
			if(id->has_name())
				std::cout<< "  name : "<< id->name()<< std::endl;
		}
		if(parkingslot.has_polygon()){
			std::cout<< "polygon : "<< std::endl;
			hdmap_proto::Polygon polygon = parkingslot.polygon();
			for(int i = 0; i < polygon.points_size(); ++i){
				hdmap_proto::Point point = polygon.points(i);
				std::cout<< "  points : x = "<<point.x() << " y = " << point.y() << " z = " << point.z() << std::endl;
			} 
		}
	} 

	std::cout<<"}"<<std::endl<<std::endl;
}



void MapIO::listStopLines(hdmap_proto::StopLine & stopline){
	// TO DO
}

void MapIO::listSpeedBumps(hdmap_proto::SpeedBump & speedbump){
	// TO DO
}

void MapIO::listPoles(hdmap_proto::Pole & pole){
	// TO DO
}

void MapIO::listBoards(hdmap_proto::Board & board){
	// TO DO
}

void MapIO::listZones(hdmap_proto::Zone & zone){
	// TO DO
}

void MapIO::listTrafficLights(hdmap_proto::TrafficLight & traffic_light){
	// TO DO
}

void MapIO::listTrafficSigns(hdmap_proto::TrafficSign & traffic_sign){
	// TO DO
}

void MapIO::listTiles(hdmap_proto::Tile & tile){
	// TO DO
}










} // end namespace  hdmap
