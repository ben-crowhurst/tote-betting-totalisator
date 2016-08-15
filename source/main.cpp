/*
 * Copyright, Gambling Holdings Limited, All Rights Reserved.
 */

//System Includes
#include <regex>
#include <cstdio>
#include <vector>
#include <string>
#include <ciso646>
#include <cstdlib>
#include <iostream>

//Project Includes
#include "bet.hpp"
#include "race.hpp"
#include "product.hpp"
#include "settings.hpp"
#include "totalisator.hpp"

//External Includes

//System Namespaces
using std::cin;
using std::regex;
using std::vector;
using std::string;
using std::smatch;
using std::getline;
using std::regex_match;
using std::regex_constants::icase;

//Project Namespaces
using gambling::Bet;
using gambling::Race;
using gambling::WIN;
using gambling::PLACE;
using gambling::Product;
using gambling::Settings;
using gambling::Totalisator;

//External Namespaces

void display_results( const Race& race )
{
    fprintf( stdout, "Win:%u:$%.2f\n", race.results.front( ), race.win_dividend );
    
    for ( unsigned int index = 0; index < race.place_dividends.size( ); index++ )
    {
        fprintf( stdout, "Place:%u:$%.2f\n", race.results[ index ], race.place_dividends[ index ] );
    }
}

Bet make_bet( const smatch& match )
{
    Bet bet = { };
    const auto product = match[ 1 ].str( );
    bet.product = ( product == "w" or product == "W" ) ? WIN : PLACE;
    bet.selection = stoi( match[ 2 ].str( ) );
    bet.stake = stoi( match[ 3 ].str( ) );
    
    return bet;
}

Race make_race( const smatch& match )
{
    Race race = { };
    race.results.push_back( 2 );
    race.results.push_back( 3 );
    race.results.push_back( 1 );
    race.results.push_back( 4 );
    
    return race;
}

int main( const int, const char** )
{
    Race race = { };
    vector< Bet > bets = { };
    
    smatch match;
    string line = "";
    vector< string > tokens = { };
    
    const auto bet_input_pattern = regex( "^Bet\\:(w|W|p|P)\\:(\\d+)\\:(\\d+)$", icase );
    const auto result_input_pattern = regex( "^Result\\:(\\d+)\\:(\\d+)\\:(\\d+)$", icase );
    
    while ( getline( cin, line ) )
    {
        const bool is_bet_input_line = regex_match( line, match, bet_input_pattern );
        
        if ( is_bet_input_line )
        {
            bets.emplace_back( make_bet( match ) );
            continue;
        }
        
        const bool is_result_input_line = regex_match( line, match, result_input_pattern );
        
        if ( is_result_input_line )
        {
            race = make_race( match );
            break;
        }
        
        fprintf( stderr, "The following input was malformed: %s\n", line.data( ) );
        return EXIT_FAILURE;
    }
    
    auto totalisator = Totalisator::create( );
    totalisator->run( race, bets );
    
    display_results( race );
    
    return EXIT_SUCCESS;
}
