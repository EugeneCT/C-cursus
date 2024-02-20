/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:28:06 by cliew             #+#    #+#             */
/*   Updated: 2024/01/10 21:41:33 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	check_specifier(char **str, va_list *argv, int *count)
{
	char	c;

	if (**str == 'c')
	{
		c = va_arg(*argv, int);
		*count += write(1, &c, 1);
	}
	if (**str == 's')
		ft_putstr(va_arg(*argv, char *), count);
	if (**str == 'p')
		ft_puthex(va_arg(*argv, void *), count);
	if (**str == 'd' || **str == 'i')
		ft_putint(va_arg(*argv, int), count);
	if (**str == 'u')
		ft_putuint(va_arg(*argv, unsigned int), count);
	if (**str == 'x')
		ft_dectohex(va_arg(*argv, int), "0123456789abcdef", count);
	if (**str == 'X')
		ft_dectohex(va_arg(*argv, int), "0123456789ABCDEF", count);
	if (**str == '%')
		*count += write(1, "%", 1);
}

void	ft_puthex(void *ptr, int *count)
{
	if (!ptr)
		*count += write(1, "(nil)", 5);
	else
	{
		*count += write(1, "0x", 2);
		ft_ulltohex((unsigned long long)ptr, "0123456789abcdef", count);
	}
}

void	ft_ulltohex(unsigned long long number, char *base, int *count)
{
	if (number > 15)
		ft_ulltohex(number / 16, base, count);
	*count += write(1, &base[number % 16], 1);
}

int	ft_printf(const char *str, ...)
{
	va_list	argv;
	int		count;
	char	*str_ptr;

	va_start(argv, str);
	str_ptr = (char *)str;
	count = 0;
	while (*str_ptr != '\0')
	{
		if (*str_ptr != '%')
		{
			count += write(1, str_ptr, 1);
			str_ptr++;
		}
		else
		{
			str_ptr++;
			check_specifier(&str_ptr, &argv, &count);
			str_ptr++;
		}
	}
	va_end(argv);
	return (count);
}
