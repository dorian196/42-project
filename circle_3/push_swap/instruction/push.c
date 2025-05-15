/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:50:06 by dpascal           #+#    #+#             */
/*   Updated: 2024/09/30 00:27:17 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_stack *a, t_stack *b)
{
	int	value;

	if (!b || !b->top)
		return ;
	value = supp_node(b);
	if (value == -1)
		return ;
	add_node(a, value);
}

int	pa(t_stack *a, t_stack *b)
{
	if (!a || !a->top)
		return (0);
	push(a, b);
	printf("pa\n");
	return (1);
}

int	pb(t_stack *a, t_stack *b)
{
	if (!a || !a->top)
		return (0);
	push(b, a);
	printf("pb\n");
	return (1);
}
