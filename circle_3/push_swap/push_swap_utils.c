/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:51:14 by dpascal           #+#    #+#             */
/*   Updated: 2024/09/09 20:46:47 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_count(const char *s, char c)
{
	int	count;
	int	onoff;
	int	i;

	count = 0;
	onoff = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			if (onoff == 0)
			{
				count++;
				onoff = 1;
			}
		}
		else
			onoff = 0;
		i++;
	}
	return (count);
}

int	ft_len(const char *s, char c, int i)
{
	int	j;

	j = 0;
	while (s[i] && s[i] != c)
	{
		i++;
		j++;
	}
	return (j);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_count_words(int count, int argc, char **argv)
{
	int		i;
	int		j;
	char	**temp;

	i = 1;
	j = 0;
	while (i < argc)
	{
		temp = ft_split(argv[i], ' ');
		j = 0;
		while (temp[j])
		{
			count++;
			j++;
		}
		ft_free_char(temp);
		i++;
	}
	return (count);
}
