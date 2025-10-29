#ifndef RPN_H
#define RPN_H

#include <iostream>
#include <stack>

class RPN
{
    private:
        std::stack<int> store;
        std::string rpn;

    public:
        RPN();
        RPN( const RPN & other );
        RPN & operator = ( const RPN & other );
        ~RPN();

        bool paseRpn(char *arg);
        bool execRpn();
        void displayResuts();
};

#endif