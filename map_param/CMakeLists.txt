cmake_minimum_required(VERSION 2.8)
 
project(map_param)

add_compile_options(-std=c++11)
add_compile_options(-fPIC)

find_package(Protobuf REQUIRED)

set(PROTOBUF_DIR "${CMAKE_CURRENT_SOURCE_DIR}/")
set(PROTOBUF_RAW_DIR "${CMAKE_CURRENT_SOURCE_DIR}/raw")


include ( ../cmake/CMakePolicies.cmake )
include ( ../cmake/CMakeSetCompilerOptions.cmake )
include( ../cmake/CMakeExternalLibs.cmake )


file( GLOB proto_list "${PROTOBUF_RAW_DIR}/*.proto")
file( GLOB header_list *.h)
file( GLOB source_list *.cc)

add_library( ${PROJECT_NAME} SHARED ${header_list} ${source_list} ${proto_list})

#by 3rdPart
target_link_libraries(${PROJECT_NAME} ${PROTOBUF_LIBRARIES})


# Add custom preprocessor definitions
if (WIN32)
	set_property( TARGET ${PROJECT_NAME} APPEND PROPERTY COMPILE_DEFINITIONS CC_USE_AS_DLL QCC_DB_USE_AS_DLL DPX_MAP_USE_AS_DLL map_param)
endif()

# install (shared) lib to specified destinations
if( WIN32 OR APPLE )
	foreach( dest ${INSTALL_DESTINATIONS} )
		install_shared( ${PROJECT_NAME} ${dest} 1 )
	endforeach()
else()
	install_shared( ${PROJECT_NAME} lib/cloudcompare 0 ) #default destination: /usr/lib
endif()
