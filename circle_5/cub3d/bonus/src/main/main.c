/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thobenel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 03:59:31 by thobenel          #+#    #+#             */
/*   Updated: 2025/05/09 03:59:32 by thobenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

int	main(int ac, char **av)
{
	t_game	game;

	ft_bzero(&game, sizeof(game));
	ft_init(&game);
	if (ft_parsing(ac, av, &game) != 0)
		return (1);
	ft_init_game(&game);
	ft_load_img(&game);
	ft_init_timer(&game.timer);
	ft_load_textures(&game);
	ft_init_player(&game.player, game.parsing.map_pos_y, game.parsing.map_pos_x,
		game.parsing.map_player);
	ft_init_monster(&game);
	mlx_mouse_hide(game.mlx, game.win);
	game.last_mouse_x = WIDTH / 2;
	mlx_mouse_move(game.mlx, game.win, WIDTH / 2, HEIGHT / 2);
	mlx_hook(game.win, 2, 1L << 0, ft_key_press, &game);
	mlx_hook(game.win, 3, 1L << 1, ft_key_release, &game);
	mlx_hook(game.win, 6, 1L << 6, ft_mouse_move, &game);
	mlx_hook(game.win, 17, 0, ft_exit_game, &game);
	mlx_expose_hook(game.win, ft_draw_loop, &game);
	mlx_loop_hook(game.mlx, ft_draw_loop, &game);
	mlx_loop(game.mlx);
	ft_exit_game(&game);
	return (0);
}
