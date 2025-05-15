/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_util_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thobenel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 01:47:32 by thobenel          #+#    #+#             */
/*   Updated: 2025/05/09 01:47:35 by thobenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

void	ft_draw_minimap_background(t_game *game, int ox, int oy)
{
	int	scale;
	int	x;
	int	y;

	scale = MINI_MAP_SCALE;
	y = -1;
	while (++y < game->map_height * scale)
	{
		x = -1;
		while (++x < game->map_width * scale)
			ft_put_pixel(ox + x, oy + y, 0x000000, game);
	}
}

void	ft_draw_tiles(t_game *game, int x, int y, int colors)
{
	int	i;
	int	j;

	i = -1;
	while (++i < MINI_MAP_SCALE)
	{
		j = -1;
		while (++j < MINI_MAP_SCALE)
			ft_put_pixel(x + j, y + i, colors, game);
	}
}

char	**copy_map_padded2(char **map)
{
	char	**cpy_map;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (map[i])
		i++;
	cpy_map = malloc(sizeof(char *) * (i + 1));
	if (!cpy_map)
		return (printf("Error: Allocation failed"), NULL);
	i = -1;
	while (map[++i])
	{
		j = 0;
		while (map[i][j])
			j++;
		cpy_map[i] = malloc(sizeof(char) * (j + 1));
		j = -1;
		while (map[i][++j])
			cpy_map[i][j] = map[i][j];
		cpy_map[i][j] = '\0';
	}
	cpy_map[i] = NULL;
	return (cpy_map);
}

void	free_map2(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
