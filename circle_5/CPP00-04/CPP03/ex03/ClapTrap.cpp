/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 08:01:51 by dpascal           #+#    #+#             */
/*   Updated: 2025/05/30 09:46:26 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
    : _hitPoints(10), _energyPoints(10), _attackDamage(0), _hitPointsCount(_hitPoints), _energyPointsCount(_energyPoints)
{
    std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string name)
    : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0), _hitPointsCount(_hitPoints), _energyPointsCount(_energyPoints)
{
    std::cout
        << "ClapTrap "
        << this->_name
        << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src)
    :  _hitPointsCount(_hitPoints), _energyPointsCount(_energyPoints)
{
    std::cout << "ClapTrap copy constructor called" << std::endl;
    *this = src;
}
ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs)
{
    std::cout << "ClapTrap copy assignment operator called" << std::endl;
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

void ClapTrap::attack(const std::string& target)
{
    if (!checkStatus(0))
    {
        std::cout << "Attack is impossible" << std::endl << std::endl;
        return ;
    }
    this->_energyPoints -= 1;
    std::cout
        << "ClapTrap " << this->_name
        << " attacks " << target
        << ", causing " << this->_attackDamage
        << " points of damage!" 
        << std::endl
        << "Energy points -1"
        << std::endl
        << "Remaining energy = " << this->_energyPoints << "/"
        << this->_energyPointsCount << std::endl << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (amount > 2147483647)
        amount = 2147483647;
    int temp = amount;
    if (temp < 0)
        temp *= -1;
    if (!checkStatus(1))
    {
        std::cout << "You don't hit a soldier on the ground" << std::endl << std::endl;
        return ;
    }
    this->_hitPoints -= temp;
    std::cout
        << "ClapTrap " << this->_name
        << " takes " << temp
        << " points of damage"
        <<  std::endl
        << "Hit points -" << temp
        <<  std::endl;
        if (this->_hitPoints < 0)
        {
            this->_hitPoints = 0;
            std::cout
                << "Remaining hit points " << this->_hitPoints
                << "/" << this->_hitPointsCount;
        }
        else
        {
            std::cout
                << "Remaining hit points = " << this->_hitPoints
                << "/" << this->_hitPointsCount;
        }
        std::cout << std::endl << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (amount > 2147483647)
        amount = 2147483647;
    int temp = amount;
    if (temp < 0)
        temp *= -1;
    if (!checkStatus(0))
    {
        std::cout << "Regain life is impossible" << std::endl << std::endl;
        return ;
    }
    if ((this->_hitPoints += temp) > this->_hitPointsCount)
        this->_hitPoints = this->_hitPointsCount;
    this->_energyPoints -= 1;
    std::cout
        << "ClapTrap " << this->_name
        << " repairs itself of " << temp
        << " hit points"
        << std::endl
        << "Remaining hit points = " << this->_hitPoints << "/"
        << this->_hitPointsCount << std::endl
        << "Energy points -1"
        << std::endl
        << "Remaining energy = " << this->_energyPoints << "/"
        << this->_energyPointsCount << std::endl << std::endl;
}

void    ClapTrap::viewStatus()
{
    std::cout 
        << "STATS:" << std::endl
        << "Name: " << this->_name << std::endl
        << "Hit points: " << this->_hitPoints << std::endl
        << "Energy points: " << this->_energyPoints
        << std::endl << std::endl;
}

bool ClapTrap::checkStatus(int status)
{
    if (this->_hitPoints <= 0)
    {
        std::cout 
            << this->_name << " is dead."
            << std::endl;
        return (false);
    }
    if (this->_energyPoints <= 0 && status != 1)
    {
        std::cout
            << this->_name << " is out of energy."
            << std::endl;
        return (false);
    }
    return (true);
}
