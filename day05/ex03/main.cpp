#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
    try
    {
        Bureaucrat s1("me", 6);
        Intern ber;

        AForm *rrf = ber.makeForm("robotomy request", "bibo");
        (void)rrf;
        s1.signForm(*rrf);
        s1.executeForm(*rrf);
        // PresidentialPardonForm a("jon");
        // s1.signForm(a);
        // s1.executeForm(a);
        // Bureaucrat s2("hid", 130);
        // ShrubberyCreationForm s("true f1");
        // s1.signForm(s);
        // s2.executeForm(s);
        // s1.signForm(s);
        // Bureaucrat *s2 = new Bureaucrat("m", 0);
        // *s1 = *s2;
        // std::cout << s1 << std::endl;
    }
    catch(const std::exception & e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}