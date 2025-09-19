#include <iostream>
#include "Bureaucrat.hpp"


int main() {
    try
    {
        Bureaucrat s1("me", 12);
        Bureaucrat *s2 = new Bureaucrat("m", 1);
        s1 = *s2;
        std::cout << s1 << std::endl;
        delete s2;
    }
    catch(const std::exception & e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}