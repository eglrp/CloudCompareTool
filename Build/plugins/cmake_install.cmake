# Install script for directory: /home/ds/3rdPart/CloudCompareTool/plugins

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
  include("/home/ds/3rdPart/CloudCompareTool/Build/plugins/qCSVMatrixIO/cmake_install.cmake")
  include("/home/ds/3rdPart/CloudCompareTool/Build/plugins/qAdditionalIO/cmake_install.cmake")
  include("/home/ds/3rdPart/CloudCompareTool/Build/plugins/qPhotoscanIO/cmake_install.cmake")
  include("/home/ds/3rdPart/CloudCompareTool/Build/plugins/qCork/cmake_install.cmake")
  include("/home/ds/3rdPart/CloudCompareTool/Build/plugins/qRANSAC_SD/cmake_install.cmake")
  include("/home/ds/3rdPart/CloudCompareTool/Build/plugins/qM3C2/cmake_install.cmake")
  include("/home/ds/3rdPart/CloudCompareTool/Build/plugins/qExampleIOPlugin/cmake_install.cmake")
  include("/home/ds/3rdPart/CloudCompareTool/Build/plugins/qHPR/cmake_install.cmake")
  include("/home/ds/3rdPart/CloudCompareTool/Build/plugins/qExamplePlugin/cmake_install.cmake")
  include("/home/ds/3rdPart/CloudCompareTool/Build/plugins/qEDL/cmake_install.cmake")
  include("/home/ds/3rdPart/CloudCompareTool/Build/plugins/qBroom/cmake_install.cmake")
  include("/home/ds/3rdPart/CloudCompareTool/Build/plugins/qHoughNormals/cmake_install.cmake")
  include("/home/ds/3rdPart/CloudCompareTool/Build/plugins/qSSAO/cmake_install.cmake")
  include("/home/ds/3rdPart/CloudCompareTool/Build/plugins/qSRA/cmake_install.cmake")
  include("/home/ds/3rdPart/CloudCompareTool/Build/plugins/qExampleGLPlugin/cmake_install.cmake")
  include("/home/ds/3rdPart/CloudCompareTool/Build/plugins/qAnimation/cmake_install.cmake")
  include("/home/ds/3rdPart/CloudCompareTool/Build/plugins/qFacets/cmake_install.cmake")
  include("/home/ds/3rdPart/CloudCompareTool/Build/plugins/qPCL/cmake_install.cmake")
  include("/home/ds/3rdPart/CloudCompareTool/Build/plugins/qPCV/cmake_install.cmake")
  include("/home/ds/3rdPart/CloudCompareTool/Build/plugins/qCSF/cmake_install.cmake")
  include("/home/ds/3rdPart/CloudCompareTool/Build/plugins/qCompass/cmake_install.cmake")
  include("/home/ds/3rdPart/CloudCompareTool/Build/plugins/qPoissonRecon/cmake_install.cmake")
  include("/home/ds/3rdPart/CloudCompareTool/Build/plugins/qLAS_FWF/cmake_install.cmake")

endif()

