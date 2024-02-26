/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 21:31:18 by cliew             #+#    #+#             */
/*   Updated: 2024/02/26 09:12:35 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	render_line(t_win *fdf, t_point start, t_point end)
{
	start.z *= fdf->cam->scale_z;
	end.z *= fdf->cam->scale_z;
	fdf->image->line = init_line(start, end, fdf);
	rotate(fdf->cam, fdf->image->line);
	project(fdf->cam, fdf->image->line);
	transform(fdf->cam, fdf->image->line);
	if (end.z > 0 || start.z > 0)
		bresenham(fdf, fdf->image->line->start, fdf->image->line->end, C_GREEN);
	else
		bresenham(fdf, fdf->image->line->start, fdf->image->line->end,
			C_WHITE);
	free(fdf->image->line);
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

void	bresenham(t_win *fdf, t_point start, t_point end, int color)
{
	float	x_step;
	float	y_step;
	int		max_steps;
	int		i_line;

	x_step = end.x - start.x;
	y_step = end.y - start.y;
	max_steps = (int)min_max_abs("max", min_max_abs("abs", x_step, 0),
			min_max_abs("abs", y_step, 0));
	x_step /= max_steps;
	y_step /= max_steps;
	i_line = 0;
	while (i_line < max_steps)
	{
		if (start.x > 0 && start.y > 0 && start.x < WINDOW_WIDTH
			&& start.y < WINDOW_HEIGHT)
			pixel_to_image(fdf->image, start.x, start.y, color);
		start.x += x_step;
		start.y += y_step;
		i_line++;
	}
}

int	fill_map_xy(t_map *map, char *file_name)
{
	char	*line;
	int		fd;
	int		rows;

	fd = open(file_name, O_RDONLY, 0);
	line = get_next_line(fd);
	map->max_x = ft_split_count(line, ' ');
	free(line);
	rows = 1;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			map->max_y = rows;
			break ;
		}
		if (ft_isprint(*line))
			rows++;
		free(line);
	}
	return (0);
}

int	fill_coors(t_map *map, int max_x, int max_y, int fd)
{
	char	*line;
	char	**split;
	int		x;
	int		y;

	y = 0;
	while (y <= max_y)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		split = ft_split(line, ' ');
		x = 0;
		while (x < max_x && split[x])
		{
			map->coordinates[x][y].x = x;
			map->coordinates[x][y].y = y;
			map->coordinates[x][y].z = ft_atoi(split[x]);
			x++;
		}
		free(line);
		free_string_array(split);
		y++;
	}
	return (0);
}
