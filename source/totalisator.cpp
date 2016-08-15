
//System Includes

//Project Includes
#include "totalisator.hpp"
#include "detail/totalisator_impl.hpp"

//External Includes

//System Namespaces

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
}
