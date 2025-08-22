/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 12:48:23 by kben-tou          #+#    #+#             */
/*   Updated: 2025/08/22 10:30:53 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_H
#define CURE_H

#include "AMateria.hpp"

class Cure: public AMateria
{
    public:
        Cure();
        Cure( Cure const & other );
        Cure & operator=( const Cure & other);
        ~Cure();

        AMateria* clone() const;
        void use(ICharacter& target);
};
#endif