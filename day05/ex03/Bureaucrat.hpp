/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 14:52:16 by kben-tou          #+#    #+#             */
/*   Updated: 2025/09/19 18:38:25 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>
#include "AForm.hpp"

class AForm;

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
        void signForm( AForm& form );
        void executeForm(AForm const & form) const;

        class GradeTooHighException : public std::exception {
            const char* what() const throw(); 
        };

        class GradeTooLowException : public std::exception {
            const char* what() const throw(); 
        };
};

std::ostream& operator << ( std::ostream& os , const Bureaucrat &other );

#endif