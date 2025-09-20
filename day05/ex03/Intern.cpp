/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 10:17:31 by kben-tou          #+#    #+#             */
/*   Updated: 2025/09/20 10:54:15 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(){
    std::cout << "Intern Constructor Called!" << std::endl;
}

Intern::Intern( const Intern &other ) {
    std::cout << "Intern copy Constructor Called!" << std::endl;
    (void)other;
}

Intern & Intern::operator=( const Intern &other ) {
    std::cout << "Intern copy operator Called!" << std::endl;
    (void)other;
    return ( *this );
}

Intern::~Intern() {
    std::cout << "Intern Destructor Called!" << std::endl;
}

AForm *Intern::create_ShrubberyCreationForm(std::string target) {
    return new ShrubberyCreationForm(target);
}

AForm *Intern::create_RobotomyRequestForm(std::string target) {
    return new RobotomyRequestForm(target);
}

AForm *Intern::create_PresidentialPardonForm(std::string target) {
    return new PresidentialPardonForm(target);
}

const char *Intern::FormNotFound::what() const throw() {
    return ( "-> Form Not Found Exception!" );
}

AForm *Intern::makeForm(std::string formName, std::string target)
{
    std::string names_of_forms[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    AForm* ( Intern::*forms[3] )( std::string ) = {
        &Intern::create_ShrubberyCreationForm,
        &Intern::create_RobotomyRequestForm,
        &Intern::create_PresidentialPardonForm
    };

    int i = 0;
    while( i < 3 && names_of_forms[i] != formName)
        i++;
    
    if (i >= 3)
        throw Intern::FormNotFound();

    return (this->*forms[i])(target);
}