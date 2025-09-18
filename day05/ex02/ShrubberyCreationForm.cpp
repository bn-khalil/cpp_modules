#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() {
    std::cout << "ShrubberyCreationForm Constructor Called!" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target): target(target){
    if (target.empty)
        //
    std::cout << "ShrubberyCreationForm parameterized Constructor Called!" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm &other ) {
    std::cout << "ShrubberyCreationForm copy Constructor Called!" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=( ShrubberyCreationForm &other ) {
    if ( this != &other) {
        // this->name = other.name;
        this->grade = other.grade;
    }
    return ( *this );
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "ShrubberyCreationForm Destructor Called!" << std::endl;
}
