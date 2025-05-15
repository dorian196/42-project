# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/20 12:00:08 by dpascal           #+#    #+#              #
#    Updated: 2024/09/30 17:32:54 by dpascal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc -g
CFLAGS = -Wall -Wextra -Werror

SRCS = push_swap.c instruction/push.c instruction/rev_rotate.c \
instruction/rotate.c instruction/swap.c push_swap_radix.c push_swap_atoi.c \
push_swap_convert.c push_swap_free.c push_swap_parsing.c push_swap_split.c \
push_swap_stack.c push_swap_struct.c push_swap_utils.c \
push_swap_value.c push_swap_bits.c push_swap_algo_3_and_5.c \

OBJS = $(SRCS:.c=.o)
NAME = push_swap

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
