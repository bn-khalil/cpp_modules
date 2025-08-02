/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 12:11:38 by kben-tou          #+#    #+#             */
/*   Updated: 2025/08/02 13:42:17 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_H
#define ICE_H

#include "AMateria.hpp"

class Ice: public AMateria
{
    public:
        Ice();
        Ice( Ice const & other );
        Ice & operator=( const Ice & other);
        ~Ice();

        AMateria* clone() const;
        void use(ICharacter& target);
};
#endif