
//System Includes
#include <stdexcept>

//Project Includes
#include "bet.hpp"
#include "race.hpp"
#include "product.hpp"
#include "settings.hpp"
#include "totalisator.hpp"

//External Includes
#include <catch.hpp>

//System Namespaces
using std::vector;

//Project Namespaces
using gambling::Bet;
using gambling::WIN;
using gambling::Race;
using gambling::Product;
using gambling::Settings;
using gambling::Totalisator;

SCENARIO( "Single WIN bet", "[totalisator]" )
{
    GIVEN( "I supply a single winning bet" )
    {
        WHEN( "I run the totalisator" )
        {
            THEN( "I should see the dividend as my stake minus the commission" )
            {
                Race race;
                race.results = { 1, 2, 3, 4 };
                
                Bet bet;
                bet.product = WIN;
                bet.selection = 1;
                bet.stake = 30;
                
                auto totalisator = Totalisator::create( );
                totalisator->run( race, { bet } );
                
                REQUIRE( race.win_dividend == 25.5 );
            }
        }
    }
    
    GIVEN( "I supply a single losing bet" )
    {
        WHEN( "I run the totalisator" )
        {
            THEN( "I should see the dividend as my stake minus the commission" )
            {
                Race race;
                race.results = { 1, 2, 3, 4 };
                
                Bet bet;
                bet.product = WIN;
                bet.selection = 4;
                bet.stake = 30;
                
                auto totalisator = Totalisator::create( );
                totalisator->run( race, { bet } );
                
                REQUIRE( race.win_dividend == 25.5 );
            }
        }
    }
}

SCENARIO( "Multiple WIN bets", "[totalisator]" )
{
    GIVEN( "I supply multiple winning bets" )
    {
        WHEN( "I run the totalisator" )
        {
            THEN( "I should see the dividend as our stakes minus the commission" )
            {
                Race race;
                race.results = { 1, 2, 3, 4 };
                
                Bet bet1;
                bet1.product = WIN;
                bet1.selection = 1;
                bet1.stake = 30;
                
                Bet bet2;
                bet2.product = WIN;
                bet2.selection = 1;
                bet2.stake = 3;
                
                auto totalisator = Totalisator::create( );
                totalisator->run( race, { bet1, bet2 } );
                
                REQUIRE( race.win_dividend == 0.85 );
            }
        }
    }
    
    GIVEN( "I supply multiple losing bets" )
    {
        WHEN( "I run the totalisator" )
        {
            THEN( "I should see the dividend as our stakes minus the commission" )
            {
                Race race;
                race.results = { 1, 2, 3, 4 };
                
                Bet bet1;
                bet1.product = WIN;
                bet1.selection = 1;
                bet1.stake = 30;
                
                Bet bet2;
                bet2.product = WIN;
                bet2.selection = 1;
                bet2.stake = 3;
                
                auto totalisator = Totalisator::create( );
                totalisator->run( race, { bet1, bet2 } );
                
                REQUIRE( race.win_dividend == 0.85 );
            }
        }
    }
}
