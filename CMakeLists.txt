
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

find_package( catch REQUIRED )

#
# Build
#
include( "${CMAKE_SOURCE_DIR}/cmake/manifest.cmake" )
include_directories( ${INCLUDE_DIR} )

add_library( "${PROJECT_NAME}-logic" ${MANIFEST} )
add_executable( ${PROJECT_NAME} "${SOURCE_DIR}/main.cpp" )
target_link_libraries( ${PROJECT_NAME} "${PROJECT_NAME}-logic" )

#
# Test
#
enable_testing( )
add_subdirectory( "${CMAKE_SOURCE_DIR}/test/unit" "unit-tests" )

#
# Install
#
install( TARGETS ${PROJECT_NAME} RUNTIME DESTINATION "distribution" )
