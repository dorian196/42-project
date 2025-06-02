/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 07:58:26 by dpascal           #+#    #+#             */
/*   Updated: 2025/05/28 12:26:10 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::bits = 8;

Fixed::Fixed()
{
    value = 0;
    // std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src)
{
    // std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed::~Fixed()
{
    // std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
    this->value = value << bits;
    // std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value)
{
    this->value = roundf(value * (1 << bits));
    // std::cout << "Float constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &rhs)
{
    // std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        this->value = rhs.value;
    }
    return *this;
}

// Compare

bool Fixed::operator>(const Fixed& other) const {
    return value > other.value;
}

bool Fixed::operator<(const Fixed& other) const {
    return value < other.value;
}

bool Fixed::operator>=(const Fixed& other) const {
    return value >= other.value;
}

bool Fixed::operator<=(const Fixed& other) const {
    return value <= other.value;
}

bool Fixed::operator==(const Fixed& other) const {
    return value == other.value;
}

bool Fixed::operator!=(const Fixed& other) const {
    return value != other.value;
}

// + / - / * / '/'

Fixed Fixed::operator+(const Fixed& other) const {
    Fixed result;
    result.value = value + other.value;
    return result;
}

Fixed Fixed::operator-(const Fixed& other) const {
    Fixed result;
    result.value = value - other.value;
    return result;
}

Fixed Fixed::operator*(const Fixed& other) const
{
    Fixed result;
    int64_t temp = static_cast<int64_t>(value) * static_cast<int64_t>(other.value);
    result.value = static_cast<int>(temp >> bits);
    return result;
}

Fixed Fixed::operator/(const Fixed& other) const
{
    Fixed result;
    int64_t temp = (static_cast<int64_t>(value) << bits) / other.value;
    result.value = static_cast<int>(temp);
    return result;
}

// Increment

Fixed& Fixed::operator++() {
    value += 1;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    ++(*this);
    return temp;
}

Fixed& Fixed::operator--() {
    value -= 1;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    --(*this);
    return temp;
}

// Min / Max

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
    if (a < b)
        return (a);
    else
        return (b);
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a < b)
        return (a);
    else
        return (b);
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
    if (a > b)
        return (a);
    else
        return (b);
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a > b)
        return (a);
    else
        return (b);
}

// Setter / Getter

int Fixed::getRawBits( void ) const
{
    // std::cout << "getRawBits member function called" << std::endl;
    return this->value;
}

void Fixed::setRawBits(int const raw)
{
    this->value = raw;
}

// Convert

float Fixed::toFloat(void) const
{
    return ((float)this->value) / (1 << bits);
}

int Fixed::toInt(void) const
{
    return this->value >> bits;
}

// Surcharge 

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}
