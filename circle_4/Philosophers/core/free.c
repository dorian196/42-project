/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 22:53:25 by dpascal           #+#    #+#             */
/*   Updated: 2025/04/22 01:31:50 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	ft_free(t_data *data_philo)
{
	int	i;

	i = 0;
	while (i < data_philo->nbr_philo)
	{
		pthread_mutex_destroy(&data_philo->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&data_philo->print_mutex);
	pthread_mutex_destroy(&data_philo->check_mutex);
	pthread_mutex_destroy(&data_philo->stop_mutex);
	free(data_philo->forks);
	free(data_philo->philos);
	free(data_philo->threads);
}
