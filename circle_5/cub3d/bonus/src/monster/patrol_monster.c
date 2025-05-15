/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patrol_monster.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thobenel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 04:00:21 by thobenel          #+#    #+#             */
/*   Updated: 2025/05/09 04:00:29 by thobenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

bool	ft_check_monster_point(float px, float py, t_game *game)
{
	int	grid_x;
	int	grid_y;

	grid_x = (int)(px / BLOCK);
	grid_y = (int)(py / BLOCK);
	if (grid_x < 0 || grid_x >= game->map_width
		|| grid_y < 0 || grid_y >= game->map_height)
		return (true);
	if (game->map[grid_y] == NULL
		|| grid_x >= (int)ft_strlen(game->map[grid_y]))
		return (true);
	if (game->map[grid_y][grid_x] == '1')
		return (true);
	return (false);
}

bool	ft_collision_monster(float x, float y, t_game *game)
{
	float	buffer;
	float	points[4][2];
	int		i;

	buffer = 16.0f;
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
		if (ft_check_monster_point(points[i][0], points[i][1], game))
			return (true);
		i++;
	}
	return (false);
}

// Fonction pour verifier si le pixel est dans l'ecran
bool	ft_is_pixel_visible(t_draw_monster *draw, t_game *game,
		float monster_dist)
{
	if (draw->screen_x < 0 || draw->screen_x >= WIDTH)
		return (false);
	if (monster_dist >= game->wall_distances[draw->screen_x])
		return (false);
	if (draw->screen_y < 0 || draw->screen_y >= HEIGHT)
		return (false);
	return (true);
}

// Deplace le monstre et verifie les collisions avec le joueur
void	ft_monster_chase_player(t_monster *m, t_player *player, t_game *game)
{
	float	new_x;
	float	new_y;

	ft_calculate_monster_chase_position(m, player, &new_x, &new_y);
	if (!ft_collision_monster(new_x, m->y, game))
		m->x = new_x;
	if (!ft_collision_monster(m->x, new_y, game))
		m->y = new_y;
	if (m->distance < BLOCK / 2)
	{
		printf("🚨 Le monstre vous a attrape ! GAME OVER 🚨\n");
		ft_exit_game(game);
	}
}

void	ft_monster_patrol(t_monster *m, t_game *game)
{
	static float	patrol_angle;
	static int		patrol_directions;
	float			new_x;
	float			new_y;

	patrol_angle = 0.0f;
	patrol_directions = 1;
	patrol_angle += 0.01f * patrol_directions;
	if (m->frame_timer % 100 == 0)
		patrol_directions *= -1;
	new_x = m->x + cos(patrol_angle) * m->speed * 0.3f;
	new_y = m->y + sin(patrol_angle) * m->speed * 0.3f;
	if (!ft_collision_monster(new_x, m->y, game))
		m->x = new_x;
	else
		patrol_directions *= -1;
	if (!ft_collision_monster(m->x, new_y, game))
		m->y = new_y;
	else
		patrol_directions *= -1;
}
