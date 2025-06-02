/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 08:03:58 by dpascal           #+#    #+#             */
/*   Updated: 2025/06/02 08:10:09 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    Brain* brain1 = new Brain();
    delete brain1;
    std::cout << "--- Test des constructeurs & destructeurs dynamiques ---" << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;
    delete i;
    std::cout << std::endl;

    std::cout << "--- Test d'un tableau polymorphe de 10 animaux ---" << std::endl;
    const int nbAnimals = 10;
    const Animal* animals[nbAnimals];
    for (int i = 0; i < nbAnimals / 2; ++i)
        animals[i] = new Dog();
    for (int i = nbAnimals / 2; i < nbAnimals; ++i)
        animals[i] = new Cat();

    std::cout << "--- Tous les animaux font un bruit ---" << std::endl;
    for (int i = 0; i < nbAnimals; ++i)
        animals[i]->makeSound();

    std::cout << "--- Suppression polymorphe du tableau ---" << std::endl;
    for (int i = 0; i < nbAnimals; ++i)
        delete animals[i];
    std::cout << std::endl;

    std::cout << "--- Copie profonde (constructeur de copie) sur Dog ---" << std::endl;
    Dog dog1;
   
    Dog dog2(dog1);
    std::cout << "Address: " << dog2.getAddress() << std::endl;
    std::cout << "Address: " << dog1.getAddress() << std::endl;
    std::cout << std::endl;

    std::cout << "--- Copie profonde (opérateur d'affectation) sur Dog ---" << std::endl;
    Dog dog3;
    dog3 = dog1;
    std::cout << "Address: " << dog3.getAddress() << std::endl;
    std::cout << "Address: " << dog1.getAddress() << std::endl;
    std::cout << std::endl;
    std::cout << "--- Fin du main ---" << std::endl;
    return 0;
}
