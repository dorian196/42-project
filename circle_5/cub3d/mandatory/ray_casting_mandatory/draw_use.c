/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_use.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thobenel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 05:49:27 by thobenel          #+#    #+#             */
/*   Updated: 2025/05/09 05:49:29 by thobenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_select_texture_two(t_ray *ray)
{
	double	tex_x_precise;

	tex_x_precise = ray->wall_x * ray->textures->width;
	ray->tex_x = (int)tex_x_precise;
	if (ray->tex_x < 0)
		ray->tex_x = 0;
	if (ray->tex_x >= ray->textures->width)
		ray->tex_x = ray->textures->width - 1;
	if (ray->side == 0 && ray->cos_angle > 0)
		ray->tex_x = ray->textures->width - ray->tex_x - 1;
	if (ray->side == 1 && ray->sin_angle < 0)
		ray->tex_x = ray->textures->width - ray->tex_x - 1;
}

void	ft_select_texture_one(t_ray *ray, t_player *player, t_game *game,
		float angle_diff)
{
	float	wall_hit_x;
	float	wall_hit_y;

	wall_hit_x = player->x + ray->cos_angle * (ray->dist / cos(angle_diff));
	wall_hit_y = player->y + ray->sin_angle * (ray->dist / cos(angle_diff));
	if (ray->side == 0)
	{
		if (ray->step_x > 0)
			ray->textures = &game->tex_ea;
		else
			ray->textures = &game->tex_we;
		ray->wall_x = wall_hit_y / BLOCK;
	}
	else
	{
		if (ray->step_y > 0)
			ray->textures = &game->tex_so;
		else
			ray->textures = &game->tex_no;
		ray->wall_x = wall_hit_x / BLOCK;
	}
	ray->wall_x = ray->wall_x - floor(ray->wall_x);
	ft_select_texture_two(ray);
}

// Calcule la distance perpendiculaire et le point d'impact
/*
	Calculer la distance perpendiculaire (evite l'effet fisheye)
	Application de la correction fisheye amelioree
	Convertir en pixels
*/
void	ft_calc_distance(t_ray *ray, t_player *player, float angle_diff)
{
	if (ray->side == 0)
		ray->dist = (ray->map_x - player->x / BLOCK + (1 - ray->step_x) / 2)
			/ ray->cos_angle;
	else
		ray->dist = (ray->map_y - player->y / BLOCK + (1 - ray->step_y) / 2)
			/ ray->sin_angle;
	ray->dist *= cos(angle_diff);
	ray->dist *= BLOCK;
}

// Calcule les paramètres pour le dessin du mur
/*
	1) Calculer la hauteur de la colonne a dessiner
	2) Limiter les valeurs pour eviter les debordements
	3) Couleurs plafond/sol avec verification des valeurs
*/
void	ft_calc_wall_params(t_ray *ray, t_game *game)
{
	ray->wall_h = (BLOCK / ray->dist) * (WIDTH / 2);
	ray->start_y = (HEIGHT - (int)ray->wall_h) / 2;
	ray->end_y = ray->start_y + (int)ray->wall_h;
	if (ray->start_y < 0)
		ray->start_y = 0;
	if (ray->end_y >= HEIGHT)
		ray->end_y = HEIGHT - 1;
	ray->ceiling_color = 0;
	ray->floor_color = 0;
	if (game->parsing.value_c[0] >= 0 && game->parsing.value_c[0] <= 255
		&& game->parsing.value_c[1] >= 0 && game->parsing.value_c[1] <= 255
		&& game->parsing.value_c[2] >= 0 && game->parsing.value_c[2] <= 255)
	{
		ray->ceiling_color = (game->parsing.value_c[0] << 16)
			| (game->parsing.value_c[1] << 8) | game->parsing.value_c[2];
	}
	if (game->parsing.value_f[0] >= 0 && game->parsing.value_f[0] <= 255
		&& game->parsing.value_f[1] >= 0 && game->parsing.value_f[1] <= 255
		&& game->parsing.value_f[2] >= 0 && game->parsing.value_f[2] <= 255)
	{
		ray->floor_color = (game->parsing.value_f[0] << 16)
			| (game->parsing.value_f[1] << 8) | game->parsing.value_f[2];
	}
}

// Fonction 3: Calcule les paramètres de rendu
void	ft_prepare_wall_rendering(t_ray *ray, t_game *game, float angle_diff,
		int column)
{
	ft_calc_distance(ray, &game->player, angle_diff);
	game->wall_distances[column] = ray->dist;
	ft_select_texture_one(ray, &game->player, game, angle_diff);
	if (ray->textures && ray->textures->data)
		ft_calc_wall_params(ray, game);
}
