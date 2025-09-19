/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 17:43:57 by kben-tou          #+#    #+#             */
/*   Updated: 2025/09/19 18:12:13 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", false, 145, 137){
    std::cout << "ShrubberyCreationForm Constructor Called!" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target): 
    AForm("ShrubberyCreationForm", false, 145, 137),
    target(target) {
    std::cout << "ShrubberyCreationForm parameterized Constructor Called!" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm &other ): 
    AForm("ShrubberyCreationForm", false, 145, 137),
    target(other.target) {
    set_is_signed(other.get_is_signed());
    std::cout << "ShrubberyCreationForm copy Constructor Called!" << std::endl;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=( const ShrubberyCreationForm &other ) {
    if ( this != &other){
        this->target = other.target;
        set_is_signed(other.get_is_signed());
    }
    return ( *this );
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "ShrubberyCreationForm Destructor Called!" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const{
    if (!get_is_signed())
        throw AForm::FormNotSinged();
    if (executor.getGrade() > get_grade_execute())
        throw AForm::GradeTooHighException();
    std::ofstream outf((this->target + "__shrubbery").c_str());
    if (!outf.is_open())
        std::cerr << "file opening failed!" << std::endl;
    outf 
    << "       ccee88oo\n"
    << "   C8O8O8Q8PoOb o8oo\n"
    << " dOB69QO8PdUOpugoO9bD\n"
    << "CgggbU8OU qOp qOdoUOdcb\n"
    << "    6OuU  /p u gcoUodpP\n"
    << "      \\\\//  /douUP\n"
    << "        \\\\////\n"
    << "         |||/\\\n"
    << "         |||\\/\n"
    << "         |||||\n"
    << "   .....//||||\\...."
    << std::endl;
    outf.close();
    std::cout << executor.getName() << " execute " << this->target << " form!" << std::endl;
}