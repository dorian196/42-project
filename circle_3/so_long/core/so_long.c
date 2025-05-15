/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 14:00:25 by dpascal           #+#    #+#             */
/*   Updated: 2024/11/20 13:44:17 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// execute export DISPLAY=localhost:0

int	check_arg(int argc)
{
	if (argc != 2)
	{
		ft_printf("Error : so_long accept only one argument\n");
		exit (0);
	}
	return (0);
}

void	create_window(t_data *data)
{
	screen_size(data, &data->game, &data->map);
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->game.width,
			data->game.height, "Game");
	if (data->win_ptr == NULL)
	{
		ft_printf("Error : mlx_new_window\n");
		exit_window(data);
	}
}

void	init_data(t_data *data, char *argv[])
{
	data->map.file = argv[1];
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
	{
		ft_printf("Error : mlx_init\n");
		exit(0);
	}
}

int	main(int argc, char *argv[])
{
	t_data	data;

	init_struct(&data);
	check_arg(argc);
	init_data(&data, argv);
	load_map(&data, &data.map, &data.count, data.map.file);
	check_map_condition(&data, &data.map);
	reach_path(&data);
	create_window(&data);
	data.img_ptr = mlx_new_image(data.mlx_ptr, data.game.width,
			data.game.height);
	if (data.img_ptr == NULL)
	{
		ft_printf("Error mlx_new_image\n");
		exit_window(&data);
		return (1);
	}
	mlx_key_hook(data.win_ptr, handle_keypress, &data);
	mlx_hook(data.win_ptr, 17, 0, close_window, &data);
	render_map(&data, &data.game);
	mlx_loop(data.mlx_ptr);
	return (0);
}
