/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 14:52:16 by kben-tou          #+#    #+#             */
/*   Updated: 2025/08/29 10:07:28 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_H
#define AFORM_H

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string name;
        bool is_singed;
        const int grade_sing;
        const int grade_execute;
    public:
        AForm();
        AForm( const std::string name, bool is_singed, int grade_sing, int grade_execute );
        AForm( const AForm &other );
        AForm &operator=( AForm &other );
        ~AForm();

        std::string getName();
        int get_is_singed();
        int get_grade_sing();
        int get_grade_execute();
        void beSigned( Bureaucrat bureaucrat );
        virtual void execute(Bureaucrat const & executor) const = 0;
};

#endif