/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thobenel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 05:17:45 by thobenel          #+#    #+#             */
/*   Updated: 2025/05/09 05:17:46 by thobenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

/* charge une seule texture de monstre */
static int	ft_load_single_monster_texture(t_game *game, int idx)
{
	char	path[256];

	sprintf(path, "%s%d%s", MONSTER_PATH, idx + 1, MONSTER_EXT);
	game->sprite_textures[idx].img = mlx_xpm_file_to_image(game->mlx,
			path, &game->sprite_textures[idx].width,
			&game->sprite_textures[idx].height);
	if (!game->sprite_textures[idx].img)
		return (ft_error("🚨 Error: Failed to load sprite texture\n",
				game));
	game->sprite_textures[idx].data = mlx_get_data_addr(
			game->sprite_textures[idx].img, &game->sprite_textures[idx].bpp,
			&game->sprite_textures[idx].size_line,
			&game->sprite_textures[idx].endian);
	return (0);
}

/* alloue et charge toutes les textures de monstres */
int	ft_load_monster_textures(t_game *game)
{
	int	i;

	game->sprite_count = MONSTER_FRAMES;
	game->sprite_textures = malloc(
			sizeof(t_textures) * game->sprite_count);
	if (!game->sprite_textures)
		return (ft_error(
				"🚨 Error: Failed to allocate memory for sprite textures\n",
				game));
	i = 0;
	while (i < MONSTER_FRAMES)
	{
		if (ft_load_single_monster_texture(game, i))
			return (1);
		i++;
	}
	return (0);
}
