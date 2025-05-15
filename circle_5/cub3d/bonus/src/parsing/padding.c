/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thobenel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 04:09:59 by thobenel          #+#    #+#             */
/*   Updated: 2025/05/09 04:10:00 by thobenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

void	flood_fill(char **deep_copy, int i, int j, int map_nb_ligne)
{
	if (i < 0 || j < 0 || i >= map_nb_ligne || j >= ft_strlen(deep_copy[i]))
		return ;
	if (deep_copy[i][j] == '1' || deep_copy[i][j] == 'B')
		return ;
	if (deep_copy[i][j] == ' ')
	{
		deep_copy[i][j] = 'B';
		flood_fill(deep_copy, i + 1, j, map_nb_ligne);
		flood_fill(deep_copy, i, j + 1, map_nb_ligne);
		flood_fill(deep_copy, i - 1, j, map_nb_ligne);
		flood_fill(deep_copy, i, j - 1, map_nb_ligne);
	}
}

char	**copy_map_padded(char **map)
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
	while (map[i++])
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

int	check_r(char **map, int i, int j, t_game *game)
{
	char	**cpy_map;
	int		res;

	cpy_map = copy_map_padded(map);
	res = 0;
	if (cpy_map[i][j] == 'R')
		res = check_fill(cpy_map, i, j, game->parsing.map_nb_ligne);
	free_map(cpy_map);
	return (res);
}

static bool	ft_is_breach_cell(char **deep_copy, int ni, int nj, t_game *game)
{
	if (ni < 0 || ni >= game->height_closed
		|| nj < 0 || nj >= game->width_closed
		|| !deep_copy[ni]
		|| nj >= (int)ft_strlen(deep_copy[ni]))
		return (false);
	if (deep_copy[ni][nj] == 'X')
		return (true);
	if (deep_copy[ni][nj] == 'R'
		&& check_r(deep_copy, ni, nj, game) != 0)
		return (true);
	return (false);
}

bool	ft_detect_breach(char **d_p, int i, int j, t_game *game)
{
	char	*msg;
	char	c;

	msg = "[DEBUG] Breach detected: case jouable adjacente à X en";
	if (!d_p || !d_p[i] || i < 0 || i >= game->height_closed
		|| j < 0 || j >= game->width_closed)
		return (false);
	c = d_p[i][j];
	if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W'
		|| c == 'D' || c == 'O')
	{
		if (ft_is_breach_cell(d_p, i - 1, j, game))
			return (printf("%s [%d][%d] en haut\n", msg, i, j), true);
		if (ft_is_breach_cell(d_p, i, j + 1, game))
			return (printf("%s [%d][%d] à droite\n", msg, i, j), true);
		if (ft_is_breach_cell(d_p, i + 1, j, game))
			return (printf("%s [%d][%d] en bas\n", msg, i, j), true);
		if (ft_is_breach_cell(d_p, i, j - 1, game))
			return (printf("%s [%d][%d] à gauche\n", msg, i, j), true);
	}
	return (false);
}
