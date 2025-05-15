/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thobenel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 05:21:00 by thobenel          #+#    #+#             */
/*   Updated: 2025/05/09 05:21:01 by thobenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

int	ft_error(const char *str, t_game *game)
{
	printf("%s", str);
	ft_exit_game(game);
	return (EXIT_FAILURE);
}

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

void	ft_clean_up(char **deep_copy, int map_nb_ligne)
{
	int	i;

	i = -1;
	while (++i < map_nb_ligne)
		free(deep_copy[i]);
	free(deep_copy);
}

int	ft_count_len_one(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}
