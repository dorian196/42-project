/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thobenel <thobenel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:28:52 by thobenel          #+#    #+#             */
/*   Updated: 2025/05/09 02:36:39 by thobenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "../libft_2.0/libft.h"
# include "../mandatory/minilibx-linux/mlx.h"
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <unistd.h>

# define DIR_NORTH 0
# define DIR_SOUTH 1
# define DIR_EAST 2
# define DIR_WEST 3

# define MONSTER_PATH "./texture/demon/sprites/walk_xpm/demon_walk_"

# define MONSTER_EXT ".xpm"
# define MONSTER_FRAMES 12

# define WIDTH 1380
# define HEIGHT 820
# define BLOCK 64
# define DEBUG 0

# define WALL 0x0073C2FB
# define PLAFOND 0x0033ceff
# define SOL 0x00262626
# define SHADOW_CASTING 0.000000005f

# define MINI_MAP_SCALE 8
# define MINI_MAP_MARG 7

# define DOOR "texture/doorgpt.xpm"

# define PI 3.14159265358979323846

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

typedef struct s_timer
{
	bool		is_running;
	time_t		start_time;
	time_t		current_time;
	time_t		best_time;
	float		elapsed_time;
}				t_timer;

typedef struct s_monster
{
	float		x;
	float		y;
	float		distance;
	float		speed;
	float		detection_range;
	bool		is_active;
	int			current_frame;
	int			frame_timer;
	int			frame_speed;
}				t_monster;

typedef struct s_sprite
{
	float		x;
	float		y;
	float		distance;
	int			texture_id;
	int			animation_frame;
	int			frame_count;
	int			iupdate_time;
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

typedef struct s_imgs
{
	void		*door;
	int			*door_data;
	int			bpp;
	int			size_line;
	int			endian;
	int			width;
	int			height;
}				t_imgs;

typedef struct s_player
{
	float		x;
	float		y;
	float		angle;
	float		dist_door;
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
	char		**map;
	float		*wall_distances;
	int			bpp;
	int			size_line;
	int			endian;
	int			map_height;
	int			map_width;
	int			last_mouse_x;
	int			last_mouse_y;
	int			sprite_count;
	int			height_closed;
	int			width_closed;
	t_player	player;
	t_parsing	parsing;
	t_textures	tex_no;
	t_textures	tex_so;
	t_textures	tex_ea;
	t_textures	tex_we;
	t_imgs		imgs;
	t_timer		timer;
	t_textures	*sprite_textures;
	t_monster	monster;
}				t_game;

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

typedef struct s_door_data
{
	int			tex_x;
	int			tex_w;
	int			tex_h;
	int			*door_data;
	t_game		*game;
}				t_door_data;

typedef struct s_draw_monster
{
	t_monster	*monster;
	t_player	*player;
	t_textures	*textures;
	float		sprite_dir_x;
	float		sprite_dir_y;
	float		sprite_angle;
	int			sprite_screen_x;
	float		sprite_size;
	float		shade;

	int			sprite_height;
	int			sprite_width;
	int			sprite_top;
	int			sprite_left;
	int			x;
	int			y;
	int			screen_x;
	int			screen_y;
	int			tex_x;
	int			tex_y;
	int			tex_index;
	int			r;
	int			g;
	int			b;
	int			color;
}				t_draw_monster;

typedef struct s_slice
{
	t_player	*player;
	t_game		*game;
	float		hit_x;
	float		hit_y;
	int			column;
}				t_slice;

/*              INIT                      */
void			ft_init(t_game *game);
void			ft_init_game(t_game *game);
void			ft_init_player(t_player *player, int x, int y, char orient);

/*              UTILS                      */
bool			ft_collision(float x, float y, t_game *game);
bool			ft_touch_col(float px, float py, t_game *game);
void			ft_update_angle(t_player *joueur);
void			ft_clear_image(t_game *game);
bool			ft_touch(float x, float y, t_game *game);
int				ft_error(const char *str, t_game *game);
int				ft_strlen(char *str);
void			ft_clean_up(char **deep_copy, int map_nb_ligne);
int				ft_count_len_one(char **map);
void			free_tab(char **map);
void			ft_free_wall_textures(t_game *game);
void			ft_free_special_textures(t_game *game);
void			ft_free_resources(t_game *game);
void			ft_free_map_data_two(t_game *game);
void			ft_free_map_data(t_game *game);
void			free_var(t_game *game);
int				ft_exit_game(void *param);

