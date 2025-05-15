/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thobenel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 04:10:06 by thobenel          #+#    #+#             */
/*   Updated: 2025/05/09 04:10:07 by thobenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

void	ft_count_len(t_game *game, char *file)
{
	int		fd;
	char	*ligne;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_error("🚨 Error \nCan't open the file\n", game);
		return ;
	}
	ligne = get_next_line(fd);
	while (ligne != NULL)
	{
		game->parsing.map_nb_ligne++;
		free(ligne);
		ligne = get_next_line(fd);
	}
	if (close(fd) < 0)
		ft_error("🚨 Warning: Error closing file\n", game);
}

/*
	Cree la bordure (inferieur ou bien superieur) 
		(Principale fonction du PADDING)
	map_copy_map = copy de la map
	ligne_index = ligne a remplir
	max_len = longeur max de la map
*/
void	ft_fill_boundary_row(char **map_copy_map, int ligne_index, int max_len,
		t_game *game)
{
	int	j;

	if (!map_copy_map || !map_copy_map[ligne_index])
		ft_error("🚨 Error \n Invalid map pointer in fill_boundary_row\n", game);
	j = -1;
	while (++j < max_len)
		map_copy_map[ligne_index][j] = 'X';
	map_copy_map[ligne_index][max_len] = '\0';
}

/*
	🚨	alloue la memoire pour une ligne de la carte copiee
	map_copy_map = tableau de la carte copiee
	line_index = index de la ligne a allouer
	size = taille a allouer
	error_msg = message erreur en cas echec
*/

void	ft_reserve_memory_for_line(t_game *game, int line_index, int size,
		const char *error_msg)
{
	game->parsing.map_copy_map[line_index] = malloc(sizeof(char) * size);
	if (!game->parsing.map_copy_map[line_index])
		ft_error(error_msg, game);
}

void	ft_parse_map(t_game *game)
{
	int		i;
	int		j;
	int		map_lines;
	char	*trimmed;

	i = game->parsing.map_start_ligne;
	map_lines = 0;
	while (game->parsing.map_copy_file[i + map_lines])
		map_lines++;
	game->parsing.map_tab_too_d = malloc(sizeof(char *) * (map_lines + 1));
	if (!game->parsing.map_tab_too_d)
		ft_error("🚨 Error \n malloc failed of the map 2D\n", game);
	j = 0;
	while (game->parsing.map_copy_file[++i])
	{
		trimmed = back_slash_n_less(game->parsing.map_copy_file[i]);
		if (ft_strlen(trimmed) > 0)
			game->parsing.map_tab_too_d[j++] = trimmed;
		else
			free(trimmed);
	}
	game->parsing.map_tab_too_d[j] = NULL;
	game->parsing.map_nb_ligne = j;
}
