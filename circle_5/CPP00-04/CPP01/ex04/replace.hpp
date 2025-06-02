/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 07:56:50 by dpascal           #+#    #+#             */
/*   Updated: 2025/05/26 11:06:11 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
# define REPLACE_HPP

#include <iostream>
#include <fstream>
#include <string>

std::string openAndReadFile(const std::string &filename);
std::string    replaceString(const std::string &content, const std::string &s1, const std::string &s2);
bool writeInNewFile(const std::string &filename, std::string &content);

#endif