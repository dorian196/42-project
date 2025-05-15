/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_value.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:22:11 by dpascal           #+#    #+#             */
/*   Updated: 2024/11/18 08:52:46 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_value(long value, int error, t_node *head)
{
	if (value > 2147483647 || value < -2147483648 || error == 1)
	{
		write(1, "Error\n", 6);
		ft_free_node(head);
		return (0);
	}
	return (1);
}

t_node	*ft_add_node_value(t_node *current, t_node **head, long value)
{
	t_node	*new;

	new = create_node(value);
	if (!new)
	{
		write(1, "Error\n", 6);
		ft_free_node(*head);
		return (0);
	}
	if (!*head)
		*head = new;
	else
		current->next = new;
	return (new);
}

t_node	*ft_value(char **result, int count)
{
	int		i;
	int		error;
	t_node	*head;
	t_node	*current;
	long	value;

	i = 0;
	error = 0;
	head = NULL;
	current = NULL;
	while (i < count)
	{
		value = ft_atoi(result[i], &error);
		if (!ft_check_value(value, error, head))
			return (NULL);
		current = ft_add_node_value(current, &head, value);
		i++;
	}
	return (head);
}
