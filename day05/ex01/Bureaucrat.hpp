/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 14:52:16 by kben-tou          #+#    #+#             */
/*   Updated: 2025/09/19 17:08:28 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
    private:
        const std::string name;
        int grade;
    public:
        Bureaucrat();
        Bureaucrat( const std::string name, int grade );
        Bureaucrat( const Bureaucrat &other );
        Bureaucrat &operator=( Bureaucrat &other );
        ~Bureaucrat();

        std::string getName() const;
        int getGrade() const;
        void setGrade( int grade );
        void increment();
        void decrement();
        void signForm( Form& form );

        class GradeTooHighException : public std::exception {
            const char* what() const throw(); 
        };

        class GradeTooLowException : public std::exception {
            const char* what() const throw(); 
        };
};

std::ostream& operator << ( std::ostream& out , const Bureaucrat &other );

#endif