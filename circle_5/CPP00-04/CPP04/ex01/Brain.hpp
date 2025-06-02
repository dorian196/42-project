/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 08:04:15 by dpascal           #+#    #+#             */
/*   Updated: 2025/05/30 12:22:04 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_hPP

#include <iostream>
#include <string>

class Brain
{
    public:
        std::string ideas[100];
        Brain();
        Brain(const Brain& src);
        Brain& operator=(const Brain& rhs);
        ~Brain();
};

#endif