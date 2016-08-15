
#ifndef _GAMBLING_PRODUCT_H
#define _GAMBLING_PRODUCT_H 1

//System Includes
#include <cstdint>

//Project Includes

//External Includes

//System Namespaces

//Project Namespaces

//External Namespaces

namespace gambling
{
    enum Product : uint8_t
    {
        NONE = 0,
        WIN = 1,
        PLACE = 2
    };
}

#endif  /* _GAMBLING_PRODUCT_H */
