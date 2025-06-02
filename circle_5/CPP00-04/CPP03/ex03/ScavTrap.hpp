/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 08:02:31 by dpascal           #+#    #+#             */
/*   Updated: 2025/05/30 10:47:06 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
    public:
        static const int    baseEnergyPoints = 50;
        ScavTrap();
        ScavTrap(const std::string name);
        ScavTrap(const ScavTrap &src);
        ~ScavTrap();
        ScavTrap &operator=(const ScavTrap &rhs);

        void attack(const std::string& target);
        using ClapTrap::takeDamage;
        using ClapTrap::beRepaired;
        void guardGate();
};

#endif