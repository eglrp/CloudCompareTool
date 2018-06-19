cmake_minimum_required(VERSION 3.0)

#添加头文件
include_directories( ${CC_CORE_LIB_SOURCE_DIR}/include )#依赖CC_CORE_LIB
include_directories( ${QCC_DB_LIB_SOURCE_DIR} )#依赖QCC_DB_LIB

if( MSVC )
	include_directories( ${CMAKE_CURRENT_SOURCE_DIR}/msvc )
endif()

project( DPX_MAP_LIB  VERSION 1.0 )

file( GLOB header_list *.h)
file( GLOB source_list *.cpp)

add_library( ${PROJECT_NAME} SHARED ${header_list} ${source_list} )

#添加依赖库
target_link_libraries( ${PROJECT_NAME} CC_CORE_LIB ) #依赖CC_CORE_LIB
target_link_libraries( ${PROJECT_NAME} QCC_DB_LIB ) #依赖QCC_DB_LIB


# Qt
qt5_use_modules(${PROJECT_NAME} Core Gui Widgets OpenGL)

# Add custom preprocessor definitions
if (WIN32)
	set_property( TARGET ${PROJECT_NAME} APPEND PROPERTY COMPILE_DEFINITIONS CC_USE_AS_DLL QCC_DB_USE_AS_DLL DPX_MAP_USE_AS_DLL)
endif()

# install (shared) lib to specified destinations
if( WIN32 OR APPLE )
	foreach( dest ${INSTALL_DESTINATIONS} )
		install_shared( ${PROJECT_NAME} ${dest} 1 )
	endforeach()
else()
	install_shared( ${PROJECT_NAME} lib/cloudcompare 0 ) #default destination: /usr/lib
endif()
