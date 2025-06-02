/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 08:05:02 by dpascal           #+#    #+#             */
/*   Updated: 2025/06/02 08:15:42 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    // Animal a;
    // Animal* a = new Animal();

    const Animal* d = new Dog();
    const Animal* c = new Cat();

    std::cout << "Dog fait : ";
    d->makeSound();
    std::cout << "Cat fait : ";
    c->makeSound();

    delete d;
    delete c;
    
    std::cout << "\n--- Tableau polymorphe ---" << std::endl;
    const Animal* animals[4];
    animals[0] = new Dog();
    animals[1] = new Cat();
    animals[2] = new Dog();
    animals[3] = new Cat();

    for (int i = 0; i < 4; i++)
        animals[i]->makeSound();

    for (int i = 0; i < 4; i++)
        delete animals[i];

    Dog d1;
    Dog d2;
    d2 = d1;
    Dog d3(d1);

    return 0;
}
