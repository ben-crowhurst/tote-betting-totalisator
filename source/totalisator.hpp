
#ifndef _GAMBLING_TOTALISATOR_H
#define _GAMBLING_TOTALISATOR_H 1

//System Includes
#include <vector>
#include <memory>

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
        class TotalisatorImpl;
    }
    
    class Totalisator
    {
        public:
            //Friends
            
            //Definitions
            
            //Constructors
            Totalisator( void );
            
            virtual ~Totalisator( void );
            
            //Functionality
            void run( Race& race, const std::vector< Bet >& bets );
            
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
            Totalisator( const Totalisator& original ) = delete;
            
            //Functionality
            
            //Getters
            
            //Setters
            
            //Operators
            Totalisator& operator =( const Totalisator& value ) = delete;
            
            //Properties
            std::unique_ptr< detail::TotalisatorImpl > m_pimpl;
    };
}

#endif  /* _GAMBLING_TOTALISATOR_H */
