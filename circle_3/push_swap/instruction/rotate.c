/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 09:32:01 by dpascal           #+#    #+#             */
/*   Updated: 2024/09/30 00:16:31 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(t_stack *a)
{
	t_node	*first;
	t_node	*temp;

	if (!a || !a->top || !a->top->next)
		return ;
	first = a->top;
	temp = a->top;
	while (temp->next)
		temp = temp->next;
	a->top = first->next;
	first->next = NULL;
	temp->next = first;
}

int	ra(t_stack *a)
{
	rotate(a);
	printf("ra\n");
	return (1);
}

int	rb(t_stack *b)
{
	rotate(b);
	printf("rb\n");
	return (1);
}

int	rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	printf("rr\n");
	return (1);
}
