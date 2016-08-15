
//System Includes

//Project Includes
#include "settings.hpp"

//External Includes
#include <catch.hpp>

//System Namespaces

//Project Namespaces
using gambling::Settings;

//External Namespaces

TEST_CASE( "confirm default values", "[settings]" )
{
    Settings settings;
    
    REQUIRE( settings.win_commission == 15 );
    REQUIRE( settings.place_commission == 12 );
    REQUIRE( settings.place_winner_boundary == 3 );
}
