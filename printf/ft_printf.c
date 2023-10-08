/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:00:16 by cliew             #+#    #+#             */
/*   Updated: 2023/10/08 21:41:41 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// va_start, va_arg, va_copy, va_end

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>

// int	func(char *chr, ...)
// {
// 	int len = 0;
// 	int i = 0;
//     va_list args;
//     va_list args2;

//     va_start(args,chr);
// 	int argc = 0;

//     int first = va_arg(args,int);
//     int second = va_arg(args,int);
//     va_copy(args2,args);
//     int third = va_arg(args,int);

//     int args2_first=va_arg(args2,int);
//     len = ft_strlen(chr);
// 	while (i < len)
// 	{
// 		if (chr[i] == '%')
// 		{
// 			argc++;
// 		}
// 		i++;
// 	}
// 	printf("argc is %d \n", argc);
//     printf("first is %d \n", first);
// 	printf("second is %d \n", second);
//     printf("third is %d \n", third);
//     printf("args2_first is %d \n", args2_first);

//     // printf(chr);

// 	return (0);
// }

// Sequence does matter in printf
// Flags can be more than 1
// gcc -o printf  ft_printf.c libft/*.c   && ./printf

// static int	check_placeholder(const char *str)
// {
// 	int	len;
// 	int	i;
// 	int	argc;

// 	argc = 0;
// 	i = 0;
// 	len = ft_strlen(str);
// 	while (i < len)
// 	{
// 		if (str[i] == '%')
// 		{
// 			argc++;
// 		}
// 		i++;
// 	}
// 	return (argc);
// }

// static int	*check_flags_helper(const char *str, va_list argv)
// {
// 	int	*ret;

// 	ret = (int *)ft_calloc(5, sizeof(int));
// 	if (str[1] == '-')
// 		ret[0] = 1;
// 	if (str[1] == '+')
// 		ret[1] = 1;
// 	if (str[1] == ' ')
// 		ret[2] = 0;
// 	if (str[1] == '#')
// 		ret[3] = 1;
// 	if (str[1] == '0')
// 		ret[4] = 1;
// 	return (ret);
// }


// int	check_flags(char str, int flags[][5])
// {

// 			while (ft_strchr("+- #0", str[i]))
// 			{
// 				flags = check_flags(&str[i], flags);
// 				i++;
// 			}
// 			while (ft_strchr("1234567890", str[i]))
// 			{
// 				flags = check_flags(&str[i], flags);
// 				i++;
// 			}
// 			if (str[i] == ',')
// 			{
// 				while (ft_strchr("1234567890", str[i]))
// 				{
// 					flags = check_flags(&str[i], flags);
// 					i++;
// 				}
// 			}
// 			else
// 			{
// 				while (ft_strchr("cspdiuxX%%", str[i]) != NULL)
// 				{
// 					flags = check_flags(&str[i], flags);
// 					i++;
// 				}
// 			}
// 		}
// 	}
// }
int	check_flags(char **str, int flags[][5])
{
			while (ft_strchr("+- #0", (**str)))
			{
				if ((**str) == '-')
					flags[0][0] = 1;
				if ((**str)== '+')
					flags[0][1]  = 1;
				if ((**str)== ' ')
					flags[0][2]  = 1;
				if ((**str) == '#')
					flags[0][3] = 1;
				if ((**str) == '0')
					flags[0][4]  = 1;
				(*str)++;
			}
				
}

int	check_min_width(char **str, int flags[][5])
{
			long width;
			width=0;
			while (ft_strchr("0123456789", (**str)))
			{

				flags[1][0]=1;
				width=width*10;
				width=width+(**str - '0');



				(*str)++;
			}
			flags[1][1] = width;
}

int	check_precision(char **str, int flags[][5])
{
			long width;
			width=0;

			if (ft_strchr(".", (**str)))
			{
				flags[2][0] = 1;
				(*str)++;
				while (ft_strchr("0123456789", (**str)))
				{

					width=width*10;
					width=width+(**str - '0');
					(*str)++;


				}
			flags[2][1] = width;

			}
}

int	check_specifier(char **str, int flags[][5])
{
	

	if (ft_strchr("cspdiuxX%%", (**str)))
	{
		flags [3][0] = 1;
		flags [3][1] = (**str);
	}

}

int specifier_c(int flags[][5],int arg){
long width;
int i;

i = 0;

if (flags[1][0] ==1)
	width = flags[1][1];
else 
	width = 0;		
	}

}
else
{


}



}
int specifier_s(int flags[][5],int arg){


	
}
int specifier_p(int flags[][5],int arg){


	
}
int specifier_d(int flags[][5],int arg){


	
}

int specifier_i(int flags[][5],int arg){


	
}

int specifier_u(int flags[][5],int arg){


	
}

int specifier_x(int flags[][5],int arg){


	
}

int specifier_X(int flags[][5],int arg){


	
}

int specifier_perc(int flags[][5],int arg){


	
}
int put_formatted_args(int flags[][5],va_list argv){
	
	if (flags[3][0]){
		if (flags[3][1]=='c')
			ft_putchar(va_arg(argv, int));
		if (flags[3][1]=='s')
			ft_putchar(va_arg(argv, int));
		if (flags[3][1]=='p')
			ft_putchar(va_arg(argv, int));
		if (flags[3][1]=='d')
			ft_putchar(va_arg(argv, int));
		if (flags[3][1]=='i')
			ft_putchar(va_arg(argv, int));
		if (flags[3][1]=='u')
			ft_putchar(va_arg(argv, int));
		if (flags[3][1]=='x')
			ft_putchar(va_arg(argv, int));
		if (flags[3][1]=='X')
			ft_putchar(va_arg(argv, int));
		if (flags[3][1]=='%')
			ft_putchar(va_arg(argv, int));
		

	}



}
// int move_ptr(char **str){

// 	if (**str == '%')
// 		write(1,*str,1);
// 	// printf((*str)[0]);
// 	*str = *str +1;

// }


int	ft_printf(const char *str, ...)
{
	int		i;
	int flags[5][5];
	char 	*str_ptr;
	va_list	argv;
	
	str_ptr= (char *)str;
	va_start(argv, str);
	i = 0;
	
	while (i < ft_strlen(str)) {
	
	{	
		if (*str_ptr != '%')
		{
			ft_putchar(*str_ptr);
			i++;
			str_ptr++;
		}
		else
		{				
			str_ptr++;
			// move_ptr(&str_ptr);
			check_flags(&str_ptr,flags);
			check_min_width(&str_ptr,flags);
			check_precision(&str_ptr,flags);
			check_specifier(&str_ptr,flags);
			put_formatted_args(flags,argv);
			str_ptr++;


		}
	}
	}
	printf("\n");
	
	for (int j = 0; j < 5; j++) {
        printf("%d ", flags[0][j]);
    }
		printf("\n");

		for (int j = 0; j < 5; j++) {
        printf("%d ", flags[1][j]);
    }
		printf("\n");

		for (int j = 0; j < 5; j++) {
        printf("%d ", flags[2][j]);
    }
			printf("\n");

			for (int j = 0; j < 5; j++) {
        printf("%d ", flags[3][j]);
    }
}
// int j = 0;
// while (j<5)
// 		{
// 			printf("%d",flags[j]);
// 			j++;
// 		}


int	main(void)
{
	int		a;
	int		b;
	float	c;
	char 	d;

	a = 12;
	// char c[] = "hello";
	b = 9;
	c = 3.14256789;
	d = 'S';

	char str[] = "This is %d and %s";
	// printf("I am testing %-6.f",c);
	// func(str, a,c, b);
	ft_printf("hello %- 32199.33c bcd", d, b);
}
