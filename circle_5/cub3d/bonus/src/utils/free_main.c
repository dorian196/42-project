/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thobenel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 05:20:38 by thobenel          #+#    #+#             */
/*   Updated: 2025/05/09 05:20:39 by thobenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

void	ft_free_resourcess(t_game *game)
{
	if (game->parsing.path_ea)
	{
		free(game->parsing.path_ea);
		game->parsing.path_ea = NULL;
	}
	if (game->parsing.path_no)
	{
		free(game->parsing.path_no);
		game->parsing.path_no = NULL;
	}
	if (game->parsing.path_so)
	{
		free(game->parsing.path_so);
		game->parsing.path_so = NULL;
	}
}

/* Libère les chemins des textures et les ressources du raycast */
void	ft_free_resources(t_game *game)
{
	if (game->wall_distances)
	{
		free(game->wall_distances);
		game->wall_distances = NULL;
	}
	if (game->parsing.path_c)
	{
		free(game->parsing.path_c);
		game->parsing.path_c = NULL;
	}
	if (game->parsing.path_f)
	{
		free(game->parsing.path_f);
		game->parsing.path_f = NULL;
	}
	if (game->parsing.path_we)
	{
		free(game->parsing.path_we);
		game->parsing.path_we = NULL;
	}
	ft_free_resourcess(game);
}

void	ft_free_map_data_two(t_game *game)
{
	if (game->parsing.map_tab_too_d)
	{
		free_tab(game->parsing.map_tab_too_d);
		game->parsing.map_tab_too_d = NULL;
	}
	if (game->map)
	{
		free_tab(game->map);
		game->map = NULL;
	}
}

void	ft_free_map_data(t_game *game)
{
	if (game->parsing.map_tab_too_d && game->parsing.map_tab_too_d == game->map)
	{
		free_tab(game->map);
		game->map = NULL;
		game->parsing.map_tab_too_d = NULL;
	}
	else
		ft_free_map_data_two(game);
	if (game->parsing.map_copy_file)
	{
		free_tab(game->parsing.map_copy_file);
		game->parsing.map_copy_file = NULL;
	}
	if (game->parsing.map_copy_map)
	{
		free_tab(game->parsing.map_copy_map);
		game->parsing.map_copy_map = NULL;
	}
}

void	free_var(t_game *game)
{
	ft_free_wall_textures(game);
	ft_free_special_textures(game);
	ft_free_resources(game);
	ft_free_map_data(game);
}
