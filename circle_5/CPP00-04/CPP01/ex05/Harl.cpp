/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 07:57:01 by dpascal           #+#    #+#             */
/*   Updated: 2025/05/26 07:57:02 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug( void )
{
    std::cout
        << "[ DEBUG ]" << std::endl
        << "I love having extra "
        << "bacon for my 7XL-double-cheese-triple-pickle-special-"
        << "ketchup burger."
        << std::endl
        << "I really do!"
        << std::endl;
}

void Harl::info( void )
{
    std::cout
        << "[ INFO ]" << std::endl
        << "I cannot believe adding extra bacon costs more money."
        << std::endl
        << "You didn’t put enough bacon in my burger!"
        << std::endl
        << "If you did, I wouldn’t be asking for more!"
        << std::endl;
}

void Harl::warning( void )
{
    std::cout
        << "[ WARNING ]" << std::endl
        << "I think I deserve to have some extra bacon for free."
        << std::endl
        << "I’ve been coming for years, whereas you started working "
        << "here just last month."
        << std::endl;
}

void Harl::error( void )
{
    std::cout
        << "[ ERROR ]" << std::endl
        << "This is unacceptable! I want to speak to the manager now."
        << std::endl;
}

void Harl::complain( std::string level )
{
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    typedef void    (Harl::*Function)();

    Function funcs[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    for (int i = 0; i < 4; i++)
    {
        if (level == levels[i])
            return (this->*funcs[i])();
    }
    std::cout << "Error: invalid level: " << level << std::endl;
}
