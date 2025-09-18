#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(){
    std::cout << "Intern Constructor Called!" << std::endl;
}

Intern::Intern( const Intern &other ) {
    (void)other;
    std::cout << "Intern copy Constructor Called!" << std::endl;
}

Intern & Intern::operator=( const Intern &other ) {
    (void)other;
    return ( *this );
}

Intern::~Intern() {
    std::cout << "Intern Destructor Called!" << std::endl;
}

AForm *Intern::makeForm(std::string formName, std::string target)
{
    std::string names_of_forms[3] = {
        "shrubbery creation", 
        "robotomy request",
         "presidential pardon"
    };
    int i = 0;
    while(names_of_forms[i] != formName)
        i++;
    switch (i)
    {
        case 0:
            return new ShrubberyCreationForm(target);
        case 1:
            return new RobotomyRequestForm(target);
        case 2:
            return new PresidentialPardonForm(target);
        default:
            std::cout << "form not found!" << std::endl;
    }
    return NULL;
}