/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:28:52 by thobenel          #+#    #+#             */
/*   Updated: 2025/05/06 03:53:48 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "../libft_2.0/libft.h"
# include "../minilibx-linux/mlx.h"
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
// #include "../minilibx_opengl/mlx.h"

# define DIR_NORTH 0
# define DIR_SOUTH 1
# define DIR_EAST 2
# define DIR_WEST 3

# define WIDTH 1280
# define HEIGHT 720
# define BLOCK 64
# define DEBUG 0

# define WALL 0x0073C2FB
# define PLAFOND 0x0033ceff
# define SOL 0x00262626
# define SHADOW_CASTING 0.0000001f

# define MINI_MAP_SCALE 8
# define MINI_MAP_MARG 10

# define PI 3.14159

// Mac
// # define W 13
// # define A 0
// # define S 1
// # define D 2
// # define LEFT 123
// # define RIGHT 124
// # define ESCP 53

# define SENSI 0.0005f

// // Linux
# define W 119
# define A 97
# define S 115
# define D 100
# define LEFT 65361
# define RIGHT 65363
# define PRESS_E 101
# define ESCP 65307

typedef struct s_sprite
{
	float		x;
	float		y;
	float		distance;
	int			texture_id;
	int			animation_frame;
	int			frame_count;
	int			update_time;
	int			last_update;
	float		speed;
	bool		is_chasing;
	float		detection_range;
	float		catch_range;
}				t_sprite;

typedef struct s_texture
{
	void		*img;
	char		*data;
	int			width;
	int			height;
	int			bpp;
	int			size_line;
	int			endian;
}				t_textures;

typedef struct s_parsing
{
	char		*path_no;
	char		*path_so;
	char		*path_ea;
	char		*path_we;
	char		*path_f;
	char		*path_c;
	int			value_f[3];
	int			value_c[3];
	char		**map_copy_file;
	char		**map_tab_too_d;
	char		**map_copy_map;
	char		map_player;
	int			map_pos_x;
	int			map_pos_y;
	int			map_player_count;
	int			map_nb_ligne;
	int			map_nb_ligne_str;
	int			map_start_ligne;
}				t_parsing;

typedef struct s_ray
{
	float		cos_angle;
	float		sin_angle;
	float		map_x;
	float		map_y;
	float		side_dist_x;
	float		side_dist_y;
	float		delta_dist_x;
	float		delta_dist_y;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	float		dist;
	float		wall_x;
	int			tex_x;
	int			tex_y;
	int			tex_index;
	float		shade;
	int			r;
	int			g;
	int			b;
	int			colors;
	float		wall_h;
	int			start_y;
	int			end_y;
	int			ceiling_color;
	int			floor_color;
	int			y;
	float		step;
	float		tex_pos;
	t_textures	*textures;
	char		tile;
}				t_ray;

typedef struct s_player
{
	float		x;
	float		y;
	float		angle;
	bool		key_up;
	bool		key_down;
	bool		key_left;
	bool		key_right;
	bool		key_escp;
	bool		left_fov;
	bool		right_fov;

}				t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	int			bpp;
	int			size_line;
	int			endian;
	int			map_height;
	int			map_width;
	int			cpy_height;
	int			cpy_width;
	int			colors;
	char		**map;
	int			last_mouse_x;
	int			last_mouse_y;
	t_player	player;
	t_parsing	parsing;
	t_textures	tex_no;
	t_textures	tex_so;
	t_textures	tex_ea;
	t_textures	tex_we;
	t_textures	*sprite_textures;
	int			sprite_count;
	float		*wall_distances;
}				t_game;

typedef struct s_slice
{
	t_player	*player;
	t_game		*game;
	float		hit_x;
	float		hit_y;
	int			column;
}				t_slice;

/*  CHECK_FILE  */
int				ft_check_file(t_game *game, char **arg);
void			ft_cp_file_while(t_game *game, int fd);
void			ft_cp_file(t_game *game, char **file);

/*  CHECK_MAP_UTILS  */
int				check_fill(char **map, int i, int j, int max_rows);
char			**copy_map_padded_while(char **map, char **cpy_map, int i,
					int j);
char			**copy_map_padded(t_game *game, char **map);

/*  CHECK_MAP  */
int				check_r(char **map, int i, int j, t_game *game);
int				ft_check_breach(char **deep_copy, int i, int j, t_game *game);
bool			ft_detect_breach(char **deep_copy, int i, int j, t_game *game);
bool			check_x(t_game *game, char **deep_copy, bool result);
bool			ft_valid_map_integrity(t_game *game);

