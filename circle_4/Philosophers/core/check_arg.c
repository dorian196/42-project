/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 22:53:05 by dpascal           #+#    #+#             */
/*   Updated: 2025/04/16 22:53:09 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	check_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			printf("philo: Invalid argument\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_int(char **av)
{
	int	num;
	int	i;

	num = 0;
	i = 1;
	while (av[i])
	{
		num = ft_atol(av[i]);
		if (num < 0)
		{
			printf("philo: Invalid argument\n");
			return (1);
		}
		if (((i == 1 || i == 2)) && num < 1)
		{
			printf("philo: Invalid argument\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_arg(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (check_is_numeric(av[i]) != 0)
			return (1);
		i++;
	}
	if (check_int(av) != 0)
		return (1);
	return (0);
}
