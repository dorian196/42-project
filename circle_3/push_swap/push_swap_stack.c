/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 16:01:15 by dorian            #+#    #+#             */
/*   Updated: 2024/09/30 18:44:55 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_reverse_stack(t_stack *reverse)
{
	t_stack	*a;
	t_node	*current;

	a = init_stack();
	if (!a)
		return (NULL);
	current = reverse->top;
	while (current)
	{
		add_node(a, current->value);
		current = current->next;
	}
	ft_free_stack(reverse);
	return (a);
}

t_stack	*ft_stack_a(t_node *tab)
{
	t_stack	*a;
	t_node	*current;

	a = init_stack();
	if (!a)
		return (NULL);
	current = tab;
	while (current)
	{
		add_node(a, current->value);
		current = current->next;
	}
	a = ft_reverse_stack(a);
	return (a);
}

t_stack	*ft_stack_b(void)
{
	t_stack	*b;

	b = (t_stack *)malloc(sizeof(t_stack));
	if (!b)
		return (NULL);
	b->top = NULL;
	b->size = 0;
	return (b);
}
