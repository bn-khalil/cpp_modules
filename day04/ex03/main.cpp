/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 12:26:57 by kben-tou          #+#    #+#             */
/*   Updated: 2025/08/02 16:08:43 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "AMateria.hpp"
#include "Character.hpp"
#include "ICharacter.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
    AMateria *ice_ball = new Ice();
    AMateria *cure = new Cure();
    (void)cure;
    ICharacter *me = new Character("bn");
    ICharacter *bch = new Character("bchafi");
    
    me->equip(ice_ball);
    me->use(0, *bch);
    std::cout << me->getName() << std::endl;

    me = bch;
    bch->equip(ice_ball);
    bch->use(0, *me);
    me->use(0, *me);
    std::cout << bch->getName() << std::endl;
    // std::cout << s->getType() << std::endl;
    // Character c;
    
    // AMateria *s = d->clone();
    // s->use();
    // std::cout << s->getType() << std::endl;
    // s->use();
    
    return 0;
}
