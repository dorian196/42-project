/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thobenel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 01:46:58 by thobenel          #+#    #+#             */
/*   Updated: 2025/05/09 01:47:00 by thobenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

void	ft_clear_ceiling(t_game *game)
{
	int	x;
	int	y;
	int	color_ceiling;

	if (game->parsing.value_c[0] >= 0 && game->parsing.value_c[1] >= 0
		&& game->parsing.value_c[2] >= 0)
		color_ceiling = (game->parsing.value_c[0] << 16)
			| (game->parsing.value_c[1] << 8)
			| game->parsing.value_c[2];
	y = -1;
	while (++y < HEIGHT / 2)
	{
		x = -1;
		while (++x < WIDTH)
			ft_put_pixel(x, y, color_ceiling, game);
	}
}

void	ft_clear_floor(t_game *game)
{
	int	x;
	int	y;
	int	color_floor;

	if (game->parsing.value_f[0] >= 0 && game->parsing.value_f[1] >= 0
		&& game->parsing.value_f[2] >= 0)
		color_floor = (game->parsing.value_f[0] << 16)
			| (game->parsing.value_f[1] << 8)
			| game->parsing.value_f[2];
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			ft_put_pixel(x, y, color_floor, game);
	}
}

/**
 * Fonction principale pour mettre à jour la position du joueur
 * @param game Structure du jeu
 * @return 0
 */
int	ft_move_player(t_game *game)
{
	t_player	*joueur;
	float		dx;
	float		dy;

	dy = 0.0f;
	dx = 0.0f;
	joueur = &game->player;
	ft_calculate_mouvement(joueur, &dx, &dy);
	if (!ft_touch_col(joueur->x + dx, joueur->y, game))
		joueur->x += dx;
	if (!ft_touch_col(joueur->x, joueur->y + dy, game))
		joueur->y += dy;
	ft_update_angle(joueur);
	ft_polish_angle(joueur);
	return (0);
}
