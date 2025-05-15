/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_split.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 09:31:29 by dpascal           #+#    #+#             */
/*   Updated: 2024/09/30 18:12:49 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_split2(int word_count, char **tab, const char *s, char c)
{
	int	start;
	int	i;
	int	j;

	start = 0;
	i = 0;
	while (start < word_count)
	{
		while (s[i] == c)
			i++;
		j = 0;
		tab[start] = malloc(sizeof(char) * ft_len(s, c, i) + 1);
		if (!tab[start])
			return ;
		while (s[i] && s[i] != c)
			tab[start][j++] = s[i++];
		tab[start][j] = '\0';
		start++;
	}
	tab[start] = 0;
}

char	**ft_split(const char *s, char c)
{
	char	**tab;
	int		word_count;

	word_count = ft_count(s, c);
	tab = malloc(sizeof(char *) * (word_count + 1));
	if (!tab)
		return (0);
	ft_split2(word_count, tab, s, c);
	return (tab);
}

char	**ft_result_argv(int count, char **result, char **argv, int argc)
{
	int		i;
	int		j;
	int		k;
	char	**temp;

	result = malloc(sizeof(char *) * (count + 1));
	if (!result)
	{
		write(1, "Error\n", 6);
		ft_free_char(result);
		return (0);
	}
	i = 1;
	k = 0;
	while (i < argc)
	{
		temp = ft_split(argv[i], ' ');
		j = 0;
		while (temp[j])
			result[k++] = temp[j++];
		i++;
		free(temp);
	}
	result[k] = 0;
	return (result);
}
