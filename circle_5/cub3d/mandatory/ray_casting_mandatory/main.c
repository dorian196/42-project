/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:28:59 by thobenel          #+#    #+#             */
/*   Updated: 2025/05/06 03:32:08 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	main(int ac, char **av)
{
	t_game	game;

	ft_bzero(&game, sizeof(game));
	ft_init(&game);
	if (ft_parsing(ac, av, &game) != 0)
		return (1);
	ft_init_game(&game);
	if (ft_load_textures(&game) != 0)
		return (1);
	ft_init_player(&game.player, game.parsing.map_pos_y, game.parsing.map_pos_x,
		game.parsing.map_player);
	mlx_hook(game.win, 2, 1L << 0, ft_key_press, &game);
	mlx_hook(game.win, 3, 1L << 1, ft_key_release, &game);
	mlx_hook(game.win, 17, 0, ft_exit_game, &game);
	mlx_expose_hook(game.win, ft_draw_loop, &game);
	mlx_loop_hook(game.mlx, ft_draw_loop, &game);
	mlx_loop(game.mlx);
	ft_exit_game(&game);
	return (0);
}
