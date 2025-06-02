/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 08:02:19 by dpascal           #+#    #+#             */
/*   Updated: 2025/05/30 10:53:44 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
    private:
        std::string _name;
    public:
        DiamondTrap();
        DiamondTrap(std::string name);
        DiamondTrap(const DiamondTrap &src);
        ~DiamondTrap();
        DiamondTrap &operator=(const DiamondTrap &rhs);

        using ScavTrap::attack;
        using ScavTrap::takeDamage;
        using FragTrap::beRepaired;
        void highFivesGuys(void);
        void guardGate(void);
        void whoAmI();
};

#endif