/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomZombie.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 12:14:22 by dpascal           #+#    #+#             */
/*   Updated: 2025/05/26 12:18:40 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void randomChump( std::string name )
{
    Zombie zombie(name);
    zombie.announce();
}
