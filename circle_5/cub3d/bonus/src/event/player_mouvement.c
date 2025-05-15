/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mouvement.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thobenel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 01:48:08 by thobenel          #+#    #+#             */
/*   Updated: 2025/05/09 01:48:15 by thobenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

/**
 * Initialise le joueur a la position (x,y) avec l'orientation specifiee
 * Centrer le joueur dans la case
 * @param player Structure du joueur a initialiser
 * @param x Position X initiale (en cases)
 * @param y Position Y initiale (en cases)
 * @param orient Caractere d'orientation ('N', 'S', 'E', 'W')
 */
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

// Debug ⬆️⬆️⬆️
// printf("[DEBUG] ft_init_player : pos_x = %f\n", player->x);
// printf("[DEBUG] ft_init_player : pos_y = %f\n", player->y);

/**
 * Calcule le déplacement du joueur en fonction des touches appuyées
 * @param joueur Structure du joueur
 * @param dx Pointeur vers le déplacement horizontal (modifié)
 * @param dy Pointeur vers le déplacement vertical (modifié)
 */
void	ft_calculate_mouvement(t_player *joueur, float *dx, float *dy)
{
	float	speed;

	speed = 8.0f;
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
