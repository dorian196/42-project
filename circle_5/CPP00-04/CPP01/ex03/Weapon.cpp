/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 07:56:14 by dpascal           #+#    #+#             */
/*   Updated: 2025/05/26 07:56:15 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string& type)
{
    this->type = type;
}

const std::string& Weapon::getType() const
{
    return (this->type);
}

void    Weapon::setType(const std::string& type)
{
    this->type = type;
}
