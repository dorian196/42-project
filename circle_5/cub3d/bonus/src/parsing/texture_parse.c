/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thobenel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 04:10:19 by thobenel          #+#    #+#             */
/*   Updated: 2025/05/09 04:10:20 by thobenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

char	*back_slash_n_less(char *str)
{
	char	*new_str;
	int		len;
	int		i;

	if (!str)
		return (NULL);
	len = 0;
	while (str[len] && str[len] != '\n')
		len++;
	new_str = malloc(sizeof(char) * len + 1);
	if (!new_str)
		return (NULL);
	i = -1;
	while (++i < len)
	{
		new_str[i] = str[i];
	}
	new_str[i] = '\0';
	return (new_str);
}

/*
	Trouve la longueur max de la ligne de la map
	Ici on a besoin de connaitre la ligne la plus longue avant le padding
	pour pouvoir allouer par la suite et enfin ajouter les caracteres tout atour

*/
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

int	ft_parse_dir_texture(t_game *game, char *map, const char *tag, char **dst)
{
	int	len;

	len = ft_strlen_v2(tag);
	if (ft_strncmp(map, tag, len) == 0)
	{
		if (*dst)
			return (1);
		*dst = ft_strdup_v2(map + len);
		if (!*dst)
			ft_error("🚨 Error\nMemory allocation failed\n", game);
		return (1);
	}
	return (0);
}

int	ft_texture_parse(t_game *game, char *map)
{
	if (ft_parse_dir_texture(game, map, "NO ", &game->parsing.path_no))
		return (1);
	if (ft_parse_dir_texture(game, map, "SO ", &game->parsing.path_so))
		return (1);
	if (ft_parse_dir_texture(game, map, "WE ", &game->parsing.path_we))
		return (1);
	if (ft_parse_dir_texture(game, map, "EA ", &game->parsing.path_ea))
		return (1);
	return (0);
}
