/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thobenel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 05:20:55 by thobenel          #+#    #+#             */
/*   Updated: 2025/05/09 05:20:57 by thobenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

// notre propre fonction pour mettre un pixel
void	ft_put_pixel(int x, int y, int colors, t_game *game)
{
	int	index;

	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	index = y * game->size_line + x * game->bpp / 8;
	game->data[index] = colors & 0xFF;
	game->data[index + 1] = (colors >> 8) & 0xFF;
	game->data[index + 2] = (colors >> 16) & 0xFF;
}

void	ft_draw_square(int x, int y, int colors, t_game *game)
{
	int	i;

	i = -1;
	while (i++ < BLOCK)
		ft_put_pixel(x + i, y, colors, game);
	i = -1;
	while (i++ < BLOCK)
		ft_put_pixel(x, y + i, colors, game);
	i = -1;
	while (i++ < BLOCK)
		ft_put_pixel(x + BLOCK, y + i, colors, game);
	i = -1;
	while (i++ < BLOCK)
		ft_put_pixel(x + i, y + BLOCK, colors, game);
}
