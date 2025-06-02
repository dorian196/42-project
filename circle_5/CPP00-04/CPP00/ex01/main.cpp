/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 07:54:15 by dpascal           #+#    #+#             */
/*   Updated: 2025/05/26 08:28:42 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

int main()
{
    PhoneBook   pb;
    std::string buff;

    std::cout << "Bienvenue dans votre PhoneBook !" << std::endl;
    std::cout << "Commandes : ADD, SEARCH, EXIT" << std::endl;
    while (1)
    {
        std::getline(std::cin, buff);
        if (buff == "ADD")
        {
            pb.addContact();
        }
        else if (buff == "SEARCH")
        {
            pb.displayContact();
            pb.searchContact();
        }
        else if (buff == "EXIT")
            break ;
    }
    return 0;
}
