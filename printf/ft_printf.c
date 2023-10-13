/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:00:16 by cliew             #+#    #+#             */
/*   Updated: 2023/10/13 17:36:12 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// va_start, va_arg, va_copy, va_end

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <limits.h>
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

int	put_formatted_args(int flags[][5], va_list *argv)
{
	int count;

	count = 0;
	if (flags[3][0])
	{
		if (flags[3][1] == 'c')
			count = specifier_c(flags, va_arg(*argv, int));
		if (flags[3][1] == 's')
			count = specifier_s(flags, va_arg(*argv, char *));
		if (flags[3][1] == 'p')
			specifier_p(flags, va_arg(*argv, void *));
		if (flags[3][1] == 'd')
			count = specifier_d(flags, va_arg(*argv, int));
		if (flags[3][1] == 'i')
			count = specifier_i(flags, va_arg(*argv, int));
		if (flags[3][1] == 'u')
			specifier_u(flags, va_arg(*argv, unsigned int));
		if (flags[3][1] == 'x')
			specifier_x(flags, va_arg(*argv, int));
		if (flags[3][1] == 'X')
			specifier_bigx(flags, va_arg(*argv, int));
		if (flags[3][1] == '%')
			write(1, "%%", 1);
	}
	return (count);
}

int	form_dict(char **str, int flags[][5])
{
	(*str)++;
    ft_memset(flags, 0,100);
	check_flags(str, flags);
	check_min_width(str, flags);
	check_precision(str, flags);
	check_specifier(str, flags);
	return (1);
}

int	ft_printf(const char *str, ...)
{
	int		flags[5][5];
	int		count;	
	char	*str_ptr;
	va_list	argv;
	
	count = 0;
	str_ptr = (char *)str;
	ft_memset(flags, 0,25*sizeof(int));
	// for (int i=0;i<5;i++)
	// {
	// 	for (int j=0;j<5;j++)
	// 		printf("%d",flags[i][j]);	2
	// }
	
	va_start(argv, str);
	while (*str_ptr != '\0')
	{
		{
			if (*str_ptr != '%')
			{
				count+=write(1, str_ptr, 1);
				str_ptr++;
			}
			else
			{
				form_dict(&str_ptr, flags);
				count+=put_formatted_args(flags, &argv);
			}
		}
		va_end(argv);
	}
	// printf("count is %d",count);

	return (count);
}


// int main(){
	

// 	char c = 'c';
// 	char s[]="By";
// 	int d = -12;


// 	ft_printf(" NULL %s NULL ", NULL);

// 	// printf("\n NULL %s NULL ", NULL);
// 	// ft_printf(" NULL %s NULL ", NULL);

// 	// printf("\n NULL %s NULL ", NULL);

// 	// printf("\n %c ", '0');

// 	// ft_printf(" %c", '0' - 256);
// 	// printf("\n %c", '0' - 256);


// }


// int main(){
// 	char c = 'c';
// 	int d = 923;
// 	int dzero = 0;
// 	int dmin=INT_MIN;
// 	int dmax = INT_MAX;
// 	unsigned int u= 932131274;
// 	int imin = INT_MIN;
// 	char s[] = "ley";
// 	// test d
// 	printf("Hello %-+010d Baby",d);
// 	printf("\n");
// 	ft_printf("Hello %-+010d Baby",d);
// 	printf("\n");

// 	printf("Hello %-+10.5d Baby",d);
// 	printf("\n");
// 	ft_printf("Hello %-+10.5d Baby",d);
// 	printf("\n");

// 	printf("Hello % 3.2d Baby",d);
// 	printf("\n");
// 	ft_printf("Hello % 3.2d Baby",d);
// 	printf("\n");

// 	printf("Hello % +05.5d Baby",d);
// 	printf("\n");
// 	ft_printf("Hello % +05.5d Baby",d);
// 	printf("\n");

// 	printf("Hello %5d Baby",d);
// 	printf("\n");
// 	ft_printf("Hello %5d Baby",d);
// 	printf("\n");

// 	printf("Hello %-5d Baby",d);
// 	printf("\n");
// 	ft_printf("Hello %-5d Baby",d);
// 	printf("\n");


// 	printf("Hello %-5.7d Baby",dmin);
// 	printf("\n");
// 	ft_printf("Hello %-5.7d Baby",dmin);
// 	printf("\n");


// 	printf("Hello %+ 5.7d Baby",dmax);
// 	printf("\n");
// 	ft_printf("Hello %+ 5.7d Baby",dmax);
// 	printf("\n");

// 	printf("Hello %+ 022.7d Baby",dzero);
// 	printf("\n");
// 	ft_printf("Hello %+ 022.7d Baby",dzero);
// 	printf("\n");

// 	printf("Hello %- 022.7d Baby",dzero);
// 	printf("\n");
// 	ft_printf("Hello %- 022.7d Baby",dzero);
// 	printf("\n");

// 	printf("Hello %-022d Baby",dzero);
// 	printf("\n");
// 	ft_printf("Hello %-022d Baby",dzero);
// 	printf("\n");

// 	printf("Hello %-022d Baby",dmax);
// 	printf("\n");
// 	ft_printf("Hello %-022d Baby",dmax);
// 	printf("\n");


// 	printf("Hello %-022d Baby",dmin);
// 	printf("\n");
// 	ft_printf("Hello %-022d Baby",dmin);
// 	printf("\n");

// 	// test i
// 	printf("Hello %-22i World",dmin);
// 	printf("\n");
// 	ft_printf("Hello %-22i World",dmin);
// 	printf("\n");

// 	printf("Hello %-+010d World",d);
// 	printf("\n");
// 	ft_printf("Hello %-+010d World",d);
// 	printf("\n");

// 	printf("Hello %-+10.5d World",d);
// 	printf("\n");
// 	ft_printf("Hello %-+10.5d World",d);
// 	printf("\n");

// 	printf("Hello % 3.2d World",d);
// 	printf("\n");
// 	ft_printf("Hello % 3.2d World",d);
// 	printf("\n");

// 	printf("Hello % +05.5d World",d);
// 	printf("\n");
// 	ft_printf("Hello % +05.5d World",d);
// 	printf("\n");

// 	printf("Hello %5d World",d);
// 	printf("\n");
// 	ft_printf("Hello %5d World",d);
// 	printf("\n");

// 	printf("Hello %-5d World",d);
// 	printf("\n");
// 	ft_printf("Hello %-5d World",d);
// 	printf("\n");


// 	printf("Hello %-5.7d World",dmin);
// 	printf("\n");
// 	ft_printf("Hello %-5.7d World",dmin);
// 	printf("\n");


// 	printf("Hello %+ 5.7d World",dmax);
// 	printf("\n");
// 	ft_printf("Hello %+ 5.7d World",dmax);
// 	printf("\n");

// 	printf("Hello %+ 022.7d World",dzero);
// 	printf("\n");
// 	ft_printf("Hello %+ 022.7d World",dzero);
// 	printf("\n");

// 	printf("Hello %- 022.7d World",dzero);
// 	printf("\n");
// 	ft_printf("Hello %- 022.7d World",dzero);
// 	printf("\n");

	// printf("Hello %-22i World",dzero);
	// printf("\n");
	// ft_printf("Hello %-22i World",dzero);
	// printf("\n");

	// printf("Hello %-22i World",dmax);
	// printf("\n");
	// ft_printf("Hello %-22i World",dmax);
	// printf("\n");


	// printf("Hello %-22i World",dmin);
	// printf("\n");
	// ft_printf("Hello %-22i World",dmin);
	// printf("\n");

	// printf("Hello %-22i World",dmin);
	// printf("\n");
	// ft_printf("Hello %-22i World",dmin);
	// printf("\n");

	// // test u
	// printf("Hello %-22u unsigned",u);
	// printf("\n");
	// ft_printf("Hello %-22u unsigned",u);
	// printf("\n");

	// printf("Hello %-22u unsigned",dmin);
	// printf("\n");
	// ft_printf("Hello %-22u unsigned",dmin);
	// printf("\n");

	// printf("Hello %-22u unsigned",dmin);
	// printf("\n");
	// ft_printf("Hello %-22u unsigned",dmin);
	// printf("\n");



	// printf("Hello %0 22u unsigned",dmin);
	// printf("\n");
	// ft_printf("Hello %0 22u unsigned",dmin);
	// printf("\n");

	// printf("Hello %-22.9u unsigned",dmin);
	// printf("\n");
	// ft_printf("Hello %-22.9u unsigned",dmin);
	// printf("\n");



	// printf("Hello %+1u unsigned",dmin);
	// printf("\n");
	// ft_printf("Hello %+1u unsigned",dmin);
	// printf("\n");


	// printf("Hello %+0 #-13.21u unsigned",dmin);
	// printf("\n");
	// ft_printf("Hello %+0 #-13.21u unsigned",dmin);
	// printf("\n");


	// printf("Hello %+015.14u unsigned",dmin);
	// printf("\n");
	// ft_printf("Hello %+015.14u unsigned",dmin);
	// printf("\n");



	// printf("Hello %+-0 #15.14u unsigned",dmin);
	// printf("\n");
	// ft_printf("Hello %+-0 #15.14u unsigned",dmin);
	// printf("\n");





	// printf("Hello %+-0 #15.14u unsigned",u);
	// printf("\n");
	// ft_printf("Hello %+-0 #15.14u unsigned",u);
	// printf("\n");

	// printf("Hello %+0 #15.14u unsigned",u);
	// printf("\n");
	// ft_printf("Hello %+0 #15.14u unsigned",u);
	// printf("\n");


	// printf("Hello %- 2.23u unsigned",u);
	// printf("\n");
	// ft_printf("Hello %- 2.23u unsigned",u);
	// printf("\n");

	// printf("Hello %-022.16u unsigned",u);
	// printf("\n");
	// ft_printf("Hello %-022.16u unsigned",u);
	// printf("\n");

	// printf("Hello %3.44u unsigned",u);
	// printf("\n");
	// ft_printf("Hello %3.44u unsigned",u);
	// printf("\n");

	// printf("Hello %+022u unsigned",u);
	// printf("\n");
	// ft_printf("Hello %+022u unsigned",u);
	// printf("\n");

	// printf("Hello %-+22u unsigned",u);
	// printf("\n");
	// ft_printf("Hello %-+22u unsigned",u);
	// printf("\n");

	// printf("Hello %022.14u unsigned",u);
	// printf("\n");
	// ft_printf("Hello %022.14u unsigned",u);
	// printf("\n");










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
