# Copyright: (C) 2015 iCub Facility - Istituto Italiano di Tecnologia
# Authors: Massimiliano Iacono
# CopyPolicy: Released under the terms of the GNU GPL v2.0.

set(PROJECTNAME collatz-server)
project(${PROJECTNAME})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}
                    ${CMAKE_CURRENT_SOURCE_DIR}/include
                    )

source_group("IDL Files" FILES ${idl_files})
set(THRIFT_GENERATED_LIBS "${CMAKE_CURRENT_SOURCE_DIR}/lib")
yarp_idl_to_dir(server_interface.thrift ${THRIFT_GENERATED_LIBS} sources headers include_dirs)

include_directories(${THRIFT_GENERATED_LIBS}/include)

add_library(server_IDL_interface
        ${THRIFT_GENERATED_LIBS}/include/ServerIDLInterface.h
        ${THRIFT_GENERATED_LIBS}/src/ServerIDLInterface.cpp
        )

add_library(server
        src/Server.cpp include/Server.h)

add_executable(${PROJECTNAME} src/serverMain.cpp )

target_link_libraries(${PROJECTNAME}
                    ${YARP_LIBRARIES}
                    server_IDL_interface
                    server
        )

install (TARGETS ${PROJECTNAME} DESTINATION bin)
