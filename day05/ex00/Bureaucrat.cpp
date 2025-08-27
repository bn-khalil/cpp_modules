/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 15:23:37 by kben-tou          #+#    #+#             */
/*   Updated: 2025/08/25 14:07:55 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {
    std::cout << "Bureaucrat Constructor Called!" << std::endl;
}

Bureaucrat::Bureaucrat( std::string name, int grade ) {
    std::cout << "Bureaucrat parameterized Constructor Called!" << std::endl;
    this->name = name;
    this->grade = grade;
}

Bureaucrat::Bureaucrat( const Bureaucrat &other ) {
    std::cout << "Bureaucrat copy Constructor Called!" << std::endl;
    *this = other;
}

Bureaucrat& Bureaucrat::operator=( const Bureaucrat &other ) {
    if ( this != &other) {
        this->name = name;
        this->grade = grade;
    }
    return ( *this );
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat Destructor Called!" << std::endl;
}

std::string Bureaucrat::getName() {
    return ( this->name );
}

int Bureaucrat::getGrade() {
    return ( this->grade );
}

void Bureaucrat::increment( int add ) {
    if ((this->grade - add) < 1 )
        throw GradeTooHighException;
    this->grade -= add;
}
void Bureaucrat::decrement( int less ) {
    if ((this->grade + less) > 150 )
        throw GradeTooLowException;
    this->grade +=less;
}

char *Bureaucrat::GradeTooHighException::what() const throw() {
    return ( "grade too hight exception!" );
}

char *Bureaucrat::GradeTooLowException::what() const throw() {
    return ( "grade too low exception!" );
}