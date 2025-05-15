/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ceilling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thobenel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 05:17:35 by thobenel          #+#    #+#             */
/*   Updated: 2025/05/09 05:17:36 by thobenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

// Dessine le plafond et le sol (quand aucun mur n'est touché)
/*
	Enregistrer une distance tres grande pour le Z-buffer
	game->wall_distances[column] = 1e30;
*/
void	ft_draw_ceiling_floor(int column, t_ray *ray, t_game *game)
{
	int	y;

	ray->ceiling_color = (game->parsing.value_c[0] << 16)
		| (game->parsing.value_c[1] << 8) | game->parsing.value_c[2];
	ray->floor_color = (game->parsing.value_f[0] << 16)
		| (game->parsing.value_f[1] << 8) | game->parsing.value_f[2];
	y = -1;
	while (++y < HEIGHT / 2)
		ft_put_pixel(column, y, ray->ceiling_color, game);
	y = HEIGHT;
	while (y < HEIGHT)
	{
		ft_put_pixel(column, y, ray->floor_color, game);
		y++;
	}
	game->wall_distances[column] = 1e30;
}
