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

#include "cub.h"

void	ft_draw_ceiling_floor(int column, t_ray *ray, t_game *game)
{
	int	y;

	ray->ceiling_color = (game->parsing.value_c[0] << 16)
		| (game->parsing.value_c[1] << 8) | game->parsing.value_c[2];
	ray->floor_color = (game->parsing.value_f[0] << 16)
		| (game->parsing.value_f[1] << 8) | game->parsing.value_f[2];
	y = -1;
	while (++y < HEIGHT / 2)
		ft_put_pixel(column, y, ray->ceiling_color, game);
	y = HEIGHT;
	while (y < HEIGHT)
	{
		ft_put_pixel(column, y, ray->floor_color, game);
		y++;
	}
	game->wall_distances[column] = 1e30;
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

void	ft_clear_ceiling(t_game *game)
{
	int	x;
	int	y;
	int	color_ceiling;

	if (game->parsing.value_c[0] >= 0 && game->parsing.value_c[1] >= 0
		&& game->parsing.value_c[2] >= 0)
		color_ceiling = (game->parsing.value_c[0] << 16)
			| (game->parsing.value_c[1] << 8)
			| game->parsing.value_c[2];
	y = -1;
	while (++y < HEIGHT / 2)
	{
		x = -1;
		while (++x < WIDTH)
			ft_put_pixel(x, y, color_ceiling, game);
	}
}

void	ft_clear_floor(t_game *game)
{
	int	x;
	int	y;
	int	color_floor;

	if (game->parsing.value_f[0] >= 0 && game->parsing.value_f[1] >= 0
		&& game->parsing.value_f[2] >= 0)
		color_floor = (game->parsing.value_f[0] << 16)
			| (game->parsing.value_f[1] << 8)
			| game->parsing.value_f[2];
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			ft_put_pixel(x, y, color_floor, game);
	}
}

int	ft_draw_loop(void *param)
{
	t_game	*game;
	float	angle;
	float	step;
	int		x;

	game = (t_game *)param;
	ft_move_player(game);
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
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	return (0);
}
