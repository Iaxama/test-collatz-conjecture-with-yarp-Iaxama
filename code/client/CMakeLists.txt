# Copyright: (C) 2015 iCub Facility - Istituto Italiano di Tecnologia
# Authors: Massimiliano Iacono
# CopyPolicy: Released under the terms of the GNU GPL v2.0.

set(PROJECTNAME collatz-client)

project(${PROJECTNAME})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        )

set(THRIFT_GENERATED_LIBS "${CMAKE_CURRENT_SOURCE_DIR}/lib")
yarp_idl_to_dir(client_interface.thrift ${THRIFT_GENERATED_LIBS} sources headers include_dirs)

include_directories(${THRIFT_GENERATED_LIBS}/include)

add_library(client_IDL_interface
        ${THRIFT_GENERATED_LIBS}/include/ClientIDLInterface.h
        ${THRIFT_GENERATED_LIBS}/src/ClientIDLInterface.cpp
        )

add_library(client
        include/Client.h
        src/Client.cpp
        )

add_executable(${PROJECTNAME} src/clientMain.cpp)

target_link_libraries(${PROJECTNAME}
        ${YARP_LIBRARIES}
        client_IDL_interface
        client
        )

install (TARGETS ${PROJECTNAME} DESTINATION bin)
