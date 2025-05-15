/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thobenel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 05:17:39 by thobenel          #+#    #+#             */
/*   Updated: 2025/05/09 05:17:40 by thobenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

// Selectionne la texture appropriee et calcule la coordonnee x de la texture
/*
	1) Point d'impact exact - stocker avec plus de precision
	2) Definir la texture a utiliser et calculer wall_x
	3) Calculer la position exacte de l'impact sur le mur
	4) Normaliser wall_x entre 0 et 1
	5) Convertir wall_x en coordonnee de texture
	6) S'assurer que tex_x est dans les limites
	7) Correction de l'inversion si necessaire
*/
void	ft_select_texture_two(t_ray *ray)
{
	double	tex_x_precise;

	tex_x_precise = ray->wall_x * ray->textures->width;
	ray->tex_x = (int)tex_x_precise;
	if (ray->tex_x < 0)
		ray->tex_x = 0;
	if (ray->tex_x >= ray->textures->width)
		ray->tex_x = ray->textures->width - 1;
	if (ray->side == 0 && ray->cos_angle > 0)
		ray->tex_x = ray->textures->width - ray->tex_x - 1;
	if (ray->side == 1 && ray->sin_angle < 0)
		ray->tex_x = ray->textures->width - ray->tex_x - 1;
}

void	ft_select_texture_one(t_ray *ray, t_player *player, t_game *game,
		float angle_diff)
{
	float	wall_hit_x;
	float	wall_hit_y;

	wall_hit_x = player->x + ray->cos_angle * (ray->dist / cos(angle_diff));
	wall_hit_y = player->y + ray->sin_angle * (ray->dist / cos(angle_diff));
	if (ray->side == 0)
	{
		if (ray->step_x > 0)
			ray->textures = &game->tex_ea;
		else
			ray->textures = &game->tex_we;
		ray->wall_x = wall_hit_y / BLOCK;
	}
	else
	{
		if (ray->step_y > 0)
			ray->textures = &game->tex_so;
		else
			ray->textures = &game->tex_no;
		ray->wall_x = wall_hit_x / BLOCK;
	}
	ray->wall_x = ray->wall_x - floor(ray->wall_x);
	ft_select_texture_two(ray);
}

int	ft_load_single_texture(t_textures *texture, char *path,
		const char *error_msg, t_game *game)
{
	texture->img = mlx_xpm_file_to_image(game->mlx, path, &texture->width,
			&texture->height);
	if (!texture->img)
		return (ft_error(error_msg, game));
	texture->data = mlx_get_data_addr(texture->img, &texture->bpp,
			&texture->size_line, &texture->endian);
	return (0);
}

int	ft_load_wall_textures(t_game *game)
{
	if (ft_load_single_texture(&game->tex_no, game->parsing.path_no,
			"🚨 Error: Failed to load North texture\n", game) != 0)
		return (1);
	if (ft_load_single_texture(&game->tex_so, game->parsing.path_so,
			"🚨 Error: Failed to load South texture\n", game) != 0)
		return (1);
	if (ft_load_single_texture(&game->tex_ea, game->parsing.path_ea,
			"🚨 Error: Failed to load East texture\n", game) != 0)
		return (1);
	if (ft_load_single_texture(&game->tex_we, game->parsing.path_we,
			"🚨 Error: Failed to load West texture\n", game) != 0)
		return (1);
	return (0);
}

/* Fonction principale qui charge toutes les textures */
void	ft_load_textures(t_game *game)
{
	if (ft_load_wall_textures(game) != 0)
		ft_exit_game(game);
	if (ft_load_monster_textures(game) != 0)
		ft_exit_game(game);
}
