
#ifndef _GAMBLING_BET_H
#define _GAMBLING_BET_H 1

//System Includes
#include <vector>
#include <cstdint>

//Project Includes

//External Includes

//System Namespaces

//Project Namespaces

//External Namespaces

namespace gambling
{
    //Forward Declaration
    enum Product : uint8_t;
    
        struct Bet
    {
        Product product = { };
        unsigned int stake = 0;
        unsigned int selection = 0;
    };
}

#endif  /* _GAMBLING_BET_H */
