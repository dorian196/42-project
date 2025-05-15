# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/03 13:58:08 by dpascal           #+#    #+#              #
#    Updated: 2024/11/21 11:43:04 by dpascal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc -g
CFLAGS = -Wall -Wextra -Werror
SRCS = core/so_long.c \
core/load_map.c \
core/move.c \
core/reach_path.c \
core/map_condition.c \
core/free.c \
core/render_map.c \
core/so_long_utils.c \
core/handle_keypress.c \
core/init.c \
libft/get_next_line/get_next_line.c \
libft/get_next_line/get_next_line_utils.c \

OBJS = $(SRCS:.c=.o)

NAME = so_long

FT_PRINTF = ./libft/printf/libftprintf.a

INCLUDES = -I./.mlx -I./libft/get_next_line -I./libft/printf -I./include

MLX_FLAGS = -L./.mlx -lmlx -L/usr/lib/X11 -lXext -lX11 -lbsd -L./libft/printf -lftprintf

all: $(NAME)

$(NAME): $(OBJS) $(FT_PRINTF)
	@make -C ./.mlx
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS) $(MLX_FLAGS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
