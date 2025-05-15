/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 09:12:37 by dpascal           #+#    #+#             */
/*   Updated: 2024/11/18 08:59:31 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
void	ft_print_stack(t_stack *a)
{
	t_node	*current;

	current = a->top;
	while (current)
	{
		printf("%ld\n", current->value);
		current = current->next;
	}
}
*/

t_stack	*ft_stack_a_and_error(t_stack *a, int argc, char **argv)
{
	char	**result;
	t_node	*tab;
	int		count;

	result = NULL;
	tab = NULL;
	a = NULL;
	count = ft_count_words(0, argc, argv);
	result = ft_result_argv(count, result, argv, argc);
	if (!ft_error(result, count, &tab))
		return (NULL);
	a = ft_stack_a(tab);
	if (!a)
		return (NULL);
	ft_free_char_and_node(result, tab);
	return (a);
}

void	ft_algo_and_print(t_stack *a, int *index_tab)
{
	t_stack	*b;

	b = ft_stack_b();
	ft_normalize_bits(a);
	ft_radix(a, b);
	ft_free_stack(b);
	ft_index_to_value(a, index_tab);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	int		*index_tab;

	a = NULL;
	a = ft_stack_a_and_error(a, argc, argv);
	if (!a)
		return (0);
	index_tab = ft_create_tab_index(a);
	ft_value_to_index(a, index_tab);
	ft_algo_and_print(a, index_tab);
	free(index_tab);
	ft_free_stack(a);
	return (0);
}
