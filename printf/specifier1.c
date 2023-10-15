/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:03:07 by cliew             #+#    #+#             */
/*   Updated: 2023/10/16 03:54:02 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	repeat_char(char char_to_repeat, int repeat_time,int *count)
{
	int	i;

	i = 0;
	if (repeat_time < 0)
		return -1;
	// printf("repeat time is %d",repeat_time);
	while (i < repeat_time)
	{
		*count +=write(1, &char_to_repeat, sizeof(char_to_repeat));
		i++;
	}
	return (repeat_time);
}
int	putchar_output(char c,int* count)
{
	*count+=write(1, &c, 1);
	return (1);

}

int	specifier_c(int flags[][5], int arg,int *count)
{
	int	width;
	int	len;

	len = 1;
	width = 0;
	if (flags[1][0] == 1)
		width = flags[1][1];
	if (flags[0][0] == 1 || ((width < len) && (width!=0)))
	{
		// printf("trigger first");
		*count+=write(1, &arg, 1);
	}
	if (width > len)
	{
		repeat_char(' ', width - len,count);
	}
	if (flags[0][0] == 0)
	{
		*count+=write(1, &arg, 1);
		// printf("trigger second");

	}
	return (1);
}

int	specifier_s(int flags[][5], char *args,int *count)
{
	int	width;
	int	len;
	char *arg =(char*) args;
	
	if (!arg && flags[2][0]==0){
		arg="(null)";
		// *count+=write(1,"(null)",6);
		// len = 6;
	}
	else if (!arg && flags[2][0]==1 && flags[2][1] < 6 )
		arg="";
	else if (!arg && flags[2][0]==1 )
		arg="(null)";
	if (arg && flags[2][0] == 1 && flags[2][1] < (int)(ft_strlen(arg)))
		len = flags[2][1];
	else if (arg)
		len = ft_strlen(arg);
	width = len;
	if (flags[1][0] == 1)
		width = flags[1][1];
	if (flags[0][0] == 1 && arg){
		ft_putstr(arg, len,count);

	}
	repeat_char(' ', (width - len),count);

	if (flags[0][0] == 0 && arg)
	{
		ft_putstr(arg, len,count);
	}
	return (len);
}

int	put_sign(int *count,int flags[][5],...)
{
	va_list			args;
	int				integer;
	unsigned int	un_integer;

	va_start(args, flags);
	integer = va_arg(args, int);
	un_integer = va_arg(args, unsigned int);
	if (integer)
	{
		if (flags[0][1] == 1)
		{
			if (integer >= 0)
				putchar_output('+',count);
			else if (integer < 0)
				putchar_output('-',count);
		}
		else if (flags[0][2] == 1)
			putchar_output(' ',count);
	}
	else if (un_integer && flags[0][2] == 1)
		putchar_output(' ',count);
	return (1);

}

int	check_len(int flags[][5], int arg)
{
	int	len;
	char *str;
	
	str =ft_itoa(arg);
	len = ft_strlen(str);
	if (flags[2][0] == 1 && flags[2][1] > len)
		len = flags[2][1];
	if (flags[0][1] == 1 || flags[0][2] == 1)
		len = len + 1;
	
	free(str);
	return (len);
}

int	check_ulen(int flags[][5], unsigned int arg)
{
	int	len;

	char *str;

	str=ft_itoa(arg);
	len = ft_strlen(str);
	
	if (((int)arg) < 0)
		len=len-1;
	if (flags[2][0] == 1 && flags[2][1] > len)
		len = flags[2][1];
	free(str);
	return (len);
}

int	check_filler(int flags[][5])
{
	if (flags[0][4] == 1)
		if (flags[2][0] == 0)
			return ('0');
		else
			return (' ');
	else if (flags[0][4] == 0)
		return (' ');
	return (1);

}
int	specifier_d(int flags[][5], int arg,int* count)
{
	int		width;
	int		len;
	char	filler;
	char *str;

	str = ft_itoa(arg);

	width = 0;
	len = check_len(flags, arg);
	filler = check_filler(flags);
	if (flags[1][0] == 1)
		width = flags[1][1];
	if (flags[0][0] != 1)
	{
		if (width > len)
			repeat_char(filler, width - len,count);
	}
	put_sign(count,flags ,arg);
	if (flags[2][0] == 1 && flags[2][1] > (int)(ft_strlen(str)) )
		repeat_char('0', flags[2][1] - (int)(ft_strlen(str)),count);
	ft_putint(arg,count);
	if (flags[0][0] == 1)
	{
		if (width > len)
			repeat_char(' ', width - len,count);
	}
	free(str);
	return (len);
}

// int	specifier_i(int flags[][5], int arg)
// {
// 	int		width;
// 	int		len;
// 	char	filler;

// 	width = 0;
// 	len = check_len(flags, arg);
// 	filler = check_filler(flags);
// 	if (flags[1][0] == 1)
// 		width = flags[1][1];
// 	if (flags[0][0] != 1)
// 	{
// 		if (width > len)
// 			repeat_char(filler, width - len);
// 	}
// 	put_sign(flags, arg);
// 	if (flags[2][0] == 1 && flags[2][1] > (int)(ft_strlen(ft_itoa(arg))))
// 		repeat_char('0', flags[2][1] - (int)(ft_strlen(ft_itoa(arg))));
// 	ft_putint(arg);
// 	if (flags[0][0] == 1)
// 	{
// 		if (width > len)
// 			repeat_char(' ', width - len);
// 	}
// 	return (1);

// }

int	specifier_u(int flags[][5], unsigned int arg,int * count)
{
	int		width;
	int		len;
	char	filler;
	int		strlen;
	char* str;
	
	width = 0;
	len = check_ulen(flags, arg);

	
	str= ft_itoa(arg);
	strlen = ft_strlen(str);
	// if (int_arg < 0)
	// {
	// 	len = len - 1;
	// 	strlen = strlen - 1;


	// }
	// printf("strlen is %d",strlen);
	// printf("\n len is %d",len);
	filler = check_filler(flags);
	if (flags[1][0] == 1)
		width = flags[1][1];
	if (flags[0][0] != 1)
	{
		if (width > len)
			repeat_char(filler, width - len,count);
	}
	if (flags[2][0] == 1 && flags[2][1] > strlen)
		repeat_char('0', flags[2][1] - strlen,count);
	ft_putuint(arg,count);
	if (flags[0][0] == 1)
	{
		if (width > len)
			repeat_char(' ', width - len,count);
	}
	free(str);

	return (1);

}
