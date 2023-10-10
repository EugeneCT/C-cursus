/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:03:07 by cliew             #+#    #+#             */
/*   Updated: 2023/10/10 10:22:41 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	repeat_char(char char_to_repeat, int repeat_time, int *output)
{
	int	i;

	i = 0;
	// printf("repeat time is %d",repeat_time);
	while (i < repeat_time)
	{
		output += write(1, &char_to_repeat, sizeof(char_to_repeat));
		i++;
	}
}

int	specifier_c(int flags[][5], int arg, int *output)
{
	int	width;
	int	i;
	int	len;

	len = 1;
	width = 0;
	i = 0;
	if (flags[1][0] == 1)
		width = flags[1][1];
	if (flags[0][0] == 1 || (width < len))
	{
		output += write(1, &arg, 1);
	}
	if (width > len)
	{
		repeat_char(' ', width - len, output);
	}
	if (flags[0][0] == 0)
	{
		output += write(1, &arg, 1);
	}
	return (1);
}

int	specifier_s(int flags[][5], char *arg, int *output)
{
	int	width;
	int	i;
	int	len;

	if (flags[2][0] == 1 && flags[2][1] < ft_strlen(arg))
		len = flags[2][1];
	else
		len = ft_strlen(arg);
	width = 0;
	i = 0;
	if (flags[1][0]==1)
		width = flags[1][1];
	if (flags[0][0] ==1 || (width < len))
		ft_putstr(arg, output, len);
	if (width > len)
		repeat_char(' ', (width - len), output);
	if (flags[0][0] == 0)
		ft_putstr(arg, output, len);
}

int	specifier_d(int flags[][5], int arg, int *output)
{
	flags[0][0] = 1;
	ft_putint(arg, output);
	return (1);
}

int	specifier_i(int flags[][5], int arg, int *output)
{
	flags[0][0] = 1;
	ft_putint(arg, output);
	return (1);
}

int	specifier_u(int flags[][5], unsigned int arg, int *output)
{
	flags[0][0] = 1;
	ft_putuint(arg, output);
	return (1);
}
