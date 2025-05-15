/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thobenel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 01:47:13 by thobenel          #+#    #+#             */
/*   Updated: 2025/05/09 01:47:16 by thobenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

bool	ft_should_draw_warning(t_game *game)
{
	return (game->monster.is_active
		&& game->monster.distance < game->monster.detection_range);
}

/* Dessine les bordures d'avertissement à l'écran */
void	ft_draw_warning_borders(t_game *game, float intensity)
{
	int	border_size;
	int	red_color;
	int	i;
	int	j;

	border_size = (int)(5 * intensity);
	red_color = 0xFF0000;
	i = -1;
	while (++i < border_size)
	{
		j = -1;
		while (++j < WIDTH)
		{
			ft_put_pixel(j, i, red_color, game);
			ft_put_pixel(j, HEIGHT - 1 - i, red_color, game);
		}
		j = -1;
		while (++j < HEIGHT)
		{
			ft_put_pixel(i, j, red_color, game);
			ft_put_pixel(WIDTH - 1 - i, j, red_color, game);
		}
	}
}

void	ft_draw_detected_warning(t_game *game)
{
	float	intensity;

	if (ft_should_draw_warning(game))
	{
		intensity = 3.0f - (game->monster.distance
				/ game->monster.detection_range);
		ft_draw_warning_borders(game, intensity);
	}
}

void	ft_draw_minimap_monster(t_game *game, int ox, int oy)
{
	int	px;
	int	py;
	int	i;
	int	j;

	px = (int)(game->monster.x / BLOCK * MINI_MAP_SCALE) + ox;
	py = (int)(game->monster.y / BLOCK * MINI_MAP_SCALE) + oy;
	i = -2;
	while (i <= 2)
	{
		j = -2;
		while (j <= 2)
		{
			ft_put_pixel(px + j, py + i, 0x0000FF, game);
			j++;
		}
		i++;
	}
}

void	ft_draw_minimap(t_game *game)
{
	int	ox;
	int	oy;

	ox = WIDTH - (game->map_width * MINI_MAP_SCALE) - MINI_MAP_MARG;
	oy = MINI_MAP_MARG;
	ft_draw_minimap_background(game, ox, oy);
	ft_draw_minimap_tiles(game, ox, oy);
	ft_draw_minimap_player(game, ox, oy);
	ft_draw_minimap_directions(game, ox, oy);
}
