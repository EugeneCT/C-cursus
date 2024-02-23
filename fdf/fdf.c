/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 19:21:44 by cliew             #+#    #+#             */
/*   Updated: 2024/02/23 21:47:36 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fill_map_details(t_map *map, char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY, 0);
	if (fd < 0)
	{
		return (1);
	}
	if (fill_map_xy(map, file_name))
		return (1);
	if (init_coors(map, map->max_x, map->max_y))
		return (1);
	fd = open(file_name, O_RDONLY, 0);
	fill_coors(map, map->max_x, map->max_y, fd);
	return (0);
}

void	print_menu(t_win *fdf)
{
	int		y;
	void	*mlx;
	void	*win;

	y = 0;
	mlx = fdf->mlx;
	win = fdf->win;
	mlx_string_put(mlx, win, 30, y += 50, C_TEXT, "Press 'ESC' to close");
	mlx_string_put(mlx, win, 30, y += 50, C_TEXT, "Zoom: press '-' or '+'");
	mlx_string_put(mlx, win, 30, y += 50, C_TEXT, "Move: press arrow keys");
	mlx_string_put(mlx, win, 30, y += 50, C_TEXT, "Rotate X: press 'S' or 'W'");
	mlx_string_put(mlx, win, 30, y += 50, C_TEXT, "Rotate Y: press 'Q' or 'E'");
	mlx_string_put(mlx, win, 30, y += 50, C_TEXT, "Rotate Z: press 'A' or 'D'");
	mlx_string_put(mlx, win, 30, y += 20, C_TEXT, "or drag left/right");
	mlx_string_put(mlx, win, 30, y += 75, C_TEXT, "To change projection view:");
	mlx_string_put(mlx, win, 30, y += 50, C_TEXT, "Isometric: press 'I'");
	mlx_string_put(mlx, win, 30, y += 50, C_TEXT, "Top View: press 'O'");
	mlx_string_put(mlx, win, 30, y += 50, C_TEXT, "Reset view: press 'R'");
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
				render_line(fdf, fdf->map->coordinates[x][y],
					fdf->map->coordinates[x + 1][y]);
			if (y < fdf->map->max_y - 1)
				render_line(fdf, fdf->map->coordinates[x][y],
					fdf->map->coordinates[x][y + 1]);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->image->image, 0, 0);
	print_menu(fdf);
}

t_win	*init_fdf(char *file_name)
{
	t_win	*fdf;

	fdf = malloc(sizeof(t_win));
	fdf->map = init_map();
	if (!fdf->map)
		exit_prog(fdf, "pre-map", "Map initialize Failed!", 1);
	if (fill_map_details(fdf->map, file_name))
		exit_prog(fdf, "map", "Map initialize Failed!", 2);
	fdf->mlx = mlx_init();
	fdf->win_x = WINDOW_WIDTH;
	fdf->win_y = WINDOW_HEIGHT;
	center_to_origin(fdf->map);
	fdf->win = mlx_new_window(fdf->mlx, fdf->win_x, fdf->win_y, WINDOW_NAME);
	fdf->image = init_image(fdf->mlx);
	if (!fdf->image)
		exit_prog(fdf, "coor", "Image initialize Failed!", 1);
	fdf->cam = init_cam(fdf->map);
	fdf->mouse = init_mouse();
	if (!fdf->mouse)
		exit_prog(fdf, "all", "Mouse initialize Failed!", 1);
	return (fdf);
}

int	main(int argc, char **argv)
{
	char	*file_name;
	t_win	*fdf;

	if (argc != 2)
		ft_errexit("Please select a fdf file!", 1);
	file_name = argv[1];
	fdf = init_fdf(file_name);
	render_img(fdf);
	mlx_key_hook(fdf->win, &key_handle, fdf);
	mlx_hook(fdf->win, 6, (1L << 6), &p_mouse_mos, fdf);
	mlx_hook(fdf->win, 4, (1L << 2), &mouse_pressed_hook, fdf);
	mlx_hook(fdf->win, 5, (1L << 3), &mouse_released_hook, fdf);
	mlx_hook(fdf->win, 17, 0, &esc_window, fdf);
	mlx_loop(fdf->mlx);
}
