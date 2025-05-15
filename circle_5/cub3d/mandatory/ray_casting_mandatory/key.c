/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 02:49:53 by dpascal           #+#    #+#             */
/*   Updated: 2025/05/06 02:50:51 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_key_press(int keycode, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keycode == ESCP)
		return (ft_exit_game(game));
	if (keycode == W)
		game->player.key_up = true;
	else if (keycode == S)
		game->player.key_down = true;
	else if (keycode == A)
		game->player.key_left = true;
	else if (keycode == D)
		game->player.key_right = true;
	else if (keycode == LEFT)
		game->player.left_fov = true;
	else if (keycode == RIGHT)
		game->player.right_fov = true;
	return (0);
}

int	ft_key_release(int keycode, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keycode == W)
		game->player.key_up = false;
	else if (keycode == S)
		game->player.key_down = false;
	else if (keycode == A)
		game->player.key_left = false;
	else if (keycode == D)
		game->player.key_right = false;
	else if (keycode == LEFT)
		game->player.left_fov = false;
	else if (keycode == RIGHT)
		game->player.right_fov = false;
	return (0);
}
