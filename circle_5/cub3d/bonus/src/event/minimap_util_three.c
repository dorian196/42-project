/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_util_three.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thobenel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 03:44:36 by thobenel          #+#    #+#             */
/*   Updated: 2025/05/09 03:44:38 by thobenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

int	check_fill2(char **map, int i, int j, int max_rows)
{
	if (i < 0 || j < 0 || i >= max_rows || map[i] == NULL
		|| j >= ft_strlen(map[i]))
		return (1);
	if (map[i][j] == 'X' || map[i][j] == '\0')
		return (1);
	if (map[i][j] != '0' && map[i][j] != 'D' && map[i][j] != 'R'
		&& map[i][j] != ' ')
		return (0);
	map[i][j] = 'V';
	if (check_fill2(map, i + 1, j, max_rows))
		return (1);
	if (check_fill2(map, i - 1, j, max_rows))
		return (1);
	if (check_fill2(map, i, j + 1, max_rows))
		return (1);
	if (check_fill2(map, i, j - 1, max_rows))
		return (1);
	return (0);
}
