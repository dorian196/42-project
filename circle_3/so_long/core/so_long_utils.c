/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 19:37:37 by dpascal           #+#    #+#             */
/*   Updated: 2024/11/20 10:35:02 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_data *data)
{
	exit_window(data);
	return (0);
}

void	exit_window(t_data *data)
{
	free_all(data, &data->map, &data->img);
	exit(0);
}

void	*ft_mlx_i(void *mlx_ptr, char *filename, int *width, int *height)
{
	return (mlx_xpm_file_to_image(mlx_ptr, filename, width, height));
}

void	ft_mlx_w(t_data *data, void *img_ptr, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img_ptr, x, y);
}

void	count_line(t_data *data, t_map *map, char *filename, int fd)
{
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error : Unable to open file %s\n", filename);
		exit_window(data);
		return ;
	}
	map->height = 0;
	map->width = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		map->height++;
		map->width = ft_strlen(line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}
