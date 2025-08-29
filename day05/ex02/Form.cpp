/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 11:27:25 by kben-tou          #+#    #+#             */
/*   Updated: 2025/08/29 10:07:07 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form(): name(""), is_singed(false), grade_sing(0), grade_execute(0) {
    std::cout << "Form Constructor Called!" << std::endl;
}

Form::Form( const std::string name, 
    bool is_singed, 
    int grade_sing, 
    int grade_execute ): 
    name ( name ),
    is_singed ( is_singed ),
    grade_sing ( grade_sing ),
    grade_execute ( grade_execute ) {
    if ( grade_sing < 1 || grade_execute < 1)
        throw Bureaucrat::GradeTooHighException();
    else if ( grade_sing > 150 || grade_execute > 150 )
        throw Bureaucrat::GradeTooLowException();
    std::cout << "Form parameterized Constructor Called!" << std::endl;
}

Form::Form( const Form &other ):
    name ( other.name ),
    is_singed ( other.is_singed ),
    grade_sing ( other.grade_sing ),
    grade_execute ( other.grade_execute ) {
    std::cout << "Form copy Constructor Called!" << std::endl;
}

Form& Form::operator=( Form &other ) {
    if ( this != &other) {
        // this->grade_sing = other.grade_sing;
        // this->grade_execute = other.grade_execute;
        this->is_singed = other.is_singed;
    }
    return ( *this );
}

Form::~Form() {
    std::cout << "Form Destructor Called!" << std::endl;
}

void Form::beSigned( Bureaucrat bureaucrat ) {
    if ( bureaucrat.getGrade() > this->grade_sing )
        throw Bureaucrat::GradeTooLowException();
    this->is_singed = true;
    std::cout << bureaucrat.getName() << " singed " << this->name << std::endl;
}


std::string Form::getName() {
    return ( this->name );
}

int Form::get_is_singed() {
    return ( this->is_singed );
}

int Form::get_grade_sing() {
    return ( this->grade_sing );
}

int Form::get_grade_execute() {
    return ( this->grade_execute );
}