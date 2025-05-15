/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thobenel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 05:20:50 by thobenel          #+#    #+#             */
/*   Updated: 2025/05/09 05:20:51 by thobenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

void	ft_calculate_check_position(t_player *pl, float dist,
	float *check_x, float *check_y)
{
	*check_x = pl->x + cos(pl->angle) * BLOCK * dist;
	*check_y = pl->y + sin(pl->angle) * BLOCK * dist;
}

void	ft_get_map_coordinates(float check_x, float check_y,
	int *map_x, int *map_y)
{
	*map_x = (int)(check_x / BLOCK);
	*map_y = (int)(check_y / BLOCK);
}

int	ft_is_player_position(t_player *pl, int map_x, int map_y)
{
	int	pl_map_x;
	int	pl_map_y;

	pl_map_x = (int)(pl->x / BLOCK);
	pl_map_y = (int)(pl->y / BLOCK);
	return (map_x == pl_map_x && map_y == pl_map_y);
}

void	ft_open_door(t_player *pl, t_game *game)
{
	float	dist;
	float	check_x;
	float	check_y;
	int		map_x;
	int		map_y;

	dist = 0.1;
	while (dist <= 2)
	{
		ft_calculate_check_position(pl, dist, &check_x, &check_y);
		ft_get_map_coordinates(check_x, check_y, &map_x, &map_y);
		if (ft_is_player_position(pl, map_x, map_y))
			dist += 0.1;
		if (game->map[map_y][map_x] == 'D')
			game->map[map_y][map_x] = 'O';
		else if (game->map[map_y][map_x] == 'O')
			game->map[map_y][map_x] = 'D';
		else
		{
			dist += 0.1;
			continue ;
		}
		break ;
	}
}

void	ft_draw_map(t_game *game)
{
	char	**map;
	int		colors;
	int		x;
	int		y;

	map = game->map;
	colors = 0x0000FF;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
				ft_draw_square(x * BLOCK, y * BLOCK, colors, game);
			x++;
		}
		y++;
	}
}
