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

#include "../../include/cub.h"

/**
 * Vérifie s'il y a une collision à la position (x,y)
 * @param x Position X à vérifier
 * @param y Position Y à vérifier
 * @param game Structure du jeu
 * @return true si collision, false sinon
 */
/* vérifie la collision en un point donné */
static bool	ft_check_collision_point(float px, float py, t_game *game)
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

bool	ft_collision(float x, float y, t_game *game)
{
	float	points[4][2];
	float	buffer;
	int		i;

	buffer = 8.0f;
	points[0][0] = x - buffer;
	points[0][1] = y - buffer;
	points[1][0] = x + buffer;
	points[1][1] = y - buffer;
	points[2][0] = x - buffer;
	points[2][1] = y + buffer;
	points[3][0] = x + buffer;
	points[3][1] = y + buffer;
	i = 0;
	while (i < 4)
	{
		if (ft_check_collision_point(points[i][0],
			points[i][1], game))
			return (true);
		i++;
	}
	return (false);
}

/**
 * Fonction auxiliaire qui vérifie les collisions
 * (utilise ft_collision avec le buffer)
 */
bool	ft_touch_col(float px, float py, t_game *game)
{
	return (ft_collision(px, py, game));
}

/**
 * Fonction manquante pour le raycasting
 * Détecte si un rayon touche un mur
 * @param x Position X du rayon
 * @param y Position Y du rayon
 * @param game Structure du jeu
 * @return true si le rayon touche un mur, false sinon
 */
bool	ft_touch(float x, float y, t_game *game)
{
	return (ft_collision(x, y, game));
}

void	ft_init_ray_two(t_ray *ray, t_player *player, float ray_angle)
{
	ray->hit = 0;
	ray->cos_angle = cos(ray_angle);
	ray->sin_angle = sin(ray_angle);
	ray->map_x = floor(player->x / BLOCK);
	ray->map_y = floor(player->y / BLOCK);
	if (ray->cos_angle == 0)
		ray->delta_dist_x = 1e30;
	else
		ray->delta_dist_x = fabs(1.0f / ray->cos_angle);
	if (ray->sin_angle == 0)
		ray->delta_dist_y = 1e30;
	else
		ray->delta_dist_y = fabs(1.0f / ray->sin_angle);
}
