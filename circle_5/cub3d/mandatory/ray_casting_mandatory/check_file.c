/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 02:35:52 by dpascal           #+#    #+#             */
/*   Updated: 2025/05/06 02:36:22 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_check_file(t_game *game, char **arg)
{
	int		fd;
	size_t	len;

	len = ft_strlen_v2(arg[1]);
	if (arg[1][len - 4] != '.' && arg[1][len - 3] != 'c' && arg[1][len
		- 2] != 'u' && arg[1][len - 2] != 'b')
		ft_error("🚨 Error \nWrong name of the file\n", game);
	fd = open(arg[1], O_RDONLY);
	if (fd < 0)
		return (ft_error("🚨 Error \nCan't open the file\n", game), close(fd),
			0);
	close(fd);
	return (1);
}

void	ft_cp_file_while(t_game *game, int fd)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		game->parsing.map_copy_file[i] = ft_strdup_v2(line);
		if (!game->parsing.map_copy_file[i])
			ft_error("🚨 Error \n Dup failed\n", game);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	game->parsing.map_copy_file[i] = NULL;
	close(fd);
}

void	ft_cp_file(t_game *game, char **file)
{
	int	fd;

	fd = open(file[1], O_RDONLY);
	if (fd < 0)
	{
		ft_error("🚨 Error \nCan't open the file\n", game);
		close(fd);
	}
	ft_count_len(game, file[1]);
	game->parsing.map_copy_file = malloc(sizeof(char *)
			* (game->parsing.map_nb_ligne + 2));
	if (!game->parsing.map_copy_file)
		ft_error("🚨 Error \nfailed memory check\n", game);
	ft_cp_file_while(game, fd);
}
