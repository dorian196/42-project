/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 10:55:32 by dpascal           #+#    #+#             */
/*   Updated: 2024/09/10 13:24:18 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_stack(t_stack *Free)
{
	t_node	*current;
	t_node	*temp;

	current = Free->top;
	while (current)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	free(Free);
}

void	ft_free_node(t_node *Free)
{
	t_node	*temp;

	while (Free)
	{
		temp = Free;
		Free = Free->next;
		free(temp);
	}
}

void	ft_free_char(char **Free)
{
	int	i;

	i = 0;
	while (Free[i])
	{
		free(Free[i]);
		i++;
	}
	free(Free);
}

void	ft_free_char_and_node(char **Char, t_node *Node)
{
	ft_free_char(Char);
	ft_free_node(Node);
}

void	ft_free_all(char **Char, t_node *Node, t_stack *Stack)
{
	ft_free_char(Char);
	ft_free_node(Node);
	ft_free_stack(Stack);
}
