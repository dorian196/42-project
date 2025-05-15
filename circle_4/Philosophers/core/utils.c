/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 22:53:53 by dpascal           #+#    #+#             */
/*   Updated: 2025/04/21 14:43:52 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

long	ft_atol(char *str)
{
	long	i;
	long	res;

	i = 0;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res);
}

int	check_stop(t_philo *philo)
{
	int	check_die;

	pthread_mutex_lock(&philo->data->stop_mutex);
	check_die = philo->data->stop;
	pthread_mutex_unlock(&philo->data->stop_mutex);
	return (check_die);
}

void	set_stop(t_data *data_philo)
{
	pthread_mutex_lock(&data_philo->stop_mutex);
	data_philo->stop = 1;
	pthread_mutex_unlock(&data_philo->stop_mutex);
}
