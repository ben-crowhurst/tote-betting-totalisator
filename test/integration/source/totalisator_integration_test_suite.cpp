
//System Includes

//Project Includes
#include "settings.hpp"
#include "totalisator.hpp"

//External Includes
#include <catch.hpp>

//System Namespaces

//Project Namespaces
using gambling::Totalisator;

//External Namespaces

TEST_CASE( "confirm default destructor throws no exceptions", "[totalisator]" )
{
    auto totalisator = Totalisator::create( );
    
    REQUIRE_NOTHROW( totalisator.reset( ) );
}
