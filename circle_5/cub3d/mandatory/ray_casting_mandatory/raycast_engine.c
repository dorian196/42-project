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

#include "cub.h"

/*
	DDA (Digital Differential Analyzer) - algorithme de tracer de ligne
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
