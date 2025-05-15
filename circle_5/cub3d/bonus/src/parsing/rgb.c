/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thobenel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 04:10:10 by thobenel          #+#    #+#             */
/*   Updated: 2025/05/09 04:10:11 by thobenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

/* Parse les valeurs RGB à partir d'une chaîne */
bool	ft_parse_rgb(char *str, int *values, t_game *game,
		const char *error_msg)
{
	char	**rgb_values;

	rgb_values = ft_split(str, ',');
	if (!rgb_values || !rgb_values[0] || !rgb_values[1] || !rgb_values[2])
	{
		if (rgb_values)
			ft_free_rgb_values(rgb_values);
		ft_error(error_msg, game);
		return (false);
	}
	values[0] = ft_atoi(rgb_values[0]);
	values[1] = ft_atoi(rgb_values[1]);
	values[2] = ft_atoi(rgb_values[2]);
	if (!ft_validate_rgb_values(values, game,
			"🚨 Error \n RGB values must be between 0 and 255 \n"))
	{
		ft_free_rgb_values(rgb_values);
		return (false);
	}
	ft_free_rgb_values(rgb_values);
	return (true);
}

/* Parse la couleur du sol (F) */
bool	ft_parse_floor_color(t_game *game, char *map)
{
	if (game->parsing.path_f)
	{
		ft_error("🚨 Error \n Duplicate floor color definition \n", game);
		return (false);
	}
	game->parsing.path_f = ft_strdup_v2(map + 2);
	if (!ft_parse_rgb(game->parsing.path_f, game->parsing.value_f, game,
			"🚨 Error \n Invalid floor color format \n"))
		return (false);
	return (true);
}

/* Parse la couleur du plafond (C) */
bool	ft_parse_ceiling_color(t_game *game, char *map)
{
	if (game->parsing.path_c)
	{
		ft_error("🚨 Error \n Duplicate ceiling color definition \n", game);
		return (false);
	}
	game->parsing.path_c = ft_strdup_v2(map + 2);
	if (!ft_parse_rgb(game->parsing.path_c, game->parsing.value_c, game,
			"🚨 Error \n Invalid ceiling color format \n"))
		return (false);
	return (true);
}

/* Fonction principale pour parser les couleurs */
void	ft_colors_parse(t_game *game, char *map)
{
	if (ft_strncmp(map, "F ", 2) == 0)
	{
		ft_parse_floor_color(game, map);
	}
	else if (ft_strncmp(map, "C ", 2) == 0)
	{
		ft_parse_ceiling_color(game, map);
	}
	else
	{
		ft_error("🚨 Error \n Invalid color identifier \n", game);
	}
}

int	ft_is_color_line(char *line)
{
	return (ft_strncmp(line, "F ", 2) == 0 || ft_strncmp(line, "C ", 2) == 0);
}
