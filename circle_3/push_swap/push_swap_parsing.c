/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 20:41:49 by dpascal           #+#    #+#             */
/*   Updated: 2024/11/18 09:42:38 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_numeric(char **result)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (result[i])
	{
		while (result[i][j])
		{
			if ((result[i][j] >= 48 && result[i][j] <= 57) || result[i][j] == 43
				|| result[i][j] == 45)
				j++;
			else
			{
				write(1, "Error\n", 6);
				return (0);
			}
		}
		j = 0;
		i++;
	}
	return (result);
}

int	ft_no_repeat_num(t_node *value)
{
	t_node	*current;
	t_node	*compare;

	current = value;
	while (current != NULL)
	{
		compare = current->next;
		while (compare != NULL)
		{
			if (current->value == compare->value)
			{
				write(1, "Error\n", 6);
				return (0);
			}
			compare = compare->next;
		}
		current = current->next;
	}
	return (1);
}

int	ft_error(char **result, int count, t_node **tab)
{
	int	error;

	error = 0;
	if (ft_numeric(result) == 0)
	{
		error = 1;
		ft_free_char_and_node(result, *tab);
		return (!error);
	}
	*tab = ft_value(result, count);
	if (*tab == NULL)
		error = 1;
	if (error == 0)
	{
		if (ft_no_repeat_num(*tab) == 0)
			error = 1;
	}
	if (error == 1)
		ft_free_char_and_node(result, *tab);
	return (!error);
}
