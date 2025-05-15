/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thobenel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 05:17:42 by thobenel          #+#    #+#             */
/*   Updated: 2025/05/09 05:17:43 by thobenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

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

// Première fonction : calcule les coordonnées et 
// récupère la couleur de la texture
void	ft_prepare_wall_texture(t_ray *ray)
{
	double	precise_tex_y;
	int		max_tex_size;

	precise_tex_y = ray->tex_pos;
	ray->tex_y = (int)precise_tex_y % ray->textures->height;
	if (ray->tex_y < 0)
		ray->tex_y = 0;
	if (ray->tex_y >= ray->textures->height)
		ray->tex_y = ray->textures->height - 1;
	ray->tex_index = ray->tex_y * ray->textures->size_line + ray->tex_x
		* (ray->textures->bpp / 8);
	max_tex_size = ray->textures->size_line * ray->textures->height;
	if (ray->tex_index < 0 || ray->tex_index + 2 >= max_tex_size)
		ray->colors = 0xFF0000;
	else
	{
		ray->r = (unsigned char)ray->textures->data[ray->tex_index + 2];
		ray->g = (unsigned char)ray->textures->data[ray->tex_index + 1];
		ray->b = (unsigned char)ray->textures->data[ray->tex_index];
	}
}

// Deuxième fonction : applique l'ombrage et dessine le pixel

void	ft_shade_and_draw_wall(t_ray *ray, int column, int y, t_game *game)
{
	ray->colors = 0;
	if (ray->colors != 0xFF0000)
	{
		ray->shade = 1.0f / (1.0f + ray->dist * ray->dist * SHADOW_CASTING);
		ray->r = (int)(ray->r * ray->shade);
		ray->g = (int)(ray->g * ray->shade);
		ray->b = (int)(ray->b * ray->shade);
		if (ray->side == 0)
		{
			ray->r = ray->r * 0.9;
			ray->g = ray->g * 0.9;
			ray->b = ray->b * 0.9;
		}
		ray->colors = (ray->r << 16) | (ray->g << 8) | ray->b;
	}
	ft_put_pixel(column, y, ray->colors, game);
}

void	ft_draw_wall(t_ray *ray, int column, int y, t_game *game)
{
	ft_prepare_wall_texture(ray);
	ft_shade_and_draw_wall(ray, column, y, game);
}
