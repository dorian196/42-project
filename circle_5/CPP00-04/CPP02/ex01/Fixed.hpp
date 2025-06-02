/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 07:58:14 by dpascal           #+#    #+#             */
/*   Updated: 2025/05/26 11:44:10 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int number;
        static const int fract;
    public:
        Fixed();
        Fixed(const Fixed &src);
        ~Fixed();
        Fixed &operator=(const Fixed &rhs);
        Fixed(const int value);
        Fixed(const float value);
        

        int getRawBits( void ) const;
        void setRawBits(int const raw);
        float toFloat( void ) const;
        int toInt( void ) const;
};
std::ostream& operator<<(std::ostream& out, Fixed const& value);

#endif