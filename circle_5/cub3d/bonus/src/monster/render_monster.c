/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_monster.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thobenel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 04:00:37 by thobenel          #+#    #+#             */
/*   Updated: 2025/05/09 04:00:38 by thobenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

bool	ft_is_valid_texture_coord(t_draw_monster *draw)
{
	return (!(draw->tex_x < 0 || draw->tex_x >= draw->textures->width
			|| draw->tex_y < 0 || draw->tex_y >= draw->textures->height));
}

// Calcule l'angle et la position à l'écran du monstre
bool	ft_calculate_monster_angle(t_draw_monster *draw, t_game *game)
{
	t_monster	*monster;

	monster = &game->monster;
	draw->monster = monster;
	draw->sprite_dir_x = monster->x - game->player.x;
	draw->sprite_dir_y = monster->y - game->player.y;
	draw->sprite_angle = atan2(draw->sprite_dir_y, draw->sprite_dir_x)
		- game->player.angle;
	while (draw->sprite_angle < -PI)
		draw->sprite_angle += 2 * PI;
	while (draw->sprite_angle > PI)
		draw->sprite_angle -= 2 * PI;
	if (fabs(draw->sprite_angle) > PI / 3)
		return (false);
	draw->sprite_screen_x = (WIDTH / 2) * (1 + draw->sprite_angle / (PI / 3));
	return (true);
}

float	ft_calculate_monster_distances(t_draw_monster *draw)
{
	float	monster_dist;
	float	angle_diff;
	float	min_dist;
	float	proximity_factor;

	monster_dist = draw->monster->distance;
	angle_diff = fabs(draw->sprite_angle);
	monster_dist *= cos(angle_diff);
	min_dist = BLOCK * 0.75f;
	if (monster_dist < min_dist)
		monster_dist = min_dist;
	proximity_factor = 1.0f;
	if (monster_dist < BLOCK * 2)
	{
		proximity_factor = 0.7f + (monster_dist / (BLOCK * 2)) * 0.3f;
		monster_dist = monster_dist / proximity_factor;
	}
	return (monster_dist);
}

// Calcule la taille du sprite à l'écran
bool	ft_calculate_sprite_size(t_draw_monster *draw, float monster_dist)
{
	float	fov_rad;
	float	proj_distance;

	fov_rad = PI / 3.0f;
	proj_distance = (WIDTH / 2.5f) / tan(fov_rad / 2.0f);
	draw->sprite_size = (BLOCK / monster_dist) * proj_distance;
	if (draw->sprite_size < 1)
		return (false);
	draw->sprite_height = draw->sprite_size;
	draw->sprite_width = draw->sprite_size;
	draw->sprite_top = (HEIGHT - draw->sprite_height) / 2;
	draw->sprite_left = draw->sprite_screen_x - draw->sprite_width / 2;
	return (true);
}

// Fonction principale qui coordonne le rendu du monstre
void	ft_draw_monster_main(t_game *game)
{
	t_draw_monster	draw;
	float			monster_dist;

	if (!ft_calculate_monster_angle(&draw, game))
		return ;
	monster_dist = ft_calculate_monster_distances(&draw);
	if (!ft_calculate_sprite_size(&draw, monster_dist))
		return ;
	draw.textures = &game->sprite_textures[draw.monster->current_frame];
	ft_draw_monster_columns(&draw, game, monster_dist);
}
