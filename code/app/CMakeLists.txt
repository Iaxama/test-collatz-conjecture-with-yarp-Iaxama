cmake_minimum_required(VERSION 2.6)

set(PROJECTNAME collatz_client_server)

include(YarpInstallationHelpers)

file(GLOB scripts ${CMAKE_CURRENT_SOURCE_DIR}/scripts/*.xml)

yarp_install(FILES ${scripts} DESTINATION ${ICUBCONTRIB_APPLICATIONS_INSTALL_DIR})
