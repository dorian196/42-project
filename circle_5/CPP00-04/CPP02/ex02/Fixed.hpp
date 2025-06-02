/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 07:58:34 by dpascal           #+#    #+#             */
/*   Updated: 2025/05/26 07:58:35 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int value;
        static const int bits;
    public:
        Fixed();
        Fixed(const Fixed &src);
        ~Fixed();
        Fixed(const int value);
        Fixed(const float value);

        Fixed &operator=(const Fixed &rhs);

        bool operator>(const Fixed& other) const;
        bool operator<(const Fixed& other) const;
        bool operator>=(const Fixed& other) const;
        bool operator<=(const Fixed& other) const;
        bool operator==(const Fixed& other) const;
        bool operator!=(const Fixed& other) const;

        Fixed operator+(const Fixed& other) const;
        Fixed operator-(const Fixed& other) const;
        Fixed operator*(const Fixed& other) const;
        Fixed operator/(const Fixed& other) const;

        Fixed& operator++();
        Fixed operator++(int);
        Fixed& operator--();
        Fixed operator--(int);

        static Fixed &min(Fixed&, Fixed&);
        static const Fixed &min(const Fixed&, const Fixed&);
        static Fixed &max(Fixed&, Fixed&);
        static const Fixed &max(const Fixed&, const Fixed&);

        int getRawBits( void ) const;
        void setRawBits(int const raw);

        float toFloat( void ) const;
        int toInt( void ) const;
};

std::ostream& operator<<(std::ostream& out, Fixed const& value);

#endif