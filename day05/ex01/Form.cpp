/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 11:27:25 by kben-tou          #+#    #+#             */
/*   Updated: 2025/08/28 11:33:23 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() {
    std::cout << "Form Constructor Called!" << std::endl;
}

Form::Form( const std::string name, bool is_signed, const int grade_sing, const int grade_execute ): 
    name ( name ),
    is_signed ( is_signed ),
    grade_sing ( grade_sing )
    grade_execute ( grade_execute ) {
    std::cout << "Form parameterized Constructor Called!" << std::endl;
}

Form::Form( Form &other ):
    name ( other.name ),
    is_signed ( other.is_signed ),
    grade_sing ( other.grade_sing )
    grade_execute ( other.grade_execute ) {
    std::cout << "Form copy Constructor Called!" << std::endl;
}

Form& Form::operator=( Form &other ) {
    if ( this != &other) {
        // this->name = other.name;
        this->grade = other.grade;
    }
    return ( *this );
}

Form::~Form() {
    std::cout << "Bureaucrat Destructor Called!" << std::endl;
}