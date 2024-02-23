/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 21:18:15 by cliew             #+#    #+#             */
/*   Updated: 2024/02/23 21:47:32 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	fdf->map->max_z = 0;
	return (line);
}

int	init_coors(t_map *map, int cols, int rows)
{
	t_point	**coordinates;
	int		i;
	int		j;

	coordinates = malloc(cols * sizeof(t_point *));
	if (!coordinates)
		return (1);
	i = 0;
	while (i++ < cols)
	{
		coordinates[i - 1] = malloc(rows * sizeof(t_point));
		if (!coordinates[i - 1])
			return (1);
		j = 0;
		while (j++ < rows)
		{
			coordinates[i - 1][j - 1].x = 0;
			coordinates[i - 1][j - 1].y = 0;
			coordinates[i - 1][j - 1].z = 0;
		}
	}
	map->coordinates = coordinates;
	return (0);
}

t_map	*init_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->coordinates = NULL;
	map->max_x = 0;
	map->max_y = 0;
	map->min_z = 0;
	return (map);
}

t_image	*init_image(void *mlx)
{
	t_image	*image;

	image = malloc(sizeof(t_image));
	if (!image)
		return (NULL);
	image->image = mlx_new_image(mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	image->buffer = mlx_get_data_addr(image->image, &image->pixel_bits,
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
	cam->scale_factor = scale_to_fit(map);
	cam->scale_z = 0.5;
	cam->move_x = WINDOW_WIDTH / 2;
	cam->move_y = WINDOW_HEIGHT / 2;
	cam->alpha = 0;
	cam->beta = 0;
	cam->gamma = 0;
	return (cam);
}
