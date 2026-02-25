#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN( const RPN& other ) {
    this->store = other.store;
    this->rpn = other.rpn;
}

RPN & RPN::operator = ( const RPN &other ) {
    if (this != &other) {
        this->store = other.store;
        this->rpn = other.rpn;
    }
    return ( *this );
}

RPN::~RPN() {}


bool RPN::paseRpn(char *arg) {
    std::string value(arg);
    size_t i = 0;

    if (value.empty())
        return false;
    for(; i < value.size(); i++) {
        if (!std::isdigit(value[i]) 
        && value[i] != '-' 
        && value[i] != '+' 
        && value[i] != '*' 
        && value[i] != '/' 
        && !std::isspace(value[i]))
            return false;
    }
    i--;
    while (std::isspace(value[i]))
        i--;
    if (value[i] != '-' 
        && value[i] != '+' 
        && value[i] != '*' 
        && value[i] != '/')
        return false;
    this->rpn = value;
    return true;
}

bool RPN::execRpn() {
    for(size_t i = 0; i < this->rpn.size(); i++) {
        if (std::isspace(rpn[i]))
            continue ;
        if (!std::isdigit(rpn[i]) && this->store.size() <= 1)
            return false;
        if (std::isdigit(rpn[i])) {
            int num = rpn[i] - '0';
            this->store.push(num);
        }
        else if (rpn[i] == '-' 
            || rpn[i] == '+' 
            || rpn[i] == '*' 
            || rpn[i] == '/') {
                int second = this->store.top();
                this->store.pop();
                int first = this->store.top();
                this->store.pop();
                int res;
                
                if (rpn[i] == '+')
                    res = first + second;
                else if (rpn[i] == '-')
                    res = first - second;
                else if (rpn[i] == '*')
                    res = first * second;
                else {
                    if (second == 0)
                        return false;
                    res = first / second;
                }
                this->store.push(res);
            }
    }
    if (this->store.size() != 1)
        return false;
    return true;
}

void RPN::displayResuts() {
    std::cout << this->store.top() << std::endl;
}
