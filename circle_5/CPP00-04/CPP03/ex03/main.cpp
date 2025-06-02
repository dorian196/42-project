/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 08:02:05 by dpascal           #+#    #+#             */
/*   Updated: 2025/05/30 11:02:07 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main( void )
{
    DiamondTrap test;
    ClapTrap    joe("Joe");
    ScavTrap    william("William");
    FragTrap    jack("Jack");
    DiamondTrap averell("Averell");

    std::cout << std::endl;

    test.viewStatus();
    joe.viewStatus();
    william.viewStatus();
    jack.viewStatus();
    averell.viewStatus();

    for (int i = 0; i < 12; i++)
        joe.attack("Shrek");
    joe.viewStatus();
    joe.takeDamage(11);
    joe.beRepaired(4);
    joe.viewStatus();
    joe.attack("Reine des neiges");
    joe.takeDamage(11);
    joe.beRepaired(4);

    william.attack("Karaba");
    william.takeDamage(58);
    william.guardGate();
    william.beRepaired(99);
    william.beRepaired(784);
    william.takeDamage(123);
    william.beRepaired(1);
    william.attack("Hulk");
    william.takeDamage(1);
    william.guardGate();

    jack.attack("Zeus");
    jack.takeDamage(70);
    jack.highFivesGuys();
    jack.beRepaired(15);
    jack.attack("Monk");
    jack.takeDamage(50);
    jack.highFivesGuys();
    jack.viewStatus();

    averell.viewStatus();
    averell.attack("Lipoutou");
    averell.highFivesGuys();
    averell.guardGate();
    averell.takeDamage(42);
    averell.beRepaired(21);
    averell.attack("Lucky Luck");
    averell.whoAmI();
    averell.viewStatus();

    DiamondTrap  copyAverell1(averell);
    copyAverell1.attack("Athena");
    DiamondTrap  copyAverell2;
    copyAverell2 = averell;
    copyAverell2.whoAmI();
    copyAverell2.attack("Luffy");
    copyAverell2.highFivesGuys();
    copyAverell2.guardGate();

    return (0);
}
