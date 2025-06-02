/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 08:01:14 by dpascal           #+#    #+#             */
/*   Updated: 2025/05/30 09:38:51 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
    : hitPoints(10), energyPoints(10), attackDamage(0), hitPointsCount(hitPoints), energyPointsCount(energyPoints)
{
    std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string name)
    : name(name), hitPoints(10), energyPoints(10), attackDamage(0), hitPointsCount(hitPoints), energyPointsCount(energyPoints)
{
    std::cout
        << "ClapTrap "
        << this->name
        << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src)
    :  hitPointsCount(hitPoints), energyPointsCount(energyPoints)
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
        this->name = rhs.name;
        this->hitPoints    = rhs.hitPoints;
        this->energyPoints = rhs.energyPoints;
        this->attackDamage = rhs.attackDamage;
        this->hitPointsCount = rhs.hitPointsCount;
        this->energyPointsCount = rhs.energyPointsCount;
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
    this->energyPoints -= 1;
    std::cout
        << "ClapTrap " << this->name
        << " attacks " << target
        << ", causing " << this->attackDamage
        << " points of damage!" 
        << std::endl
        << "Energy points -1"
        << std::endl
        << "Remaining energy = " << this->energyPoints << "/"
        << this->energyPointsCount << std::endl << std::endl;
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
    this->hitPoints -= temp;
    std::cout
        << "ClapTrap " << this->name
        << " takes " << temp
        << " points of damage"
        <<  std::endl
        << "Hit points -" << temp
        <<  std::endl;
        if (this->hitPoints < 0)
        {
            this->hitPoints = 0;
            std::cout
                << "Remaining hit points " << this->hitPoints
                << "/" << this->hitPointsCount;
        }
        else
        {
            std::cout
                << "Remaining hit points = " << this->hitPoints
                << "/" << this->hitPointsCount;
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
    if ((this->hitPoints += temp) > this->hitPointsCount)
        this->hitPoints = this->hitPointsCount;
    this->energyPoints -= 1;
    std::cout
        << "ClapTrap " << this->name
        << " repairs itself of " << temp
        << " hit points"
        << std::endl
        << "Remaining hit points = " << this->hitPoints << "/"
        << this->hitPointsCount << std::endl
        << "Energy points -1"
        << std::endl
        << "Remaining energy = " << this->energyPoints << "/"
        << this->energyPointsCount << std::endl << std::endl;
}

void    ClapTrap::viewStatus()
{
    std::cout 
        << "STATS:" << std::endl
        << "Name: " << this->name << std::endl
        << "Hit points: " << this->hitPoints << std::endl
        << "Energy points: " << this->energyPoints
        << std::endl << std::endl;
}

bool ClapTrap::checkStatus(int status)
{
    if (this->hitPoints <= 0)
    {
        std::cout 
            << this->name << " is dead."
            << std::endl;
        return (false);
    }
    if (this->energyPoints <= 0 && status != 1)
    {
        std::cout
            << this->name << " is out of energy."
            << std::endl;
        return (false);
    }
    return (true);
}

