/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 09:32:08 by dpascal           #+#    #+#             */
/*   Updated: 2024/09/30 00:16:49 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_stack *a)
{
	t_node	*first;
	t_node	*second;

	if (!a || !a->top || !a->top->next)
		return ;
	first = a->top;
	second = a->top->next;
	first->next = second->next;
	second->next = first;
	a->top = second;
}

int	sa(t_stack *a)
{
	swap(a);
	printf("sa\n");
	return (1);
}

int	sb(t_stack *b)
{
	swap(b);
	printf("sb\n");
	return (1);
}

int	ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	printf("ss\n");
	return (1);
}
