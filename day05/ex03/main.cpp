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
        Bureaucrat s1("bn", 5);
    
        Intern ber1;
        Intern *ber2 = new Intern();

        AForm *rrf = ber1.makeForm("robotomy request", "bibo");
        AForm *cre = ber2->makeForm("shrubbery creation", "dido");
        AForm *per = ber2->makeForm("presidential pardon", "kiko");

        std::cout << "==============================" << std::endl;
        s1.signForm(*rrf);
        s1.executeForm(*rrf);
        std::cout << "==============================" << std::endl;
        s1.signForm(*cre);
        s1.executeForm(*cre);
        std::cout << "==============================" << std::endl;
        s1.signForm(*per);
        s1.executeForm(*per);
        std::cout << "==============================" << std::endl;

        AForm *inc = ber1.makeForm("invalid", "tito");

        s1.signForm(*inc);
        s1.executeForm(*inc);
        
        std::cout << *inc << std::endl; 
    }
    catch(const std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}