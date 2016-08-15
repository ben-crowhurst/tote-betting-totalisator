/*
 * Copyright, Gambling Holdings Limited, All Rights Reserved.
 */

//System Includes
#include <random>
#include <ciso646>
#include <stdexcept>
#include <algorithm>

//Project Includes
#include "bet.hpp"
#include "race.hpp"
#include "product.hpp"
#include "detail/totalisator_impl.hpp"

//External Includes

//System Namespaces
using std::vector;
using std::shuffle;
using std::mt19937;
using std::domain_error;
using std::random_device;

//Project Namespaces

//External Namespaces

namespace gambling
{
    namespace detail
    {
        TotalisatorImpl::TotalisatorImpl( void ) : m_win_commission( 0 ),
            m_place_commission( 0 ),
            m_place_winner_boundary( 0 )
        {
            return;
        }
        
        TotalisatorImpl::~TotalisatorImpl( void )
        {
            return;
        }
        
        void TotalisatorImpl::validate( const Race& race )
        {
            if ( race.number_of_runners == 0 )
            {
                throw domain_error( "Number of runners not specified." );
            }
            
            if ( m_place_winner_boundary > race.number_of_runners )
            {
                throw domain_error( "Place winner boundary too large, must be less then or equal too number of runners." );
            }
        }
        
        void TotalisatorImpl::validate( const Race& race, const vector< Bet >& bets )
        {
            for ( const auto& bet : bets )
            {
                if ( bet.product not_eq WIN and bet.product not_eq PLACE )
                {
                    throw domain_error( "Bet product unknown, must be one of WIN or PLACE." );
                }
                
                if ( bet.selection > race.number_of_runners )
                {
                    throw domain_error( "Bet selection out of range." );
                }
            }
        }
        
        void TotalisatorImpl::generate_race_results( Race& race )
        {
            if ( not race.results.empty( ) )
            {
                return;
            }
            
            for ( unsigned int index = 1; index <= race.number_of_runners; index++ )
            {
                race.results.push_back( index );
            }
            
            random_device device;
            mt19937 seed( device( ) );
            shuffle( race.results.begin( ), race.results.end( ), seed );
        }
        
        void TotalisatorImpl::calculate_dividends( Race& race, const vector< Bet >& bets )
        {
            race.win_dividend = calculate_dividend( bets, race.results.front( ), WIN, m_win_commission );
            
            race.place_dividends.resize( m_place_winner_boundary );
            
            for ( unsigned int index = 0; index < m_place_winner_boundary; index++ )
            {
                const auto dividend = calculate_dividend( bets, race.results.at( index ), PLACE, m_place_commission );
                race.place_dividends[ index ] = dividend / m_place_winner_boundary;
            }
        }
        
        double TotalisatorImpl::subtract_commission( const unsigned int total, const unsigned int percentage )
        {
            const double dividend = total * percentage;
            
            if ( dividend <= 0 )
            {
                return total;
            }
            
            const auto quotient = dividend / 100.0;
            return total - quotient;
        }
        
        double TotalisatorImpl::calculate_dividend( const vector< Bet >& bets, const unsigned int selection, const Product product, const unsigned int commission )
        {
            double pool = 0.0;
            double winning_punters_stakes = 0.0;
            
            for ( const auto& bet : bets )
            {
                if ( bet.product == product )
                {
                    pool += bet.stake;
                    
                    if ( bet.selection == selection )
                    {
                        winning_punters_stakes += bet.stake;
                    }
                }
            }
            
            pool = subtract_commission( pool, commission );
            return pool / winning_punters_stakes;
        }
    }
}
