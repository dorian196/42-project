/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 08:01:27 by dpascal           #+#    #+#             */
/*   Updated: 2025/05/30 09:51:53 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    hitPointsCount = 100;
    energyPointsCount = 50;
    std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name)
{
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    hitPointsCount = 100;
    energyPointsCount = 50;
    std::cout
        << "ScavTrap "
        << this->name
        << " constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap()
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
    *this = src;
}
ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &rhs)
{
    std::cout << "ScavTrap copy assignment operator called" << std::endl;
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

void ScavTrap::attack(const std::string& target)
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
        << "ScavTrap " << this->name
        << " attacks " << target
        << ", causing " << this->attackDamage
        << " points of damage!" 
        << std::endl
        << "Energy points -1"
        << std::endl
        << "Remaining energy " << this->energyPoints
        << "/" << this->energyPointsCount << std::endl << std::endl;
}

void ScavTrap::guardGate()
{
    if (!checkStatus(1))
    {
        std::cout
            << "Entered eternal rest mode!"
            << std::endl << std::endl;
        return ;
    }
    std::cout
        << "ScavTrap " << name 
        << " entered Gate Keeper mode!"
        << std::endl<< std::endl;
}

