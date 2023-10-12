/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:06:31 by cliew             #+#    #+#             */
/*   Updated: 2023/10/11 22:52:26 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_dectohex(unsigned long long number, char *base, int *output)
{
	if (number > 15)
		ft_dectohex(number / 16, base, output);
	*output += write(1, &base[number % 16], 1);
}

void	ft_putstr(char *str,int len)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return ;
	}
	if (len ==0){
		while (str[i])
		{
			write(1, &str[i], 1);
			i++;
		}
	}
	else{

		while (i < len)
		{
			write(1, &str[i], 1);
			i++;
		}
	}
}

void	ft_putint(int number, int *output)
{
	char	c;
	long	temp_number;

	temp_number = number;
	if (temp_number < 0)
	{
		*output += write(1, "-", 1);
		temp_number *= -1;
	}
	if (temp_number > 9)
		ft_putint(temp_number / 10, output);
	c = temp_number % 10 + 48;
	*output += write(1, &c, 1);
}

void	ft_putuint(unsigned int number, int *output)
{
	char	c;

	if (number > 9)
		ft_putuint(number / 10, output);
	c = number % 10 + 48;
	*output += write(1, &c, 1);
}
