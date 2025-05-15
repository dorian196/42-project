/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:50:29 by dpascal           #+#    #+#             */
/*   Updated: 2024/09/30 16:43:53 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_max(t_stack *a)
{
	t_node	*current;
	int		max;

	current = a->top;
	max = current->value;
	while (current)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	return (max);
}

int	ft_find_min(t_stack *a)
{
	t_node	*current;
	int		min;

	current = a->top;
	min = current->value;
	while (current)
	{
		if (current->value < min)
			min = current->value;
		current = current->next;
	}
	return (min);
}

int	ft_count_bits(int num)
{
	int	bits;

	bits = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num >>= 1;
		bits++;
	}
	return (bits);
}

void	ft_normalize_bits(t_stack *a)
{
	t_node	*current;
	int		num;
	int		max_bits;
	int		aligned;
	int		bit_position;

	max_bits = ft_count_bits(ft_find_max(a));
	current = a->top;
	while (current)
	{
		num = current->value;
		aligned = 0;
		bit_position = 0;
		while (bit_position < max_bits)
		{
			if (num & 1 << bit_position)
				aligned |= 1 << bit_position;
			bit_position++;
		}
		current->value = aligned;
		current = current->next;
	}
}
