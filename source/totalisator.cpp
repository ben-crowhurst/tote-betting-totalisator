/*
 * Copyright, Gambling Holdings Limited, All Rights Reserved.
 */

//System Includes

//Project Includes
#include "bet.hpp"
#include "race.hpp"
#include "settings.hpp"
#include "totalisator.hpp"
#include "detail/totalisator_impl.hpp"

//External Includes

//System Namespaces
using std::vector;
using std::unique_ptr;
using std::shared_ptr;

//Project Namespaces
using gambling::detail::TotalisatorImpl;

//External Namespaces

namespace gambling
{
    Totalisator::~Totalisator( void )
    {
        return;
    }
    
    void Totalisator::run( Race& race, const vector< Bet >& bets )
    {
        if ( bets.empty( ) )
        {
            return;
        }
        
        m_pimpl->validate( race );
        m_pimpl->validate( race, bets );
        m_pimpl->generate_race_results( race );
        m_pimpl->calculate_dividends( race, bets );
    }
    
    shared_ptr< Totalisator > Totalisator::create( const Settings& settings )
    {
        return shared_ptr< Totalisator >( new Totalisator( settings ) );
    }
    
    Totalisator::Totalisator( const Settings& settings ) : m_pimpl( new TotalisatorImpl )
    {
        m_pimpl->m_win_commission = settings.win_commission;
        m_pimpl->m_place_commission = settings.place_commission;
        m_pimpl->m_place_winner_boundary = settings.place_winner_boundary;
    }
}
