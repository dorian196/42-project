/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 22:53:34 by dpascal           #+#    #+#             */
/*   Updated: 2025/04/23 08:55:44 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	print_msg(int msg, t_philo *philo, int id)
{
	pthread_mutex_lock(&philo->data->print_mutex);
	if (check_stop(philo) == 1 && msg != 5)
	{
		if (msg == 6)
			printf(ALLFINISH, ft_timer() - philo->data->start_time);
		pthread_mutex_unlock(&philo->data->print_mutex);
		return ;
	}
	if (msg == 1)
		printf(FORK, ft_timer() - philo->data->start_time, philo->id);
	else if (msg == 2)
		printf(EAT, ft_timer() - philo->data->start_time, philo->id);
	else if (msg == 3)
		printf(SLEEP, ft_timer() - philo->data->start_time, philo->id);
	else if (msg == 4)
		printf(THINK, ft_timer() - philo->data->start_time, philo->id);
	else if (msg == 5)
		printf(DEAD, ft_timer() - philo->data->start_time, id);
	pthread_mutex_unlock(&philo->data->print_mutex);
}
