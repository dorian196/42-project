/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 02:33:54 by dpascal           #+#    #+#             */
/*   Updated: 2025/05/06 03:38:12 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	check_r(char **map, int i, int j, t_game *game)
{
	char	**cpy_map;
	int		res;

	cpy_map = copy_map_padded(game, map);
	res = 0;
	if (cpy_map[i][j] == 'R')
		res = check_fill(cpy_map, i, j, game->parsing.map_nb_ligne);
	free_tab(cpy_map);
	return (res);
}

int	ft_check_breach(char **deep_copy, int i, int j, t_game *game)
{
	if (i - 1 >= 0 && deep_copy[i - 1] && j < ft_strlen(deep_copy[i - 1])
		&& (deep_copy[i - 1][j] == 'X' || ((deep_copy[i - 1][j] == 'R')
		&& check_r(deep_copy, i - 1, j, game) != 0)))
		return (1);
	if (j + 1 < game->cpy_width && j + 1 < ft_strlen(deep_copy[i])
		&& (deep_copy[i][j + 1] == 'X' || ((deep_copy[i][j + 1] == 'R')
		&& check_r(deep_copy, i, j + 1, game) != 0)))
		return (1);
	if (i + 1 < game->cpy_height && deep_copy[i + 1]
		&& j < ft_strlen(deep_copy[i + 1]) && (deep_copy[i + 1][j] == 'X'
		|| ((deep_copy[i + 1][j] == 'R') && check_r(deep_copy, i + 1, j,
			game) != 0)))
		return (1);
	if (j - 1 >= 0 && (deep_copy[i][j - 1] == 'X' || ((deep_copy[i][j
				- 1] == 'R') && check_r(deep_copy, i, j - 1, game) != 0)))
		return (1);
	return (0);
}

bool	ft_detect_breach(char **deep_copy, int i, int j, t_game *game)
{
	char	current;

	if (!deep_copy || !deep_copy[i] || i < 0 || i >= game->cpy_height || j < 0
		|| j >= game->cpy_width)
		return (false);
	current = deep_copy[i][j];
	if (current == '0' || current == 'N' || current == 'S' || current == 'E'
		|| current == 'W')
	{
		if (ft_check_breach(deep_copy, i, j, game) != 0)
			return (true);
	}
	return (false);
}

bool	check_x(t_game *game, char **deep_copy, bool result)
{
	int	i;
	int	j;

	i = -1;
	while (deep_copy[++i])
	{
		j = -1;
		while (deep_copy[i][++j])
		{
			game->cpy_height = game->parsing.map_nb_ligne + 2;
			game->cpy_width = ft_find_longest_line(game->parsing.map_tab_too_d)
				+ 2;
			if (ft_detect_breach(deep_copy, i, j, game) == true)
			{
				result = true;
				break ;
			}
		}
		if (result == true)
			break ;
	}
	return (result);
}

bool	ft_valid_map_integrity(t_game *game)
{
	bool	result;
	char	**deep_copy;

	result = false;
	ft_copy_map(game);
	deep_copy = game->parsing.map_copy_map;
	result = check_x(game, deep_copy, result);
	ft_clean_up(deep_copy, game->parsing.map_nb_ligne + 2);
	return (result);
}
