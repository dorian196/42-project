/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 09:31:52 by dpascal           #+#    #+#             */
/*   Updated: 2024/09/30 00:16:05 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse(t_stack *a)
{
	t_node	*prev;
	t_node	*last;

	if (!a || !a->top || !a->top->next)
		return ;
	prev = NULL;
	last = a->top;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	if (prev)
		prev->next = NULL;
	last->next = a->top;
	a->top = last;
}

int	rra(t_stack *a)
{
	reverse(a);
	printf("rra\n");
	return (1);
}

int	rrb(t_stack *b)
{
	reverse(b);
	printf("rrb\n");
	return (1);
}

int	rrr(t_stack *a, t_stack *b)
{
	reverse(a);
	reverse(b);
	printf("rrr\n");
	return (1);
}
