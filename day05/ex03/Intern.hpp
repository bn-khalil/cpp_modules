#include <iostream>
#include "AForm.hpp"

class Intern {
    private:
        AForm *create_ShrubberyCreationForm(std::string target);
        AForm *create_RobotomyRequestForm(std::string target);
        AForm *create_PresidentialPardonForm(std::string target);
    public:
        Intern();
        Intern(const Intern& other);
        Intern& operator = ( const Intern& other );
        ~Intern();

        AForm *makeForm(std::string formName, std::string target);
        class FormNotFound : public std::exception {
            const char* what() const throw();
        }; 
};