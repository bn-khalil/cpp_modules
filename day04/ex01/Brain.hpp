/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 16:32:32 by kben-tou          #+#    #+#             */
/*   Updated: 2025/08/20 13:20:50 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BRAIN_H
#define BRAIN_H

#include <iostream>
#include "Brain.hpp"

class Brain
{
    private:
        std::string ideas[100];
        int index;
    public:
        Brain();
        Brain( const Brain &other );
        Brain &operator=( const Brain &other );
        ~Brain();

        std::string *getIdeas();
        void setIdea( std::string idea );
};

#endif