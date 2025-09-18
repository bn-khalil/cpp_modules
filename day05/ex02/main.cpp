#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
    try
    {
        Bureaucrat s1("me", 145);
        Bureaucrat s2("hid", 130);
        ShrubberyCreationForm s("true f1");
        s1.signForm(s);
        // s1.signForm(s);
        s2.executeForm(s);
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