/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thobenel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 03:59:25 by thobenel          #+#    #+#             */
/*   Updated: 2025/05/09 03:59:27 by thobenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

void	ft_init_game(t_game *game)
{
	int	i;
	int	line_len;

	game->map_width = 0;
	game->map_height = game->parsing.map_nb_ligne;
	i = -1;
	while (++i < game->map_height)
	{
		line_len = ft_strlen(game->parsing.map_tab_too_d[i]);
		if (line_len > game->map_width)
			game->map_width = line_len;
	}
	game->wall_distances = malloc(sizeof(float) * WIDTH);
	if (!game->wall_distances)
		ft_exit_game(&game);
	game->map = game->parsing.map_tab_too_d;
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "cucube");
	game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->data = mlx_get_data_addr(game->img, &game->bpp, &game->size_line,
			&game->endian);
}

// Placer le monstre a une position sur la carte où il y a un espace libre
void	ft_init_monster(t_game *game)
{
	int	start_x;
	int	start_y;

	start_x = 3;
	start_y = 3;
	while (game->map[start_y][start_x] != '0')
	{
		start_x = (start_x + 1) % game->map_width;
		if (start_x == 0)
			start_y = (start_y + 1) % game->map_height;
	}
	game->monster.x = start_x * BLOCK + BLOCK / 2;
	game->monster.y = start_y * BLOCK + BLOCK / 2;
	game->monster.current_frame = 0;
	game->monster.frame_timer = 0;
	game->monster.frame_speed = 8;
	game->monster.speed = 7.0f;
	game->monster.detection_range = 50 * BLOCK;
	game->monster.is_active = true;
}

//      Initialisation des chemins vers les textures
void	ft_init(t_game *game)
{
	game->parsing.path_no = NULL;
	game->parsing.path_so = NULL;
	game->parsing.path_ea = NULL;
	game->parsing.path_we = NULL;
	game->parsing.value_f[0] = -1;
	game->parsing.value_f[1] = -1;
	game->parsing.value_f[2] = -1;
	game->parsing.value_c[0] = -1;
	game->parsing.value_c[1] = -1;
	game->parsing.value_c[2] = -1;
	game->parsing.map_tab_too_d = NULL;
	game->parsing.map_copy_file = NULL;
	game->parsing.map_copy_map = NULL;
	game->parsing.map_player = '\0';
	game->parsing.map_pos_x = 0;
	game->parsing.map_pos_y = 0;
	game->parsing.map_player_count = 0;
	game->parsing.map_nb_ligne = 0;
	game->parsing.map_nb_ligne_str = 0;
}
