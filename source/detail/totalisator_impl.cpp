
//System Includes
#include <ciso646>
#include <stdexcept>

//Project Includes
#include "bet.hpp"
#include "race.hpp"
#include "product.hpp"
#include "detail/totalisator_impl.hpp"

//External Includes

//System Namespaces
using std::vector;
using std::domain_error;

//Project Namespaces

//External Namespaces

namespace gambling
{
    namespace detail
    {
        TotalisatorImpl::TotalisatorImpl( void )
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
        
        }
        
        void TotalisatorImpl::calculate_dividends( Race& race, const vector< Bet >& bets )
        {
        
        }
    }
}
