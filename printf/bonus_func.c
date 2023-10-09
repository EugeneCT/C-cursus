/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:08:08 by cliew             #+#    #+#             */
/*   Updated: 2023/10/09 21:20:28 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_flags(char **str, int flags[][5])
{
	while (ft_strchr("+- #0", (**str)))
	{
		if ((**str) == '-')
			flags[0][0] = 1;
		if ((**str) == '+')
			flags[0][1] = 1;
		if ((**str) == ' ')
			flags[0][2] = 1;
		if ((**str) == '#')
			flags[0][3] = 1;
		if ((**str) == '0')
			flags[0][4] = 1;
		(*str)++;
	}
	return (1);
}

int	check_min_width(char **str, int flags[][5])
{
	long	width;

	width = 0;
	while (ft_strchr("0123456789", (**str)))
	{
		flags[1][0] = 1;
		width = width * 10;
		width = width + (**str - '0');
		(*str)++;
	}
	flags[1][1] = width;
	return (1);
}

int	check_precision(char **str, int flags[][5])
{
	long	width;

	width = 0;
	if (ft_strchr(".", (**str)))
	{
		flags[2][0] = 1;
		(*str)++;
		while (ft_strchr("0123456789", (**str)))
		{
			width = width * 10;
			width = width + (**str - '0');
			(*str)++;
		}
		flags[2][1] = width;
	}
	return (1);
}

int	check_specifier(char **str, int flags[][5])
{
	if (ft_strchr("cspdiuxX%%", (**str)))
	{
		flags[3][0] = 1;
		flags[3][1] = (**str);
	}
	(*str)++;
	return (1);
}
