/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 14:52:16 by kben-tou          #+#    #+#             */
/*   Updated: 2025/09/19 18:36:42 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_H
#define AFORM_H

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string name;
        bool is_signed;
        const int grade_sing;
        const int grade_execute;
    public:
        AForm();
        AForm( const std::string name, bool is_signed, int grade_sing, int grade_execute );
        AForm( const AForm &other );
        AForm &operator=( AForm &other );
        virtual ~AForm();

        std::string getName() const;
        bool get_is_signed() const;
        int get_grade_sing() const;
        int get_grade_execute() const;
        void set_is_signed(bool is_signed);
        void beSigned( const Bureaucrat & bureaucrat );
        virtual void execute(Bureaucrat const & executor) const = 0;

        class GradeTooHighException : public std::exception {
            const char* what() const throw(); 
        };

        class GradeTooLowException : public std::exception {
            const char* what() const throw(); 
        };

        class FormNotSinged : public std::exception {
            const char* what() const throw();
        };
};

std::ostream& operator << (std::ostream &out, const AForm &other);

#endif