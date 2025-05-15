/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:22:08 by dpascal           #+#    #+#             */
/*   Updated: 2024/09/29 23:30:58 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(long value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}

int	add_node(t_stack *stack, int value)
{
	t_node	*new_node;

	new_node = create_node(value);
	if (!new_node)
		return (0);
	new_node->next = stack->top;
	stack->top = new_node;
	stack->size++;
	return (value);
}

int	supp_node(t_stack *stack)
{
	t_node	*save_node;
	int		value;

	if (stack == NULL || stack->top == NULL)
		return (-1);
	save_node = stack->top;
	value = save_node->value;
	stack->top = save_node->next;
	free(save_node);
	stack->size--;
	return (value);
}
