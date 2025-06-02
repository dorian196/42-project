/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 08:04:58 by dpascal           #+#    #+#             */
/*   Updated: 2025/05/26 08:04:59 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Dog default constructor called" << std::endl;
    brain = new Brain();
    this->type = "Dog";
}

Dog::Dog(const Dog& src) : Animal(src)
{
    std::cout << "Dog copy constructor called" << std::endl;
    brain = new Brain(*src.brain);
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
    delete this->brain;
}

Dog &Dog::operator=(const Dog &rhs)
{
    std::cout << "Dog copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        Animal::operator=(rhs);
        delete brain;
        brain = new Brain(*rhs.brain);
    }
    return (*this);
}

void Dog::makeSound() const
{
    std::cout << "WOOAF" << std::endl;
}
