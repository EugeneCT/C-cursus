/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 19:21:44 by cliew             #+#    #+#             */
/*   Updated: 2024/02/20 16:58:10 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void fill_map_xy(t_map *map,char* file_name)
{
	char* line;
	int fd;
	char* width_array;
	int rows;
	
	fd = open(file_name, O_RDONLY, 0);
	line = get_next_line(fd);
	width_array=ft_split(line,' ');
	map->max_x=sizeof(width_array)/sizeof(width_array[0]);
	free(width_array);
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
		width_array=ft_split(line,' ');
		if (map->max_x != sizeof(width_array)/sizeof(width_array[0]))
			return (0);
		if (ft_isprint(*line))
			rows++;
		free(line);
	}
}

int fill_map_details(t_map *map,char* file_name)
{
	int fd;
	
	fd = open(file_name, O_RDONLY, 0);
	if (fd < 0)
	{	
		close(fd);
		return (ft_puterr("File open error!",1));
	}
	
	fill_map_xy(map);
	
	
}

void init_map(t_map* map)
{
	t_map	*map;
	int fd;
	
	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->coordinates=NULL;
	map->max_x=0;
	map->max_y=0;
	map->min_z=0;
}

int main()
{
	char* file_name = "42.fdf";
	
	t_win* fdf;

	int fd;

	fdf = malloc(sizeof(t_win));
	init_map(fdf->map);
	fill_map_details(fdf->map,file_name);

}


	// parse_map
