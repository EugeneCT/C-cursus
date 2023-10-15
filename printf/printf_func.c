/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:06:31 by cliew             #+#    #+#             */
/*   Updated: 2023/10/16 03:38:01 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_dectohex(unsigned int number, char *base,int *count)
{

	// printf("%lld",number);
	// count=0;
	if (number > 15)
		ft_dectohex(number / 16, base,count);
	*count+=write(1, &base[number % 16], 1);
	return 1;
}


int	ft_udectohex(unsigned long long number, char *base,int *count)
{

	// printf("%lld",number);
	// count=0;
	if (number > 15)
		ft_udectohex(number / 16, base,count);
	*count+=write(1, &base[number % 16], 1);
	return 1;
}

void	ft_putstr(char *str,int len,int *count)
{
	int	i;

	i = 0;
	if (!str)
	{
		*count+=write(1, "(null)", 6);
		return ;
	}
	// if (len ==0){
	// 	while (str[i])
	// 	{
	// 		*count+=write(1, &str[i], 1);
	// 		i++;
	// 	}
	// }
	// else{

	while (i < len)
	{
		*count+=write(1, &str[i], 1);
		i++;
	}
	
}

void	ft_putint(int number,int *count)
{
	char	c;
	long	temp_number;

	temp_number = number;
	if (temp_number < 0)
	{
		*count+=write(1, "-", 1);
		temp_number *= -1;
	}
	if (temp_number > 9)
		ft_putint(temp_number / 10,count);
	c = temp_number % 10 + 48;
	*count+=write(1, &c, 1);
}

int	ft_putuint(unsigned int number,int *count)
{
	char	c;
	
	if (number > 9)
		ft_putuint(number / 10,count);
	c = number % 10 + 48;
	*count+=write(1, &c, 1);
	return 1;
}
