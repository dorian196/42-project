/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thobenel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 01:47:08 by thobenel          #+#    #+#             */
/*   Updated: 2025/05/09 01:47:09 by thobenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

/**
 * Gere l'evenement de relachement d'une touche
 * @param keycode Code de la touche relachee
 * @param param Pointeur vers la structure du jeu
 * @return 0
 */
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

/**
 * Gère l'événement d'appui sur une touche
 * @param keycode Code de la touche appuyée
 * @param param Pointeur vers la structure du jeu
 * @return 0 en cas de succès, 1 pour quitter
 */
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
	else if (keycode == PRESS_E)
		ft_open_door(&game->player, game);
	return (0);
}
