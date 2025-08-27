/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 14:52:16 by kben-tou          #+#    #+#             */
/*   Updated: 2025/08/25 14:08:47 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>

class Bureaucrat
{
    private:
        const std::string name;
        int grade;
    public:
        Bureaucrat();
        Bureaucrat( std::string name, int grade );
        Bureaucrat( const Bureaucrat &other );
        Bureaucrat &operator=( const Bureaucrat &other );
        ~Bureaucrat();

        std::string getName();
        int getGrade();

        void increment( int add );
        void decrement( int less );

        class GradeTooHighException : public std::exception {
            virtual const char* what() const throw(); 
        };

        class GradeTooLowException : public std::exception {
            virtual const char* what() const throw(); 
        };
};

#endif