/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 23:37:26 by cliew             #+#    #+#             */
/*   Updated: 2024/02/23 21:48:47 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../../minilibx-linux/mlx.h"
# include "./libft_max/getnextline/gnl.h"
# include "./libft_max/libft/libft.h"
# include "./libft_max/printf/printf.h"
# include "colors.h"
# include "keys.h"
# include <fcntl.h>
# include <math.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_mouse
{
	int		mouse_x;
	int		mouse_y;
	int		prev_mouse_x;
	int		prev_mouse_y;
	int		is_pressed;
	int		mouse_x_diff;
	int		mouse_y_diff;

}			t_mouse;

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
}			t_point;

typedef struct s_map
{
	t_point	**coordinates;
	int		max_x;
	int		max_y;
	int		max_z;
	int		min_z;
}			t_map;

typedef struct s_line
{
	t_point	start;
	t_point	end;
}			t_line;

typedef struct s_image
{
	void	*image;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	char	*buffer;
	t_line	*line;
}			t_image;

typedef struct s_cam
{
	int		projection;
	float	scale_factor;
	float	scale_z;
	float	move_x;
	float	move_y;
	double	alpha;
	double	beta;
	double	gamma;
}			t_cam;

typedef struct s_win
{
	t_map	*map;
	void	*mlx;
	int		win_x;
	int		win_y;
	void	*win;
	t_image	*image;
	t_cam	*cam;
	t_mouse	*mouse;
}			t_win;

/*Window basic configuration*/
# define WINDOW_NAME "fdf"
# define WINDOW_WIDTH 1200
# define WINDOW_HEIGHT 900
# define MAX_PIXEL 1080000

/* Colors configuration*/
# define BACKGROUND_DEFAULT C_GREY
# define C_TEXT C_WHITE

/*Conversion bases & useful angles in rad*/
# define HEXADECIMAL_L_BASE "0123456789abcdef"
# define ANG_1 0.01745329
# define ANG_30 0.52359877
# define ANG_45 0.78539816

/*Enumerator for projection names*/
enum		e_projection
{
	ISOMETRIC,
	TOP
};

void		render_img(t_win *fdf);
t_win		*init_fdf(char *file_name);
int			fill_map_details(t_map *map, char *file_name);
void		print_menu(t_win *fdf);

/*Rotate */
void		rotate(t_cam *cam, t_line *line);
void		rotate_x(t_line *line, double angle);
void		rotate_y(t_line *line, double angle);
void		rotate_z(t_line *line, double angle);

/*Transform */
void		isometric(t_line *line);
void		project(t_cam *cam, t_line *line);
void		transform(t_cam *cam, t_line *line);
void		scale(t_line *line, int scale_factor);
void		translate(t_line *line, int move_x, int move_y);

/*Mouse_events*/
t_mouse		*init_mouse(void);
int			p_mouse_mos(int x, int y, t_win *fdf);
int			mouse_pressed_hook(int button, int x, int y, t_win *fdf);
int			mouse_released_hook(int button, int x, int y, t_win *fdf);
int			esc_window(t_win *fdf);

/*Key events*/
void		key_project(int keycode, t_win *fdf);
void		key_rotate(int keycode, t_win *fdf);
void		key_scale(int keycode, t_win *fdf);
void		key_translate(int keycode, t_win *fdf);
int			key_handle(int keycode, t_win *fdf);

/*Cleans*/
void		reset(t_win *fdf);
void		exit_prog(t_win *fdf, char *type, char *exit_msg, int exit_code);
void		free_string_array(char **string_array);
void		close_coordinates(t_point **coordinates, int width);
void		clear_image(t_image *image, int image_size);

/*Inits*/
int			init_coors(t_map *map, int cols, int rows);
t_map		*init_map(void);
t_image		*init_image(void *mlx);
t_cam		*init_cam(t_map *map);
t_line		*init_line(t_point start, t_point end, t_win *fdf);

/*Render*/
int			fill_coors(t_map *map, int max_x, int max_y, int fd);
int			fill_map_xy(t_map *map, char *file_name);
void		bresenham(t_win *fdf, t_point start, t_point end, int color);
void		pixel_to_image(t_image *image, float x, float y, int color);
void		render_line(t_win *fdf, t_point start, t_point end);

/*Utils*/
float		min_max_abs(char *ops, float a, float b);
int			ft_split_count(char *line, char space);
void		center_to_origin(t_map *map);
float		scale_to_fit(t_map *map);

#endif