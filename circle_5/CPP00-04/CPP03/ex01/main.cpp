/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 08:01:01 by dpascal           #+#    #+#             */
/*   Updated: 2025/05/26 08:01:02 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main( void )
{
    ClapTrap    fizz("Fizz");
    ScavTrap    eren("Eren");

    std::cout << std::endl;
    fizz.viewStatus();
    for (int i = 0; i < 12; i++)
        fizz.attack("Titan colossal");
    fizz.viewStatus();
    fizz.takeDamage(11);
    fizz.beRepaired(4);
    fizz.viewStatus();
    fizz.attack("Ketchup");
    fizz.takeDamage(11);
    fizz.beRepaired(4);
    eren.attack("Oui oui");
    eren.takeDamage(58);
    eren.guardGate();
    eren.beRepaired(99);
    eren.beRepaired(784);
    eren.takeDamage(123);
    eren.beRepaired(1);
    eren.attack("cacahuete");
    eren.takeDamage(1);
    eren.guardGate();
    return (0);
}
