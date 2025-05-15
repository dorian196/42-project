/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:27:06 by dpascal           #+#    #+#             */
/*   Updated: 2024/11/20 14:09:23 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_img(t_data *data, t_img *img)
{
	img->stone = ft_mlx_i(data->mlx_ptr, S, &img->width, &img->height);
	img->floor = ft_mlx_i(data->mlx_ptr, F, &img->width, &img->height);
	img->player = ft_mlx_i(data->mlx_ptr, P, &img->width, &img->height);
	img->player1 = ft_mlx_i(data->mlx_ptr, P, &img->width, &img->height);
	img->exit_z = ft_mlx_i(data->mlx_ptr, Z, &img->width, &img->height);
	img->exit = ft_mlx_i(data->mlx_ptr, E, &img->width, &img->height);
	img->exit_x = ft_mlx_i(data->mlx_ptr, X, &img->width, &img->height);
	img->tree = ft_mlx_i(data->mlx_ptr, T, &img->width, &img->height);
	img->enemy = ft_mlx_i(data->mlx_ptr, M, &img->width, &img->height);
	img->enemy_d = ft_mlx_i(data->mlx_ptr, D, &img->width, &img->height);
	if (!img->stone || !img->floor || !img->player || !img->player1
		|| !img->exit_z || !img->exit || !img->exit_x || !img->tree
		|| !img->enemy || !img->enemy_d)
	{
		ft_printf("Error : image loading\n");
		exit_window(data);
	}
}

void	check_map_validity(t_data *data, int y, int x, int free_exit)
{
	if (free_exit == 1)
	{
		ft_printf("Error : map is not complete\n");
		exit_window(data);
	}
	if (y == 0)
	{
		ft_printf("Error : empty map\n");
		exit_window(data);
	}
	if (y < 3 || x < 5)
	{
		ft_printf("Error : invalid map (minimum values 5x3)\n");
		exit_window(data);
	}
}

char	*create_map2(t_data *data, t_map *map, char *line, int line_length)
{
	(void)data;
	(void)map;
	(void)line_length;
	if (line[map->line_length - 1] == '\n')
	{
		line[map->line_length - 1] = '\0';
		map->line_length--;
	}
	return (line);
}

void	create_map(t_data *data, t_map *map, t_count *count, int fd)
{
	char	*line;
	int		x;

	line = get_next_line(fd);
	while (line != NULL)
	{
		map->line_length = ft_strlen(line);
		create_map2(data, map, line, map->line_length);
		map->map[map->y] = line;
		if (map->width != map->line_length)
			map->free_exit = 1;
		x = 0;
		while (line[x])
		{
			if (line[x] == 'M')
				count->collectable_count++;
			x++;
		}
		map->y++;
		line = get_next_line(fd);
	}
	check_map_validity(data, map->y, x, map->free_exit);
}

void	load_map(t_data *data, t_map *map, t_count *count, char *filename)
{
	int	fd;

	load_img(data, &data->img);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error : No such file directory : %s\n", filename);
		exit_window(data);
	}
	count_line(data, map, filename, fd);
	map->map = malloc(sizeof(char *) * map->height);
	if (!map->map)
	{
		ft_printf("Error : memory allocation failed\n");
		close(fd);
		exit_window(data);
	}
	create_map(data, map, count, fd);
	close(fd);
}
