/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 07:55:14 by dpascal           #+#    #+#             */
/*   Updated: 2025/05/26 07:55:15 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    this->name = name;
}

Zombie::~Zombie()
{
    std::cout
        << this->name
        << ": is destroyed"
        << std::endl; 
}

void Zombie::announce( void )
{
    std::cout
        << this->name
        << ": BraiiiiiiinnnzzzZ..."
        << std::endl;
}
