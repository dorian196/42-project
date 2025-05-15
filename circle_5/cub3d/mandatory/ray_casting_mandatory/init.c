/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 01:47:35 by dpascal           #+#    #+#             */
/*   Updated: 2025/05/06 02:50:24 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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

void	ft_init_game(t_game *game)
{
	int	i;
	int	line_len;

	game->map_width = 0;
	game->map_height = game->parsing.map_nb_ligne;
	i = 0;
	while (i < game->map_height)
	{
		line_len = ft_strlen_v2(game->parsing.map_tab_too_d[i]);
		if (line_len > game->map_width)
			game->map_width = line_len;
		i++;
	}
	game->wall_distances = malloc(sizeof(float) * WIDTH);
	if (!game->wall_distances)
		return ;
	game->map = game->parsing.map_tab_too_d;
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "cucube");
	game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->data = mlx_get_data_addr(game->img, &game->bpp, &game->size_line,
			&game->endian);
}

int	ft_load_textures(t_game *game)
{
	game->tex_no.img = mlx_xpm_file_to_image(game->mlx, game->parsing.path_no,
			&game->tex_no.width, &game->tex_no.height);
	if (!game->tex_no.img)
		return (ft_error("🚨 Error: Failed to load North texture\n", game));
	game->tex_no.data = mlx_get_data_addr(game->tex_no.img, &game->tex_no.bpp,
			&game->tex_no.size_line, &game->tex_no.endian);
	game->tex_so.img = mlx_xpm_file_to_image(game->mlx, game->parsing.path_so,
			&game->tex_so.width, &game->tex_so.height);
	if (!game->tex_so.img)
		return (ft_error("🚨 Error: Failed to load South texture\n", game));
	game->tex_so.data = mlx_get_data_addr(game->tex_so.img, &game->tex_so.bpp,
			&game->tex_so.size_line, &game->tex_so.endian);
	game->tex_ea.img = mlx_xpm_file_to_image(game->mlx, game->parsing.path_ea,
			&game->tex_ea.width, &game->tex_ea.height);
	if (!game->tex_ea.img)
		return (ft_error("🚨 Error: Failed to load East texture\n", game));
	game->tex_ea.data = mlx_get_data_addr(game->tex_ea.img, &game->tex_ea.bpp,
			&game->tex_ea.size_line, &game->tex_ea.endian);
	game->tex_we.img = mlx_xpm_file_to_image(game->mlx, game->parsing.path_we,
			&game->tex_we.width, &game->tex_we.height);
	if (!game->tex_we.img)
		return (ft_error("🚨 Error: Failed to load West texture\n", game));
	game->tex_we.data = mlx_get_data_addr(game->tex_we.img, &game->tex_we.bpp,
			&game->tex_we.size_line, &game->tex_we.endian);
	return (0);
}

void	ft_init_player(t_player *player, int x, int y, char orient)
{
	player->x = x * BLOCK + BLOCK / 2;
	player->y = y * BLOCK + BLOCK / 2;
	if (orient == 'N')
		player->angle = 3 * PI / 2;
	else if (orient == 'S')
		player->angle = PI / 2;
	else if (orient == 'E')
		player->angle = 0;
	else if (orient == 'W')
		player->angle = PI;
	else
		player->angle = PI / 2;
	player->key_down = false;
	player->key_up = false;
	player->key_left = false;
	player->key_right = false;
	player->left_fov = false;
	player->right_fov = false;
}
