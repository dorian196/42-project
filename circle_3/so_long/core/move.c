/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 13:42:39 by dpascal           #+#    #+#             */
/*   Updated: 2024/11/03 15:22:43 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_exit(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map.height)
	{
		x = 0;
		while (data->map.map[y][x])
		{
			if (data->map.map[y][x] == 'X')
				data->map.map[y][x] = 'E';
			x++;
		}
		y++;
	}
}

void	prev_pos(t_data *data)
{
	if (data->map.map[data->game.y][data->game.x] == 'N')
		data->map.map[data->game.y][data->game.x] = 'D';
	else
		data->map.map[data->game.y][data->game.x] = '0';
}

void	check_exit(t_data *data)
{
	if (data->map.map[data->game.y][data->game.x] == 'E')
	{
		mlx_do_sync(data->mlx_ptr);
		data->map.map[data->game.y][data->game.x] = 'Z';
		render_map(data, &data->game);
		mlx_do_sync(data->mlx_ptr);
		sleep(2);
		exit_window(data);
	}
}

void	check_mob(t_data *data)
{
	if (data->map.map[data->game.y][data->game.x] == 'M'
		|| data->map.map[data->game.y][data->game.x] == 'D')
	{
		if (data->map.map[data->game.y][data->game.x] == 'M')
			data->count.collectable++;
		data->map.map[data->game.y][data->game.x] = 'N';
		if (data->count.collectable == data->count.collectable_count)
			open_exit(data);
	}
	else if (data->map.map[data->game.y][data->game.x] == 'D')
		data->map.map[data->game.y][data->game.x] = 'P';
}

int	move_player(t_data *data, int new_x, int new_y)
{
	prev_pos(data);
	data->game.x = new_x;
	data->game.y = new_y;
	if (data->map.map[data->game.y][data->game.x] == '0')
	{
		data->map.map[data->game.y][data->game.x] = 'P';
	}
	if (data->map.map[data->game.y][data->game.x] == 'E')
		check_exit(data);
	check_mob(data);
	render_map(data, &data->game);
	return (1);
}
