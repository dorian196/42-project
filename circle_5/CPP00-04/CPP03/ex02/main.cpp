/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 08:01:22 by dpascal           #+#    #+#             */
/*   Updated: 2025/05/26 08:01:23 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main( void )
{
    ClapTrap    nimbus("Nimbus 2000");
    ScavTrap    guldan("Gul'dan");
    FragTrap    goelan("Goelan");

    std::cout << std::endl;

    nimbus.viewStatus();
    guldan.viewStatus();
    goelan.viewStatus();

    for (int i = 0; i < 12; i++)
        nimbus.attack("Voldemort");
    nimbus.viewStatus();
    nimbus.takeDamage(11);
    nimbus.beRepaired(4);
    nimbus.viewStatus();
    nimbus.attack("Kirikou");
    nimbus.takeDamage(11);
    nimbus.beRepaired(4);

    guldan.attack("Trump");
    guldan.takeDamage(58);
    guldan.guardGate();
    guldan.beRepaired(99);
    guldan.beRepaired(784);
    guldan.takeDamage(123);
    guldan.beRepaired(1);
    guldan.attack("Dracofeu");
    guldan.takeDamage(1);
    guldan.guardGate();

    goelan.attack("Pikachu");
    goelan.takeDamage(70);
    goelan.highFivesGuys();
    goelan.beRepaired(15);
    goelan.attack("Zidane");
    goelan.takeDamage(50);
    goelan.highFivesGuys();
    goelan.viewStatus();

    return (0);
}
