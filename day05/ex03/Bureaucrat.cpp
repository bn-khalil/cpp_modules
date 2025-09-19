/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 15:23:37 by kben-tou          #+#    #+#             */
/*   Updated: 2025/09/19 18:38:35 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("BureaucratNoName"), grade( 150 ) {
    std::cout << "Bureaucrat Constructor Called!" << std::endl;
}

Bureaucrat::Bureaucrat( const std::string name, int grade ): name ( name ), grade( grade ) {
    if ( grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if ( grade > 150 )
        throw Bureaucrat::GradeTooHighException();
    std::cout << "Bureaucrat parameterized Constructor Called!" << std::endl;
}

Bureaucrat::Bureaucrat( const Bureaucrat &other ): name ( other.name ), grade( other.grade ) {
    std::cout << "Bureaucrat copy Constructor Called!" << std::endl;
}

Bureaucrat& Bureaucrat::operator=( Bureaucrat &other ) {
    std::cout << "Bureaucrat copy assignment operator Called!" << std::endl;
    if ( this != &other) 
        this->grade = other.grade;
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

void Bureaucrat::increment() {
    if ( (this->grade - 1) < 1 )
        throw Bureaucrat::GradeTooHighException();
    this->grade--;
}
void Bureaucrat::decrement() {
    if ( (this->grade + 1) > 150 )
        throw Bureaucrat::GradeTooLowException();
    this->grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return ( "-> Bureaucrat grade too hight exception!" );
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return ( "-> Bureaucrat grade too low exception!" );
}

void Bureaucrat::setGrade( int grade ) {
    if ( grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else if ( grade < 1)
        throw Bureaucrat::GradeTooHighException();
    this->grade = grade;
}

void Bureaucrat::signForm( AForm& form ) {
    try {
        form.beSigned( *this );
    }
    catch(std::exception & e) {
        std::cout << this->getName() << " " <<  "couldn’t sign " << form.getName() << " because form grade is too high"<< std::endl;
    }
}

void Bureaucrat::executeForm(AForm const & form) const {
    try
    {
        form.execute( *this );
        std::cout << this->name << " executed " << form.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}


std::ostream& operator << ( std::ostream& out , const Bureaucrat& other ) {
    out << other.getName() << ", bureaucrat grade " << other.getGrade();
    return ( out );
}