/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 17:44:13 by kben-tou          #+#    #+#             */
/*   Updated: 2025/09/20 10:59:06 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", false, 25, 5){
    std::cout << "PresidentialPardonForm Constructor Called!" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( std::string target): 
    AForm("PresidentialPardonForm", false, 25, 5),
    target(target) {
    std::cout << "PresidentialPardonForm parameterized Constructor Called!" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm &other ): 
    AForm("PresidentialPardonForm", false, 25, 5),
    target(other.target) {
    set_is_signed(other.get_is_signed());
    std::cout << "PresidentialPardonForm copy Constructor Called!" << std::endl;
}

PresidentialPardonForm & PresidentialPardonForm::operator=( const PresidentialPardonForm &other ) {
    std::cout << "PresidentialPardonForm copy operator Called!" << std::endl;
    if ( this != &other){
        this->target = other.target;
        set_is_signed(other.get_is_signed());
    }
    return ( *this );
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "PresidentialPardonForm Destructor Called!" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const{
    if (!get_is_signed())
        throw AForm::FormNotSinged();
    if (executor.getGrade() > get_grade_execute())
        throw AForm::GradeTooHighException();

    std::cout << this->target << " has been pardoned by Zaphod Beeblebrox !" << std::endl; 
}
