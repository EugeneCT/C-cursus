/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:06:31 by cliew             #+#    #+#             */
/*   Updated: 2024/01/10 21:41:15 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putstr(char *str, int *count)
{
	int	i;

	i = 0;
	if (!str)
	{
		*count += write(1, "(null)", 6);
		return ;
	}
	while (str[i])
	{
		*count += write(1, &str[i], 1);
		i++;
	}
}

void	ft_putint(int number, int *count)
{
	long	temp_number;
	char	*str;

	temp_number = number;
	str = ft_itoa(temp_number);
	ft_putstr(str, count);
	free(str);
}

void	ft_putuint(unsigned int number, int *count)
{
	char	c;

	if (number > 9)
		ft_putuint(number / 10, count);
	c = number % 10 + 48;
	*count += write(1, &c, 1);
}

void	ft_dectohex(unsigned int number, char *base, int *count)
{
	if (number > 15)
		ft_dectohex(number / 16, base, count);
	*count += write(1, &base[number % 16], 1);
}
