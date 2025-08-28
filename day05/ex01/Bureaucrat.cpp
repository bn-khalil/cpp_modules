/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 15:23:37 by kben-tou          #+#    #+#             */
/*   Updated: 2025/08/28 11:08:02 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {
    std::cout << "Bureaucrat Constructor Called!" << std::endl;
}

Bureaucrat::Bureaucrat( const std::string name, int grade ): name ( name ), grade( grade ) {
    if ( grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if ( grade > 150 )
        throw Bureaucrat::GradeTooHighException();
    std::cout << "Bureaucrat parameterized Constructor Called!" << std::endl;
}

Bureaucrat::Bureaucrat( Bureaucrat &other ): name ( other.name ), grade( other.grade ) {
    std::cout << "Bureaucrat copy Constructor Called!" << std::endl;
}

Bureaucrat& Bureaucrat::operator=( Bureaucrat &other ) {
    if ( this != &other) {
        // this->name = other.name;
        this->grade = other.grade;
    }
    return ( *this );
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat Destructor Called!" << std::endl;
}

std::string Bureaucrat::getName() const {
    return ( this->name );
}

int Bureaucrat::getGrade() const {
    return ( this->grade );
}

void Bureaucrat::increment( int add ) {
    if ((this->grade - add) < 1 )
        throw Bureaucrat::GradeTooHighException();
    this->grade -= add;
}
void Bureaucrat::decrement( int less ) {
    if ((this->grade + less) > 150 )
        throw Bureaucrat::GradeTooLowException();
    this->grade +=less;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return ( "grade too hight exception!" );
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return ( "grade too low exception!" );
}

std::ostream& operator << ( std::ostream& out , const Bureaucrat& other ) {
    out << other.getName() << ", bureaucrat grade " << other.getGrade();
    return ( out );
}