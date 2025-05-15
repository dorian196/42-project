/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo_3_and_5.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 00:06:42 by dpascal           #+#    #+#             */
/*   Updated: 2024/09/30 01:00:35 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sort_3(t_stack *a, int count)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	while (1)
	{
		first = a->top;
		second = first->next;
		third = second->next;
		if (first->value < second->value && second->value < third->value)
			break ;
		if (first->value > second->value)
			count += sa(a);
		else if (second->value > third->value)
			count += rra(a);
		else if (first->value > third->value)
			count += ra(a);
	}
	return (count);
}

int	ft_sort_5_bis(t_stack *a, t_stack *b, int min_value)
{
	int	count;

	count = 0;
	while (b->top)
	{
		if (b->top->value == min_value)
			count += pa(a, b);
		else
		{
			count += pa(a, b);
			count += ra(a);
		}
	}
	return (count);
}

int	ft_sort_5(t_stack *a, t_stack *b, int count)
{
	int	min_value;
	int	max_value;

	min_value = ft_find_min(a);
	max_value = ft_find_max(a);
	while (a->size > 3)
	{
		if (a->top->value == min_value || a->top->value == max_value)
			count += pb(a, b);
		else
			count += ra(a);
	}
	count = ft_sort_3(a, count);
	count += ft_sort_5_bis(a, b, min_value);
	while (a->top->value != min_value)
		count += rra(a);
	return (count);
}
