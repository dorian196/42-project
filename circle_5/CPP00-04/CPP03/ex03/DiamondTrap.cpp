/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 08:01:55 by dpascal           #+#    #+#             */
/*   Updated: 2025/05/30 11:15:02 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
    : ClapTrap("default_clap_name"), ScavTrap("Default"), FragTrap("Default"), _name("default")
{
    this->_hitPoints = FragTrap::baseHitPoints;
    this->_energyPoints = ScavTrap::baseEnergyPoints;
    this->_attackDamage = FragTrap::baseAttackDammage;
    this->_hitPointsCount = FragTrap::baseHitPoints;
    this->_energyPointsCount = ScavTrap::baseEnergyPoints;
    std::cout << "DiamondTrap " << this->_name << " constructed!" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
    : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name)
{
    this->_hitPoints = FragTrap::baseHitPoints;
    this->_energyPoints = ScavTrap::baseEnergyPoints;
    this->_attackDamage = FragTrap::baseAttackDammage;
    this->_hitPointsCount = FragTrap::baseHitPoints;
    this->_energyPointsCount = ScavTrap::baseEnergyPoints;
    std::cout << "DiamondTrap " << this->_name << " constructed!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& src)
    : ClapTrap(src), ScavTrap(src), FragTrap(src), _name(src._name)
{
    std::cout << "DiamondTrap " << _name << " copy constructed!" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& rhs) {
    if (this != &rhs) {
        this->_hitPoints = FragTrap::baseHitPoints;
        this->_energyPoints = ScavTrap::baseEnergyPoints;
        this->_attackDamage = FragTrap::baseAttackDammage;
        this->_hitPointsCount = FragTrap::baseHitPoints;
        this->_energyPointsCount = ScavTrap::baseEnergyPoints;
        _name = rhs._name;
    }
    std::cout << "DiamondTrap " << _name << " assigned!" << std::endl;
    return *this;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap destructor called" << std::endl;
}

void DiamondTrap::whoAmI()
{
    std::cout 
        << "DiamondTrap name: " << this->_name
        << ", ClapTrap name: " << ClapTrap::_name << std::endl;
}

void DiamondTrap::guardGate()
{
    if (!checkStatus(1))
    {
        std::cout
            << "Entered eternal rest mode!"
            << std::endl << std::endl;
        return ;
    }
    std::cout
        << "Diamond " << _name 
        << " entered Gate Keeper mode!"
        << std::endl<< std::endl;
}

void DiamondTrap::highFivesGuys(void)
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
        << "Diamond "
        << this->_name
        << " requests a high five!"
        << std::endl << std::endl;
}
