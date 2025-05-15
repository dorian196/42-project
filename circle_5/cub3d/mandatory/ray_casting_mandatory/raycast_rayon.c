/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_rayon.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thobenel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 05:14:32 by thobenel          #+#    #+#             */
/*   Updated: 2025/05/09 05:14:33 by thobenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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

/*
	1)Direction du rayon
	2)Position sur la grille
	3)Calculer delta_dist
		(distance necessaire pour traverser une cellule)
	4)Determiner les etapes et distances initiales
	5)
*/
void	ft_init_ray_one(t_ray *ray, t_player *player, float ray_angle)
{
	ft_init_ray_two(ray, player, ray_angle);
	if (ray->cos_angle < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (player->x / BLOCK - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - player->x / BLOCK)
			* ray->delta_dist_x;
	}
	if (ray->sin_angle < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (player->y / BLOCK - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - player->y / BLOCK)
			* ray->delta_dist_y;
	}
}

// Fonction 1: Initialise et normalise l'angle du rayon
void	ft_prepare_ray_angle(float *angle_diff, t_ray *ray, t_player *player,
		float ray_angle)
{
	*angle_diff = ray_angle - player->angle;
	while (*angle_diff > PI)
		*angle_diff -= 2 * PI;
	while (*angle_diff < -PI)
		*angle_diff += 2 * PI;
	ft_init_ray_one(ray, player, ray_angle);
}

// Fonction 2: Lance le rayon et vérifie les collisions
int	ft_process_ray_collision(t_ray *ray, t_game *game)
{
	if (!ft_cast_ray_one(ray, game))
		return (0);
	if (ray->map_y >= 0 && ray->map_y < game->map_height
		&& game->map[(int)ray->map_y] != NULL && ray->map_x >= 0
		&& ray->map_x < ft_strlen(game->map[(int)ray->map_y]))
	{
		ray->tile = game->map[(int)ray->map_y][(int)ray->map_x];
	}
	else
		ray->tile = '1';
	return (1);
}
