/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_convert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:03:39 by dpascal           #+#    #+#             */
/*   Updated: 2024/09/30 18:45:17 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(int *index_tab, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (index_tab[j] > index_tab[j + 1])
			{
				temp = index_tab[j];
				index_tab[j] = index_tab[j + 1];
				index_tab[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

int	*ft_create_tab_index(t_stack *a)
{
	t_node	*current;
	int		*index_tab;
	int		size;
	int		i;

	size = a->size;
	index_tab = (int *)malloc(sizeof(int) * size);
	if (!index_tab)
		return (NULL);
	current = a->top;
	i = 0;
	while (current)
	{
		index_tab[i] = current->value;
		current = current->next;
		i++;
	}
	ft_sort(index_tab, size);
	return (index_tab);
}

t_stack	*ft_value_to_index(t_stack *a, int *index_tab)
{
	t_node	*current;
	int		size;
	int		i;

	current = a->top;
	size = a->size;
	while (current)
	{
		i = 0;
		while (i < size)
		{
			if (current->value == index_tab[i])
			{
				current->value = i;
				break ;
			}
			i++;
		}
		current = current->next;
	}
	return (a);
}

void	ft_index_to_value(t_stack *a, int *index_tab)
{
	t_node	*current;

	current = a->top;
	while (current)
	{
		current->value = index_tab[current->value];
		current = current->next;
	}
}

t_stack	*ft_convert_a(t_stack *a, t_node *tab, int *index_tab)
{
	a = ft_stack_a(tab);
	if (!a)
	{
		ft_free_node(tab);
		return (0);
	}
	a = ft_value_to_index(a, index_tab);
	return (a);
}
