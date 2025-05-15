/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uputnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 02:58:37 by dpascal           #+#    #+#             */
/*   Updated: 2024/05/10 00:05:43 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_uputnbr(unsigned int n, char *base, int len)
{
	unsigned int	baselen;

	baselen = ft_strlen(base);
	if (n >= baselen)
		len = ft_uputnbr(n / baselen, base, len);
	len += ft_putchar(base[n % baselen]);
	return (len);
}
/*
int	main(void)
{
	unsigned long long	n;

	n = 1234;
	ft_uputnbr(n, "0123456789abcdef", 0);
	return (0);
}*/
