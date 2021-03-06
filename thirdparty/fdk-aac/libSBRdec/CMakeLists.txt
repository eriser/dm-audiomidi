CMAKE_MINIMUM_REQUIRED (VERSION 2.8)

PROJECT("libSBRdec")
MESSAGE(STATUS "Configuring libSBRdec library")

SET(CMAKE_MODULE_PATH ${FDK_PATH_TO_DM_ROOT}/dm-cmake)
INCLUDE(SetPlatformDefines)
INCLUDE(SetTargetOptions)
SET_PLATFORM_DEFINES()

FILE(GLOB src_filez "${CMAKE_CURRENT_SOURCE_DIR}/src/*.*")
FILE(GLOB hdr_filez "${CMAKE_CURRENT_SOURCE_DIR}/include/*.*")

IF (ANDROID)
  FILE(GLOB platform_filez "${CMAKE_CURRENT_SOURCE_DIR}/arm/block_arm.cpp")
ELSE (ANDROID)
  SET(platform_filez "")
ENDIF (ANDROID)

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/../libAACdec/include)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/../libAACenc/include)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/../libFDK/include)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/../libMpegTPDec/include)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/../libMpegTPEnc/include)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/../libPCMutils/include)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/../libSBRdec/include)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/../libSBRenc/include)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/../libSYS/include)
ADD_LIBRARY(FdkAacSBRdec ${src_filez} ${hdr_filez} ${platform_filez})
FSET_TARGET_OPTIONS(FdkAacSBRdec "")
