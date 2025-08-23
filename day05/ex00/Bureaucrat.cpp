/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 15:23:37 by kben-tou          #+#    #+#             */
/*   Updated: 2025/08/22 15:30:41 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {

}

Bureaucrat::Bureaucrat( std::string name, int grade) {
    this->name = name;
    this->name = grade;
}

std::string Bureaucrat::getName() {
    return ( this->name );
}
int Bureaucrat::getGrade() {
    return ( this->grade );
}
void Bureaucrat::increment() {
    this->grade++;
}
void Bureaucrat::decrement() {
    this->grade--;
}