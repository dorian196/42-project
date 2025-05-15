/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 13:12:08 by dpascal           #+#    #+#             */
/*   Updated: 2024/11/20 13:46:47 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_struct(t_data *data)
{
	data->map.map = NULL;
	data->map.file = NULL;
	data->map.width = 0;
	data->map.height = 0;
	data->map.line_length = 0;
	data->map.visited = 0;
	data->map.y = 0;
	data->map.free_exit = 0;
	data->game.width = 0;
	data->game.height = 0;
	data->game.x = 0;
	data->game.y = 0;
	data->img.width = 0;
	data->img.height = 0;
	data->count.collectable = 0;
	data->count.collectable2 = 0;
	data->count.collectable_count = 0;
	data->count.exit = 0;
	data->count.count_move = 0;
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->img_ptr = NULL;
	data->width = 0;
	data->height = 0;
}
