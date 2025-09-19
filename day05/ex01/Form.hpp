/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 14:52:16 by kben-tou          #+#    #+#             */
/*   Updated: 2025/09/19 17:10:53 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
#define FORM_H

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string name;
        bool is_signed;
        const int grade_sing;
        const int grade_execute;
    public:
        Form();
        Form( const std::string name, bool is_signed, int grade_sing, int grade_execute );
        Form( const Form &other );
        Form &operator=( Form &other );
        ~Form();

        std::string getName() const;
        int get_is_signed() const;
        int get_grade_sing() const;
        int get_grade_execute() const;
        void set_is_signed( bool is_signed );
        void beSigned( const Bureaucrat & bureaucrat );

        class GradeTooHighException : public std::exception {
            const char* what() const throw(); 
        };

        class GradeTooLowException : public std::exception {
            const char* what() const throw(); 
        };
};

std::ostream& operator << ( std::ostream& out , const Form &other );

#endif