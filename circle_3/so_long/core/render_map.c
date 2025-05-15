/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:30:21 by dpascal           #+#    #+#             */
/*   Updated: 2024/11/03 15:01:51 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	screen_size(t_data *data, t_game *game, t_map *map)
{
	mlx_get_screen_size(data->mlx_ptr, &(data->width), &(data->height));
	if (data->width > 1920)
		data->width = 1920;
	if (data->height > 1080)
		data->height = 1080;
	game->width = map->width * TILE_SIZE;
	game->height = map->height * TILE_SIZE;
	if (game->width > data->width)
		game->width = data->width;
	if (game->height > data->height)
		game->height = data->height;
}

void	set_camera(t_game *game, t_map *map, t_pos *pos)
{
	pos->start_x = game->x - (game->width / (2 * TILE_SIZE));
	pos->start_y = game->y - (game->height / (2 * TILE_SIZE));
	if (pos->start_x < 0)
		pos->start_x = 0;
	if (pos->start_y < 0)
		pos->start_y = 0;
	if (pos->start_x > map->width - (game->width / TILE_SIZE))
		pos->start_x = map->width - (game->width / TILE_SIZE);
	if (pos->start_y > map->height - (game->height / TILE_SIZE))
		pos->start_y = map->height - (game->height / TILE_SIZE);
}

void	draw_tile(t_data *data, t_pos *pos, int pos_x, int pos_y)
{
	if (data->map.map[pos->y][pos->x] == '1')
		ft_mlx_w(data, data->img.stone, pos_x, pos_y);
	else if (data->map.map[pos->y][pos->x] == '0')
		ft_mlx_w(data, data->img.floor, pos_x, pos_y);
	else if (data->map.map[pos->y][pos->x] == 'P')
		ft_mlx_w(data, data->img.player, pos_x, pos_y);
	else if (data->map.map[pos->y][pos->x] == 'N')
		ft_mlx_w(data, data->img.player, pos_x, pos_y);
	else if (data->map.map[pos->y][pos->x] == 'Z')
		ft_mlx_w(data, data->img.exit_z, pos_x, pos_y);
	else if (data->map.map[pos->y][pos->x] == 'E')
		ft_mlx_w(data, data->img.exit, pos_x, pos_y);
	else if (data->map.map[pos->y][pos->x] == 'X')
		ft_mlx_w(data, data->img.exit_x, pos_x, pos_y);
	else if (data->map.map[pos->y][pos->x] == 'T')
		ft_mlx_w(data, data->img.tree, pos_x, pos_y);
	else if (data->map.map[pos->y][pos->x] == 'M')
		ft_mlx_w(data, data->img.enemy, pos_x, pos_y);
	else if (data->map.map[pos->y][pos->x] == 'D')
		ft_mlx_w(data, data->img.enemy_d, pos_x, pos_y);
}

void	render_map(t_data *data, t_game *game)
{
	t_pos	pos;
	int		pos_x;
	int		pos_y;

	set_camera(game, &data->map, &pos);
	pos.y = 0;
	while (pos.y < data->map.height)
	{
		pos.x = 0;
		while (pos.x < data->map.width)
		{
			pos_x = (pos.x - pos.start_x) * TILE_SIZE;
			pos_y = (pos.y - pos.start_y) * TILE_SIZE;
			if (pos.x >= 0 && pos.x < game->width && pos.y >= 0
				&& pos.y < game->height)
			{
				draw_tile(data, &pos, pos_x, pos_y);
			}
			pos.x++;
		}
		pos.y++;
	}
}
