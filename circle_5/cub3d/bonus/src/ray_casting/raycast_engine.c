/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_engine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thobenel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 05:14:29 by thobenel          #+#    #+#             */
/*   Updated: 2025/05/09 05:14:30 by thobenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

/**
 * Normalise l'angle du joueur dans l'intervalle [0, 2π]
 * @param joueur Structure du joueur
 */
void	ft_polish_angle(t_player *joueur)
{
	if (joueur->angle < 0)
		joueur->angle += 2 * PI;
	if (joueur->angle >= 2 * PI)
		joueur->angle -= 2 * PI;
}

int	ft_cast_ray_two(t_ray *ray, t_game *game)
{
	if (ray->map_y >= 0 && ray->map_y < game->map_height
		&& game->map[(int)ray->map_y] != NULL && ray->map_x >= 0
		&& ray->map_x < ft_strlen(game->map[(int)ray->map_y]))
	{
		ray->tile = game->map[(int)ray->map_y][(int)ray->map_x];
		if (ray->tile == '1' || ray->tile == 'D')
			ray->hit = 1;
		return (0);
	}
	return (1);
}

// DDA (Digital Differential Analyzer) - algorithme de tracer de ligne
/*
	1) Passer a la prochaine case
	2) Mur vertical (est/ouest)
	3) Mur horizontal (nord/sud)
	4) Verifier si on est hors limites
	5) Verifier que la position est valide dans la carte
	6) Si on sort des limites, arrêter le rayon

*/
int	ft_cast_ray_one(t_ray *ray, t_game *game)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (ray->map_x < 0 || ray->map_y < 0 || ray->map_x >= game->map_width
			|| ray->map_y >= game->map_height)
			return (0);
		if (ft_cast_ray_two(ray, game) != 0)
			return (0);
	}
	return (1);
}

void	ft_render_column_use(t_ray *ray)
{
	double	step_precise;

	step_precise = (double)ray->textures->height / ray->wall_h;
	ray->step = step_precise;
	ray->tex_pos = 0;
	if (ray->start_y < 0)
		ray->tex_pos = -ray->start_y * ray->step;
	ray->y = ray->start_y;
}

void	ft_render_column(t_ray *ray, int column, t_game *game)
{
	int			y;
	t_door_data	door_data;
	t_player	*player;

	player = &game->player;
	y = 0;
	while (y < ray->start_y)
	{
		ft_put_pixel(column, y, ray->ceiling_color, game);
		y++;
	}
	ft_render_column_use(ray);
	while (ray->y < ray->end_y)
	{
		if (ray->tile == 'D' && game->imgs.door_data != NULL)
		{
			ft_prepare_door_texture(ray, player, game, &door_data);
			ft_draw_door_pixel(ray, column, ray->y, &door_data);
		}
		else
			ft_draw_wall(ray, column, ray->y, game);
		ray->tex_pos += ray->step;
		ray->y++;
	}
}
