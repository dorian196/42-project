/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 02:30:28 by dpascal           #+#    #+#             */
/*   Updated: 2025/05/06 03:31:11 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_color_f(t_game *game, char *map, int i, char **rgb_values)
{
	if (ft_strncmp(map, "F ", 2) == 0)
	{
		if (game->parsing.path_f)
			ft_error("🚨 Error \n Duplicate floor color definition \n", game);
		game->parsing.path_f = ft_strdup_v2(map + 2);
		rgb_values = ft_split(game->parsing.path_f, ',');
		if (!rgb_values || !rgb_values[0] || !rgb_values[1] || !rgb_values[2])
			ft_error("🚨 Error \n Invalid floor color format \n", game);
		game->parsing.value_f[0] = ft_atoi(rgb_values[0]);
		game->parsing.value_f[1] = ft_atoi(rgb_values[1]);
		game->parsing.value_f[2] = ft_atoi(rgb_values[2]);
		if (game->parsing.value_f[0] < 0 || game->parsing.value_f[0] > 255
			|| game->parsing.value_f[1] < 0 || game->parsing.value_f[1] > 255
			|| game->parsing.value_f[2] < 0 || game->parsing.value_f[2] > 255)
			ft_error("🚨 Error \n RGB values must be between 0 and 255 \n",
				game);
		i = -1;
		while (rgb_values[++i])
			free(rgb_values[i]);
		free(rgb_values);
		return (1);
	}
	return (0);
}

int	ft_color_c(t_game *game, char *map, int i, char **rgb_values)
{
	if (ft_strncmp(map, "C ", 2) == 0)
	{
		if (game->parsing.path_c)
			ft_error("🚨 Error \n Duplicate ceiling color definition \n", game);
		game->parsing.path_c = ft_strdup_v2(map + 2);
		rgb_values = ft_split(game->parsing.path_c, ',');
		if (!rgb_values || !rgb_values[0] || !rgb_values[1] || !rgb_values[2])
			ft_error("🚨 Error \n Invalid ceiling color format \n", game);
		game->parsing.value_c[0] = ft_atoi(rgb_values[0]);
		game->parsing.value_c[1] = ft_atoi(rgb_values[1]);
		game->parsing.value_c[2] = ft_atoi(rgb_values[2]);
		if (game->parsing.value_c[0] < 0 || game->parsing.value_c[0] > 255
			|| game->parsing.value_c[1] < 0 || game->parsing.value_c[1] > 255
			|| game->parsing.value_c[2] < 0 || game->parsing.value_c[2] > 255)
			ft_error("🚨 Error \n RGB values must be between 0 and 255 \n",
				game);
		i = -1;
		while (rgb_values[++i])
			free(rgb_values[i]);
		free(rgb_values);
		return (1);
	}
	return (0);
}

void	ft_colors_parse(t_game *game, char *map)
{
	int		i;
	char	**rgb_values;

	i = 0;
	rgb_values = NULL;
	if (ft_color_f(game, map, i, rgb_values) != 0)
		return ;
	else if (ft_color_c(game, map, i, rgb_values) != 0)
		return ;
	else
		ft_error("🚨 Error \n Invalid color identifier \n", game);
}

void	ft_color_sky(t_game *game)
{
	int	x;
	int	y;
	int	color_ceiling;

	if (game->parsing.value_c[0] >= 0
		&& game->parsing.value_c[1] >= 0
		&& game->parsing.value_c[2] >= 0)
		color_ceiling = (game->parsing.value_c[0] << 16)
			| (game->parsing.value_c[1] << 8)
			| game->parsing.value_c[2];
	y = -1;
	while (++y < HEIGHT / 2)
	{
		x = -1;
		while (++x < WIDTH)
			ft_put_pixel(x, y, color_ceiling, game);
	}
}

void	ft_get_colors(t_game *game)
{
	int	x;
	int	y;
	int	color_floor;

	ft_color_sky(game);
	if (game->parsing.value_f[0] >= 0
		&& game->parsing.value_f[1] >= 0
		&& game->parsing.value_f[2] >= 0)
		color_floor = (game->parsing.value_f[0] << 16)
			| (game->parsing.value_f[1] << 8)
			| game->parsing.value_f[2];
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			ft_put_pixel(x, y, color_floor, game);
	}
}
