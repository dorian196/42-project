/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 22:53:17 by dpascal           #+#    #+#             */
/*   Updated: 2025/04/17 16:56:56 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	eating(t_philo *philo)
{
	print_msg(2, philo, philo->id);
	pthread_mutex_lock(&philo->data->check_mutex);
	philo->last_meal_time = ft_timer();
	philo->count_eat++;
	pthread_mutex_unlock(&philo->data->check_mutex);
	ft_sleep(philo->data->time_eat);
}

int	end_eating(t_philo *philo)
{
	if (philo->data->nbr_meals != -1
		&& philo->count_eat >= philo->data->nbr_meals)
		return (1);
	return (0);
}
