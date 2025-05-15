/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_projection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thobenel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 05:14:17 by thobenel          #+#    #+#             */
/*   Updated: 2025/05/09 05:14:18 by thobenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

// Calcule la distance perpendiculaire et le point d'impact
/*
	Calculer la distance perpendiculaire (evite l'effet fisheye)
	Application de la correction fisheye amelioree
	Convertir en pixels
*/
void	ft_calc_distance(t_ray *ray, t_player *player, float angle_diff)
{
	if (ray->side == 0)
		ray->dist = (ray->map_x - player->x / BLOCK + (1 - ray->step_x) / 2)
			/ ray->cos_angle;
	else
		ray->dist = (ray->map_y - player->y / BLOCK + (1 - ray->step_y) / 2)
			/ ray->sin_angle;
	ray->dist *= cos(angle_diff);
	ray->dist *= BLOCK;
}

// Fonction 3: Calcule les paramètres de rendu
void	ft_prepare_wall_rendering(t_ray *ray, t_game *game, float angle_diff,
		int column)
{
	ft_calc_distance(ray, &game->player, angle_diff);
	game->wall_distances[column] = ray->dist;
	ft_select_texture_one(ray, &game->player, game, angle_diff);
	if (ray->textures && ray->textures->data)
		ft_calc_wall_params(ray, game);
}

// Fonction principale de lancer de rayon
/*
	1) Normaliser l'angle_diff entre -PI et PI
	2) Lancer le rayon jusqu'a un mur
	3) Récupérer la tile touchée - AVEC VÉRIFICATION
	4) Calculer la distance et point d'impact
	5) Enregistrer la distance pour le Z-buffer (utilisé par les sprites)
	6) Sélectionner la texture et calculer les coordonnées
	7) Vérifier que la texture est valide
	8) Calculer les paramètres du mur
	9) Dessiner la colonne complete
*/
void	ft_draw_line(t_player *player, t_game *game, float ray_angle,
		int column)
{
	t_ray	ray;
	float	angle_diff;

	ft_prepare_ray_angle(&angle_diff, &ray, player, ray_angle);
	if (!ft_process_ray_collision(&ray, game))
		return (ft_draw_ceiling_floor(column, &ray, game));
	ft_prepare_wall_rendering(&ray, game, angle_diff, column);
	if (!ray.textures || !ray.textures->data)
	{
		ft_draw_ceiling_floor(column, &ray, game);
		return ;
	}
	ft_render_column(&ray, column, game);
}

int	ft_draw_loop(void *param)
{
	t_game	*game;
	float	angle;
	float	step;
	int		x;

	game = (t_game *)param;
	ft_move_player(game);
	ft_update_monster(game);
	ft_clear_ceiling(game);
	ft_clear_floor(game);
	step = (PI / 3.0f) / (float)WIDTH;
	angle = game->player.angle - (PI / 6.0f);
	x = -1;
	while (++x < WIDTH)
	{
		ft_draw_line(&game->player, game, angle, x);
		angle += step;
	}
	ft_draw_monster_main(game);
	ft_draw_minimap(game);
	ft_draw_timer(game);
	ft_draw_detected_warning(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	ft_draw_timer_text(game);
	return (0);
}
