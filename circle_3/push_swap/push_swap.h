/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 09:30:48 by dpascal           #+#    #+#             */
/*   Updated: 2024/09/30 18:44:46 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int					ft_count(const char *s, char c);
int					ft_strlen(const char *s);
int					ft_len(const char *s, char c, int i);
int					ft_count_words(int count, int argc, char **argv);

char				**ft_split(const char *s, char c);
char				**ft_result_argv(int count, char **result, char **argv,
						int argc);

char				**ft_numeric(char **result);

long				ft_atoi(const char *s, int *error);

typedef struct s_node
{
	long			value;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
	int				size;
}					t_stack;

t_node				*tab_list(long *tab, int count);
t_node				*create_node(long value);
t_node				*ft_value(char **result, int count);
t_stack				*init_stack(void);

t_stack				*ft_reverse_stack(t_stack *reverse);
t_stack				*ft_stack_a(t_node *tab);
t_stack				*ft_stack_b(void);
t_stack				*ft_convert_a(t_stack *a, t_node *tab, int *index_tab);
t_stack				*ft_value_to_index(t_stack *a, int *index_tab);

int					add_node(t_stack *stack, int value);
int					supp_node(t_stack *stack);

int					ft_no_repeat_num(t_node *value);
int					ft_error(char **result, int count, t_node **tab);

int					*ft_create_tab_index(t_stack *a);

void				ft_index_to_value(t_stack *a, int *index_tab);
void				ft_radix(t_stack *a, t_stack *b);
void				ft_normalize_bits(t_stack *a);

void				ft_free_char(char **Free);
void				ft_free_node(t_node *Free);
void				ft_free_stack(t_stack *Free);
void				ft_free_char_and_node(char **Char, t_node *Node);
void				ft_free_all(char **Char, t_node *Node, t_stack *Stack);

int					pa(t_stack *a, t_stack *b);
int					pb(t_stack *a, t_stack *b);

int					sa(t_stack *a);
int					sb(t_stack *b);
int					ss(t_stack *a, t_stack *b);

int					ra(t_stack *a);
int					rb(t_stack *b);
int					rr(t_stack *a, t_stack *b);

int					rra(t_stack *a);
int					rrb(t_stack *b);
int					rrr(t_stack *a, t_stack *b);

int					ft_count_bits(int num);
int					ft_find_max(t_stack *a);
int					ft_find_min(t_stack *a);

int					ft_sort_3(t_stack *a, int count);
int					ft_sort_5(t_stack *a, t_stack *b, int count);
int					ft_check_sort(t_stack *a);

#endif
