
#ifndef _GAMBLING_BET_H
#define _GAMBLING_BET_H 1

//System Includes
#include <vector>
#include <cstdint>

//Project Includes
#include "product.hpp"

//External Includes

//System Namespaces

//Project Namespaces

//External Namespaces

namespace gambling
{
    struct Bet
    {
        Product product = NONE;
        unsigned int stake = 0;
        unsigned int selection = 0;
    };
    
    typedef std::vector< Bet > Bets;
}

#endif  /* _GAMBLING_BET_H */
