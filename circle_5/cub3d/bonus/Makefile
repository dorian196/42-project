# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thobenel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/21 14:29:12 by thobenel          #+#    #+#              #
#    Updated: 2025/04/21 14:29:13 by thobenel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = cub3D_bonus
CC          = gcc -g
RM          = rm -f

LIBFT_DIR   = ../libft_2.0
MLX_DIR     = ../mandatory/minilibx-linux

INCLUDES    = -I include -I$(LIBFT_DIR) -I$(MLX_DIR) -fsanitize=leak	
CFLAGS      = -Wall -Wextra -Werror $(INCLUDES)


SRCS = \
		src/ray_casting/draw_projection.c \
		src/ray_casting/raycast_engine.c \
		src/ray_casting/raycast_rayon.c \
		src/ray_casting/wall_casting.c \
		src/event/camera.c \
		src/event/mouse.c \
		src/event/timer_drawing_one.c \
		src/event/event_utils.c \
		src/event/minimap.c \
		src/event/minimap_util_one.c \
		src/event/minimap_util_two.c \
		src/event/minimap_util_three.c \
		src/event/player_mouvement.c \
		src/event/timer_utils.c \
		src/event/keyboard.c \
		src/event/timer.c \
		src/event/window_event.c \
		src/monster/action_monster.c \
		src/monster/draw_monster.c \
		src/monster/patrol_monster.c \
		src/monster/render_monster.c \
		src/parsing/copy.c \
		src/parsing/main_parsing.c \
		src/parsing/padding.c \
		src/parsing/parse_map.c \
		src/parsing/rgb.c \
		src/parsing/rgb_utils.c \
		src/parsing/texture_parse.c \
		src/parsing/valid_map.c \
		src/texture/draw_ceilling.c \
		src/texture/draw_texture.c \
		src/texture/draw_wall.c \
		src/texture/monster_texture.c \
		src/texture/texture_door.c \
		src/utils/free_main.c \
		src/utils/free_utils.c \
		src/utils/image_utils.c \
		src/utils/map_utils.c \
		src/utils/pixel_utils.c \
		src/utils/utils.c \
		src/main/main.c \
		src/main/init.c \

OBJS = $(SRCS:.c=.o)

LDFLAGS = \
	-L$(LIBFT_DIR) -lft \
	-L$(MLX_DIR)   -lmlx \
	-lX11 -lXext -lm

all: $(LIBFT_DIR)/libft.a $(MLX_DIR)/libmlx.a $(NAME)

$(LIBFT_DIR)/libft.a:
	@$(MAKE) -C $(LIBFT_DIR)

$(MLX_DIR)/libmlx.a:
	@$(MAKE) -C $(MLX_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Cleaning objects..."
	$(RM) $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	@echo "Cleaning executables..."
	$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(MLX_DIR)/libmlx.a

re: fclean all

.PHONY: all clean fclean re