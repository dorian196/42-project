/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_radix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:05:27 by dpascal           #+#    #+#             */
/*   Updated: 2024/11/12 06:58:37 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_sort(t_stack *a)
{
	t_node	*current;

	if (!a || !a->top)
		return (1);
	current = a->top;
	while (current && current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

int	ft_radix_2(t_stack *a, t_stack *b, int bits, int count)
{
	int	size;
	int	i;
	int	j;
	int	num;

	i = 0;
	while (i < bits)
	{
		size = a->size;
		j = 0;
		while (j++ < size)
		{
			num = a->top->value;
			if ((num >> i) & 1)
				count += ra(a);
			else
				count += pb(a, b);
		}
		while (b->top)
			count += pa(a, b);
		i++;
	}
	return (count);
}

void	ft_radix(t_stack *a, t_stack *b)
{
	int	bits;
	int	count;

	bits = ft_count_bits(ft_find_max(a));
	if (!a || !b)
		return ;
	if (ft_check_sort(a) == 1)
		return ;
	count = 0;
	if (a->size == 3)
	{
		count = ft_sort_3(a, count);
		return ;
	}
	if (a->size == 5)
	{
		count = ft_sort_5(a, b, count);
		return ;
	}
	count += ft_radix_2(a, b, bits, count);
}
