cmake_minimum_required(VERSION 2.8)
 
project(test_MapIO)

include_directories(
${PROJECT_SOURCE_DIR}/../include
${PROJECT_SOURCE_DIR}/../proto
)

add_executable(test_MapIO main.cc)

target_link_libraries(test_MapIO 
${PROJECT_SOURCE_DIR}/../lib/libmap_param.so 
protobuf
)
 
