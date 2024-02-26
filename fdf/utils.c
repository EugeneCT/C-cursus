/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 21:41:01 by cliew             #+#    #+#             */
/*   Updated: 2024/02/26 09:12:46 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	min_max_abs(char *ops, float a, float b)
{
	if (ft_strcmp(ops, "min") == 0)
	{
		if (a < b)
			return (a);
		else
			return (b);
	}
	else if (ft_strcmp(ops, "max") == 0)
	{
		if (a > b)
			return (a);
		else
			return (b);
	}
	else if (ft_strcmp(ops, "abs") == 0)
	{
		if (a < 0)
			return (-a);
		else
			return (a);
	}
	return (0);
}

float	scale_to_fit(t_map *map)
{
	float	scale_x;
	float	scale_y;
	float	scale_factor;

	scale_x = WINDOW_WIDTH / map->max_x;
	scale_y = WINDOW_HEIGHT / map->max_y;
	scale_factor = min_max_abs("min", scale_x, scale_y);
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

int	ft_split_count(char *line, char space)
{
	char	**width_array;
	int		count;

	count = 0;
	width_array = NULL;
	width_array = ft_split(line, space);
	while (width_array[count] != NULL)
	{
		count++;
	}
	free_string_array(width_array);
	return (count);
}
