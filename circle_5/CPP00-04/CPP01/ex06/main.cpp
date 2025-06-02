/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 07:57:24 by dpascal           #+#    #+#             */
/*   Updated: 2025/05/26 07:57:25 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Error: bad numbers of arguments !" << std::endl;
        return (1);
    }
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int index_level = -1;

    for (int i = 0; i < 4; i++)
    {
        if (argv[1] == levels[i])
            index_level = i;
    }

    Harl    harl;
    switch (index_level)
    {
        case 0:
            harl.complain("DEBUG");
            std::cout << std::endl;
            // fall through
        case 1:
            harl.complain("INFO");
            std::cout << std::endl;
            // fall through
        case 2:
            harl.complain("WARNING");
            std::cout << std::endl;
            // fall through
        case 3:
            harl.complain("ERROR");
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}