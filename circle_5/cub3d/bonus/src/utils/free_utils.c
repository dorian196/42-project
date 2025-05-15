/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thobenel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 05:20:42 by thobenel          #+#    #+#             */
/*   Updated: 2025/05/09 05:20:42 by thobenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_tab(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		if (map[i])
		{
			free(map[i]);
			map[i] = NULL;
		}
		i++;
	}
	free(map);
}

/* Libère les textures des murs */
void	ft_free_wall_textures(t_game *game)
{
	if (game->tex_no.img)
	{
		mlx_destroy_image(game->mlx, game->tex_no.img);
		game->tex_no.img = NULL;
	}
	if (game->tex_so.img)
	{
		mlx_destroy_image(game->mlx, game->tex_so.img);
		game->tex_so.img = NULL;
	}
	if (game->tex_ea.img)
	{
		mlx_destroy_image(game->mlx, game->tex_ea.img);
		game->tex_ea.img = NULL;
	}
	if (game->tex_we.img)
	{
		mlx_destroy_image(game->mlx, game->tex_we.img);
		game->tex_we.img = NULL;
	}
}

/* Libère la texture de la porte et les sprites du monstre */
void	ft_free_special_textures(t_game *game)
{
	int	i;

	if (game->imgs.door)
	{
		mlx_destroy_image(game->mlx, game->imgs.door);
		game->imgs.door = NULL;
	}
	if (game->sprite_textures)
	{
		i = 0;
		while (i < game->sprite_count)
		{
			if (game->sprite_textures[i].img)
			{
				mlx_destroy_image(game->mlx, game->sprite_textures[i].img);
				game->sprite_textures[i].img = NULL;
			}
			i++;
		}
		free(game->sprite_textures);
		game->sprite_textures = NULL;
	}
}
