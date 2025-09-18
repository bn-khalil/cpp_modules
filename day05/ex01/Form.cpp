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

Form::Form(): name(""), is_signed(false), grade_sing(0), grade_execute(0) {
    std::cout << "Form Constructor Called!" << std::endl;
}

Form::Form( const std::string name, 
    bool is_signed, 
    int grade_sing, 
    int grade_execute ): 
    name ( name ),
    is_signed ( is_signed ),
    grade_sing ( grade_sing ),
    grade_execute ( grade_execute ) {
    if ( grade_sing < 1 || grade_execute < 1)
        throw Form::GradeTooHighException();
    else if ( grade_sing > 150 || grade_execute > 150 )
        throw Form::GradeTooLowException();
    std::cout << "Form parameterized Constructor Called!" << std::endl;
}

Form::Form( const Form &other ):
    name ( other.name ),
    is_signed ( other.is_signed ),
    grade_sing ( other.grade_sing ),
    grade_execute ( other.grade_execute ) {
    std::cout << "Form copy Constructor Called!" << std::endl;
}

Form& Form::operator=( Form &other ) {
    if ( this != &other) {
        // this->grade_sing = other.grade_sing;
        // this->grade_execute = other.grade_execute;
        this->is_signed = other.is_signed;
    }
    return ( *this );
}

Form::~Form() {
    std::cout << "Form Destructor Called!" << std::endl;
}

const char *Form::GradeTooHighException::what() const throw() {
    return ( "Form grade too hight exception!" );
}

const char *Form::GradeTooLowException::what() const throw() {
    return ( "Form grade too low exception!" );
}

void Form::beSigned( Bureaucrat bureaucrat ) {
    if ( bureaucrat.getGrade() > this->grade_sing )
        throw Form::GradeTooLowException();
    this->is_signed = true;
    std::cout << bureaucrat.getName() << " singed " << this->name << std::endl;
}

std::string Form::getName() {
    return ( this->name );
}

int Form::get_is_signed() {
    return ( this->is_signed );
}

int Form::get_grade_sing() {
    return ( this->grade_sing );
}

int Form::get_grade_execute() {
    return ( this->grade_execute );
}