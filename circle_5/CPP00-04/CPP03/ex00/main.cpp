/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 07:59:00 by dpascal           #+#    #+#             */
/*   Updated: 2025/05/30 08:53:28 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main( void )
{
    ClapTrap    a("Bob");
    ClapTrap    b("Spartakuss");

    std::cout << std::endl;
    a.viewStatus();
    for (int i = 0; i < 12; i++)
        a.attack("Idefix");
    a.viewStatus();
    a.takeDamage(5);
    a.beRepaired(4);
    a.viewStatus();
    a.attack("Marley");
    a.takeDamage(21);
    a.beRepaired(4);
    b.attack("Booba");
    b.takeDamage(1);
    b.beRepaired(99);
    return (0);
}
