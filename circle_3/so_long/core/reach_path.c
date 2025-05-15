/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reach_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 14:46:52 by dpascal           #+#    #+#             */
/*   Updated: 2024/11/20 09:23:35 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	position(t_data *data, t_pos *pos)
{
	if (data->map.map[pos->y][pos->x] == 'P')
	{
		data->game.x = pos->x;
		data->game.y = pos->y;
	}
}

void	pos_player(t_data *data)
{
	t_pos	pos;

	pos.y = 0;
	while (pos.y < data->map.height)
	{
		pos.x = 0;
		while (pos.x < data->map.width)
		{
			position(data, &pos);
			pos.x++;
		}
		pos.y++;
	}
}

void	init_visited(int **visited, t_data *data, int y)
{
	int	x;

	x = 0;
	while (x < data->map.width)
	{
		visited[y][x] = 0;
		x++;
	}
}

void	check_path(t_data *data, int x, int y, int **visited)
{
	if (data->map.map[y][x] == '1' || data->map.map[y][x] == 'T'
		|| visited[y][x])
		return ;
	visited[y][x] = 1;
	if (data->map.map[y][x] == 'M')
		data->count.collectable2++;
	if (data->map.map[y][x] == 'X')
		data->count.exit = 1;
	check_path(data, x + 1, y, visited);
	check_path(data, x - 1, y, visited);
	check_path(data, x, y + 1, visited);
	check_path(data, x, y - 1, visited);
}

void	reach_path(t_data *data)
{
	int	y;

	pos_player(data);
	data->map.visited = malloc(data->map.height * sizeof(int *));
	if (!data->map.visited)
	{
		exit_window(data);
	}
	y = 0;
	while (y < data->map.height)
	{
		data->map.visited[y] = malloc(data->map.width * sizeof(int));
		if (!data->map.visited[y])
			free_line(data->map.visited, data);
		init_visited(data->map.visited, data, y);
		y++;
	}
	check_path(data, data->game.x, data->game.y, data->map.visited);
	if (data->count.collectable2 != data->count.collectable_count
		|| !(data->count.exit))
	{
		printf("Error : Map does not contain a valid path\n");
		exit_window(data);
	}
}