/*  COLLISION  */
bool			ft_collision(float x, float y, t_game *game);
bool			ft_touch_col(float px, float py, t_game *game);

/*  COLORS  */
int				ft_color_f(t_game *game, char *map, int i, char **rgb_values);
int				ft_color_c(t_game *game, char *map, int i, char **rgb_values);
void			ft_colors_parse(t_game *game, char *map);
void			ft_color_sky(t_game *game);
void			ft_get_colors(t_game *game);

/*  COPY_MAP  */
int				ft_find_longest_line(char **map_tab_too_d);
void			ft_fill_boundary_row(t_game *game, char **map_copy_map,
					int ligne_index, int max_len);
void			ft_reserve_memory_for_line(t_game *game, int line_index,
					int size, const char *error_msg);
void			ft_transfer_ligne_with_border(t_game *game, int i, int max_len);
void			ft_copy_map(t_game *game);

/*  DRAW_UTILS  */
void			ft_put_pixel(int x, int y, int colors, t_game *game);
void			ft_draw_square(int x, int y, int size, t_game *game);
void			ft_draw_map(t_game *game);

/*  DRAW  */
void			ft_draw_line(t_player *player, t_game *game, float ray_angle,
					int column);

/*  EXIT  */
int				ft_error(const char *str, t_game *game);
void			ft_clean_up(char **deep_copy, int map_nb_ligne);
void			free_tab(char **map);
void			free_var(t_game *game);
int				ft_exit_game(void *param);

/*  INIT  */
void			ft_init(t_game *game);
void			ft_init_game(t_game *game);
int				ft_load_textures(t_game *game);
void			ft_init_player(t_player *player, int x, int y, char orient);

/*  KEY  */
int				ft_key_press(int keycode, void *param);
int				ft_key_release(int keycode, void *param);

/*  MAIN  */
int				ft_draw_loop(void *param);
int				main(int ac, char **av);

/*  PARSE_COLORS_TEXTURES  */
int				ft_is_color_line(char *line);
int				ft_parse_param_while(t_game *game, int count, char *cpy,
					int *i);
void			ft_parse_param(t_game *game);

/*  PARSING  */
void			ft_parse_map(t_game *game);
void			ft_char_map(t_game *game);
void			ft_get_positions(t_game *game, int i, int j, int *count);
void			ft_check_pl_placement(t_game *game);
int				ft_parsing(int ac, char **av, t_game *game);

/*  RAY_CAST  */
void			ft_calculate_mouvement(t_player *joueur, float *dx, float *dy);
void			ft_update_angle(t_player *joueur);
void			ft_polish_angle(t_player *joueur);
void			ft_draw_wall(t_ray *ray, int column, int y, t_game *game);
int				ft_move_player(t_game *game);
int				ft_cast_ray_one(t_ray *ray, t_game *game);
int				ft_cast_ray_two(t_ray *ray, t_game *game);
void			ft_render_column_use(t_ray *ray);
int				ft_process_ray_collision(t_ray *ray, t_game *game);
void			ft_prepare_ray_angle(float *angle_diff, t_ray *ray,
					t_player *player, float ray_angle);
void			ft_init_ray_one(t_ray *ray, t_player *player, float ray_angle);
void			ft_init_ray_two(t_ray *ray, t_player *player, float ray_angle);
bool			ft_check_collision_point(float px, float py, t_game *game);
bool			ft_touch(float x, float y, t_game *game);
void			ft_clear_floor(t_game *game);
void			ft_clear_ceiling(t_game *game);
void			ft_prepare_wall_rendering(t_ray *ray, t_game *game,
					float angle_diff, int column);
void			ft_calc_wall_params(t_ray *ray, t_game *game);
void			ft_calc_distance(t_ray *ray, t_player *player,
					float angle_diff);
void			ft_select_texture_one(t_ray *ray, t_player *player,
					t_game *game,
					float angle_diff);
void			ft_select_texture_two(t_ray *ray);
void			ft_draw_ceiling_floor(int column, t_ray *ray, t_game *game);
void			ft_render_column(t_ray *ray, int column, t_game *game);

/*  TEXTURES  */
int				ft_texture_no_so(t_game *game, char *map);
int				ft_texture_we_ea(t_game *game, char *map);
int				ft_texture_parse(t_game *game, char *map);

/*  UTILS  */
int				ft_strlen(char *str);
int				ft_count_len_one(char **map);
void			ft_count_len(t_game *game, char *file);
char			*back_slash_n_less(char *str);

#endif