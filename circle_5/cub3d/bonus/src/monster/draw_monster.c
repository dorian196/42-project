/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_monster.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thobenel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 04:00:13 by thobenel          #+#    #+#             */
/*   Updated: 2025/05/09 04:00:14 by thobenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

bool	ft_draw_monster_two(t_game *game, t_draw_monster *draw)
{
	t_player	*player;

	player = &game->player;
	draw->sprite_dir_x = draw->monster->x - player->x;
	draw->sprite_dir_y = draw->monster->y - player->y;
	draw->sprite_angle = atan2(draw->sprite_dir_y, draw->sprite_dir_x)
		- player->angle;
	if (draw->sprite_angle < -PI)
		draw->sprite_angle += 2 * PI;
	if (draw->sprite_angle > PI)
		draw->sprite_angle -= 2 * PI;
	if (fabs(draw->sprite_angle) > PI / 3)
		return (false);
	draw->sprite_screen_x = (WIDTH / 2) * (1 + draw->sprite_angle / (PI / 3));
	draw->sprite_size = (BLOCK / draw->monster->distance) * (WIDTH / 2);
	if (draw->sprite_size < 1)
		return (false);
	draw->sprite_height = draw->sprite_size;
	draw->sprite_width = draw->sprite_size;
	draw->sprite_top = (HEIGHT - draw->sprite_height) / 2;
	draw->sprite_left = draw->sprite_screen_x - draw->sprite_width / 2;
	return (true);
}

void	ft_draw_monster_one(t_game *game, t_draw_monster *draw)
{
	draw->tex_y = draw->y * draw->textures->height / draw->sprite_height;
	draw->tex_index = draw->tex_y * draw->textures->size_line + draw->tex_x
		* (draw->textures->bpp / 8);
	draw->r = (unsigned char)draw->textures->data[draw->tex_index + 2];
	draw->g = (unsigned char)draw->textures->data[draw->tex_index + 1];
	draw->b = (unsigned char)draw->textures->data[draw->tex_index];
	draw->shade = 1.0f / (1.0f + draw->monster->distance
			* draw->monster->distance * SHADOW_CASTING);
	draw->r = (int)(draw->r * draw->shade);
	draw->g = (int)(draw->g * draw->shade);
	draw->b = (int)(draw->b * draw->shade);
	draw->color = (draw->r << 16) | (draw->g << 8) | draw->b;
	if (draw->color != 0)
		ft_put_pixel(draw->screen_x, draw->screen_y, draw->color, game);
}

void	ft_draw_single_monster_pixel(t_draw_monster *draw, t_game *game,
		float monster_dist)
{
	draw->tex_index = draw->tex_y * draw->textures->size_line + draw->tex_x
		* (draw->textures->bpp / 8);
	draw->r = (unsigned char)draw->textures->data[draw->tex_index + 2];
	draw->g = (unsigned char)draw->textures->data[draw->tex_index + 1];
	draw->b = (unsigned char)draw->textures->data[draw->tex_index];
	draw->shade = 1.0f / (1.0f + monster_dist * monster_dist * SHADOW_CASTING);
	draw->r = (int)(draw->r * draw->shade);
	draw->g = (int)(draw->g * draw->shade);
	draw->b = (int)(draw->b * draw->shade);
	draw->color = (draw->r << 16) | (draw->g << 8) | draw->b;
	if (draw->color != 0)
		ft_put_pixel(draw->screen_x, draw->screen_y, draw->color, game);
}

// Fonction pour dessiner une ligne verticale du sprite
void	ft_draw_monster_vertical_line(t_draw_monster *draw, t_game *game,
		float monster_dist)
{
	draw->y = 0;
	while (draw->y < draw->sprite_height)
	{
		draw->screen_y = draw->sprite_top + draw->y;
		if (draw->screen_y < 0 || draw->screen_y >= HEIGHT)
		{
			draw->y++;
			continue ;
		}
		draw->tex_y = draw->y * draw->textures->height / draw->sprite_height;
		if (!ft_is_valid_texture_coord(draw))
		{
			draw->y++;
			continue ;
		}
		ft_draw_single_monster_pixel(draw, game, monster_dist);
		draw->y++;
	}
}

// Fonction pour dessiner toutes les colonnes du sprite
void	ft_draw_monster_columns(t_draw_monster *draw, t_game *game,
		float monster_dist)
{
	draw->x = 0;
	while (draw->x < draw->sprite_width)
	{
		draw->screen_x = draw->sprite_left + draw->x;
		if (draw->screen_x < 0 || draw->screen_x >= WIDTH
			|| monster_dist >= game->wall_distances[draw->screen_x])
		{
			draw->x++;
			continue ;
		}
		draw->tex_x = draw->x * draw->textures->width / draw->sprite_width;
		ft_draw_monster_vertical_line(draw, game, monster_dist);
		draw->x++;
	}
}
