
//System Includes

//Project Includes
#include "race.hpp"

//External Includes
#include <catch.hpp>

//System Namespaces

//Project Namespaces
using gambling::Race;

//External Namespaces

TEST_CASE( "confirm default values", "[race]" )
{
    Race race;
    
    REQUIRE( race.results.empty( ) );
    REQUIRE( race.number_of_runners == 4 );
    REQUIRE( race.win_dividend == 0.0 );
    REQUIRE( race.place_dividends.empty( ) );
}
