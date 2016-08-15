
//System Includes
#include <vector>
#include <stdexcept>
#include <algorithm>

//Project Includes
#include "bet.hpp"
#include "race.hpp"
#include "product.hpp"
#include "settings.hpp"
#include "totalisator.hpp"

//External Includes
#include <catch.hpp>

//System Namespaces
using std::sort;
using std::vector;
using std::unique;
using std::domain_error;

//Project Namespaces
using gambling::Bet;
using gambling::Race;
using gambling::Product;
using gambling::Settings;
using gambling::Totalisator;

//External Namespaces

TEST_CASE( "confirm default destructor throws no exceptions", "[totalisator]" )
{
    auto totalisator = Totalisator::create( );
    
    REQUIRE_NOTHROW( totalisator.reset( ) );
}

TEST_CASE( "validate setting number of runners to zero", "[totalisator]" )
{
    auto totalisator = Totalisator::create( );
    
    Race race;
    race.number_of_runners = 0;
    vector< Bet > bets = { };
    
    REQUIRE_THROWS_AS( totalisator->run( race, bets ), domain_error );
}

TEST_CASE( "validate setting number of runners to less-than place winner boundary", "[totalisator]" )
{
    Settings settings;
    settings.place_winner_boundary = 10;
    
    auto totalisator = Totalisator::create( settings );
    
    Race race;
    race.number_of_runners = 3;
    vector< Bet > bets = { };
    
    REQUIRE_THROWS_AS( totalisator->run( race, bets ), domain_error );
}

TEST_CASE( "validate setting incorrect Bet product ", "[totalisator]" )
{
    auto totalisator = Totalisator::create( );
    
    Race race;
    
    Bet bet;
    bet.product = static_cast< Product >( 4 );
    
    vector< Bet > bets;
    bets.push_back( bet );
    
    REQUIRE_THROWS_AS( totalisator->run( race, bets ), domain_error );
}

TEST_CASE( "validate setting out-of-range Bet selection", "[totalisator]" )
{
    auto totalisator = Totalisator::create( );
    
    Race race;
    
    Bet bet;
    bet.selection = 99;
    
    vector< Bet > bets;
    bets.push_back( bet );
    
    REQUIRE_THROWS_AS( totalisator->run( race, bets ), domain_error );
}

TEST_CASE( "validate Race results are not overwritten when supplied", "[totalisator]" )
{
    auto expectation = vector< unsigned int > { 1, 2, 3, 4 };
    
    Race race;
    race.results = expectation;
    vector< Bet > bets;
    
    auto totalisator = Totalisator::create( );
    totalisator->run( race, bets );
    
    REQUIRE( race.results == expectation );
}

TEST_CASE( "validate Race results are randomised when not supplied", "[totalisator]" )
{
    Race race;
    vector< Bet > bets;
    
    auto totalisator = Totalisator::create( );
    totalisator->run( race, bets );
    
    auto results = race.results;
    REQUIRE( results.size( ) == race.number_of_runners );
    
    auto end = results.end( );
    sort( results.begin( ), end );
    bool contains_duplicates = ( unique( results.begin( ), end ) not_eq end );
    REQUIRE( contains_duplicates == false );
    
    race.results.clear( );
    totalisator->run( race, bets );
    
    auto previous_results = results;
    REQUIRE( race.results not_eq previous_results );
}
