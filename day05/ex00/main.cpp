#include <iostream>
#include "Bureaucrat.hpp"


int main() {
    try
    {
        Bureaucrat bur1("bn", 150);
        Bureaucrat bur2 = bur1;

        bur1.increment();

        std::cout << bur1 << std::endl;
        std::cout << bur2 << std::endl;

        Bureaucrat *b1 = new Bureaucrat("ka", 1);
        Bureaucrat *b2 = new Bureaucrat("li", 31);
        
        b1->decrement();

        std::cout << *b1 << std::endl;
        std::cout << *b2 << std::endl;

        delete b1;
        delete b2;
    }
    catch(const std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}