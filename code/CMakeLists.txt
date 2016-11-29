
project(collatz-conjecture)

cmake_minimum_required(VERSION 2.8.9)

find_package(YARP REQUIRED)
find_package(ICUB REQUIRED)
find_package(ICUBcontrib REQUIRED)

# Set build directory
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/server/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)

include(YarpIDL)

list(APPEND CMAKE_MODULE_PATH ${YARP_MODULE_PATH})
list(APPEND CMAKE_MODULE_PATH ${ICUB_MODULE_PATH})
list(APPEND CMAKE_MODULE_PATH ${ICUBCONTRIB_MODULE_PATH})


set(idl_files comm_interface.thrift)
yarp_add_idl(IDL_GEN_FILES comm_interface.thrift)

add_library(comm_IDL_interface
        ${IDL_GEN_FILES})

add_subdirectory(client)
add_subdirectory(server)
