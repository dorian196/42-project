/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:21:48 by thobenel          #+#    #+#             */
/*   Updated: 2025/05/06 02:39:24 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_count_len_one(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

void	ft_count_len(t_game *game, char *file)
{
	int		fd;
	char	*ligne;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_error("🚨 Error \nCan't open the file\n", game);
		return ;
	}
	ligne = get_next_line(fd);
	while (ligne != NULL)
	{
		game->parsing.map_nb_ligne++;
		free(ligne);
		ligne = get_next_line(fd);
	}
	if (close(fd) < 0)
		ft_error("🚨 Warning: Error closing file\n", game);
}

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
