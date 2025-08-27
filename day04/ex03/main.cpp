/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 12:26:57 by kben-tou          #+#    #+#             */
/*   Updated: 2025/08/25 14:11:30 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "ICharacter.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");
    me->equip(new Cure());
    me->equip(new Ice());
    me->equip(new Ice());
    me->equip(new Cure());
    me->equip(new Cure());
    me->unequip(0);
    me->use(0, *me);
    me->use(1, *me);
    me->use(2, *me);

    me->use(3, *me);
    me->use(4, *me);
    me->use(5, *me);

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    me->use(0, *me);
    me->use(1, *me);
    
    me->unequip(0);
    me->unequip(1);
    me->unequip(2);
    me->unequip(3);
    me->use(0, *me);
    me->equip(src->createMateria("ice"));
    me->equip(src->createMateria("cure"));

    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    me->use(2, *bob);

    delete bob;
    delete me;
    delete src;

    return 0;
}