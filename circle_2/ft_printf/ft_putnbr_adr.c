/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_adr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 23:31:52 by dpascal           #+#    #+#             */
/*   Updated: 2024/05/10 00:00:20 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_adr(unsigned long n, char *base, int len)
{
	unsigned long	baselen;

	if (n < 0)
	{
		ft_putchar('-');
		n = n * -1;
		len++;
	}
	baselen = ft_strlen(base);
	if (n >= baselen)
		len = ft_putnbr_adr(n / baselen, base, len);
	len += ft_putchar(base[n % baselen]);
	return (len);
}
