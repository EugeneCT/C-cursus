/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 21:03:25 by cliew             #+#    #+#             */
/*   Updated: 2024/02/27 19:49:03 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mouse	*init_mouse(void)
{
	t_mouse	*mousey;

	mousey = malloc(sizeof(t_mouse));
	mousey->mouse_x = 0;
	mousey->mouse_y = 0;
	mousey->prev_mouse_x = 0;
	mousey->prev_mouse_y = 0;
	mousey->mouse_x_diff = 0;
	mousey->mouse_y_diff = 0;
	mousey->is_pressed = 0;
	return (mousey);
}

int	p_mouse_mos(int x, int y, t_win *fdf)
{
	if (fdf->mouse->is_pressed == 0)
	{
		(fdf->mouse->prev_mouse_x) = x;
		(fdf->mouse->prev_mouse_y) = y;
	}
	else if (fdf->mouse->is_pressed == 1)
	{
		(fdf->mouse->mouse_x) = x;
		(fdf->mouse->mouse_y) = y;
		fdf->mouse->mouse_x_diff = fdf->mouse->mouse_x
			- fdf->mouse->prev_mouse_x;
		fdf->mouse->mouse_y_diff = fdf->mouse->mouse_y
			- fdf->mouse->prev_mouse_y;
		fdf->cam->gamma -= ((fdf->mouse->mouse_x_diff / 100) * ANG_1);
	}
		render_img(fdf);

	return (1);
}

int	mouse_pressed_hook(int button, int x, int y, t_win *fdf)
{
	if (button == 1)
		fdf->mouse->is_pressed = 1;
	render_img(fdf);
	return (x + y);
}

int	mouse_released_hook(int button, int x, int y, t_win *fdf)
{
	fdf->mouse->is_pressed = 0;
	// render_img(fdf);
	return (x + y + button);
}

int	esc_window(t_win *fdf)
{
	exit_prog(fdf, "all", "Goodbye and have a good day!", 0);
	return (1);
}
