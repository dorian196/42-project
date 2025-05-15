/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_monster.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thobenel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 03:59:48 by thobenel          #+#    #+#             */
/*   Updated: 2025/05/09 04:00:08 by thobenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

/*
	1) Calculer la distance
	2) Mettre a jour l'animation
	3) Vérifier si le joueur est détecté
		A) Le joueur est a portée, activer la poursuite
		B) Direction normalisée vers le joueur
		C) Ajuster la vitesse en fonction de la distance 
			(plus rapide quand il est proche)
		D) Nouvelle position en direction du joueur
		E) Vérifier les collisions et déplacer le monstre
		F) Si le monstre attrape le joueur GAME OVER
	4) SINON
		A) Le joueur est hors de portée
		B) Mouvement de patrouille déterministe au lieu d'aléatoire 
			(un modèle de mouvement en "huit")
		C) Incrémenter l'angle de patrouille
		D) Changer de direction après un certain temps
		E) Calculer la nouvelle position basée sur un mouvement circulaire
		F) Vérifier les collisions
*/
void	ft_calculate_monster_distance(t_monster *m, t_player *player)
{
	float	dy;
	float	dx;

	dx = player->x - m->x;
	dy = player->y - m->y;
	m->distance = sqrt(dx * dx + dy * dy);
}

void	ft_update_monster_animation(t_monster *m)
{
	m->frame_timer++;
	if (m->frame_timer >= m->frame_speed)
	{
		m->current_frame = (m->current_frame + 1) % MONSTER_FRAMES;
		m->frame_timer = 0;
	}
}

void	ft_calculate_monster_chase_position(t_monster *m, t_player *player,
		float *new_x, float *new_y)
{
	float	dir_x;
	float	dir_y;
	float	adjusted_speed;

	dir_x = (player->x - m->x) / m->distance;
	dir_y = (player->y - m->y) / m->distance;
	adjusted_speed = m->speed * (1 + (1 - m->distance / m->detection_range));
	*new_x = m->x + dir_x * adjusted_speed;
	*new_y = m->y + dir_y * adjusted_speed;
}

void	ft_stop_monster_m(t_game *game, t_monster *m)
{
	if (game->timer.is_running)
	{
		printf("Timer arrêté! Distance: %f\n", m->distance);
		game->timer.current_time = time(NULL);
		game->timer.elapsed_time = difftime(game->timer.current_time,
				game->timer.start_time);
		if (game->timer.best_time == 0
			|| game->timer.elapsed_time > game->timer.best_time)
			game->timer.best_time = game->timer.elapsed_time;
		game->timer.is_running = false;
	}
	m->is_active = false;
	ft_monster_patrol(m, game);
}

void	ft_update_monster(t_game *game)
{
	t_player	*player;

	player = &game->player;
	ft_calculate_monster_distance(&game->monster, player);
	ft_update_monster_animation(&game->monster);
	if (game->monster.distance < game->monster.detection_range)
	{
		if (!game->timer.is_running)
		{
			game->timer.start_time = time(NULL);
			game->timer.is_running = true;
		}
		game->monster.is_active = true;
		ft_monster_chase_player(&game->monster, player, game);
	}
	else
		ft_stop_monster_m(game, &game->monster);
	if (game->timer.is_running)
	{
		game->timer.current_time = time(NULL);
		game->timer.elapsed_time = difftime(game->timer.current_time,
				game->timer.start_time);
	}
}
