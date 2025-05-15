/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 02:38:05 by dpascal           #+#    #+#             */
/*   Updated: 2025/05/06 02:57:07 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_find_longest_line(char **map_tab_too_d)
{
	int	max_len;
	int	len;
	int	i;

	max_len = 0;
	i = 0;
	while (map_tab_too_d[i] != NULL)
	{
		len = strlen(map_tab_too_d[i]);
		if (len > max_len)
			max_len = len;
		i++;
	}
	return (max_len);
}

void	ft_fill_boundary_row(t_game *game, char **map_copy_map, int ligne_index,
		int max_len)
{
	int	j;

	if (!map_copy_map || !map_copy_map[ligne_index])
		ft_error("🚨 Error \n Invalid map pointer in fill_boundary_row\n", game);
	j = -1;
	while (++j < max_len)
		map_copy_map[ligne_index][j] = 'X';
	map_copy_map[ligne_index][max_len] = '\0';
}

void	ft_reserve_memory_for_line(t_game *game, int line_index, int size,
		const char *error_msg)
{
	game->parsing.map_copy_map[line_index] = malloc(sizeof(char) * size);
	if (!game->parsing.map_copy_map[line_index])
		ft_error(error_msg, game);
}

void	ft_transfer_ligne_with_border(t_game *game, int i, int max_len)
{
	int		j;
	int		target;
	char	current;

	target = i + 1;
	ft_reserve_memory_for_line(game, target, max_len + 3,
		"Memory allocation failed for map line");
	game->parsing.map_copy_map[target][0] = 'X';
	j = 0;
	while (j < max_len)
	{
		if (j < ft_strlen(game->parsing.map_tab_too_d[i]))
		{
			current = game->parsing.map_tab_too_d[i][j];
			if (current == ' ')
				game->parsing.map_copy_map[target][j + 1] = 'R';
			else
				game->parsing.map_copy_map[target][j + 1] = current;
		}
		else
			game->parsing.map_copy_map[target][j + 1] = 'X';
		j++;
	}
	game->parsing.map_copy_map[target][j + 1] = 'X';
	game->parsing.map_copy_map[target][j + 2] = '\0';
}

void	ft_copy_map(t_game *game)
{
	int	max_len;
	int	i;

	game->parsing.map_copy_map = malloc(sizeof(char *)
			* (game->parsing.map_nb_ligne + 3));
	if (!game->parsing.map_copy_map)
		ft_error("🚨 Error \n malloc failed for copy map\n", game);
	max_len = ft_find_longest_line(game->parsing.map_tab_too_d);
	ft_reserve_memory_for_line(game, 0, max_len + 3,
		"Memory allocation failed for top border");
	ft_fill_boundary_row(game, game->parsing.map_copy_map, 0, max_len + 2);
	i = -1;
	while (++i < game->parsing.map_nb_ligne)
		ft_transfer_ligne_with_border(game, i, max_len);
	ft_reserve_memory_for_line(game, game->parsing.map_nb_ligne + 1, max_len
		+ 3, "Memory allocation failed for bottom border");
	ft_fill_boundary_row(game, game->parsing.map_copy_map,
		game->parsing.map_nb_ligne + 1, max_len + 2);
	game->parsing.map_copy_map[game->parsing.map_nb_ligne + 2] = NULL;
}
