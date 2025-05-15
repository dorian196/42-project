/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 02:47:10 by dpascal           #+#    #+#             */
/*   Updated: 2025/05/06 03:38:23 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	check_fill(char **map, int i, int j, int max_rows)
{
	if (i < 0 || j < 0 || i > max_rows + 1 || map[i] == NULL
		|| j >= ft_strlen(map[i]))
		return (0);
	if (map[i][j] == 'X')
		return (1);
	if (map[i][j] != '0' && map[i][j] != 'R')
		return (0);
	map[i][j] = 'V';
	if (check_fill(map, i + 1, j, max_rows))
		return (1);
	if (check_fill(map, i - 1, j, max_rows))
		return (1);
	if (check_fill(map, i, j + 1, max_rows))
		return (1);
	if (check_fill(map, i, j - 1, max_rows))
		return (1);
	return (0);
}

char	**copy_map_padded_while(char **map, char **cpy_map, int i, int j)
{
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		cpy_map[i] = malloc(sizeof(char) * (j + 1));
		j = 0;
		while (map[i][j])
		{
			cpy_map[i][j] = map[i][j];
			j++;
		}
		cpy_map[i][j] = '\0';
		i++;
	}
	cpy_map[i] = NULL;
	return (cpy_map);
}

char	**copy_map_padded(t_game *game, char **map)
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
		ft_error("Error: Allocation failed", game);
	i = 0;
	return (copy_map_padded_while(map, cpy_map, i, j));
}
