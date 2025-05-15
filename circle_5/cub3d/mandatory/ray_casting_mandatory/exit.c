/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 01:45:28 by dpascal           #+#    #+#             */
/*   Updated: 2025/05/06 01:46:16 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_error(const char *str, t_game *game)
{
	printf("%s", str);
	ft_exit_game(game);
	exit(EXIT_FAILURE);
	return (EXIT_FAILURE);
}

void	ft_clean_up(char **deep_copy, int map_nb_ligne)
{
	int	i;

	i = -1;
	while (++i < map_nb_ligne)
		free(deep_copy[i]);
	free(deep_copy);
}

void	free_tab(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_var(t_game *game)
{
	if (game->parsing.path_c)
		free(game->parsing.path_c);
	if (game->parsing.path_f)
		free(game->parsing.path_f);
	if (game->parsing.path_we)
		free(game->parsing.path_we);
	if (game->parsing.path_ea)
		free(game->parsing.path_ea);
	if (game->parsing.path_no)
		free(game->parsing.path_no);
	if (game->parsing.path_so)
		free(game->parsing.path_so);
	if (game->parsing.map_tab_too_d)
		free_tab(game->parsing.map_tab_too_d);
	if (game->parsing.map_copy_file)
		free_tab(game->parsing.map_copy_file);
}

int	ft_exit_game(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (game->img)
		mlx_destroy_image(game->mlx, game->img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free_var(game);
	exit(EXIT_SUCCESS);
	return (0);
}
