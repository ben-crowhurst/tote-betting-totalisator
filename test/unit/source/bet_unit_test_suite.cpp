
//System Includes

//Project Includes
#include "bet.hpp"

//External Includes
#include <catch.hpp>

//System Namespaces

//Project Namespaces
using gambling::Bet;

//External Namespaces

TEST_CASE( "confirm default values", "[bet]" )
{
    Bet bet;
    
    REQUIRE( bet.stake == 0 );
    REQUIRE( bet.selection == 0 );
}
