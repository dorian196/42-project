/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 18:13:49 by dpascal           #+#    #+#             */
/*   Updated: 2024/11/20 14:09:02 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_all_map(int **visited, t_map *map)
{
	int	y;

	if (visited)
	{
		y = 0;
		while (y < map->height)
		{
			free(visited[y]);
			y++;
		}
		free(visited);
		visited = NULL;
	}
}

void	free_line(int **visited, t_data *data)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (i < y)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
	exit_window(data);
}

void	free_map(t_map *map)
{
	int	y;

	if (map->map)
	{
		y = 0;
		while (y < map->height && y <= map->y)
		{
			free(map->map[y]);
			y++;
		}
		free(map->map);
		map->map = NULL;
	}
}

void	free_img(t_data *data, t_img *img)
{
	if (img->stone)
		mlx_destroy_image(data->mlx_ptr, img->stone);
	if (img->floor)
		mlx_destroy_image(data->mlx_ptr, img->floor);
	if (img->player)
		mlx_destroy_image(data->mlx_ptr, img->player);
	if (img->player1)
		mlx_destroy_image(data->mlx_ptr, img->player1);
	if (img->exit_z)
		mlx_destroy_image(data->mlx_ptr, img->exit_z);
	if (img->exit)
		mlx_destroy_image(data->mlx_ptr, img->exit);
	if (img->exit_x)
		mlx_destroy_image(data->mlx_ptr, img->exit_x);
	if (img->tree)
		mlx_destroy_image(data->mlx_ptr, img->tree);
	if (img->enemy)
		mlx_destroy_image(data->mlx_ptr, img->enemy);
	if (img->enemy_d)
		mlx_destroy_image(data->mlx_ptr, img->enemy_d);
	if (data->img_ptr)
		mlx_destroy_image(data->mlx_ptr, data->img_ptr);
}

void	free_all(t_data *data, t_map *map, t_img *img)
{
	if (map)
		free_map(map);
	if (img)
		free_img(data, img);
	if (data->map.visited)
		free_all_map(data->map.visited, &data->map);
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
}
