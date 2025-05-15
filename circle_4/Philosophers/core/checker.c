/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 22:53:13 by dpascal           #+#    #+#             */
/*   Updated: 2025/04/23 01:18:35 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	mutex_death(t_data *data_philo, int i)
{
	if (ft_timer()
		- data_philo->philos[i].last_meal_time > data_philo->time_die)
	{
		print_msg(5, data_philo->philos, data_philo->philos[i].id);
		set_stop(data_philo);
		return (1);
	}
	return (0);
}

int	check_philo(t_data *data_philo, int i, int *end)
{
	pthread_mutex_lock(&data_philo->check_mutex);
	if (mutex_death(data_philo, i) == 1)
	{
		pthread_mutex_unlock(&data_philo->check_mutex);
		return (1);
	}
	if (data_philo->philos[i].count_eat >= data_philo->nbr_meals
		&& data_philo->nbr_meals != -1)
		(*end)++;
	pthread_mutex_unlock(&data_philo->check_mutex);
	return (0);
}

void	check_monitor(t_data *data_philo)
{
	int	i;
	int	end;

	while (1)
	{
		if (check_stop(data_philo->philos) == 1)
			return ;
		i = 0;
		end = 0;
		while (i < data_philo->nbr_philo)
		{
			if (check_philo(data_philo, i, &end) == 1)
				return ;
			i++;
		}
		if (check_end(data_philo, end) == 1)
			return ;
		usleep(500);
	}
}

int	check_end(t_data *data_philo, int end)
{
	if (end == data_philo->nbr_philo)
	{
		set_stop(data_philo);
		print_msg(6, data_philo->philos, data_philo->philos->id);
		return (1);
	}
	return (0);
}
