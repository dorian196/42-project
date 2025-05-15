/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thobenel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 01:48:02 by thobenel          #+#    #+#             */
/*   Updated: 2025/05/09 01:48:04 by thobenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

// Normalize angle to [0, 2π)
int	ft_mouse_move(int x, int y, void *param)
{
	t_game	*game;
	int		dx;

	(void)y;
	game = (t_game *)param;
	if (x == game->last_mouse_x)
		return (0);
	dx = x - game->last_mouse_x;
	game->player.angle += dx * SENSI;
	if (game->player.angle < 0)
		game->player.angle += 2 * PI;
	else if (game->player.angle >= 2 * PI)
		game->player.angle -= 2 * PI;
	mlx_mouse_move(game->mlx, game->win, WIDTH / 2, HEIGHT / 2);
	game->last_mouse_x = WIDTH / 2;
	return (0);
}
