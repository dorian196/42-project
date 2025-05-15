/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 02:53:18 by dpascal           #+#    #+#             */
/*   Updated: 2025/05/06 03:15:11 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

bool	ft_collision(float x, float y, t_game *game)
{
	int	grid_x;
	int	grid_y;

	grid_x = (int)(x / BLOCK);
	grid_y = (int)(y / BLOCK);
	if (grid_x < 0 || grid_x >= game->map_width || grid_y < 0
		|| grid_y >= game->map_height)
		return (true);
	if (game->map[grid_y] == NULL
		|| grid_x >= (int)ft_strlen_v2(game->map[grid_y]))
		return (true);
	return (game->map[grid_y][grid_x] == '1'
		|| game->map[grid_y][grid_x] == 'D');
}

bool	ft_touch_col(float px, float py, t_game *game)
{
	return (ft_collision(px, py, game));
}

void	ft_render_column(t_ray *ray, int column, t_game *game)
{
	int			y;

	y = 0;
	while (y < ray->start_y)
	{
		ft_put_pixel(column, y, ray->ceiling_color, game);
		y++;
	}
	ft_render_column_use(ray);
	while (ray->y < ray->end_y)
	{
		ft_draw_wall(ray, column, ray->y, game);
		ray->tex_pos += ray->step;
		ray->y++;
	}
}
