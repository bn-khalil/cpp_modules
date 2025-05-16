/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:24:59 by kben-tou          #+#    #+#             */
/*   Updated: 2025/05/16 15:51:43 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H
#include <iostream>


class Zombie{
    private:
    std::string name;
    
    public:
    Zombie( std::string name );
    ~Zombie();

    void announce( void );
};

void randomChump( std::string name );
Zombie* newZombie( std::string name );

#endif
