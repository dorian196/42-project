/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 22:53:43 by dpascal           #+#    #+#             */
/*   Updated: 2025/04/16 22:55:51 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	ft_sleep(long timer_sleep)
{
	long	start;

	start = ft_timer();
	while (ft_timer() - start < timer_sleep)
		usleep(100);
}
