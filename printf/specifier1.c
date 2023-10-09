/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:03:07 by cliew             #+#    #+#             */
/*   Updated: 2023/10/09 22:49:00 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	specifier_p(int flags[][5], void *arg, int *output)
{
	unsigned long long	arg_long;

	flags[0][0] = 1;
	arg_long = (unsigned long long)arg;
	if (!arg_long)
	{
		*output += write(1, "(nil)", 5);
		return (1);
	}
	ft_dectohex(arg_long, "0123456789abcdef", output);
	return (1);
}

int	specifier_d(int flags[][5], int arg, int *output)
{
	flags[0][0] = 1;
	ft_putuint(arg, output);
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
