/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 08:01:35 by dpascal           #+#    #+#             */
/*   Updated: 2025/05/30 09:30:23 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    public:
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