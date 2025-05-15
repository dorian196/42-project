/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors_textures.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 02:33:02 by dpascal           #+#    #+#             */
/*   Updated: 2025/05/06 02:52:37 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_is_color_line(char *line)
{
	return (ft_strncmp(line, "F ", 2) == 0 || ft_strncmp(line, "C ", 2) == 0);
}

int	ft_parse_param_while(t_game *game, int count, char *cpy, int *i)
{
	while (count < 6 && game->parsing.map_copy_file[*i])
	{
		cpy = back_slash_n_less(game->parsing.map_copy_file[*i]);
		if (strlen(cpy) == 0)
			(*i)++;
		else
		{
			if (ft_texture_parse(game, cpy) != 0)
				count++;
			else if (ft_is_color_line(cpy))
			{
				ft_colors_parse(game, cpy);
				count++;
			}
			else
				ft_error("🚨 Error \n Invalid element\n", game);
			(*i)++;
		}
		free(cpy);
	}
	return (count);
}

void	ft_parse_param(t_game *game)
{
	int		count;
	int		i;
	char	*cpy;

	i = 0;
	count = 0;
	cpy = NULL;
	count = ft_parse_param_while(game, count, cpy, &i);
	if (count != 6)
		ft_error("🚨 Error \n Missing something in file\n", game);
	game->parsing.map_start_ligne = i;
}
