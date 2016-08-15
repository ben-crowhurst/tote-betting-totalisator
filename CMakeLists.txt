
project( "totalisator" )

cmake_minimum_required( VERSION 2.8.10 )

#
# Configuration
#
include( "${CMAKE_SOURCE_DIR}/cmake/configuration.cmake" )

#
# Dependencies
#
set( CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules" )

#
# Build
#
include( "${CMAKE_SOURCE_DIR}/cmake/manifest.cmake" )
include_directories( ${INCLUDE_DIR} )

add_executable( ${PROJECT_NAME} ${MANIFEST} )
target_link_libraries( ${PROJECT_NAME} )

#
# Test
#

#
# Install
#
install( TARGETS ${PROJECT_NAME} RUNTIME DESTINATION "distribution" )
