#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try
    {
        const Bureaucrat s1("me", 12);
        Form s;
        // Bureaucrat *s2 = new Bureaucrat("m", 0);
        // *s1 = *s2;
        std::cout << s1 << std::endl;
    }
    catch(const std::exception & e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}