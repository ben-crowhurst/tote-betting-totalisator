
#ifndef _GAMBLING_SETTINGS_H
#define _GAMBLING_SETTINGS_H 1

//System Includes
#include <cstdint>

//Project Includes

//External Includes

//System Namespaces

//Project Namespaces

//External Namespaces

namespace gambling
{
    struct Settings
    {
        uint8_t win_commission = 15;
        uint8_t place_commission = 12;
        
        unsigned int place_winner_boundary = 3;
    };
}

#endif  /* _GAMBLING_SETTINGS_H */
