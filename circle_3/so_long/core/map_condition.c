/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_condition.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:00:15 by dpascal           #+#    #+#             */
/*   Updated: 2024/11/20 13:59:57 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_walls(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	while (x < map->width)
	{
		if (map->map[0][x] != '1' || map->map[map->height - 1][x] != '1')
			return (1);
		x++;
	}
	y = 0;
	while (y < map->height)
	{
		if (map->map[y][0] != '1' || map->map[y][map->width - 1] != '1')
			return (1);
		y++;
	}
	return (0);
}

int	check_format(t_map *map)
{
	if (map->height >= map->width)
		return (1);
	return (0);
}

int	check_tyle2(t_map *map, t_status *status, int x, int y)
{
	if (map->map[y][x] != '1' && map->map[y][x] != 'P' && map->map[y][x] != 'M'
		&& map->map[y][x] != 'T' && map->map[y][x] != 'X'
		&& map->map[y][x] != '0')
		return (1);
	if (map->map[y][x] == 'P')
		status->player = status->player + 1;
	else if (map->map[y][x] == 'M')
		status->mob = 1;
	else if (map->map[y][x] == 'X')
		status->exit = status->exit + 1;
	return (0);
}

int	check_tyle(t_map *map)
{
	t_status	status;
	int			x;
	int			y;

	status.player = 0;
	status.mob = 0;
	status.exit = 0;
	y = 0;
	while (y < map->height && map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			if (check_tyle2(map, &status, x, y))
				return (1);
			x++;
		}
		y++;
	}
	if (status.player != 1 || !status.mob || status.exit != 1)
		return (2);
	return (0);
}

void	check_map_condition(t_data *data, t_map *map)
{
	if (check_walls(map) == 1)
	{
		ft_printf("Error : The map is not completely surrounded by walls\n");
		exit_window(data);
	}
	if (check_format(map) == 1)
	{
		ft_printf("Error : Map is not rectangular\n");
		exit_window(data);
	}
	if (check_tyle(map) == 1)
	{
		ft_printf("Error : Incorrect tile value\n");
		exit_window(data);
	}
	if (check_tyle(map) == 2)
	{
		ft_printf("Error : missing element or duplicates element\n");
		exit_window(data);
	}
}
