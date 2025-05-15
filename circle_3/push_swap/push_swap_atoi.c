/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_atoi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 11:16:32 by dpascal           #+#    #+#             */
/*   Updated: 2024/09/10 11:39:54 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_atoi2(const char *s, int *error, int *sign, int *i)
{
	int	count;

	count = 0;
	while ((s[*i] >= 9 && s[*i] <= 13) || (s[*i] == 32))
		(*i)++;
	while (s[*i] == '+' || s[*i] == '-')
	{
		count++;
		if (count > 1)
		{
			*error = 1;
			return ;
		}
		if (s[*i] == '-')
			*sign *= -1;
		(*i)++;
		if (!(s[*i] >= '0' && s[*i] <= '9'))
		{
			*error = 1;
			return ;
		}
	}
}

long	ft_atoi(const char *s, int *error)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	ft_atoi2(s, error, &sign, &i);
	if (*error)
	{
		*error = 1;
		return (0);
	}
	while (s[i] >= '0' && s[i] <= '9')
		result = result * 10 + (s[i++] - '0');
	if (s[i] == '-' || s[i] == '+')
	{
		*error = 1;
		return (0);
	}
	return (result * sign);
}
