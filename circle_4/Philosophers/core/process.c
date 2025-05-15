/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 22:53:39 by dpascal           #+#    #+#             */
/*   Updated: 2025/04/23 09:02:20 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	one_philo(t_philo *philo)
{
	if (philo->data->nbr_philo == 1)
	{
		printf(FORK, ft_timer() - philo->data->start_time, philo->id);
		ft_sleep(philo->data->time_die);
		pthread_mutex_lock(&philo->data->stop_mutex);
		if (!philo->data->stop)
		{
			philo->data->stop = 1;
			printf(DEAD, ft_timer() - philo->data->start_time, philo->id);
		}
		pthread_mutex_unlock(&philo->data->stop_mutex);
		return (1);
	}
	return (0);
}

int	philo_fork_n_eat(t_philo *philo)
{
	if (check_stop(philo) == 1)
		return (1);
	take_fork(philo);
	if (check_stop(philo) == 1)
	{
		end_fork(philo);
		return (1);
	}
	eating(philo);
	if (check_stop(philo) == 1)
	{
		end_fork(philo);
		return (1);
	}
	return (0);
}

void	*philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (one_philo(philo) == 1)
		return (NULL);
	while (1)
	{
		if (philo_fork_n_eat(philo) == 1)
			break ;
		end_fork(philo);
		if (end_eating(philo) == 1 || check_stop(philo) == 1)
			break ;
		print_msg(3, philo, philo->id);
		if (check_stop(philo) == 1)
			break ;
		ft_sleep(philo->data->time_sleep);
		if (check_stop(philo) == 1)
			break ;
		print_msg(4, philo, philo->id);
		if (check_stop(philo) == 1)
			break ;
	}
	return (NULL);
}

int	init_process(t_data *data_philo)
{
	int	i;

	i = 0;
	while (i < data_philo->nbr_philo)
	{
		data_philo->philos[i].id = i;
		data_philo->philos[i].last_meal_time = ft_timer();
		data_philo->philos[i].count_eat = 0;
		data_philo->philos[i].left_fork = &data_philo->forks[i];
		data_philo->philos[i].right_fork = &data_philo->forks[(i + 1)
			% data_philo->nbr_philo];
		data_philo->philos[i].data = data_philo;
		i++;
	}
	return (0);
}

int	ft_process(t_data *data_philo)
{
	int	i;

	if (init_process(data_philo) != 0)
		return (1);
	i = 0;
	while (i < data_philo->nbr_philo)
	{
		if (pthread_create(&data_philo->threads[i], NULL, philo,
				&data_philo->philos[i]) != 0)
		{
			printf("Error: thread\n");
			return (1);
		}
		i++;
	}
	usleep(100);
	check_monitor(data_philo);
	i = 0;
	while (i < data_philo->nbr_philo)
	{
		pthread_join(data_philo->threads[i], NULL);
		i++;
	}
	return (0);
}
