/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thobenel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 04:09:46 by thobenel          #+#    #+#             */
/*   Updated: 2025/05/09 04:09:47 by thobenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

bool	ft_handle_param(t_game *game, char *cpy)
{
	if (ft_texture_parse(game, cpy) != 0)
		return (true);
	if (ft_is_color_line(cpy))
	{
		ft_colors_parse(game, cpy);
		return (true);
	}
	ft_error("🚨 Error\nInvalid element\n", game);
	return (false);
}

void	ft_parse_param(t_game *game)
{
	int		count;
	int		i;
	char	*cpy;

	count = 0;
	i = 0;
	while (count < 6 && game->parsing.map_copy_file[i])
	{
		cpy = back_slash_n_less(game->parsing.map_copy_file[i]);
		if (ft_strlen(cpy) > 0 && ft_handle_param(game, cpy))
			count++;
		free(cpy);
		i++;
	}
	if (count != 6)
		ft_error("🚨 Error\nMissing something in file\n", game);
	game->parsing.map_start_ligne = i;
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

void	ft_display_map_debug(char **map, int nb_line)
{
	int	i;

	(void)nb_line;
	printf("----- Debug: Map -----\n");
	i = -1;
	while (map[++i] != NULL)
	{
		printf("%s\n", map[i]);
	}
	printf("----------------------\n");
}

int	ft_parsing(int ac, char **av, t_game *game)
{
	if (ac != 2)
		ft_error("🚨 Error \nWrong number of arguments\n", game);
	if (ft_check_file(av, game))
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
