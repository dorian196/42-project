/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer_drawing_one.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thobenel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 01:48:27 by thobenel          #+#    #+#             */
/*   Updated: 2025/05/09 01:48:28 by thobenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

/* Dessine le fond du timer */
void	ft_draw_timer_background(t_game *game, int ox, int oy, int width)
{
	int	x;
	int	y;

	y = -1;
	while (++y < 30)
	{
		x = -1;
		while (++x < width)
			ft_put_pixel(ox + x, oy + y, 0x222222, game);
	}
}

void	ft_draw_progress_bar(t_game *game, int ox, int oy, float progress)
{
	int	progress_width;
	int	timer_color;
	int	y;
	int	x;
	int	color_value;

	progress_width = (int)(progress * 312);
	color_value = (int)(progress * 255);
	timer_color = (color_value << 16) | ((255 - color_value) << 8) | 0;
	y = 4;
	while (++y < 25)
	{
		x = -1;
		while (++x < progress_width)
			ft_put_pixel(ox + x, oy + y, timer_color, game);
	}
}

void	ft_draw_timer_border(t_game *game, int ox, int oy, int width)
{
	int	x;
	int	y;

	x = -1;
	while (++x < width)
	{
		ft_put_pixel(ox + x, oy, 0xFFFFFF, game);
		ft_put_pixel(ox + x, oy + 29, 0xFFFFFF, game);
	}
	y = -1;
	while (++y < 30)
	{
		ft_put_pixel(ox, oy + y, 0xFFFFFF, game);
		ft_put_pixel(ox + width - 1, oy + y, 0xFFFFFF, game);
	}
}

void	ft_draw_timer(t_game *game)
{
	int		ox;
	int		oy;
	int		timer_width;
	float	progress;

	ft_calculate_timer_position(game, &ox, &oy, &timer_width);
	ft_draw_timer_background(game, ox, oy, timer_width);
	ft_update_timer(&game->timer);
	progress = ft_calculate_timer_progress(game);
	ft_draw_progress_bar(game, ox, oy, progress);
	ft_draw_timer_border(game, ox, oy, timer_width);
}

void	ft_draw_timer_text(t_game *game)
{
	int		ox;
	int		oy;
	char	timer_text[100];
	int		text_color;

	text_color = 0xFFFFFF;
	ox = WIDTH - (game->map_width * MINI_MAP_SCALE) - MINI_MAP_MARG;
	oy = MINI_MAP_MARG + (game->map_height * MINI_MAP_SCALE) + 10;
	if (game->monster.is_active)
		sprintf(timer_text, "Poursuite: %.1f s", game->timer.elapsed_time);
	else if (game->timer.best_time > 0)
		sprintf(timer_text, "Record: %.1ld s", game->timer.best_time);
	else
		sprintf(timer_text, "Pas de record");
	mlx_string_put(game->mlx, game->win, ox + 10, oy + 20, text_color,
		timer_text);
}
