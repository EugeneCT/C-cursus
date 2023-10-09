/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:00:16 by cliew             #+#    #+#             */
/*   Updated: 2023/10/09 22:39:44 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// va_start, va_arg, va_copy, va_end

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>

// Sequence does matter in printf
// Flags can be more than 1
// gcc -o printf  ft_printf.c libft/*.c   && ./printf
// flags [0][0] = 1 if '-'
// flags [0][1] = 1 if '+'
// flags [0][2] = 1 if ' '
// flags [0][3] = 1 if '#'
// flags [0][4] = 1 if '0'

// flags [1][0] = 1 if min width declared
// flags [1][1] = min width

// flags [2][0] = 1 if precision declared
// flags [2][1] = precision number

// flags [3][0] = 1 if specifier declared
// flags [3][1] = specifier in int

int	put_formatted_args(int flags[][5], va_list argv, int *output)
{
	if (flags[3][0])
	{
		if (flags[3][1] == 'c')
			specifier_c(flags, va_arg(argv, int), output);
		if (flags[3][1] == 's')
			specifier_s(flags, va_arg(argv, char *), output);
		if (flags[3][1] == 'p')
			specifier_p(flags, va_arg(argv, void *), output);
		if (flags[3][1] == 'd')
			specifier_d(flags, va_arg(argv, int), output);
		if (flags[3][1] == 'i')
			specifier_i(flags, va_arg(argv, int), output);
		if (flags[3][1] == 'u')
			specifier_u(flags, va_arg(argv, unsigned int), output);
		if (flags[3][1] == 'x')
			specifier_x(flags, va_arg(argv, int), output);
		if (flags[3][1] == 'X')
			specifier_bigx(flags, va_arg(argv, int), output);
		if (flags[3][1] == '%')
			*output += write(1, "%%", 1);
	}
	return (1);
}

int	form_dict(char **str, int flags[][5])
{
	(*str)++;
	check_flags(str, flags);
	check_min_width(str, flags);
	check_precision(str, flags);
	check_specifier(str, flags);
	return (1);
}

int	ft_printf(const char *str, ...)
{
	int		flags[5][5];
	char	*str_ptr;
	va_list	argv;
	int		output;

	str_ptr = (char *)str;
	va_start(argv, str);
	while (*str_ptr != '\0')
	{
		{
			if (*str_ptr != '%')
			{
				output += write(1, str_ptr, 1);
				str_ptr++;
			}
			else
			{
				form_dict(&str_ptr, flags);
				put_formatted_args(flags, argv, &output);
			}
		}
		va_end(argv);
	}
	return (output);
}

// int	main(void)
// {
// 	int				a;
// 	int				b;
// 	float			c;
// 	char			d;
// 	unsigned int	u;

// 	a = 28;
// 	char s[] = "hello";
// 	b = 9;
// 	c = 3.14256789;
// 	d = 'S';
// 	u = 100;
// 	char str[] = "string";
// 	// printf("I am testing %-6.f",c);
// 	// func(str, a,c, b);
// 	ft_printf("hello %% bcd %X %s", a, str, a, c);
// 	// printf("hello %% bcd %i",a,b,c);
// }
// printf("\n");

// for (int j = 0; j < 5; j++) {
//     printf("%d ", flags[0][j]);
// }
// 	printf("\n");

// 	for (int j = 0; j < 5; j++) {
//     printf("%d ", flags[1][j]);
// }
// 	printf("\n");

// 	for (int j = 0; j < 5; j++) {
//     printf("%d ", flags[2][j]);
// }
// 		printf("\n");

// 		for (int j = 0; j < 5; j++) {
//     printf("%d ", flags[3][j]);
// }
