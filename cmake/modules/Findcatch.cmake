
find_path( catch_INCLUDE catch.hpp HINTS "${CMAKE_SOURCE_DIR}/dependency/catch/include" "/usr/include" "/usr/local/include" "/opt/local/include" )

if ( catch_INCLUDE )
    set( CATCH_FOUND TRUE )

    message( STATUS "Found Catch include at: ${catch_INCLUDE}" )
else ( )
    message( FATAL_ERROR "Failed to locate Catch dependency." )
endif ( )
