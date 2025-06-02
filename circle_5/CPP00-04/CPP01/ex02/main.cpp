/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 07:55:51 by dpascal           #+#    #+#             */
/*   Updated: 2025/05/26 10:53:58 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main( void )
{
    std::string str = "Hi THIS IS BRAIN";
    std::string *strPTR = &str;
    std::string &strREF = str;

    std::cout << "Adresse de str        : " << &str << std::endl;
    std::cout << "Adresse par stringPTR : " << strPTR << std::endl;
    std::cout << "Adresse par stringREF : " << &strREF << std::endl;

    std::cout << "Valeur de str         : " << str << std::endl;
    std::cout << "Valeur par stringPTR  : " << *strPTR << std::endl;
    std::cout << "Valeur par stringREF  : " << strREF << std::endl;

    return (0);
}