/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 08:02:27 by dpascal           #+#    #+#             */
/*   Updated: 2025/05/30 10:23:48 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
    public:
        static const int    baseHitPoints = 100;
        static const int    baseAttackDammage = 30;
        FragTrap();
        FragTrap(const std::string name);
        FragTrap(const FragTrap &src);
        ~FragTrap();
        FragTrap &operator=(const FragTrap &rhs);

        void attack(const std::string& target);
        using ClapTrap::takeDamage;
        using ClapTrap::beRepaired;
        void highFivesGuys(void);
};

#endif