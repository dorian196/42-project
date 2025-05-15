/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thobenel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 01:47:03 by thobenel          #+#    #+#             */
/*   Updated: 2025/05/09 01:47:05 by thobenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

int	ft_exit_game(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (game)
	{
		if (game->img)
			mlx_destroy_image(game->mlx, game->img);
		if (game->win)
			mlx_destroy_window(game->mlx, game->win);
		free_var(game);
		if (game->mlx)
		{
			mlx_destroy_display(game->mlx);
			free(game->mlx);
		}
	}
	exit(EXIT_SUCCESS);
	return (0);
}
