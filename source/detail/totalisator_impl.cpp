
//System Includes

//Project Includes
#include "bet.hpp"
#include "race.hpp"
#include "detail/totalisator_impl.hpp"

//External Includes

//System Namespaces
using std::vector;

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
        
        }
        
        void TotalisatorImpl::validate( const Race& race, const vector< Bet >& bets )
        {
        
        }
        
        void TotalisatorImpl::generate_race_results( Race& race )
        {
        
        }
        
        void TotalisatorImpl::calculate_dividends( Race& race, const vector< Bet >& bets )
        {
        
        }
    }
}
