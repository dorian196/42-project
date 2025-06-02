/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 07:57:53 by dpascal           #+#    #+#             */
/*   Updated: 2025/05/26 07:57:54 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

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
        int getRawBits( void ) const;
        void setRawBits(int const raw);
};

#endif