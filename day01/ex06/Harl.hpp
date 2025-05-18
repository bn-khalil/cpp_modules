#ifndef Harl_H
#define Harl_H

#include <iostream>

typedef enum s_type{
    DEBUG,
    INFO,
    WARNING,
    ERROR
} t_type;

class Harl
{
    private:
        void debug( void );
        void info( void );
        void warning( void );
        void error( void );
    public:
        void complain( std::string level );
};
#endif
