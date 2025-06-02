/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 07:54:19 by dpascal           #+#    #+#             */
/*   Updated: 2025/05/26 08:56:50 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

bool    onlyAlpha(const std::string& str)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        if (!std::isalpha(str[i]) && str[i] != ' ')
            return (false);
    }
    return (true);
}

std::string whileEmptyAndChar(const std::string& prompt)
{
    std::string input;

    input = "";
    while (input.empty() || !onlyAlpha(input))
    {
        std::cout << prompt;
        std::getline(std::cin, input);
        if (input.empty())
            std::cout << "This field cannot be empty" << std::endl;
        else if (!onlyAlpha(input))
            std::cout << "This field must contain only letters and spaces" << std::endl;
    }
    return (input);
}

bool onlyDigit(const std::string& str)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        if (!std::isdigit(str[i]))
            return (false);
    }
    return (true);
}

std::string whileEmptyAndInt(const std::string& prompt)
{
    std::string input;

    input = "";
    while (input.empty() || !onlyDigit(input))
    {
        std::cout << prompt;
        std::getline(std::cin, input);
        if (input.empty())
            std::cout << "This field cannot be empty" << std::endl;
        else if (!onlyDigit(input))
            std::cout << "This field must contain only digits" << std::endl;
    }
    return (input);
}

std::string whileEmpty(const std::string& prompt)
{
    std::string input;

    input = "";
    while (input.empty())
    {
        std::cout << prompt;
        std::getline(std::cin, input);
        if (input.empty())
            std::cout << "This field cannot be empty" << std::endl;
    }
    return (input);
}

PhoneBook::PhoneBook() : nbrContacts(0), index(0) {}

void    PhoneBook::addContact()
{
    Contact c;
    std::string input;

    input = whileEmptyAndChar("Enter first name : ");
    c.setFirstName(input);
    input = whileEmptyAndChar("Enter last name : ");
    c.setLastName(input);
    input = whileEmptyAndChar("Enter nick name : ");
    c.setNickName(input);
    input = whileEmptyAndInt("Enter phone number : ");
    c.setPhoneNumber(input);
    input = whileEmpty("Enter darkest secret name : ");
    c.setDarkestSecret(input);
    contacts[index] = c;
    index = (index + 1) % 8;
    if (nbrContacts < 8)
        nbrContacts++;
}

std::string intToString(int n)
{
    std::stringstream ss;
    ss << n;
    return (ss.str());
}

void formatCoulumn(const std::string& str)
{
    std::string value = str;
    if (str.length() > 10)
        value = value.substr(0, 9) + ".";
    std::cout << std::setw(10) << std::right << value;
}

void    PhoneBook::displayContact() const
{
    std::cout << "_____________________________________________" << std::endl;
    std::cout << "|";
    formatCoulumn("Index");
    std::cout << "|";
    formatCoulumn("First name");
    std::cout << "|";
    formatCoulumn("Last name");
    std::cout << "|";
    formatCoulumn("Nick name");
    std::cout << "|" << std::endl;
    for (int i = 0; i < nbrContacts; i++)
    {
        std::cout << "|";
        formatCoulumn(intToString(i));
        std::cout << "|";
        formatCoulumn(contacts[i].getFirstName());
        std::cout << "|";
        formatCoulumn(contacts[i].getLastName());
        std::cout << "|";
        formatCoulumn(contacts[i].getNickName());
        std::cout << "|" << std::endl;
    }
    std::cout << "_____________________________________________" << std::endl;
}

int checkInput(std::string input)
{
    int index;
    bool isNumber = true;

    isNumber = true;
    for (size_t i = 0; i < input.length(); i++)
    {
        if (!isdigit(input[i]))
        {
            isNumber = false;
            break ;
        }
    }
    if (!isNumber || input.empty())
        return (-1);
    std::istringstream iss(input);
    iss >> index;
    return (index);
}

void    PhoneBook::searchContact() const
{
    int idx;
    std::string input;

    idx = -1;
    if (nbrContacts == 0)
        std::cout << "No contacts found" << std::endl;
    else
    {
        while (idx < 0 || idx >= nbrContacts)
        {
            input = whileEmptyAndInt("Enter the contact's index : ");
            idx = checkInput(input);
            if (idx < 0 || idx >= nbrContacts)
            {
                std::cout << "Invalid index" << std::endl;
            }
        }
        std::cout << "_____________________________________________" << std::endl;
        std::cout << "Index: " << intToString(idx) << std::endl;
        std::cout << "First name: " << contacts[idx].getFirstName() << std::endl;
        std::cout << "Last name: " << contacts[idx].getLastName() << std::endl;
        std::cout << "Nick name: " << contacts[idx].getNickName() << std::endl;
        std::cout << "Phone number: " << contacts[idx].getPhoneNumber() << std::endl;
        std::cout << "Darkest secret: " << contacts[idx].getDarkestSecret() << std::endl;
        std::cout << "_____________________________________________" << std::endl;
    }
}