/*              PLAYER                  */
void			ft_calculate_mouvement(t_player *joueur, float *dx, float *dy);
int				ft_move_player(t_game *game);

/*              GAME                     */
int				ft_hl_red_cross(t_game *game);
int				ft_mouse_move(int x, int y, void *param);

/*              PARSING                      */
int				ft_parsing(int ac, char **av, t_game *game);
void			ft_display_map_debug(char **map, int nb_line);
void			ft_check_pl_placement(t_game *game);
void			ft_get_positions(t_game *game, int i, int j, int *count);
void			ft_cp_file(t_game *game, char **file);
int				ft_check_file(char **arg, t_game *game);
void			ft_char_map(t_game *game);
void			ft_parse_map(t_game *game);
bool			ft_valid_map_integrity(t_game *game);
bool			check_x(t_game *game, char **deep_copy, bool result);
bool			ft_detect_breach(char **deep_copy, int i, int j, t_game *game);
int				check_r(char **map, int i, int j, t_game *game);
void			free_map(char **map);
char			**copy_map_padded(char **map);
int				check_fill(char **map, int i, int j, int max_rows);
void			ft_copy_map(t_game *game);
void			ft_transfer_ligne_with_border(t_game *game, int i, int max_len);
void			ft_reserve_memory_for_line(t_game *game, int line_index,
					int size, const char *error_msg);
void			flood_fill(char **deep_copy, int i, int j, int map_nb_ligne);
void			ft_fill_boundary_row(char **map_copy_map, int ligne_index,
					int max_len, t_game *game);
void			ft_parse_param(t_game *game);
int				ft_is_color_line(char *line);
void			ft_colors_parse(t_game *game, char *map);
bool			ft_parse_ceiling_color(t_game *game, char *map);
bool			ft_parse_floor_color(t_game *game, char *map);
bool			ft_parse_rgb(char *str, int *values, t_game *game,
					const char *error_msg);
void			ft_free_rgb_values(char **rgb_values);
bool			ft_validate_rgb_values(int *value, t_game *game,
					const char *error_msg);
int				ft_texture_parse(t_game *game, char *map);
int				ft_find_longest_line(char **map_tab_too_d);
char			*back_slash_n_less(char *str);
void			ft_count_len(t_game *game, char *file);

/*              MAP                         */
void			ft_draw_map(t_game *game);
void			ft_draw_square(int x, int y, int colors, t_game *game);

/*              RAY-CASTING                    */
void			ft_put_pixel(int x, int y, int colors, t_game *game);
int				ft_draw_loop(void *param);
void			ft_draw_line(t_player *player, t_game *game, float ray_angle,
					int column);
void			ft_prepare_wall_rendering(t_ray *ray, t_game *game,
					float angle_diff, int column);
void			ft_prepare_ray_angle(float *angle_diff, t_ray *ray,
					t_player *player, float ray_angle);
void			ft_render_column(t_ray *ray, int column, t_game *game);
void			ft_render_column_use(t_ray *ray);
void			ft_draw_wall(t_ray *ray, int column, int y, t_game *game);
void			ft_shade_and_draw_wall(t_ray *ray, int column, int y,
					t_game *game);
void			ft_calc_distance(t_ray *ray, t_player *player,
					float angle_diff);
void			ft_draw_ceiling_floor(int column, t_ray *ray, t_game *game);
int				ft_cast_ray_one(t_ray *ray, t_game *game);
int				ft_cast_ray_two(t_ray *ray, t_game *game);
void			ft_init_ray_one(t_ray *ray, t_player *player, float ray_angle);
void			ft_init_ray_two(t_ray *ray, t_player *player, float ray_angle);
int				ft_load_wall_textures(t_game *game);
int				ft_load_single_texture(t_textures *texture, char *path,
					const char *error_msg, t_game *game);
bool			ft_is_pixel_visible(t_draw_monster *draw, t_game *game,
					float monster_dist);
