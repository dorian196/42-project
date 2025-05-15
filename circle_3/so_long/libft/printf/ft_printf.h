/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 02:08:31 by dpascal           #+#    #+#             */
/*   Updated: 2024/11/01 11:21:58 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_p_adress(unsigned long p, int len);
int	ft_putnbr(int n, char *base, int len);
int	ft_uputnbr(unsigned int n, char *base, int len);
int	ft_putnbr_adr(unsigned long n, char *base, int len);
int	ft_written(const char *format, va_list args, int len, int i);
int	ft_printf(const char *format, ...);
int	ft_strlen(char *s);

#endif
