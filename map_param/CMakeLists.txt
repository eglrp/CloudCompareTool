cmake_minimum_required(VERSION 2.8)
 
project(map_param)
find_package(protobuf)
include_directories(
${PROJECT_SOURCE_DIR}/include
${PROJECT_SOURCE_DIR}/proto
)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)

add_library(${PROJECT_NAME} SHARED
src/MapParam_HDmap_IO.cc
)

target_link_libraries(${PROJECT_NAME} 
${PROJECT_SOURCE_DIR}/lib/libmapparam.a 
protobuf
)
 