bool			ft_is_valid_texture_coord(t_draw_monster *draw);
void			ft_polish_angle(t_player *joueur);

/*              MINI-MAP                */
void			ft_draw_minimap_background(t_game *game, int ox, int oy);
void			ft_draw_tiles(t_game *game, int x, int y, int colors);
char			**copy_map_padded2(char **map);
void			free_map2(char **map);
int				check_fill2(char **map, int i, int j, int max_rows);
int				check_r2(char **map, int i, int j, t_game *game);
void			ft_draw_minimap_tiles(t_game *game, int ox, int oy);
void			ft_draw_minimap_player(t_game *game, int ox, int oy);
void			ft_draw_minimap_directions(t_game *game, int ox, int oy);
void			ft_draw_warning_borders(t_game *game, float intensity);
void			ft_draw_detected_warning(t_game *game);
void			ft_draw_minimap_monster(t_game *game, int ox, int oy);
void			ft_draw_minimap(t_game *game);

/*              MONSTER                */
int				ft_load_monster_textures(t_game *game);
void			ft_draw_monster_main(t_game *game);
void			ft_draw_monster_columns(t_draw_monster *draw, t_game *game,
					float monster_dist);
void			ft_draw_monster_vertical_line(t_draw_monster *draw,
					t_game *game, float monster_dist);
void			ft_draw_single_monster_pixel(t_draw_monster *draw, t_game *game,
					float monster_dist);
bool			ft_calculate_sprite_size(t_draw_monster *draw,
					float monster_dist);
float			ft_calculate_monster_distances(t_draw_monster *draw);
bool			ft_calculate_monster_angle(t_draw_monster *draw, t_game *game);
bool			ft_draw_monster_two(t_game *game, t_draw_monster *draw);
void			ft_draw_monster_one(t_game *game, t_draw_monster *draw);
void			ft_update_monster(t_game *game);
void			ft_monster_patrol(t_monster *m, t_game *game);
void			ft_monster_chase_player(t_monster *m, t_player *player,
					t_game *game);
void			ft_calculate_monster_chase_position(t_monster *m,
					t_player *player, float *new_x, float *new_y);
void			ft_update_monster_animation(t_monster *m);
void			ft_calculate_monster_distance(t_monster *m, t_player *player);
void			ft_init_monster(t_game *game);

/*              DOOR                */
void			ft_draw_door_pixel(t_ray *ray, int column, int y,
					t_door_data *door_data);
void			ft_prepare_door_texture(t_ray *ray, t_player *player,
					t_game *game, t_door_data *door_data);
void			ft_prepare_door_texture_two(int is_vert, t_ray *ray,
					t_door_data *door_data, int tex_w);
void			ft_calc_wall_params(t_ray *ray, t_game *game);
void			ft_open_door(t_player *player, t_game *game);

/*              KEY                 */
int				ft_key_press(int keycode, void *param);
int				ft_key_release(int keycode, void *param);

/*              TIMER                */
void			ft_stop_monster_m(t_game *game, t_monster *m);
void			ft_init_timer(t_timer *timer);
void			ft_start_timer(t_timer *timer);
void			ft_stop_timer(t_timer *timer);
void			ft_update_timer(t_timer *timer);
void			ft_calculate_timer_position(t_game *game, int *ox, int *oy,
					int *width);
void			ft_draw_timer_background(t_game *game, int ox, int oy,
					int width);
float			ft_calculate_timer_progress(t_game *game);
void			ft_draw_progress_bar(t_game *game, int ox, int oy,
					float progress);
void			ft_draw_timer_border(t_game *game, int ox, int oy, int width);
void			ft_draw_timer(t_game *game);
void			ft_draw_timer_text(t_game *game);

/*              COLLISION                      */
int				ft_process_ray_collision(t_ray *ray, t_game *game);

/*              IMAGE               */
int				ft_load_img(t_game *game);
void			ft_prepare_wall_texture(t_ray *ray);
void			ft_select_texture_one(t_ray *ray, t_player *player,
					t_game *game, float angle_diff);
void			ft_select_texture_two(t_ray *ray);
void			ft_load_textures(t_game *game);
void			ft_clear_ceiling(t_game *game);
void			ft_clear_floor(t_game *game);

#endif