/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 07:56:01 by dpascal           #+#    #+#             */
/*   Updated: 2025/05/26 07:56:02 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon)
    : name(name), weapon(weapon) {}

void    HumanA::attack( void )
{
    std::cout
        << this->name
        << " attacks with their "
        << this->weapon.getType()
        << std::endl;
}
