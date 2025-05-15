/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 02:29:48 by dpascal           #+#    #+#             */
/*   Updated: 2025/05/06 02:30:17 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_texture_no_so(t_game *game, char *map)
{
	if (ft_strncmp(map, "NO ", 3) == 0)
	{
		if (game->parsing.path_no)
			return (1);
		game->parsing.path_no = ft_strdup_v2(map + 3);
		if (!game->parsing.path_no)
			ft_error("🚨 Error \n Memory allocation failed\n", game);
		return (1);
	}
	else if (ft_strncmp(map, "SO ", 3) == 0)
	{
		if (game->parsing.path_so)
			return (1);
		game->parsing.path_so = ft_strdup_v2(map + 3);
		if (!game->parsing.path_so)
			ft_error("🚨 Error \n Memory allocation failed\n", game);
		return (1);
	}
	return (0);
}

int	ft_texture_we_ea(t_game *game, char *map)
{
	if (ft_strncmp(map, "WE ", 3) == 0)
	{
		if (game->parsing.path_we)
			return (1);
		game->parsing.path_we = ft_strdup_v2(map + 3);
		if (!game->parsing.path_we)
			ft_error("🚨 Error \n Memory allocation failed\n", game);
		return (1);
	}
	else if (ft_strncmp(map, "EA ", 3) == 0)
	{
		if (game->parsing.path_ea)
			return (1);
		game->parsing.path_ea = ft_strdup_v2(map + 3);
		if (!game->parsing.path_ea)
			ft_error("🚨 Error \n Memory allocation failed\n", game);
		return (1);
	}
	return (0);
}

int	ft_texture_parse(t_game *game, char *map)
{
	if (ft_texture_no_so(game, map) != 0)
		return (1);
	else if (ft_texture_we_ea(game, map) != 0)
		return (1);
	return (0);
}
