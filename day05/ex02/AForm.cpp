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
#include "AForm.hpp"

AForm::AForm(): name(""), is_signed(false), grade_sing(0), grade_execute(0) {
    std::cout << "AForm Constructor Called!" << std::endl;
}

AForm::AForm( const std::string name, 
    bool is_signed, 
    int grade_sing, 
    int grade_execute ): name ( name ),
    is_signed ( is_signed ),
    grade_sing ( grade_sing ),
    grade_execute ( grade_execute ) {
    if ( grade_sing < 1 || grade_execute < 1)
        throw AForm::GradeTooHighException();
    else if ( grade_sing > 150 || grade_execute > 150 )
        throw AForm::GradeTooLowException();
    std::cout << "AForm parameterized Constructor Called!" << std::endl;
}

AForm::AForm( const AForm &other ):
    name ( other.name ),
    is_signed ( other.is_signed ),
    grade_sing ( other.grade_sing ),
    grade_execute ( other.grade_execute ) {
    std::cout << "AForm copy Constructor Called!" << std::endl;
}

AForm& AForm::operator=( AForm &other ) {
    std::cout << "AForm copy assignment operator Called!" << std::endl;
    if ( this != &other)
        this->is_signed = other.is_signed;
    return ( *this );
}

AForm::~AForm() {
    std::cout << "AForm Destructor Called!" << std::endl;
}

const char *AForm::GradeTooHighException::what() const throw() {
    return ( "-> AForm grade too hight exception!" );
}

const char *AForm::GradeTooLowException::what() const throw() {
    return ( "-> AForm grade too low exception!" );
}

const char *AForm::FormNotSinged::what() const throw() {
    return ( "-> form not singed exception!" );
}

void AForm::set_is_signed(bool is_signed)
{
    this->is_signed = is_signed;
}

void AForm::beSigned(Bureaucrat bureaucrat)
{
    if ( bureaucrat.getGrade() > this->grade_sing )
        throw AForm::GradeTooHighException();
    if (this->is_signed)
    {
        std::cout  << "form " << this->name << " is already singed by " << bureaucrat.getName() << std::endl;
        return ;
    }
    this->is_signed = true;
    std::cout << bureaucrat.getName() << " singed " << this->name << std::endl;
}

std::string AForm::getName() const{
    return ( this->name );
}

bool AForm::get_is_signed() const{
    return ( this->is_signed );
}

int AForm::get_grade_sing() const{
    return ( this->grade_sing );
}

int AForm::get_grade_execute() const{
    return ( this->grade_execute );
}
