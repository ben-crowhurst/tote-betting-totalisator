
project( "acceptance test suite" )

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
add_executable( totalisator_acceptance_test_suite ${SOURCE_DIR}/totalisator_acceptance_test_suite.cpp )
target_link_libraries( totalisator_acceptance_test_suite ${PROJECT_LIBRARY_NAME} )
add_test( totalisator_acceptance_test_suite ${EXECUTABLE_OUTPUT_PATH}/totalisator_acceptance_test_suite )
