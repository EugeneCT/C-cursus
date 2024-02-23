/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 19:21:44 by cliew             #+#    #+#             */
/*   Updated: 2024/02/23 14:52:23 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
float min_max_abs(char* ops,float a,float b)
{
	if (ft_strcmp(ops,"min")==0)
	{
	if (a < b)
		return (a);
	else
		return (b);
	}
	else if (ft_strcmp(ops,"max")==0)
	{
	if (a > b)
		return (a);
	else
		return (b);
	}
	else if (ft_strcmp(ops,"abs")==0)
	{
	if (a < 0)
		return (-a);
	else
		return (a);
	}
	return 0;
}

// static int	color_gradient(t_color *color, float progress)
// {
// 	int		r;
// 	int		g;
// 	int		b;

// 	r = color->delta_r * progress;
// 	if (r < -255)
// 		r = 0;
// 	else if (r > 255)
// 		r = 255;
// 	r = r << 16;
// 	g = color->delta_g * progress;
// 	if (g < -255)
// 		g = 0;
// 	else if (g > 255)
// 		g = 255;
// 	g = g << 8;
// 	b = color->delta_b * progress;
// 	if (b < -255)
// 		b = 0;
// 	else if (b > 255)
// 		b = 255;
// 	return (color->start_color + r + g + b);
// }



// int	get_color(t_color *color, int i_line, int line_size)
// {
// 	float	progress;

// 	progress = (float) i_line / (float) line_size;
// 	return (color_gradient(color, progress));
// }

// t_color	*color_init(t_point start, t_point end)
// {
// 	t_color	*color;

// 	color = malloc(sizeof(t_color));
// 	if (!color)
// 		return (NULL);
// 	color->start_color = start.color;
// 	color->start_r = (C_RED & start.color) >> 16;
// 	color->start_g = (C_GREEN & start.color) >> 8;
// 	color->start_b = (C_BLUE & start.color);
// 	color->end_color = end.color;
// 	color->end_r = (C_RED & end.color) >> 16;
// 	color->end_g = (C_GREEN & end.color) >> 8;
// 	color->end_b = (C_BLUE & end.color);
// 	color->delta_r = (color->end_r - color->start_r);
// 	color->delta_g = (color->end_g - color->start_g);
// 	color->delta_b = (color->end_b - color->start_b);
// 	return (color);
// }

// t_color	*color_pallet_init(int min_color, int max_color)
// {
// 	t_color	*color;

// 	color = malloc(sizeof(t_color));
// 	if (!color)
// 		return (NULL);
// 	color->start_color = min_color;
// 	color->start_r = (C_RED & min_color) >> 16;
// 	color->start_g = (C_GREEN & min_color) >> 8;
// 	color->start_b = (C_BLUE & min_color);
// 	color->end_color = max_color;
// 	color->end_r = (C_RED & max_color) >> 16;
// 	color->end_g = (C_GREEN & max_color) >> 8;
// 	color->end_b = (C_BLUE & max_color);
// 	color->delta_r = (color->end_r - color->start_r);
// 	color->delta_g = (color->end_g - color->start_g);
// 	color->delta_b = (color->end_b - color->start_b);
// 	return (color);
// }

// static void	apply_colors(t_win *fdf, t_point *point)
// {
// 	t_color	*col;

// 	col = NULL;
// 	if (fdf->cam->color_pallet == FALSE)
// 	{
// 		if (point->color == -1)
// 			point->color = LINE_DEFAULT;
// 	}
// 	else
// 	{
// 		if (point->z >= 0)
// 		{
// 			col = color_pallet_init(C_GREY, C_ORANGY);
// 			point->color = get_color(col, min_max_abs("abs",point->z,0), min_max_abs("abs",fdf->map->max_z,0));
// 			free(col);
// 		}
// 		else
// 		{
// 			col = color_pallet_init(C_GREY, C_BLUEY);
// 			point->color = get_color(col, min_max_abs("abs",point->z,0), min_max_abs("abs",fdf->map->max_z,0));
// 			free(col);
// 		}
// 	}
// }


static void	close_coordinates(t_point **coordinates, int width)
{
	int		i;

	i = 0;
	while (i < width)
	{
		free(coordinates[i]);
		i++;
	}
	free(coordinates);
}


void	exit_prog(t_win *fdf,char* type,char* exit_msg,int exit_code)
{
	close_coordinates(fdf->map->coordinates, fdf->map->max_x);
	free(fdf->map);
	if (ft_strcmp(type,"all")==0)
	{
		mlx_destroy_image(fdf->mlx, fdf->image->image);
		free(fdf->image);
		free(fdf->cam);
		mlx_destroy_window(fdf->mlx, fdf->win);
		mlx_destroy_display(fdf->mlx);
		free(fdf->mlx);

	}
	// else if (ft_strcmp(type,"map")==0)
	// {
	// 	mlx_destroy_window(fdf->mlx, fdf->win);
	// 	mlx_destroy_display(fdf->mlx);
	// 	free(fdf->mlx);
	// }
	free(fdf);
	ft_errexit(exit_msg,exit_code);
}



float	scale_to_fit(t_map *map)
{
	float	scale_x;
	float	scale_y;
	float	scale_factor;

	scale_x = WINDOW_WIDTH / map->max_x;
	scale_y = WINDOW_HEIGHT / map->max_y;
	scale_factor = min_max_abs("min",scale_x,scale_y);

	if (scale_factor < 4)
		return (2);
	return (scale_factor / 2);
}


void	center_to_origin(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->max_y)
	{
		x = 0;
		while (x < map->max_x)
		{
			map->coordinates[x][y].x -= map->max_x / 2;
			map->coordinates[x][y].y -= map->max_y / 2;
			x++;
		}
		y++;
	}
}

int ft_split_count(char* line, char space)
{

	char** width_array;
	int count;

	count=0;
	width_array=NULL;
	width_array=ft_split(line,space);
	while (width_array[count] != NULL) {
		count++;
	}
	free(width_array);
	return count;

}

int fill_map_xy(t_map *map,char* file_name)
{
	char* line;
	int fd;
	int rows;
	
	fd = open(file_name, O_RDONLY, 0);
	line = get_next_line(fd);
	map->max_x=ft_split_count(line,' ');
	free(line);
	rows=1;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			map->max_y=rows;
			break ;
		}
		if (map->max_x != ft_split_count(line,' '))
			return (1);
		if (ft_isprint(*line))
			rows++;
		free(line);
	}
	return 0;
}

int init_coors(t_map* map, int cols, int rows)
{
	t_point	**coordinates;
	int		i;
	int		j;

	coordinates = malloc(cols * sizeof(t_point *));
	if (!coordinates)
		return (1);
	i = 0;
	while (i < cols)
	{
		coordinates[i] = malloc(rows * sizeof(t_point));
		if (!coordinates[i])
			return (1);
		j = 0;
		while (j < rows)
		{
			coordinates[i][j].x = 0;
			coordinates[i][j].y = 0;
			coordinates[i][j].z = 0;
			coordinates[i][j].color = -1;
			j++;
		}
		i++;
	
	}
	map->coordinates=coordinates;
	return 0;
}

int fill_coors( t_map *map,int max_x,int max_y,char *file_name)
{
	int		fd;
	char	*line;
	char	**split;
	int x;
	int y;

	y=0;
	fd = open(file_name, O_RDONLY, 0);
	while (y <= max_y)
	{
		line=get_next_line(fd);
		if (line==NULL)
			break;
		split=ft_split(line,' ');
		x=0;
		while (x < max_x)
		{
			map->coordinates[x][y].x=x;
			map->coordinates[x][y].y=y;
			map->coordinates[x][y].z=ft_atoi(split[x]);
			x++;
		}
		free(line);
		free(split);
		y++;
	}
	return (0);
}

int fill_map_details(t_map *map,char* file_name)
{
	int fd;
	
	fd = open(file_name, O_RDONLY, 0);
	if (fd < 0)
	{	
		close(fd);
		return 1;
	}
	
	if (fill_map_xy(map,file_name))
		return 1;
	if (init_coors(map,map->max_x,map->max_y))
		return 1;
	fill_coors(map,map->max_x,map->max_y,file_name);
	return 0;
}


t_map* init_map()
{
	t_map* map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->coordinates=NULL;
	map->max_x=0;
	map->max_y=0;
	map->min_z=0;

	
	return (map);
}

t_image	*init_image(void *mlx)
{
	t_image	*image;

	image = malloc(sizeof(t_image));
	if (!image)
		return (NULL);
	image->image = mlx_new_image(mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	image->buffer = mlx_get_data_addr(image->image, &image->pixel_bits, \
			&image->line_bytes, &image->endian);
	image->line = NULL;
	return (image);
}

t_cam	*init_cam(t_map *map)
{
	t_cam	*cam;

	cam = malloc(sizeof(t_cam));
	if (!cam)
		return (NULL);
	cam->projection = ISOMETRIC;
	// cam->color_pallet = FALSE;
	cam->scale_factor = scale_to_fit(map);
	cam->scale_z = 0.5;
	cam->move_x = WINDOW_WIDTH / 2;
	cam->move_y = WINDOW_HEIGHT / 2;
	cam->alpha = 0;
	cam->beta = 0;
	cam->gamma = 0;
	return (cam);
}

t_mouse	*init_mouse()
{

	t_mouse *mousey;

	mousey = malloc(sizeof(t_mouse));
	mousey->mouse_x=0;
	mousey->mouse_y=0;
	mousey->prev_mouse_x=0;
	mousey->prev_mouse_y=0;
	mousey->mouse_x_diff=0;
	mousey->mouse_y_diff=0;
	mousey->is_pressed=0;
	return mousey;
}




t_win	*init_fdf(char *file_name)
{
	t_win* fdf;
	
	fdf = malloc(sizeof(t_win));
	fdf->map=init_map();
	if (!fdf->map)
		exit_prog(fdf,"map","Map initialize Failed!",1);
	if (fill_map_details(fdf->map,file_name))
		exit_prog(fdf,"map","Map initialize Failed!",2);
	fdf->mlx = mlx_init();
	fdf->win_x = WINDOW_WIDTH;
	fdf->win_y = WINDOW_HEIGHT;
	center_to_origin(fdf->map);
	fdf->win = mlx_new_window(fdf->mlx, fdf->win_x, fdf->win_y, WINDOW_NAME);
	fdf->image = init_image(fdf->mlx);
	if (!fdf->image)
		exit_prog(fdf,"map","Image initialize Failed!",1);
	fdf->cam = init_cam(fdf->map);
	if (!fdf->cam)
		exit_prog(fdf,"all","Camera initialize Failed!",1);

	fdf->mouse = init_mouse();
	if (!fdf->mouse)
		exit_prog(fdf,"all","Mouse initialize Failed!",1);
	return fdf;
}

void	pixel_to_image(t_image *image, float x, float y, int color)
{
	int	pixel;

	pixel = ((int)y * image->line_bytes) + ((int)x * 4);
	image->buffer[pixel] = (color);

	if (image->endian == 1)
	{
		image->buffer[pixel + 0] = (color >> 24);
		image->buffer[pixel + 1] = (color >> 16) & 0xff;
		image->buffer[pixel + 2] = (color >> 8) & 0xff;
		image->buffer[pixel + 3] = (color) & 0xff;
	}
	else if (image->endian == 0)
	{
		image->buffer[pixel + 0] = (color) & 0xff;
		image->buffer[pixel + 1] = (color >> 8) & 0xff;
		image->buffer[pixel + 2] = (color >> 16) & 0xff;
		image->buffer[pixel + 3] = (color >> 24);
	}
}


void	clear_image(t_image *image, int image_size)
{
	int	x;
	int	y;

	ft_bzero(image->buffer, image_size);
	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			pixel_to_image(image, x, y, BACKGROUND_DEFAULT);
			x++;
		}
		y++;
	}
}


void	bresenham(t_win *fdf, t_point start, t_point end,int color)
{
	float	x_step;
	float	y_step;
	int		max_steps;
	int		i_line;


	x_step = end.x - start.x;
	y_step = end.y - start.y;
	max_steps = (int)min_max_abs("max",min_max_abs("abs",x_step,0), min_max_abs("abs",y_step,0));
	x_step /= max_steps;
	y_step /= max_steps;


	i_line = 0;
	while (i_line < max_steps)
	{
		if (start.x > 0 && start.y > 0 && start.x < WINDOW_WIDTH && start.y < \
				WINDOW_HEIGHT)

			pixel_to_image(fdf->image, start.x, start.y, color);
		start.x += x_step;
		start.y += y_step;
		i_line++;
	}
	// free(color);
}


t_line	*init_line(t_point start, t_point end, t_win *fdf)
{
	t_line	*line;

	line = malloc(sizeof(t_line));
	if (!line)
		return (NULL);
	line->start.x = start.x;
	line->start.y = start.y;
	line->start.z = start.z;
	line->end.x = end.x;
	line->end.y = end.y;
	line->end.z = end.z;
	line->transform_z = min_max_abs("max",(fdf->map->max_z - fdf->map->min_z), \
		min_max_abs("max",fdf->map->max_x, fdf->map->max_y));
	return (line);
}

static void	render_line(t_win *fdf, t_point start, t_point end)
{
	start.z *= fdf->cam->scale_z;
	end.z *= fdf->cam->scale_z;
	// apply_colors(fdf, &start);
	// apply_colors(fdf, &end);
	fdf->image->line = init_line(start, end, fdf);
	rotate(fdf->cam, fdf->image->line);
	project(fdf->cam, fdf->image->line);
	transform(fdf->cam, fdf->image->line);
	if (end.z>0|| start.z>0)
		bresenham(fdf, fdf->image->line->start, fdf->image->line->end,8421376);
	else
		bresenham(fdf, fdf->image->line->start, fdf->image->line->end,16777215);

	free(fdf->image->line);

}

void	print_menu(t_win *fdf)
{
	int		y;
	// char	*projection;
	void	*mlx;
	void	*win;
	char	*str;

	y = 0;
	mlx = fdf->mlx;
	win = fdf->win;
	// projection = get_projection_name(fdf);
	// mlx_string_put(mlx, win, 50, y += 50, C_TEXT, projection);
	str=ft_strjoin("Alpha is : ",ft_itoa(fdf->cam->alpha));
	mlx_string_put(mlx, win, 50, y += 35, C_TEXT,str );
	free(str);

	str=ft_strjoin("Beta is : ",ft_itoa(fdf->cam->beta));
	mlx_string_put(mlx, win, 50, y += 35, C_TEXT,str );
	free(str);
	str=ft_strjoin("Gamma is : ",ft_itoa(fdf->cam->gamma));
	mlx_string_put(mlx, win, 50, y += 35, C_TEXT,str );
	free(str);

	str=ft_strjoin("Mouse x is : ",ft_itoa(fdf->mouse->mouse_x));
	mlx_string_put(mlx, win, 50, y += 35, C_TEXT,str );
	free(str);

	str=ft_strjoin("Mouse y is : ",ft_itoa(fdf->mouse->mouse_y));
	mlx_string_put(mlx, win, 50, y += 35, C_TEXT,str );
	free(str);

	str=ft_strjoin("Mouse pressed is : ",ft_itoa(fdf->mouse->is_pressed));
	mlx_string_put(mlx, win, 50, y += 35, C_TEXT,str );
	free(str);

	str=ft_strjoin("Prev Mouse x is : ",ft_itoa(fdf->mouse->prev_mouse_x));
	mlx_string_put(mlx, win, 50, y += 35, C_TEXT,str );
	free(str);

	str=ft_strjoin("Prev Mouse y is : ",ft_itoa(fdf->mouse->prev_mouse_y));
	mlx_string_put(mlx, win, 50, y += 35, C_TEXT,str );
	free(str);

	str=ft_strjoin("x_diff pressed is : ",ft_itoa(fdf->mouse->mouse_x_diff));
	mlx_string_put(mlx, win, 50, y += 35, C_TEXT,str );
	free(str);
	str=ft_strjoin("y_diff pressed is : ",ft_itoa(fdf->mouse->mouse_y_diff));
	mlx_string_put(mlx, win, 50, y += 35, C_TEXT,str );
	free(str);



	
	mlx_string_put(mlx, win, 50, y += 35, C_TEXT, "Press 'ESC' to close");
	mlx_string_put(mlx, win, 50, y += 35, C_TEXT, "Zoom: press '-' or '+'");
	mlx_string_put(mlx, win, 50, y += 20, C_TEXT, "Move: press arrow keys");
	mlx_string_put(mlx, win, 50, y += 20, C_TEXT, "Rotate X: press 'S' or 'W'");
	mlx_string_put(mlx, win, 50, y += 20, C_TEXT, "Rotate Y: press 'Q' or 'E'");
	mlx_string_put(mlx, win, 50, y += 20, C_TEXT, "Rotate Z: press 'A' or 'D'");
	mlx_string_put(mlx, win, 50, y += 20, C_TEXT, "Scale Z: press 'Z' or 'X'");
	mlx_string_put(mlx, win, 50, y += 20, C_TEXT, "(Z scale limited to 100%)");
	mlx_string_put(mlx, win, 50, y += 35, C_TEXT, "To change projection view:");
	mlx_string_put(mlx, win, 50, y += 20, C_TEXT, "Isometric: press 'I'");
	mlx_string_put(mlx, win, 50, y += 20, C_TEXT, "Top View: press 'O'");
	mlx_string_put(mlx, win, 50, y += 35, C_TEXT, "Reset view: press 'R'");
}


void	render_img(t_win *fdf)
{
	int	x;
	int	y;

	clear_image(fdf->image, MAX_PIXEL * 4);
	y = 0;
	while (y < fdf->map->max_y)
	{
		x = 0;
		while (x < fdf->map->max_x)
		{
			if (x < fdf->map->max_x - 1)
				render_line(fdf, fdf->map->coordinates[x][y], \
					fdf->map->coordinates[x + 1][y]);
			if (y < fdf->map->max_y - 1)
				render_line(fdf, fdf->map->coordinates[x][y], \
					fdf->map->coordinates[x][y + 1]);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->image->image, 0, 0);
	print_menu(fdf);
}


static void	key_translate(int keycode, t_win *fdf)
{
	if (keycode == KEY_RIGHT)
		fdf->cam->move_x += 10;
	else if (keycode == KEY_LEFT)
		fdf->cam->move_x -= 10;
	else if (keycode == KEY_DOWN)
		fdf->cam->move_y += 10;
	else if (keycode == KEY_UP)
		fdf->cam->move_y -= 10;
}

static void	key_scale(int keycode, t_win *fdf)
{
	if (keycode == KEY_PLUS)
		fdf->cam->scale_factor += 1;
	else if (keycode == KEY_MINUS)
		fdf->cam->scale_factor -= 1;
	else if (keycode == KEY_Z && fdf->cam->scale_z > -1)
		fdf->cam->scale_z -= 0.1;
	else if (keycode == KEY_X && fdf->cam->scale_z < 1)
		fdf->cam->scale_z += 0.1;
}

static void	key_rotate(int keycode, t_win *fdf)
{
	if (keycode == KEY_S)
		fdf->cam->alpha -= (5 * ANG_1);
	else if (keycode == KEY_W)
		fdf->cam->alpha += (5 * ANG_1);
	else if (keycode == KEY_A)
		fdf->cam->gamma -= (5 * ANG_1);
	else if (keycode == KEY_D)
		fdf->cam->gamma += (5 * ANG_1);
	else if (keycode == KEY_Q)
		fdf->cam->beta -= (5 * ANG_1);
	else if (keycode == KEY_E)
		fdf->cam->beta += (5 * ANG_1);
}

static void	key_project(int keycode, t_win *fdf)
{
	
	if (keycode == KEY_I)
		fdf->cam->projection = ISOMETRIC;
	else if (keycode == KEY_O)
		fdf->cam->projection = TOP;
}

void	reset(t_win *fdf)
{
	fdf->cam->scale_factor = scale_to_fit(fdf->map);
	fdf->cam->scale_z = 1;
	fdf->cam->move_x = WINDOW_WIDTH / 2;
	fdf->cam->move_y = WINDOW_HEIGHT / 2;
	fdf->cam->alpha = 0;
	fdf->cam->beta = 0;
	fdf->cam->gamma = 0;
}







int	key_handle(int keycode, t_win *fdf)
{
	if (keycode == KEY_ESC)
		exit_prog(fdf,"all","Bye!",0);
	else if (keycode == KEY_RIGHT || keycode == KEY_LEFT || keycode == KEY_UP \
		|| keycode == KEY_DOWN)
		key_translate(keycode, fdf);
	else if (keycode == KEY_PLUS || keycode == KEY_MINUS || keycode == KEY_Z \
		|| keycode == KEY_X)
		key_scale(keycode, fdf);
	else if (keycode == KEY_A || keycode == KEY_S || keycode == KEY_D \
		|| keycode == KEY_Q || keycode == KEY_W || keycode == KEY_E)
		key_rotate(keycode, fdf);
	else if (keycode == KEY_P || keycode == KEY_I || keycode == KEY_O)
		key_project(keycode, fdf);
	else if (keycode == KEY_R)
		reset(fdf);
	render_img(fdf);
	return (0);
}


int p_mouse_mos(int x, int y, t_win *fdf)
{

	if (fdf->mouse->is_pressed==0)
	{
		(fdf->mouse->prev_mouse_x)=x;
		(fdf->mouse->prev_mouse_y)=y;
	}
	else if (fdf->mouse->is_pressed==1)
	{
		(fdf->mouse->mouse_x)=x;
		(fdf->mouse->mouse_y)=y;
		fdf->mouse->mouse_x_diff=fdf->mouse->mouse_x-fdf->mouse->prev_mouse_x;
		fdf->mouse->mouse_y_diff=fdf->mouse->mouse_y-fdf->mouse->prev_mouse_y;
		// fdf->cam->alpha -= (fdf->mouse->mouse_x_diff * ANG_1);
		fdf->cam->gamma += ((fdf->mouse->mouse_x_diff/100) * ANG_1);
		// fdf->cam->gamma -= (y_diff * ANG_1);
		fdf->cam->alpha -= ((fdf->mouse->mouse_y_diff/100) * ANG_1);
		render_img(fdf);

	}
	// render_img(fdf);

	return 1;

}

int		mouse_pressed_hook(int button, int x, int y, t_win *fdf)
{
	if (button==1)
		fdf->mouse->is_pressed = 1;
	render_img(fdf);
	return x+y;


}

int		mouse_released_hook(int button, int x, int y, t_win *fdf)
{
	fdf->mouse->is_pressed = 0;
	render_img(fdf);

	return (x+y+button);
}

int main(int argc, char **argv)
{
	char	*file_name;
	t_win	*fdf;
	// file_name="42.fdf";
	if (argc != 2)
		ft_errexit("ERRor!!",1);
	file_name = argv[1];
	fdf = init_fdf(file_name);

	render_img(fdf);
	// if (argc!=2)
	// 	ft_errexit("ERRor!!",1);
	// else
	// 	printf("%s",argv[1]);
	// printf("%s",argv[0]);


	

	mlx_key_hook(fdf->win, &key_handle, fdf);

	mlx_hook(fdf->win, 6, (1L<<6), &p_mouse_mos, fdf);

	mlx_hook(fdf->win, 4, (1L<<2), &mouse_pressed_hook, fdf);
	mlx_hook(fdf->win, 5, (1L<<3), &mouse_released_hook, fdf);
	mlx_loop(fdf->mlx);
	
}


	// parse_map
