/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 22:53:30 by dpascal           #+#    #+#             */
/*   Updated: 2025/04/21 14:08:45 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	init_var(t_data *data_philo, t_philo *philo)
{
	memset(philo, 0, sizeof(t_philo));
	memset(data_philo, 0, sizeof(t_data));
	data_philo->nbr_meals = -1;
}

int	init_data(char **av, t_data *data_philo)
{
	int	i;

	data_philo->nbr_philo = ft_atol(av[1]);
	data_philo->time_die = ft_atol(av[2]);
	data_philo->time_eat = ft_atol(av[3]);
	data_philo->time_sleep = ft_atol(av[4]);
	if (av[5])
		data_philo->nbr_meals = ft_atol(av[5]);
	i = 0;
	data_philo->threads = malloc(sizeof(pthread_t) * data_philo->nbr_philo);
	data_philo->philos = malloc(sizeof(t_philo) * data_philo->nbr_philo);
	data_philo->forks = malloc(sizeof(pthread_mutex_t) * data_philo->nbr_philo);
	if (!data_philo->threads || !data_philo->philos || !data_philo->forks)
		return (1);
	while (i < data_philo->nbr_philo)
	{
		pthread_mutex_init(&data_philo->forks[i], NULL);
		i++;
	}
	data_philo->start_time = ft_timer();
	pthread_mutex_init(&data_philo->print_mutex, NULL);
	pthread_mutex_init(&data_philo->check_mutex, NULL);
	pthread_mutex_init(&data_philo->stop_mutex, NULL);
	return (0);
}
