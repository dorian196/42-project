/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 08:02:00 by dpascal           #+#    #+#             */
/*   Updated: 2025/05/30 11:03:43 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    _hitPointsCount = 100;
    _energyPointsCount = 100;
    std::cout << "FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    _hitPointsCount = 100;
    _energyPointsCount = 100;
    std::cout
        << "FragTrap "
        << this->_name
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
        this->_name = rhs._name;
        this->_hitPoints    = rhs._hitPoints;
        this->_energyPoints = rhs._energyPoints;
        this->_attackDamage = rhs._attackDamage;
        this->_hitPointsCount = rhs._hitPointsCount;
        this->_energyPointsCount = rhs._energyPointsCount;
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
    this->_energyPoints -= 1;
    std::cout
        << "FragTrap " << this->_name
        << " attacks " << target
        << ", causing " << this->_attackDamage
        << " points of damage!" 
        << std::endl
        << "Energy points -1"
        << std::endl
        << "Remaining energy " << this->_energyPoints
        << "/" << this->_energyPointsCount << std::endl << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    if (!checkStatus(1))
    {
        std::cout
            << this->_name
            << " tries to move but he can't!"
            << std::endl << std::endl;
        return ;
    }
    std::cout
        << "FragTrap "
        << this->_name
        << " requests a high five!"
        << std::endl << std::endl;
}
