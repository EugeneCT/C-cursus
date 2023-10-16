/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:03:57 by cliew             #+#    #+#             */
/*   Updated: 2023/10/16 21:52:52 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int	specifier_p(int flags[][5], void *arg,int *count)
{
	unsigned long long	arg_long;
	
	flags[0][0] = 1;
	arg_long = (unsigned long long)arg;
	if (!arg_long)
	{
		*count+=write(1, "(nil)", 5);
		return (0);
	}
	*count += write(1, "0x", 2);

	ft_udectohex(arg_long, "0123456789abcdef",count);
	return (1);
}

int	specifier_x(int flags[][5],unsigned int arg,int *count)
{

	flags[0][0] = 1;
	// if (!arg)
	// {
	// 	write(1, "(nil)", 5);
	// 	return 5;
	// }

	if (flags[0][3]==1)
		*count += write(1, "0x", 2);
	ft_dectohex(arg, "0123456789abcdef",count);

	// printf("count is %d",count);
	return (1);
}

int	specifier_bigx(int flags[][5], unsigned int arg,int *count)
{

	flags[0][0] = 1;
	if (flags[0][3]==1)
		*count += write(1, "0X", 2);

	ft_dectohex(arg, "0123456789ABCDEF",count);
	return (1);
}
