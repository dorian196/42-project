/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thobenel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 04:10:14 by thobenel          #+#    #+#             */
/*   Updated: 2025/05/09 04:10:15 by thobenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

/* Vérifie si les valeurs RGB sont valides (entre 0 et 255) */
bool	ft_validate_rgb_values(int *value, t_game *game,
		const char *error_msg)
{
	if (value[0] < 0 || value[0] > 255 || value[1] < 0
		|| value[1] > 255 || value[2] < 0 || value[2] > 255)
	{
		ft_error(error_msg, game);
		return (false);
	}
	return (true);
}

/* Libère la mémoire allouée pour les valeurs RGB */
void	ft_free_rgb_values(char **rgb_values)
{
	int	i;

	i = -1;
	while (rgb_values[++i])
		free(rgb_values[i]);
	free(rgb_values);
}
