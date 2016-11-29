# Copyright: (C) 2015 iCub Facility - Istituto Italiano di Tecnologia
# Authors: Massimiliano Iacono
# CopyPolicy: Released under the terms of the GNU GPL v2.0.

cmake_minimum_required(VERSION 2.6)
set(PROJECTNAME collatz-client)

project(${PROJECTNAME})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        )

add_library(client
        include/Client.h
        src/Client.cpp
        )

add_executable(${PROJECTNAME} src/clientMain.cpp)

target_link_libraries(${PROJECTNAME}
        ${YARP_LIBRARIES}
        client
        comm_IDL_interface
        )
