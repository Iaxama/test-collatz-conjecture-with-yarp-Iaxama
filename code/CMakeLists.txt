
project(collatz-conjecture)

cmake_minimum_required(VERSION 2.8.9)

find_package(YARP REQUIRED)
find_package(ICUB REQUIRED)
find_package(ICUBcontrib REQUIRED)

# Set build directory
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)

include(YarpIDL)

list(APPEND CMAKE_MODULE_PATH ${YARP_MODULE_PATH})
list(APPEND CMAKE_MODULE_PATH ${ICUB_MODULE_PATH})
list(APPEND CMAKE_MODULE_PATH ${ICUBCONTRIB_MODULE_PATH})

set(THRIFT_GENERATED_LIBS "${CMAKE_CURRENT_SOURCE_DIR}/lib")
yarp_idl_to_dir(comm_interface.thrift ${THRIFT_GENERATED_LIBS} sources headers include_dirs)

include_directories(${THRIFT_GENERATED_LIBS}/include)
include_directories(common)
add_library(comm_IDL_interface
        ${THRIFT_GENERATED_LIBS}/include/CommInterface.h
        ${THRIFT_GENERATED_LIBS}/src/CommInterface.cpp
        )

add_subdirectory(client)
add_subdirectory(server)
