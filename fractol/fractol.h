/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 23:37:26 by cliew             #+#    #+#             */
/*   Updated: 2024/02/19 19:28:50 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./libft_max/getnextline/gnl.h"
# include "./libft_max/libft/libft.h"
# include "./libft_max/printf/printf.h"
# include "./minilibx-linux/mlx.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

# define WIDTH 1000
# define HEIGHT 1000
# define MAX_ITERATIONS 200
# define JULIA_RE 0.285
# define JULIA_IM 0.01


typedef struct s_settings
{
	double	zoom;
	double	center_real;
	double	center_imag;
	double	center_real2;
	double	center_imag2;
	double	shift_amt;
	double	z_real_squared;
	double	z_imag_new;
	int		color;
	void	*win_ptr;
	void	*mlx_ptr;
	char	*fractal;
}		t_settings;
#endif