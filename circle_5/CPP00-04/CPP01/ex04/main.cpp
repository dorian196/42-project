/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 07:56:44 by dpascal           #+#    #+#             */
/*   Updated: 2025/05/26 11:04:43 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "Error: bad numbers of arguments!" << std::endl;
        return (1);
    }
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    if (s1.empty())
    {
        std::cout << "Error: s1 is empty!" << std::endl;
        return (1);
    }
    std::string content = openAndReadFile(filename);
    if (content.empty())
    {
        std::cout << "Error: cannot open: " << filename << std::endl;
        return (1);
    }
    std::string replaced = replaceString(content, s1, s2);
    if (!writeInNewFile(filename, replaced))
    {
        std::cout << "Error: cannot create: " << filename << ".replace" << std::endl;
        return (1);
    }
    return (0);
}
