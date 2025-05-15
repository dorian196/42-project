/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_util_one.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thobenel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 01:47:18 by thobenel          #+#    #+#             */
/*   Updated: 2025/05/09 01:47:21 by thobenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

int	check_r2(char **map, int i, int j, t_game *game)
{
	char	**cpy_map;
	int		res;

	cpy_map = copy_map_padded2(map);
	res = 0;
	if (cpy_map[i][j] == ' ')
	{
		res = check_fill2(cpy_map, i, j, game->parsing.map_nb_ligne);
	}
	free_map2(cpy_map);
	return (res);
}

unsigned int	ft_get_minimap_color(t_game *game, int j, int i)
{
	int		row_len;
	char	c;

	row_len = ft_strlen(game->map[j]);
	if (i < row_len)
	{
		c = game->map[j][i];
		if (c == '0' || c == 'N' || c == 'S'
			|| c == 'E' || c == 'W')
			return (0xFFFFFF);
		if (c == 'D' || c == 'O')
			return (0x888000);
		if (c == ' ' && check_r2(game->map, j, i, game) == 0)
			return (0xFFFFFF);
	}
	return (0x000000);
}

/* parcourt la map et dessine chaque tile de la minimap */
void	ft_draw_minimap_tiles(t_game *game, int ox, int oy)
{
	int	i;
	int	j;

	j = -1;
	while (++j < game->map_height)
	{
		i = -1;
		while (++i < game->map_width)
			ft_draw_tiles(game,
				ox + i * MINI_MAP_SCALE,
				oy + j * MINI_MAP_SCALE,
				ft_get_minimap_color(game, j, i));
	}
}

void	ft_draw_minimap_player(t_game *game, int ox, int oy)
{
	int	px;
	int	py;
	int	x;
	int	y;

	px = (int)(game->player.x / BLOCK * MINI_MAP_SCALE) + ox;
	py = (int)(game->player.y / BLOCK * MINI_MAP_SCALE) + oy;
	y = -1;
	while (y <= 1)
	{
		x = -1;
		while (x <= 1)
		{
			ft_put_pixel(px + x, py + y, 0xFF0000, game);
			x++;
		}
		y++;
	}
}

void	ft_draw_minimap_directions(t_game *game, int ox, int oy)
{
	int	len;
	int	step;
	int	px;
	int	py;

	px = (int)(game->player.x / BLOCK * MINI_MAP_SCALE) + ox;
	py = (int)(game->player.y / BLOCK * MINI_MAP_SCALE) + oy;
	len = MINI_MAP_SCALE * 2;
	step = -1;
	while (++step < len)
	{
		ft_put_pixel(px + (int)(cos(game->player.angle) * step), py
			+ (int)(sin(game->player.angle) * step), 0xFF0000, game);
	}
}
