/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 19:21:44 by cliew             #+#    #+#             */
/*   Updated: 2024/02/21 20:20:41 by cliew            ###   ########.fr       */
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

	x=0;
	fd = open(file_name, O_RDONLY, 0);
	while (x <= max_x)
	{
		line=get_next_line(fd);
		if (line==NULL)
			break;
		split=ft_split(line,' ');
		y=0;
		while (y <= max_y)
		{
			map->coordinates[x][y].x=x;
			map->coordinates[x][y].y=y;
			map->coordinates[x][y].z=ft_atoi(split[y]);
			y++;
		}
		free(line);
		free(split);
		x++;
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
	cam->color_pallet = FALSE;
	cam->scale_factor = scale_to_fit(map);
	cam->scale_z = 1;
	cam->move_x = WINDOW_WIDTH / 2;
	cam->move_y = WINDOW_HEIGHT / 2;
	cam->alpha = 0;
	cam->beta = 0;
	cam->gamma = 0;
	return (cam);
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
	fdf->win = mlx_new_window(fdf->mlx, fdf->win_x, fdf->win_y, WINDOW_NAME);
	fdf->image = init_image(fdf->mlx);
	if (!fdf->image)
		exit_prog(fdf,"map","Image initialize Failed!",1);
	fdf->cam = init_cam(fdf->map);
	if (!fdf->cam)
		exit_prog(fdf,"all","Camera initialize Failed!",1);
	return fdf;
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

void	pixel_to_image(t_image *image, float x, float y, int color)
{
	int	pixel;

	pixel = ((int)y * image->line_bytes) + ((int)x * 4);
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

void	bresenham(t_win *fdf, t_point start, t_point end)
{
	float	x_step;
	float	y_step;
	int		max_steps;
	int		i_line;
	t_color	*color;

	x_step = end.x - start.x;
	y_step = end.y - start.y;
	max_steps = (int)min_max_abs("max",min_max_abs("abs",x_step,0), min_max_abs("abs",y_step,0));
	x_step /= max_steps;
	y_step /= max_steps;
	color = C_RED;
	// if (!color)
		// close_all(fdf, 8);
	i_line = 0;
	while (i_line < max_steps)
	{
		// start.color = get_color(color, i_line++, max_steps);
		if (start.x > 0 && start.y > 0 && start.x < WINDOW_WIDTH && start.y < \
				WINDOW_HEIGHT)
			pixel_to_image(fdf->image, start.x, start.y, color);
		start.x += x_step;
		start.y += y_step;
	}
	free(color);
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
	line->start.color = start.color;
	line->end.x = end.x;
	line->end.y = end.y;
	line->end.z = end.z;
	line->end.color = end.color;
	line->transform_z = min_max_abs("max",(fdf->map->max_z - fdf->map->min_z), \
		min_max_abs("max",fdf->map->max_x, fdf->map->max_y));
	return (line);
}

static void	render_line(t_win *fdf, t_point start, t_point end)
{
	start.z *= fdf->cam->scale_z;
	end.z *= fdf->cam->scale_z;
	fdf->image->line = init_line(start, end, fdf);
	bresenham(fdf, fdf->image->line->start, fdf->image->line->end);
	free(fdf->image->line);

}





void	render_img(t_win *fdf)
{
	int	x;
	int	y;

	// clear_image(fdf->image, MAX_PIXEL * 4);
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
	// print_menu(fdf);
}
int main()
{
	char	*file_name;
	t_win	*fdf;
	
	file_name="42.fdf";
	// if (argc != 2)
	// 	error(1);
	// file_name = argv[1];
	fdf = init_fdf(file_name);
	render_img(fdf);
	// if (argc!=2)
	// 	ft_errexit("ERRor!!",1);
	// else
	// 	printf("%s",argv[1]);
	// printf("%s",argv[0]);

	// mlx_loop(fdf->mlx);

	// printf("map-max x is %d and max_y is %d",fdf->map->max_x,fdf->map->max_y);
	
}


	// parse_map
