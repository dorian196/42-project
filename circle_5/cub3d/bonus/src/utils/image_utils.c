/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thobenel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 05:20:47 by thobenel          #+#    #+#             */
/*   Updated: 2025/05/09 05:20:48 by thobenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

int	ft_load_img(t_game *game)
{
	ft_memset(&game->imgs, 0, sizeof(t_imgs));
	game->imgs.door = mlx_xpm_file_to_image(game->mlx, DOOR, &game->imgs.width,
			&game->imgs.height);
	if (!game->imgs.door)
		return (perror("mlx_xpm_file_to_image"),
			printf("Error: load game->imgs.door\n"), 1);
	game->imgs.door_data = (int *)mlx_get_data_addr(game->imgs.door,
			&game->imgs.bpp, &game->imgs.size_line, &game->imgs.endian);
	return (0);
}
