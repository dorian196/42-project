/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_casting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thobenel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 05:14:36 by thobenel          #+#    #+#             */
/*   Updated: 2025/05/09 05:14:36 by thobenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/**
 * Vérifie s'il y a une collision à la position (x,y)
 * @param x Position X à vérifier
 * @param y Position Y à vérifier
 * @param game Structure du jeu
 * @return true si collision, false sinon
 */
/* vérifie la collision en un point donné */
bool	ft_check_collision_point(float px, float py, t_game *game)
{
	int		grid_x;
	int		grid_y;
	char	c;

	grid_x = (int)(px / BLOCK);
	grid_y = (int)(py / BLOCK);
	if (grid_x < 0 || grid_x >= game->map_width
		|| grid_y < 0 || grid_y >= game->map_height)
		return (true);
	if (!game->map[grid_y]
		|| grid_x >= (int)ft_strlen(game->map[grid_y]))
		return (true);
	c = game->map[grid_y][grid_x];
	if (c == '1' || c == 'D')
		return (true);
	return (false);
}
