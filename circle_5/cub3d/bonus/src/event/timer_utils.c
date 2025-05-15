/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thobenel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 01:48:31 by thobenel          #+#    #+#             */
/*   Updated: 2025/05/09 01:48:32 by thobenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

float	ft_calculate_timer_progress(t_game *game)
{
	float	progress;

	progress = 0.0f;
	if (game->monster.is_active)
		progress = fmin(1.0f, game->timer.elapsed_time / 30.0f);
	else if (game->timer.best_time > 0)
		progress = fmin(1.0f, game->timer.best_time / 30.0f);
	return (progress);
}
