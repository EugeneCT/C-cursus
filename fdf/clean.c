/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 21:26:11 by cliew             #+#    #+#             */
/*   Updated: 2024/02/23 21:47:42 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	reset(t_win *fdf)
{
	fdf->cam->scale_factor = scale_to_fit(fdf->map);
	fdf->cam->scale_z = 0.5;
	fdf->cam->move_x = WINDOW_WIDTH / 2;
	fdf->cam->move_y = WINDOW_HEIGHT / 2;
	fdf->cam->alpha = 0;
	fdf->cam->beta = 0;
	fdf->cam->gamma = 0;
}

void	close_coordinates(t_point **coordinates, int width)
{
	int	i;

	i = 0;
	while (i < width)
	{
		free(coordinates[i]);
		i++;
	}
	free(coordinates);
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

void	free_string_array(char **string_array)
{
	int	i;

	i = 0;
	if (string_array == NULL)
	{
		return ;
	}
	while (string_array[i] != NULL)
	{
		free(string_array[i]);
		i++;
	}
	free(string_array);
}

void	exit_prog(t_win *fdf, char *type, char *exit_msg, int exit_code)
{
	if (ft_strcmp(type, "map") == 0)
		free(fdf->map);
	if (ft_strcmp(type, "coor") == 0)
	{
		close_coordinates(fdf->map->coordinates, fdf->map->max_x);
		free(fdf->map);
		mlx_destroy_window(fdf->mlx, fdf->win);
		mlx_destroy_display(fdf->mlx);
		free(fdf->mlx);
	}
	if (ft_strcmp(type, "all") == 0)
	{
		close_coordinates(fdf->map->coordinates, fdf->map->max_x);
		mlx_destroy_image(fdf->mlx, fdf->image->image);
		free(fdf->map);
		free(fdf->image);
		free(fdf->cam);
		free(fdf->mouse);
		mlx_destroy_window(fdf->mlx, fdf->win);
		mlx_destroy_display(fdf->mlx);
		free(fdf->mlx);
	}
	free(fdf);
	ft_errexit(exit_msg, exit_code);
}
