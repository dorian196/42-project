/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 08:01:18 by dpascal           #+#    #+#             */
/*   Updated: 2025/05/30 09:52:02 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    hitPointsCount = 100;
    energyPointsCount = 100;
    std::cout << "FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name)
{
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    hitPointsCount = 100;
    energyPointsCount = 100;
    std::cout
        << "FragTrap "
        << this->name
        << " constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &src) : ClapTrap()
{
    std::cout << "FragTrap copy constructor called" << std::endl;
    *this = src;
}
FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &rhs)
{
    std::cout << "FragTrap copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        this->name = rhs.name;
        this->hitPoints    = rhs.hitPoints;
        this->energyPoints = rhs.energyPoints;
        this->attackDamage = rhs.attackDamage;
        this->hitPointsCount = rhs.hitPointsCount;
        this->energyPointsCount = rhs.energyPointsCount;
    }
    return (*this);
}

void FragTrap::attack(const std::string& target)
{
    if (!checkStatus(0))
    {
        std::cout
            << "Impossible to attack " << target
            << std::endl << std::endl;
        return ;
    }
    this->energyPoints -= 1;
    std::cout
        << "FragTrap " << this->name
        << " attacks " << target
        << ", causing " << this->attackDamage
        << " points of damage!" 
        << std::endl
        << "Energy points -1"
        << std::endl
        << "Remaining energy " << this->energyPoints
        << "/" << this->energyPointsCount << std::endl << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    if (!checkStatus(1))
    {
        std::cout
            << this->name
            << " tries to move but he can't!"
            << std::endl << std::endl;
        return ;
    }
    std::cout
        << "FragTrap "
        << this->name
        << " requests a high five!"
        << std::endl << std::endl;
}
