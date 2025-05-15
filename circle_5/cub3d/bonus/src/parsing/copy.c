/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thobenel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 04:32:14 by thobenel          #+#    #+#             */
/*   Updated: 2025/05/09 04:32:15 by thobenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

/*
Copie une ligne de la map original vers la carte copiee
i = index de la ligne dans la map original
max_len = longuer max de la carte
*/
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

/*
cree une copie de la map avec une bordure (PADDING)
verifie si elle est fermee
*/
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
	ft_fill_boundary_row(game->parsing.map_copy_map, 0, max_len + 2, game);
	i = -1;
	while (++i < game->parsing.map_nb_ligne)
		ft_transfer_ligne_with_border(game, i, max_len);
	ft_reserve_memory_for_line(game, game->parsing.map_nb_ligne + 1, max_len
		+ 3, "Memory allocation failed for bottom border");
	ft_fill_boundary_row(game->parsing.map_copy_map, game->parsing.map_nb_ligne
		+ 1, max_len + 2, game);
	game->parsing.map_copy_map[game->parsing.map_nb_ligne + 2] = NULL;
}

int	check_fill(char **map, int i, int j, int max_rows)
{
	if (i < 0 || j < 0 || i > max_rows + 1 || map[i] == NULL
		|| j >= ft_strlen(map[i]))
		return (0);
	if (map[i][j] == 'X')
		return (1);
	if (map[i][j] != '0' && map[i][j] != 'D' && map[i][j] != 'R')
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

void	ft_read_map_copy(t_game *game, int fd)
{
	int		i;
	char	*line;

	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		game->parsing.map_copy_file[i] = ft_strdup_v2(line);
		if (!game->parsing.map_copy_file[i])
		{
			ft_error("🚨 Error\nDup failed\n", game);
			free(line);
			return ;
		}
		free(line);
		line = get_next_line(fd);
		i++;
	}
	game->parsing.map_copy_file[i] = NULL;
}

void	ft_cp_file(t_game *game, char **file)
{
	int	fd;

	fd = open(file[1], O_RDONLY);
	if (fd < 0)
	{
		ft_error("🚨 Error\nCan't open the file\n", game);
		return ;
	}
	ft_count_len(game, file[1]);
	game->parsing.map_copy_file = malloc(
			sizeof(char *) * (game->parsing.map_nb_ligne + 2));
	if (!game->parsing.map_copy_file)
	{
		ft_error("🚨 Error\nfailed memory check\n", game);
		close(fd);
		return ;
	}
	ft_read_map_copy(game, fd);
	close(fd);
}
