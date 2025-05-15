/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_door.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thobenel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 05:17:50 by thobenel          #+#    #+#             */
/*   Updated: 2025/05/09 05:17:51 by thobenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

void	ft_prepare_door_texture_two(int is_vert, t_ray *ray,
		t_door_data *door_data, int tex_w)
{
	float	hit_offset;

	if (is_vert)
		hit_offset = ray->wall_x * BLOCK;
	else
		hit_offset = (1 - ray->wall_x) * BLOCK;
	door_data->tex_x = (int)((hit_offset / BLOCK) * tex_w);
}

// Première fonction : calcule les coordonnées de texture de la porte
void	ft_prepare_door_texture(t_ray *ray, t_player *player, t_game *game,
		t_door_data *door_data)
{
	int	tex_w;
	int	tex_h;
	int	prev_x;
	int	curr_x;
	int	is_vert;

	tex_w = game->imgs.width;
	tex_h = game->imgs.height;
	prev_x = (int)((player->x + (ray->map_x - ray->step_x) * BLOCK) / BLOCK);
	curr_x = (int)(ray->map_x);
	is_vert = (prev_x != curr_x);
	ft_prepare_door_texture_two(is_vert, ray, door_data, tex_w);
	if (door_data->tex_x < 0)
		door_data->tex_x = 0;
	if (door_data->tex_x >= tex_w)
		door_data->tex_x = tex_w - 1;
	door_data->tex_w = tex_w;
	door_data->tex_h = tex_h;
	door_data->door_data = game->imgs.door_data;
	door_data->game = game;
	ray->shade = 1.0f / (1.0f + ray->dist * ray->dist * SHADOW_CASTING);
}

// Deuxième fonction : dessine le pixel de la porte
void	ft_draw_door_pixel(t_ray *ray, int column, int y,
		t_door_data *door_data)
{
	int	door_tex_y;
	int	door_index;
	int	color;

	door_tex_y = ((y - ray->start_y) * door_data->tex_h) / ray->wall_h;
	if (door_tex_y < 0)
		door_tex_y = 0;
	if (door_tex_y >= door_data->tex_h)
		door_tex_y = door_data->tex_h - 1;
	door_index = door_tex_y * door_data->tex_w + door_data->tex_x;
	if (door_index >= 0 && door_index < (door_data->tex_w * door_data->tex_h))
	{
		color = door_data->door_data[door_index];
		ray->r = ((color >> 16) & 0xFF) * ray->shade;
		ray->g = ((color >> 8) & 0xFF) * ray->shade;
		ray->b = (color & 0xFF) * ray->shade;
		color = (ray->r << 16) | (ray->g << 8) | ray->b;
		ft_put_pixel(column, y, color, door_data->game);
	}
	else
		ft_put_pixel(column, y, 0xFF0000, door_data->game);
}
