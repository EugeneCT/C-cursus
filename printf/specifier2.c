/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:03:57 by cliew             #+#    #+#             */
/*   Updated: 2023/10/13 13:39:07 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int	specifier_p(int flags[][5], void *arg)
{
	unsigned long long	arg_long;

	flags[0][0] = 1;
	arg_long = (unsigned long long)arg;
	if (!arg_long)
	{
		write(1, "(nil)", 5);
		return (1);
	}
	ft_dectohex(arg_long, "0123456789abcdef");
	return (1);
}

int	specifier_x(int flags[][5], int arg)
{
	flags[0][0] = 1;
	if (!arg)
		write(1, "(nil)", 5);
	ft_dectohex(arg, "0123456789abcdef");
	return (1);
}

int	specifier_bigx(int flags[][5], int arg)
{
	flags[0][0] = 1;
	if (!arg)
		write(1, "(nil)", 5);
	ft_dectohex(arg, "0123456789ABCDEF");
	return (1);
}
