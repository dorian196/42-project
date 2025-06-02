/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 07:55:27 by dpascal           #+#    #+#             */
/*   Updated: 2025/05/26 07:55:28 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main( void )
{
    int N = 4;
    Zombie *horde = zombieHorde(N, "Zomb");

    for (int i = 0; i < N; i++)
        horde[i].announce();
    delete[] horde;
    return (0);
}
