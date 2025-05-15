/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thobenel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 01:48:22 by thobenel          #+#    #+#             */
/*   Updated: 2025/05/09 01:48:23 by thobenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

void	ft_init_timer(t_timer *timer)
{
	timer->is_running = false;
	timer->best_time = 0;
	timer->elapsed_time = 0.0f;
}

void	ft_start_timer(t_timer *timer)
{
	if (!timer->is_running)
	{
		timer->is_running = true;
		timer->start_time = time(NULL);
	}
}

void	ft_stop_timer(t_timer *timer)
{
	if (timer->is_running)
	{
		timer->is_running = false;
		timer->current_time = time(NULL);
		timer->elapsed_time = difftime(timer->current_time, timer->start_time);
		if (timer->best_time == 0 || timer->elapsed_time > timer->best_time)
			timer->best_time = timer->elapsed_time;
	}
}

void	ft_update_timer(t_timer *timer)
{
	if (timer->is_running)
	{
		timer->current_time = time(NULL);
		timer->elapsed_time = difftime(timer->current_time, timer->start_time);
	}
}

/* Calcule les positions et dimensions du timer */
void	ft_calculate_timer_position(t_game *game, int *ox, int *oy, int *width)
{
	*ox = WIDTH - (game->map_width * MINI_MAP_SCALE) - MINI_MAP_MARG;
	*oy = MINI_MAP_MARG + (game->map_height * MINI_MAP_SCALE) + 10;
	*width = game->map_width * MINI_MAP_SCALE;
}
