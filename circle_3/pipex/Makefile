# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/04 12:43:38 by dpascal           #+#    #+#              #
#    Updated: 2024/11/27 08:50:32 by dpascal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc -g
CFLAGS = -Wall -Wextra -Werror
SRCS = core/pipex.c \
core/cmd.c \
core/utils.c \
core/free.c \
core/split.c \
core/process.c \
core/init.c \
core/init_var.c \
core/utils_error.c \


OBJS = $(SRCS:.c=.o)

NAME = pipex

FT_PRINTF = ./libft/printf/libftprintf.a

INCLUDES =  -I./libft/printf -I./include

MLX_FLAGS = -L./libft/printf -lftprintf

all: $(NAME)

$(NAME): $(OBJS) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS) $(MLX_FLAGS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all