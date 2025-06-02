/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 08:02:09 by dpascal           #+#    #+#             */
/*   Updated: 2025/05/30 09:48:42 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    _hitPointsCount = 100;
    _energyPointsCount = 50;
    std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    _hitPointsCount = 100;
    _energyPointsCount = 50;
    std::cout
        << "ScavTrap "
        << this->_name
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
        this->_name = rhs._name;
        this->_hitPoints    = rhs._hitPoints;
        this->_energyPoints = rhs._energyPoints;
        this->_attackDamage = rhs._attackDamage;
        this->_hitPointsCount = rhs._hitPointsCount;
        this->_energyPointsCount = rhs._energyPointsCount;
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
    this->_energyPoints -= 1;
    std::cout
        << "ScavTrap " << this->_name
        << " attacks " << target
        << ", causing " << this->_attackDamage
        << " points of damage!" 
        << std::endl
        << "Energy points -1"
        << std::endl
        << "Remaining energy " << this->_energyPoints
        << "/" << this->_energyPointsCount << std::endl << std::endl;
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
        << "ScavTrap " << _name 
        << " entered Gate Keeper mode!"
        << std::endl<< std::endl;
}

