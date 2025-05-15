/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:31:22 by thobenel          #+#    #+#             */
/*   Updated: 2025/05/06 02:40:21 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_parse_map(t_game *game)
{
	int		i;
	int		j;
	int		map_lines;
	char	*trimmed;

	i = game->parsing.map_start_ligne;
	map_lines = 0;
	while (game->parsing.map_copy_file[i + map_lines])
		map_lines++;
	game->parsing.map_tab_too_d = malloc(sizeof(char *) * (map_lines + 1));
	if (!game->parsing.map_tab_too_d)
		ft_error("🚨 Error \n malloc failed of the map 2D\n", game);
	j = 0;
	while (game->parsing.map_copy_file[++i])
	{
		trimmed = back_slash_n_less(game->parsing.map_copy_file[i]);
		if (ft_strlen_v2(trimmed) > 0)
			game->parsing.map_tab_too_d[j++] = trimmed;
		else
			free(trimmed);
	}
	game->parsing.map_tab_too_d[j] = NULL;
	game->parsing.map_nb_ligne = j;
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
				&& tmp != 'S' && tmp != 'E' && tmp != 'W' && tmp != '\n')
			{
				ft_error("🚨 Error \n invalid carac in map\n", game);
			}
		}
	}
}

void	ft_get_positions(t_game *game, int i, int j, int *count)
{
	char	tmp;

	if (!game || !game->parsing.map_tab_too_d
		|| !game->parsing.map_tab_too_d[i])
		return ;
	if (j >= ft_strlen(game->parsing.map_tab_too_d[i]))
		return ;
	tmp = game->parsing.map_tab_too_d[i][j];
	if (tmp == 'N' || tmp == 'S' || tmp == 'E' || tmp == 'W')
	{
		game->parsing.map_player = tmp;
		game->parsing.map_pos_x = i;
		game->parsing.map_pos_y = j;
		(*count)++;
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

int	ft_parsing(int ac, char **av, t_game *game)
{
	if (ac != 2)
		ft_error("🚨 Error \nWrong number of arguments\n", game);
	if (ft_check_file(game, av))
	{
		ft_cp_file(game, av);
		ft_parse_param(game);
		ft_parse_map(game);
		ft_check_pl_placement(game);
		if (ft_valid_map_integrity(game) == true)
			ft_error("🚨 Error \n map not closed\n", game);
	}
	return (0);
}
