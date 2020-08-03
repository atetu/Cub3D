/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atetu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 15:50:37 by atetu             #+#    #+#             */
/*   Updated: 2020/03/07 14:31:56 by atetu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <fcntl.h>
# include <sys/errno.h>
# include <stdio.h>
# include <math.h>
# include <stdlib.h>

# include "../libft/libft.h"
# include "../minilibx_opengl/mlx.h"

# define KEY_PRESS 2
# define KEY_RELEASE 3
# define EVENT_EXIT 17
# define LEFT 123
# define RIGHT 124
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define SHIFT 257
# define ESC 53

typedef struct		s_sprite{
	double			x;
	double			y;
}					t_sprite;

typedef struct		s_array{
	int				resolution_x;
	int				resolution_y;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*sp;
	int				f_r;
	int				f_g;
	int				f_b;
	int				c_r;
	int				c_g;
	int				c_b;
	int				floor;
	int				ceiling;
	int				resolution;
	int				height;
	int				width;
	int				count_sprites;
	t_sprite		*array_sprite;
	int				save;
	char			**map;
	int				rows;
	int				len_line;
	int				flag_map;
	double			pos_x;
	double			pos_y;
	char			dir;
	int				**hit;
	int				map_created;
	int				wrong_line;
}					t_array;

typedef struct		s_image{
	void			*mlx_ptr;
	void			*img_ptr;
	int				*pic;
	int				bpp;
	int				stride;
	int				endian;
	int				width;
	int				height;
	int				line;
}					t_image;

typedef struct		s_loaded_image{
	void			*ptr;
	int				*pic;
	int				bpp;
	int				stride;
	int				endian;
	int				width;
	int				height;
	int				line;
}					t_loaded_image;

typedef struct		s_color{
	int				floor_red;
	int				floor_green;
	int				floor_blue;
	int				ceiling_red;
	int				ceiling_green;
	int				ceiling_blue;
}					t_color;

typedef struct		s_player{
	int				resolution_x;
	int				resolution_y;
	void			*ptr;
	void			*win_ptr;
	void			*img_mlx_ptr;
	void			*img_win_ptr;
	char			**map;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			screen_x;
	double			screen_y;
	double			time;
	double			old_time;
	double			rot_speed;
	int				move;
	int				first_loop;
	t_image			*image;
	t_loaded_image	*tex_north;
	t_loaded_image	*tex_south;
	t_loaded_image	*tex_west;
	t_loaded_image	*tex_east;
	t_loaded_image	*sprite;
	int				is_forward_pressed;
	int				is_backward_pressed;
	int				is_move_right_pressed;
	int				is_move_left_pressed;
	int				is_look_left_pressed;
	int				is_look_right_pressed;
	int				is_shift_pressed;
	int				color_ceiling;
	int				color_floor;
	int				count_sprites;
	t_sprite		*array_sprite;
	int				exit;
	int				save;
	int				rows;
}					t_player;

typedef struct		s_header{
	int				size;
	int				width;
	int				height;
	int				planes;
	int				bpp;
	int				compression;
	int				image_size;
	int				hor_resolution;
	int				vert_resolution;
	int				nb_colors;
	int				nb_imp_colors;
}					t_header;

typedef struct		s_ray{
	int				resolution_x;
	int				resolution_y;
	double			position_screen;
	double			cursor;
	double			wall_dist;
	int				x_start;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			screen_x;
	double			screen_y;
	double			ray_x;
	double			ray_y;
	int				tile_x;
	int				tile_y;
	double			first_dist_x;
	double			first_dist_y;
	double			dist_x;
	double			dist_y;
	int				step_x;
	int				step_y;
	int				side;
	double			wall_x;
	double			step;
	int				tex_x;
	double			tex_y;
}					t_ray;

typedef struct		s_draw{
	int				line_height;
	int				start_line;
	int				end_line;
}					t_draw;

typedef struct		s_sp{
	double			sprite_x;
	double			sprite_y;
	double			inv;
	double			transform_x;
	double			transform_y;
	int				sprite_screen_x;
	int				sprite_height;
	int				stripe;
	int				sprite_width;
	int				draw_start_x;
	int				draw_start_y;
	int				draw_end_x;
	int				draw_end_y;
	int				tex_x;
	int				tex_y;
}					t_sp;

int					get_next_line(int fd, char **line);
int					ft_parser_dir_no(char **line, t_array *array, char *data);
int					ft_parser_dir_so_p(char **line, t_array *array, char *data);
int					ft_parser_dir_we(char **line, t_array *array, char *data);
int					ft_parser_dir_ea(char **line, t_array *array, char *data);
int					parser_map(char **line, t_array *array);
int					ft_check_map(char **map, t_array *array, int x, int y);
char				*ft_atoi_digit(char *str, int *n);
char				*ft_atoi_digit_fc(char *str, int *n, char *arg);
char				*move_isspace(char *str);
int					ft_check_isspace_beginning(t_array *array, char *str,
		char *arg);
int					ft_check_isspace(char *str, char *arg);
int					ft_check_conflicting_arg(int nb, char *str);
int					ft_correct_char(char c, char expected_c, char *arg);
int					ft_parser_dir_data(char **line, t_array *array);
int					parser_resolution(char **line, t_array *array, char *arg,
		char *nb);
int					parser(char **str, t_array *array);
int					check_len(int len, int rows);
int					check_one(char *str);
int					check_one_char(char c);
int					check_char(char *str, int len, int *position);
int					ft_creation_map(char **map, char **line, t_array *array);
int					ft_malloc_map(char **line, int nb, int i, char **map);
void				ft_fill_map(char **line, int i, char **map, t_array *array);
int					ft_parser_floor(char **line, t_array *array);
int					ft_parser_ceiling(char **line, t_array *array);
int					parser_ceiling_floor_data(char **line, t_array *array);
void				ft_initialize_array(t_array *array);
int					ft_struct_ok(t_array *array);
int					ft_struct2_ok(t_array *array);
int					ft_fill_array(char **line, int i, char **str, char *arg);
int					ft_fill_south_sprite(char *data, t_array *array,
		char **line, int i);
int					ft_first_read(char **argv, t_array *array, int *fd);
char				**ft_second_read(char **argv, int rows, char **map,
		t_array *array);
int					window(t_array *array, char **map);
int					ft_pos(char **map, t_array *array);
int					ft_initialize_player(t_player *player, t_array *array,
		char **map);
void				ft_dir_plane(char dir, t_player *player);
int					key_hook(t_player *player);
int					key_rotation(t_player *player);
int					loop(t_player *player);
int					initialization_engine(t_array *array, char **map);
int					load_image(t_player *player, t_array *array);
int					texture_info(t_player *player, t_loaded_image *tex,
		char *dir);
t_loaded_image		*determine_texture(t_player *player, t_ray *ray);
int					color_assemble(int red, int green, int blue);
int					ft_sprite(t_player *player, double *zbuffer);
int					ft_initialize_sprites(char **map, t_array *array);
int					ft_exit_esc(t_player *player);
int					ft_exit_red_cross(t_player *player);
int					ft_check_save(char **argv, t_array *array);
int					ft_save(t_player *player);
int					ft_resolution_ok(t_array *array);
void				ft_dir_plane_ns(char dir, t_player *player);
void				ft_dir_plane_ew(char dir, t_player *player);
void				move_pos(t_player *player, double *new_pos_x,
		double *new_pos_y);
void				key_rotation_left(t_player *player);
void				key_rotation_right(t_player *player);
int					initialization_image(t_player *player);
int					draw_window(t_player *player, double *zbuffer);
void				ray_distance(t_ray *ray, t_player *player);
void				ray_hit(t_player *player, t_ray *ray);
void				ray_determine_ray_tile(t_player *player, t_ray *ray);
void				ray_draw_floor_ceiling(t_player *player, t_ray *ray,
		t_draw *draw);
void				ray_draw_texture(t_player *player, t_draw *draw, t_ray *ray,
		t_loaded_image *texture);
void				initialize_ray(t_player *player, t_ray *ray);
void				ray_calculate_line(t_ray *ray, t_draw *draw,
		t_player *player);
void				ray_calculate_texture(t_ray *ray, t_draw *draw,
		t_player *player, t_loaded_image *texture);
int					key_pressed(int keycode, t_player *player);
int					key_released(int keycode, t_player *player);
void				initialize_draw(t_draw *draw);
void				init_text_struct_player(t_player *player);
char				*ft_free_str(char *str);
void				ft_destroy(t_player *player);
int					ft_open(int fd);
int					ft_close(int fd);
int					ft_map(char **map, t_array *array);
int					ft_transpose_file_to_map(int fd, char **line, char **map,
		t_array *array);
double				*ft_free_array(double *array);
void				ft_free_texture(t_player *player);
void				ft_free_map_player(t_player *player);
char				**ft_free_map(char **map);
double				*ft_free_array(double *array);
void				handle_exit(t_player *player);
int					ft_check_range_colors(int red, int green, int blue);
int					ft_check_nb_argc(int argc, char **argv, t_array *array);
int					ft_check_result(int result);
void				pustr_error(char *str);
int					check_nothing_more(char c, char *str);
int					ft_check_conflicting_arg_south_sprites(char *data,
		t_array *array);
int					check_existing_map(int row, char c);
void				ray_draw_texture_line(t_player *player, t_draw *draw,
		t_ray *ray, t_loaded_image *texture);
int					parse_line(char **line, t_array *array);
int					map_character(char c);
int					wrong_line(int row, char c);
int					check_beginning(char *str, int flag, char *arg,
		t_array *array);
int					check_dig_arg(char **line, int *n, char *arg, char *nb);
int					wrong_char(t_array *array, char c, char *line);
int					ft_check_isspace_map(char *str);
int					*ft_free_int(int *i);
int					**ft_free_hit(t_array *array);
int					no_char_map(char **line, int *i);
int					ft_check_beginning_map(char **line, int *i);
void				establish_char_map(char *map, int *x, char c, int *sprites);
int					check_char_map(char c);
int					is_malloc_map(char **map, int nb);
int					check_longest_line(char **map, t_array *array);
int					ft_fill_new_map_row(char **new_map, char **map, int len,
		int **hit);
int					ft_fill_new_map(char **map, t_array *array, int len);
int					ft_after_map(t_array *array);
int					ft_check_conflicting_arg_str(char*arg, char *str);
int					put_error(void);
int					check_space(char c);
void				ft_free_map_new_hit(char ***map, t_array *array,
		char ***new_map);
void				ft_free_map_hit(char ***map, t_array *array);
int					ft_check_first_char(char **line, int i, int row);
void				error_wrong_configuration(void);
int					error_wrong_line(char **line, t_array *array);
int					check_char_dir(char c, char expected, char *data,
		char given_data);
int					end_line_ok(char *data, t_array *array, char **line, int i);
int					error_wrong_conf_wmap(char c, int i);
void				error_wrong_line_configuration(char *arg);
int					error_start_map(char c, int i);
void				which_missing(t_array *array);
void				putstr_error(char *str);
void				putstr_too_many(char *str);
void				ft_free_texture_array(t_array *array);
void				putstr_error_fc(char *arg);
void				ft_destroy_save(t_player *player);
int					ft_exit_esc_save(t_player *player);
#endif
