/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 19:21:44 by cliew             #+#    #+#             */
/*   Updated: 2024/02/21 09:48:16 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
t_point	**init_coors(int cols, int rows)
{
	t_point	**coordinates;
	int		i;
	int		j;

	coordinates = malloc(cols * sizeof(t_point *));
	if (!coordinates)
		return (NULL);
	i = 0;
	while (i < cols)
	{
		coordinates[i] = malloc(rows * sizeof(t_point));
		if (!coordinates[i])
			return (NULL);
		j = 0;
		while (j < rows)
		{
			coordinates[i][j].x = 0;
			coordinates[i][j].y = 0;
			coordinates[i][j].z = 0;
			coordinates[i][j].color = 0;
			j++;
		}
		i++;
	}
	return (coordinates);
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
		return (ft_puterr("File open error!",1));
	}
	
	fill_map_xy(map,file_name);
	map->coordinates =init_coors(map->max_x,map->max_y);
	fill_coors(map,map->max_x,map->max_y,file_name);
	return 1;
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

int main()
{
	char* file_name = "42.fdf";
	
	t_win* fdf;

	fdf = malloc(sizeof(t_win));
	fdf->map=init_map();
	fill_map_details(fdf->map,file_name);
	printf("map-max x is %d and max_y is %d",fdf->map->max_x,fdf->map->max_y);

}


	// parse_map
