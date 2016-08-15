
#ifndef _GAMBLING_RACE_H
#define _GAMBLING_RACE_H 1

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
    struct Race
    {
        unsigned int number_of_runners = 4;
        std::vector< unsigned int > results = { };
        
        double win_dividend = 0.0;
        std::vector< double > place_dividends = { };
    };
}

#endif  /* _GAMBLING_RACE_H */
