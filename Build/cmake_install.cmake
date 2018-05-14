# Install script for directory: /home/ds/3rdPart/CloudCompareTool

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/ds/3rdPart/CloudCompareTool/Build/CC/cmake_install.cmake")
  include("/home/ds/3rdPart/CloudCompareTool/Build/libs/CCFbo/cmake_install.cmake")
  include("/home/ds/3rdPart/CloudCompareTool/Build/libs/qCC_db/cmake_install.cmake")
  include("/home/ds/3rdPart/CloudCompareTool/Build/libs/qCC_io/cmake_install.cmake")
  include("/home/ds/3rdPart/CloudCompareTool/Build/libs/qCC_glWindow/cmake_install.cmake")
  include("/home/ds/3rdPart/CloudCompareTool/Build/libs/qcustomplot/cmake_install.cmake")
  include("/home/ds/3rdPart/CloudCompareTool/Build/plugins/cmake_install.cmake")
  include("/home/ds/3rdPart/CloudCompareTool/Build/qCC/cmake_install.cmake")
  include("/home/ds/3rdPart/CloudCompareTool/Build/ccViewer/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/ds/3rdPart/CloudCompareTool/Build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
