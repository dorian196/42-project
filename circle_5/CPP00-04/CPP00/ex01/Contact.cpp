/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 07:54:11 by dpascal           #+#    #+#             */
/*   Updated: 2025/05/26 07:54:12 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void    Contact::setFirstName(const std::string &name)
{
    firstName = name;
}

void    Contact::setLastName(const std::string &name)
{
    lastName = name;
}

void    Contact::setNickName(const std::string &name)
{
    nickName = name;
}

void    Contact::setPhoneNumber(const std::string &number)
{
    phoneNumber = number;
}

void    Contact::setDarkestSecret(const std::string &secret)
{
    darkestSecret = secret;
}

std::string Contact::getFirstName() const
{
    return firstName;
}

std::string Contact::getLastName() const
{
    return lastName;
}

std::string Contact::getNickName() const
{
    return nickName;
}

std::string Contact::getPhoneNumber() const
{
    return phoneNumber;
}

std::string Contact::getDarkestSecret() const
{
    return darkestSecret;
}