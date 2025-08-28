/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 11:27:25 by kben-tou          #+#    #+#             */
/*   Updated: 2025/08/28 21:54:51 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat"

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
    this->is_signed = true;
    std::cout << bureaucrat.getName() << " singe " << this->name << " form!" << std::enld;
}