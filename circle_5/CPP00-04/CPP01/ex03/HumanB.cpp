/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 07:56:06 by dpascal           #+#    #+#             */
/*   Updated: 2025/05/26 07:56:07 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
    : name(name), weapon(NULL) {}

void    HumanB::setWeapon(Weapon& weapon)
{
    this->weapon = &weapon;
}

void    HumanB::attack( void )
{
    if (this->weapon)
    {
        std::cout
            << this->name
            << " attacks with their "
            << this->weapon->getType()
            << std::endl;
    }
    else
    {
        std::cout
            << this->name
            << " has no weapon"
            << std::endl;
    }
}
