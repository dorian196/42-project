/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 21:30:17 by dpascal           #+#    #+#             */
/*   Updated: 2024/11/24 10:27:26 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_count(char *s, char c)
{
	int	i;
	int	count;
	int	onoff;

	i = 0;
	count = 0;
	onoff = 0;
	while (s[i])
	{
		if (s[i] != c && onoff == 0)
		{
			count++;
			onoff = 1;
		}
		else
			onoff = 0;
		i++;
	}
	return (count);
}

int	ft_len(char *str, char c, int i)
{
	int	j;

	j = 0;
	while (str[i] && str[i] != c)
	{
		i++;
		j++;
	}
	return (j);
}

char	**ft_split_init(t_pipex *pipex, char *str, char c, char **tab)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	start = 0;
	while (str[i] && start < ft_count(str, c))
	{
		while (str[i] == c)
			i++;
		tab[start] = malloc(sizeof(char) * ft_len(str, c, i) + 1);
		if (!tab[start])
			free_error(pipex, "Erreur allocation ft_split(tab[start])", 0);
		j = 0;
		while (str[i] && str[i] != c)
			tab[start][j++] = str[i++];
		tab[start][j] = '\0';
		start++;
	}
	tab[start] = NULL;
	return (tab);
}

char	**ft_split(t_pipex *pipex, char *str, char c)
{
	char	**tab;
	int		words;

	words = ft_count(str, c);
	tab = malloc(sizeof(char *) * (words + 1));
	if (!tab)
		free_error(pipex, "Erreur allocation ft_split(tab)", 0);
	tab = ft_split_init(pipex, str, c, tab);
	return (tab);
}
