/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 07:58:30 by dpascal           #+#    #+#             */
/*   Updated: 2025/05/28 12:27:07 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{
    Fixed a;
    Fixed const b( 10 );
    Fixed const c( 30 );
    Fixed const d( b );
    a = Fixed( 54 );
    std::cout << "Valeur de base: " << std::endl;
    std::cout << "Valeur de a: " << a << std::endl;
    std::cout << "Valeur de b: " << b << std::endl;
    std::cout << "Valeur de c: " << c << std::endl;
    std::cout << "Valeur de d: " << d << std::endl;
    std::cout << std::endl;
    std::cout << "Valeur en bits: " << std::endl;
    std::cout << "Valeur de a: " << a.getRawBits() << std::endl;
    std::cout << "Valeur de b: " << b.getRawBits() << std::endl;
    std::cout << "Valeur de c: " << c.getRawBits() << std::endl;
    std::cout << "Valeur de d: " << d.getRawBits() << std::endl;
    std::cout << std::endl;
    std::cout << "Opérateurs de comparaison: " << std::endl;
    std::cout << "a > b: " << (a > b) << std::endl;
    std::cout << "a < b: " << (a < b) << std::endl;
    std::cout << "b >= b: " << (b >= b) << std::endl;
    std::cout << "a <= d: " << (a <= d) << std::endl;
    std::cout << "b == b: " << (b == b) << std::endl;
    std::cout << "a != c: " << (a != c) << std::endl;
    std::cout << std::endl;
    std::cout << "Opérateurs arithmétiques : " << std::endl;
    std::cout << "Valeur de a + b: " << a + b << std::endl;
    std::cout << "Valeur de c / b: " << c / b << std::endl;
    std::cout << "Valeur de b - c: " << b - c << std::endl;
    std::cout << "Valeur de b * d: " << b * d << std::endl;
    std::cout << std::endl;
    std::cout << "Fonctions Min / Max : " << std::endl;
    std::cout << "Valeur max entre a et b: " << Fixed::max( a, b ) << std::endl;
    std::cout << "Valeur min entre a et b: " << Fixed::min( a, b ) << std::endl;
    std::cout << std::endl;
    std::cout << "Opérateurs d'incrémentation et de décrémentation : " << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << "Valeur de a: " << a << std::endl;
    std::cout << --a << std::endl;
    std::cout << a-- << std::endl;
    std::cout << "Valeur de a: " << a << std::endl;
    

    return 0;
}
