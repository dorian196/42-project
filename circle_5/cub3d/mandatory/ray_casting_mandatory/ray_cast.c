/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:29:02 by thobenel          #+#    #+#             */
/*   Updated: 2025/05/06 03:16:46 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_calculate_mouvement(t_player *joueur, float *dx, float *dy)
{
	float	speed;

	speed = 5.0f;
	if (joueur->key_up)
	{
		*dx += cos(joueur->angle) * speed;
		*dy += sin(joueur->angle) * speed;
	}
	if (joueur->key_down)
	{
		*dx -= cos(joueur->angle) * speed;
		*dy -= sin(joueur->angle) * speed;
	}
	if (joueur->key_right)
	{
		*dx += cos(joueur->angle + PI / 2) * speed;
		*dy += sin(joueur->angle + PI / 2) * speed;
	}
	if (joueur->key_left)
	{
		*dx -= cos(joueur->angle + PI / 2) * speed;
		*dy -= sin(joueur->angle + PI / 2) * speed;
	}
}

void	ft_update_angle(t_player *joueur)
{
	if (joueur->left_fov)
		joueur->angle -= 0.03f;
	if (joueur->right_fov)
		joueur->angle += 0.03f;
}

int	ft_move_player(t_game *game)
{
	t_player	*joueur;
	float		dx;
	float		dy;

	dy = 0.0f;
	dx = 0.0f;
	joueur = &game->player;
	ft_calculate_mouvement(joueur, &dx, &dy);
	if (!ft_touch_col(joueur->x + dx, joueur->y, game))
		joueur->x += dx;
	if (!ft_touch_col(joueur->x, joueur->y + dy, game))
		joueur->y += dy;
	ft_update_angle(joueur);
	ft_polish_angle(joueur);
	return (0);
}
