
project( "unit test suite" )

cmake_minimum_required( VERSION 2.8.10 )

#
# Configuration
#
set( SOURCE_DIR "source" )
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DCATCH_CONFIG_MAIN" )

include_directories( SYSTEM ${catch_INCLUDE} )

#
# Build
#
add_executable( bet_unit_test_suite ${SOURCE_DIR}/bet_unit_test_suite.cpp )
target_link_libraries( bet_unit_test_suite ${PROJECT_LIBRARY_NAME} )
add_test( bet_unit_test_suite ${EXECUTABLE_OUTPUT_PATH}/bet_unit_test_suite )

add_executable( race_unit_test_suite ${SOURCE_DIR}/race_unit_test_suite.cpp )
target_link_libraries( race_unit_test_suite ${PROJECT_LIBRARY_NAME} )
add_test( race_unit_test_suite ${EXECUTABLE_OUTPUT_PATH}/race_unit_test_suite )

add_executable( settings_unit_test_suite ${SOURCE_DIR}/settings_unit_test_suite.cpp )
target_link_libraries( settings_unit_test_suite ${PROJECT_LIBRARY_NAME} )
add_test( settings_unit_test_suite ${EXECUTABLE_OUTPUT_PATH}/settings_unit_test_suite )
