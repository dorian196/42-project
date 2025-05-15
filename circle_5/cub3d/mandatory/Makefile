# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/21 14:29:12 by thobenel          #+#    #+#              #
#    Updated: 2025/05/06 03:33:38 by dpascal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = cub3D_mandatory
BONUS_NAME  = cub3D_bonus

# Compiler and flags
CC          = gcc
CFLAGS      = -Wall -Wextra -Werror -g \
              -I include \
              -I $(LIBFT_DIR) \
              -I $(MLX_DIR)
LDFLAGS     = -L $(LIBFT_DIR) -lft \
              -L $(MLX_DIR)   -lmlx \
              -lX11 -lXext -lm

# Clean utility
RM          = rm -f

# External libraries
LIBFT_DIR   = ../libft_2.0
MLX_DIR     = ../mandatory/minilibx-linux

# Mandatory sources
SRCS = \
	ray_casting_mandatory/raycast_engine.c \
	ray_casting_mandatory/raycast_rayon.c \
	ray_casting_mandatory/wall_casting.c \
	ray_casting_mandatory/draw_use.c \
	ray_casting_mandatory/check_file.c \
	ray_casting_mandatory/check_map_utils.c \
	ray_casting_mandatory/check_map.c \
	ray_casting_mandatory/collision.c \
	ray_casting_mandatory/colors.c \
	ray_casting_mandatory/copy_map.c \
	ray_casting_mandatory/draw_utils.c \
	ray_casting_mandatory/draw.c \
	ray_casting_mandatory/exit.c \
	ray_casting_mandatory/init.c \
	ray_casting_mandatory/key.c \
	ray_casting_mandatory/main.c \
	ray_casting_mandatory/parse_colors_textures.c \
	ray_casting_mandatory/parsing.c \
	ray_casting_mandatory/ray_cast.c \
	ray_casting_mandatory/textures.c \
	ray_casting_mandatory/utils.c

# Bonus sources
SRCS_BONUS = \
	../bonus/src/ray_casting/draw_projection.c \
	../bonus/src/ray_casting/raycast_engine.c \
	../bonus/src/ray_casting/raycast_rayon.c \
	../bonus/src/ray_casting/wall_casting.c \
	../bonus/src/event/camera.c \
	../bonus/src/event/mouse.c \
	../bonus/src/event/timer_drawing_one.c \
	../bonus/src/event/event_utils.c \
	../bonus/src/event/minimap.c \
	../bonus/src/event/minimap_util_one.c \
	../bonus/src/event/minimap_util_two.c \
	../bonus/src/event/minimap_util_three.c \
	../bonus/src/event/player_mouvement.c \
	../bonus/src/event/timer_utils.c \
	../bonus/src/event/keyboard.c \
	../bonus/src/event/timer.c \
	../bonus/src/event/window_event.c \
	../bonus/src/monster/action_monster.c \
	../bonus/src/monster/draw_monster.c \
	../bonus/src/monster/patrol_monster.c \
	../bonus/src/monster/render_monster.c \
	../bonus/src/parsing/copy.c \
	../bonus/src/parsing/main_parsing.c \
	../bonus/src/parsing/padding.c \
	../bonus/src/parsing/parse_map.c \
	../bonus/src/parsing/rgb.c \
	../bonus/src/parsing/rgb_utils.c \
	../bonus/src/parsing/texture_parse.c \
	../bonus/src/parsing/valid_map.c \
	../bonus/src/texture/draw_ceilling.c \
	../bonus/src/texture/draw_texture.c \
	../bonus/src/texture/draw_wall.c \
	../bonus/src/texture/monster_texture.c \
	../bonus/src/texture/texture_door.c \
	../bonus/src/utils/free_main.c \
	../bonus/src/utils/free_utils.c \
	../bonus/src/utils/image_utils.c \
	../bonus/src/utils/map_utils.c \
	../bonus/src/utils/pixel_utils.c \
	../bonus/src/utils/utils.c \
	../bonus/src/main/main.c \
	../bonus/src/main/init.c

# Object files
OBJS        = $(SRCS:.c=.o)
BONUS_OBJS  = $(SRCS_BONUS:.c=.o)

# Phony targets
.PHONY: all bonus clean fclean re

# Default target: build mandatory
all: $(LIBFT_DIR)/libft.a $(MLX_DIR)/libmlx.a $(NAME)

$(NAME): $(OBJS)
	@echo "🚀 Building mandatory executable: $@"
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

# Build bonus target
bonus: $(LIBFT_DIR)/libft.a $(MLX_DIR)/libmlx.a $(BONUS_OBJS)
	@echo "✨ Building bonus executable: $@"
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS_NAME) $(LDFLAGS)

# Compile libft and mlx
$(LIBFT_DIR)/libft.a:
	@echo "📚 Compiling libft..."
	$(MAKE) -C $(LIBFT_DIR)

$(MLX_DIR)/libmlx.a:
	@echo "🖌️ Compiling minilibx..."
	$(MAKE) -C $(MLX_DIR)

# Generic rule: .c to .o
%.o: %.c
	@echo "🔨 Compiling $< -> $@"
	$(CC) $(CFLAGS) -c $< -o $@

# Remove object files
clean:
	@echo "🧹 Cleaning object files..."
	$(RM) $(OBJS) $(BONUS_OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

# Remove executables and static libs
fclean: clean
	@echo "💣 Cleaning executables and libs..."
	$(RM) $(NAME) $(BONUS_NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(MLX_DIR)/libmlx.a

# Rebuild everything
re: fclean all