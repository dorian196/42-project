/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:58:53 by dpascal           #+#    #+#             */
/*   Updated: 2024/11/21 11:44:27 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/get_next_line/get_next_line.h"
# include "../libft/printf/ft_printf.h"  

# define TILE_SIZE 96
// # define KEY_Z 122
// # define KEY_Q 113
// # define KEY_D 100
// # define KEY_S 115
# define KEY_ESC 65307
# define KEY_Z 65362
# define KEY_Q 65361
# define KEY_D 65363
# define KEY_S 65364

# define P "assets/player.xpm"
# define M "assets/enemy.xpm"
# define D "assets/enemy_dead.xpm"
# define T "assets/tree.xpm"
# define S "assets/stone.xpm"
# define F "assets/floor.xpm"
# define E "assets/exit.xpm"
# define X "assets/exit_close.xpm"
# define Z "assets/exit_player.xpm"

# include "../.mlx/mlx.h"
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_map
{
	char	**map;
	char	*file;
	int		**visited;
	int		width;
	int		height;
	int		line_length;
	int		y;
	int		free_exit;
}			t_map;

typedef struct s_game
{
	int		width;
	int		height;
	int		x;
	int		y;
	int		prev_x;
	int		prev_y;
}			t_game;

typedef struct s_img
{
	void	*stone;
	void	*floor;
	void	*player;
	void	*player1;
	void	*exit_z;
	void	*exit;
	void	*exit_x;
	void	*tree;
	void	*enemy;
	void	*enemy_d;
	int		width;
	int		height;
}			t_img;

typedef struct s_count
{
	int		collectable;
	int		collectable2;
	int		collectable_count;
	int		exit;
	int		count_move;
}			t_count;

typedef struct s_data
{
	void	*data;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;

	int		width;
	int		height;
	t_map	map;
	t_game	game;
	t_img	img;
	t_count	count;
}			t_data;

typedef struct s_status
{
	int		exit;
	int		player;
	int		mob;
}			t_status;

typedef struct s_pos
{
	int		start_x;
	int		start_y;
	int		x;
	int		y;
}			t_pos;

void		free_all_map(int **visited, t_map *map);
void		free_line(int **visited, t_data *data);
void		free_map(t_map *map);
void		free_img(t_data *data, t_img *img);
void		free_all(t_data *data, t_map *map, t_img *img);

int			can_move_to(int x, int y, t_data *data);
int			handle_keypress(int key, t_data *data);

void		init_struct(t_data *data);

void		load_img(t_data *data, t_img *img);
void		check_map_validity(t_data *data, int y, int x, int free_exit);
char		*create_map2(t_data *data, t_map *map, char *line, int line_length);
void		create_map(t_data *data, t_map *map, t_count *count, int fd);
void		load_map(t_data *data, t_map *map, t_count *count, char *filename);

int			check_walls(t_map *map);
int			check_format(t_map *map);
int			check_tyle2(t_map *map, t_status *status, int x, int y);
int			check_tyle(t_map *map);
void		check_map_condition(t_data *data, t_map *map);

void		open_exit(t_data *data);
void		prev_pos(t_data *data);
void		check_exit(t_data *data);
void		check_mob(t_data *data);
int			move_player(t_data *data, int new_x, int new_y);

void		check_path(t_data *data, int x, int y, int **visited);
void		reach_path(t_data *data);

void		screen_size(t_data *data, t_game *game, t_map *map);
void		set_camera(t_game *game, t_map *map, t_pos *pos);
void		draw_tile(t_data *data, t_pos *pos, int x, int y);
void		render_map(t_data *data, t_game *game);

void		*ft_mlx_i(void *mlx_ptr, char *filename, int *width, int *height);
int			close_window(t_data *data);
void		exit_window(t_data *data);
void		ft_mlx_w(t_data *data, void *img_ptr, int x, int y);
void		count_line(t_data *data, t_map *map, char *filename, int fd);

#endif