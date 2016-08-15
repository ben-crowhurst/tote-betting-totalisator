
#ifndef _GAMBLING_DETAIL_TOTALISATOR_IMPL_H
#define _GAMBLING_DETAIL_TOTALISATOR_IMPL_H 1

//System Includes
#include <vector>

//Project Includes

//External Includes

//System Namespaces

//Project Namespaces

//External Namespaces

namespace gambling
{
    //Forward Declarations
    struct Bet;
    struct Race;
    
    namespace detail
    {
        //Forward Declarations
        
        class TotalisatorImpl
        {
            public:
                //Friends
                
                //Definitions
                
                //Constructors
                TotalisatorImpl( void );
                
                virtual ~TotalisatorImpl( void );
                
                //Functionality
                void validate( const Race& race );
                
                void validate( const Race& race, const std::vector< Bet >& bets );
                
                void generate_race_results( Race& race );
                
                void calculate_dividends( Race& race, const std::vector< Bet >& bets );
                
                //Getters
                
                //Setters
                
                //Operators
                
                //Properties
                
            protected:
                //Friends
                
                //Definitions
                
                //Constructors
                
                //Functionality
                
                //Getters
                
                //Setters
                
                //Operators
                
                //Properties
                
            private:
                //Friends
                
                //Definitions
                
                //Constructors
                TotalisatorImpl( const TotalisatorImpl& original ) = delete;
                
                //Functionality
                
                //Getters
                
                //Setters
                
                //Operators
                TotalisatorImpl& operator =( const TotalisatorImpl& value ) = delete;
                
                //Properties
        };
    }
}

#endif  /* _GAMBLING_DETAIL_TOTALISATOR_IMPL_H */
