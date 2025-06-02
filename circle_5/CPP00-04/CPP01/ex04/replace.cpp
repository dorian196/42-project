/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:04:21 by dpascal           #+#    #+#             */
/*   Updated: 2025/05/26 11:15:15 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

std::string openAndReadFile(const std::string &filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        return "";
    std::string buffer;
    std::string line;
    while (std::getline(file, line))
    {
        buffer += line;
        if (!file.eof())
            buffer += '\n';
    }
    return (buffer);
}

std::string    replaceString(const std::string &content, const std::string &s1, const std::string &s2)
{
    std::string replaced;
    size_t pos = 0;
    size_t next_pos;

    while ((next_pos = content.find(s1, pos)) != std::string::npos)
    {
        replaced += content.substr(pos, next_pos - pos);
        replaced += s2;
        pos = next_pos + s1.length();
    }
    replaced += content.substr(pos);
    return (replaced);
}

bool writeInNewFile(const std::string &filename, std::string &content)
{
    std::string file = filename + ".replace";
    std::ofstream newFile(file.c_str());
    if (!newFile.is_open())
        return (false);
    newFile << content;
    return (true);
}