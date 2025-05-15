/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 00:04:55 by dpascal           #+#    #+#             */
/*   Updated: 2024/05/10 00:03:06 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_written(const char *format, va_list args, int len, int i)
{
	if (format[i] == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (format[i] == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (format[i] == 'p')
		len = ft_p_adress(va_arg(args, unsigned long), len);
	else if (format[i] == 'd' || format[i] == 'i')
		len = ft_putnbr(va_arg(args, int), "0123456789", len);
	else if (format[i] == 'u')
		len = ft_uputnbr(va_arg(args, unsigned int), "0123456789", len);
	else if (format[i] == 'x')
		len = ft_uputnbr(va_arg(args, unsigned int), "0123456789abcdef", len);
	else if (format[i] == 'X')
		len = ft_uputnbr(va_arg(args, unsigned int), "0123456789ABCDEF", len);
	else if (format[i] == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			len = ft_written(format, args, len, i);
		}
		else
		{
			ft_putchar(format[i]);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}
/*
#include <stdio.h>
int	main(void)
{
	int i = ft_printf(" %x\n ", 2147483647);
	ft_printf("%d\n", i);
	int j = printf(" %x\n ", 2147483647);
	printf("%d", j);
	return (0);
}*/
