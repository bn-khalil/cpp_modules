/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 17:44:07 by kben-tou          #+#    #+#             */
/*   Updated: 2025/09/19 18:09:01 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include <ctime>


RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", false, 72, 45){
    std::cout << "RobotomyRequestForm Constructor Called!" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( std::string target): 
    AForm("RobotomyRequestForm", false, 72, 45),
    target(target) {
    std::cout << "RobotomyRequestForm parameterized Constructor Called!" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm &other ): 
    AForm("RobotomyRequestForm", false, 72, 45),
    target(other.target) {
    set_is_signed(other.get_is_signed());
    std::cout << "RobotomyRequestForm copy Constructor Called!" << std::endl;
}

RobotomyRequestForm & RobotomyRequestForm::operator=( const RobotomyRequestForm &other ) {
    if ( this != &other){
        this->target = other.target;
        set_is_signed(other.get_is_signed());
    }
    return ( *this );
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "RobotomyRequestForm Destructor Called!" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const{
    if (!get_is_signed())
        throw AForm::FormNotSinged();
    if (executor.getGrade() > get_grade_execute())
        throw AForm::GradeTooHighException();
    std::cout << "Bzzzzzzzz... drilling noises..." << std::endl;
    if (time(NULL) % 2)
        std::cout << this->target << " has been robotomized successfully!" << std::endl;
    else
        std::cout << this->target << " robotomized failed!" << std::endl;
}