/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:03:57 by cliew             #+#    #+#             */
/*   Updated: 2023/10/15 16:33:40 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int	specifier_p(int flags[][5], void *arg)
{
	unsigned long long	arg_long;
	int count;
	
	count=0;
	flags[0][0] = 1;
	arg_long = (unsigned long long)arg;
	if (!arg_long)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	count += write(1, "0x", 2);

	ft_udectohex(arg_long, "0123456789abcdef",&count);
	return (count);
}

int	specifier_x(int flags[][5],unsigned int arg)
{
	int count;

	count = 0;
	flags[0][0] = 1;
	// if (!arg)
	// {
	// 	write(1, "(nil)", 5);
	// 	return 5;
	// }
	ft_dectohex(arg, "0123456789abcdef",&count);
	// printf("count is %d",count);
	return (count);
}

int	specifier_bigx(int flags[][5], unsigned int arg)
{
	int count;

	count = 0;
	flags[0][0] = 1;

	ft_dectohex(arg, "0123456789ABCDEF",&count);
	return (count);
}
