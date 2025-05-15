/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keypress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:48:21 by dpascal           #+#    #+#             */
/*   Updated: 2024/11/20 09:19:47 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	can_move_to(int x, int y, t_data *data)
{
	if (x < 0 || y < 0 || x >= data->map.width || y >= data->map.height)
	{
		ft_printf("Error : Map Overflow\n");
		exit_window(data);
		return (0);
	}
	if (data->map.map[y][x] == '0' || data->map.map[y][x] == 'M'
		|| data->map.map[y][x] == 'D' || data->map.map[y][x] == 'E')
		return (1);
	else
	{
		ft_printf("Error : mouvement impossible\n");
		return (0);
	}
}

int	handle_keypress(int key, t_data *data)
{
	int	move;

	move = 0;
	if (key == KEY_Z && can_move_to(data->game.x, data->game.y - 1, data))
		move = move_player(data, data->game.x,
				data->game.y - 1);
	else if (key == KEY_S && can_move_to(data->game.x, data->game.y + 1, data))
		move = move_player(data, data->game.x,
				data->game.y + 1);
	else if (key == KEY_Q && can_move_to(data->game.x - 1, data->game.y, data))
		move = move_player(data, data->game.x - 1,
				data->game.y);
	else if (key == KEY_D && can_move_to(data->game.x + 1, data->game.y, data))
		move = move_player(data, data->game.x + 1,
				data->game.y);
	else if (key == KEY_ESC)
		exit_window(data);
	if (move == 1)
	{
		data->count.count_move++;
		ft_printf("Move = %d\n", data->count.count_move);
	}
	return (0);
}
