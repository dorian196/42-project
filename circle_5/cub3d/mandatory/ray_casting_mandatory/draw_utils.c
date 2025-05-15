/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 01:46:56 by dpascal           #+#    #+#             */
/*   Updated: 2025/05/06 01:47:26 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_put_pixel(int x, int y, int colors, t_game *game)
{
	int	index;

	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	index = y * game->size_line + x * game->bpp / 8;
	game->data[index] = colors & 0xFF;
	game->data[index + 1] = (colors >> 8) & 0xFF;
	game->data[index + 2] = (colors >> 16) & 0xFF;
}

void	ft_draw_square(int x, int y, int size, t_game *game)
{
	int	i;

	i = -1;
	while (i++ < size)
		ft_put_pixel(x + i, y, game->colors, game);
	i = -1;
	while (i++ < size)
		ft_put_pixel(x, y + i, game->colors, game);
	i = -1;
	while (i++ < size)
		ft_put_pixel(x + size, y + i, game->colors, game);
	i = -1;
	while (i++ < size)
		ft_put_pixel(x + i, y + size, game->colors, game);
}

void	ft_draw_map(t_game *game)
{
	char	**map;
	int		x;
	int		y;

	map = game->map;
	game->colors = 0x0000FF;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
				ft_draw_square(x * BLOCK, y * BLOCK, BLOCK, game);
			x++;
		}
		y++;
	}
}

/**
 * Normalise l'angle du joueur dans l'intervalle [0, 2π]
 * @param joueur Structure du joueur
 */
void	ft_polish_angle(t_player *joueur)
{
	if (joueur->angle < 0)
		joueur->angle += 2 * PI;
	if (joueur->angle >= 2 * PI)
		joueur->angle -= 2 * PI;
}

int	ft_cast_ray_two(t_ray *ray, t_game *game)
{
	if (ray->map_y >= 0 && ray->map_y < game->map_height
		&& game->map[(int)ray->map_y] != NULL && ray->map_x >= 0
		&& ray->map_x < ft_strlen(game->map[(int)ray->map_y]))
	{
		ray->tile = game->map[(int)ray->map_y][(int)ray->map_x];
		if (ray->tile == '1' || ray->tile == 'D')
			ray->hit = 1;
		return (0);
	}
	return (1);
}
