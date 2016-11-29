# Copyright: (C) 2015 iCub Facility - Istituto Italiano di Tecnologia
# Authors: Massimiliano Iacono
# CopyPolicy: Released under the terms of the GNU GPL v2.0.

set(PROJECTNAME collatz-server)
project(${PROJECTNAME})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}
                    ${CMAKE_CURRENT_SOURCE_DIR}/include
                    )

add_library(server
        src/Server.cpp include/Server.h)

source_group("IDL Files" FILES ${idl_files})

add_executable(${PROJECTNAME} src/serverMain.cpp )


target_link_libraries(${PROJECTNAME}
                    ${YARP_LIBRARIES}
                    comm_IDL_interface
                    server
        )

install (TARGETS ${PROJECTNAME} DESTINATION bin)
