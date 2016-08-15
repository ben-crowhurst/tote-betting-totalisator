
//System Includes

//Project Includes
#include "bet.hpp"
#include "race.hpp"
#include "totalisator.hpp"
#include "detail/totalisator_impl.hpp"

//External Includes

//System Namespaces
using std::vector;
using std::unique_ptr;

//Project Namespaces
using gambling::detail::TotalisatorImpl;

//External Namespaces

namespace gambling
{
    Totalisator::Totalisator( void ) : m_pimpl( new TotalisatorImpl )
    {
        return;
    }
    
    Totalisator::~Totalisator( void )
    {
        return;
    }
    
    void Totalisator::run( Race& race, const vector< Bet >& bets )
    {
        m_pimpl->validate( race );
        m_pimpl->validate( race, bets );
        m_pimpl->generate_race_results( race );
        m_pimpl->calculate_dividends( race, bets );
    }
}
