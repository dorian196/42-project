/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thobenel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 04:10:23 by thobenel          #+#    #+#             */
/*   Updated: 2025/05/09 04:10:24 by thobenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

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
			game->height_closed = game->parsing.map_nb_ligne + 2;
			game->width_closed = \
				ft_find_longest_line(game->parsing.map_tab_too_d) + 2;
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
	int		i;
	int		j;
	bool	result;
	char	**deep_copy;

	result = false;
	ft_copy_map(game);
	deep_copy = game->parsing.map_copy_map;
	i = -1;
	while (deep_copy[++i])
	{
		j = -1;
		while (deep_copy[i][++j])
		{
			if (deep_copy[i][j] == ' ')
				flood_fill(deep_copy, i, j, game->parsing.map_nb_ligne + 2);
		}
	}
	result = check_x(game, deep_copy, result);
	ft_clean_up(deep_copy, game->parsing.map_nb_ligne + 2);
	game->parsing.map_copy_map = NULL;
	return (result);
}

int	ft_check_file(char **arg, t_game *game)
{
	int		fd;
	size_t	len;

	len = ft_strlen(arg[1]);
	if (arg[1][len - 4] != '.' && arg[1][len - 3] != 'c' && arg[1][len
		- 2] != 'u' && arg[1][len - 2] != 'b')
		ft_error("🚨 Error \nWrong name of the file\n", game);
	fd = open(arg[1], O_RDONLY);
	if (fd < 0)
		return (ft_error("🚨 Error \nCan't open the file\n", game), close(fd),
			0);
	close(fd);
	return (1);
}

void	ft_char_map(t_game *game)
{
	int		x;
	int		y;
	char	tmp;

	if (!game || !game->parsing.map_tab_too_d)
		ft_error("🚨 Error \n Invalid map data in ft_char_map\n", game);
	x = -1;
	while (game->parsing.map_tab_too_d[++x])
	{
		y = -1;
		while (game->parsing.map_tab_too_d[x][++y])
		{
			tmp = game->parsing.map_tab_too_d[x][y];
			if (tmp != '1' && tmp != '0' && tmp != ' ' && tmp != 'N'
				&& tmp != 'S' && tmp != 'E' && tmp != 'W' && tmp != 'D'
				&& tmp != 'O' && tmp != '\n')
			{
				printf("🚨 Caractère invalide '%c' \
					trouvé à la position [%d][%d]\n", tmp, x, y);
				ft_error("🚨 Error \n invalid carac in map\n", game);
			}
		}
	}
}

void	ft_check_pl_placement(t_game *game)
{
	int	i;
	int	j;
	int	count;

	if (!game || !game->parsing.map_tab_too_d)
		ft_error("🚨 Error \n Invalid map data\n", game);
	ft_char_map(game);
	count = 0;
	i = -1;
	while (game->parsing.map_tab_too_d[++i])
	{
		j = -1;
		while (game->parsing.map_tab_too_d[i][++j])
			ft_get_positions(game, i, j, &count);
	}
	if (count < 1)
		ft_error("🚨 Error \n no player on the map\n", game);
	else if (count > 1)
		ft_error("🚨 Error \n too many player ont the map\n", game);
}
