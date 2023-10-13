/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:03:07 by cliew             #+#    #+#             */
/*   Updated: 2023/10/13 17:51:56 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	repeat_char(char char_to_repeat, int repeat_time)
{
	int	i;

	i = 0;
	// printf("repeat time is %d",repeat_time);
	while (i < repeat_time)
	{
		write(1, &char_to_repeat, sizeof(char_to_repeat));
		i++;
	}
	return (repeat_time);
}
int	putchar_output(char c)
{
	write(1, &c, 1);
	return (1);

}

int	specifier_c(int flags[][5], int arg)
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
		write(1, &arg, 1);
	}
	if (width > len)
	{
		repeat_char(' ', width - len);
	}
	if (flags[0][0] == 0)
	{
		write(1, &arg, 1);
		// printf("trigger second");

	}
	return (1);
}

int	specifier_s(int flags[][5], char *arg)
{
	int	width;
	int	len;
	
	if (!arg){
		write(1,"(null)",6);
		return 0;
	}
	if (flags[2][0] == 1 && flags[2][1] < (int)(ft_strlen(arg)))
		len = flags[2][1];
	else
		len = ft_strlen(arg);
	width = 0;
	if (flags[1][0] == 1)
		width = flags[1][1];
	if (flags[0][0] == 1 || ((width < len) && (width !=0)))
		ft_putstr(arg, len);
	if (width > len)
		len+=repeat_char(' ', (width - len));
	if (flags[0][0] == 0)
		ft_putstr(arg, len);
	return (len);
}

int	put_sign(int flags[][5], ...)
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
				putchar_output('+');
			else if (integer < 0)
				putchar_output('-');
		}
		else if (flags[0][2] == 1)
			putchar_output(' ');
	}
	if (un_integer && flags[0][2] == 1)
		putchar_output(' ');
	return (1);

}

int	check_len(int flags[][5], int arg)
{
	int	len;

	len = ft_strlen(ft_itoa(arg));
	if (flags[2][0] == 1 && flags[2][1] > len)
		len = flags[2][1];
	if (flags[0][1] == 1 || flags[0][2] == 1)
		len = len + 1;
	return (len);
}

int	check_ulen(int flags[][5], unsigned int arg)
{
	int	len;

	len = ft_strlen(ft_itoa(arg));
	if (((int)arg) < 0)
		len=len-1;
	if (flags[2][0] == 1 && flags[2][1] > len)
		len = flags[2][1];
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
int	specifier_d(int flags[][5], int arg)
{
	int		width;
	int		len;
	char	filler;
	char *str_len;

	str_len = ft_itoa(arg);
	// str_len = (int)(ft_strlen(ft_itoa(arg)));

	width = 0;
	len = check_len(flags, arg);
	filler = check_filler(flags);
	if (flags[1][0] == 1)
		width = flags[1][1];
	if (flags[0][0] != 1)
	{
		if (width > len)
			len+=repeat_char(filler, width - len);
	}
	put_sign(flags, arg);
	if (flags[2][0] == 1 && flags[2][1] > (int)(ft_strlen(str_len)) )
		len+=repeat_char('0', flags[2][1] - (int)(ft_strlen(str_len)));
	ft_putint(arg);
	if (flags[0][0] == 1)
	{
		if (width > len)
			len+=repeat_char(' ', width - len);
	}
	free(str_len);
	return (len);
}

int	specifier_i(int flags[][5], int arg)
{
	int		width;
	int		len;
	char	filler;

	width = 0;
	len = check_len(flags, arg);
	filler = check_filler(flags);
	if (flags[1][0] == 1)
		width = flags[1][1];
	if (flags[0][0] != 1)
	{
		if (width > len)
			repeat_char(filler, width - len);
	}
	put_sign(flags, arg);
	if (flags[2][0] == 1 && flags[2][1] > (int)(ft_strlen(ft_itoa(arg))))
		repeat_char('0', flags[2][1] - (int)(ft_strlen(ft_itoa(arg))));
	ft_putint(arg);
	if (flags[0][0] == 1)
	{
		if (width > len)
			repeat_char(' ', width - len);
	}
	return (1);

}

int	specifier_u(int flags[][5], unsigned int arg)
{
	int		width;
	int		len;
	char	filler;
	int		int_arg;
	int		strlen;

	width = 0;
	int_arg = (int )arg;
	len = check_ulen(flags, arg);
	strlen = ft_strlen(ft_itoa(arg));
	if (int_arg < 0)
	{
		len = len - 1;
		strlen = strlen - 1;


	}
	// printf("strlen is %d",strlen);
	// printf("\n len is %d",len);
	filler = check_filler(flags);
	if (flags[1][0] == 1)
		width = flags[1][1];
	if (flags[0][0] != 1)
	{
		if (width > len)
			repeat_char(filler, width - len);
	}
	if (flags[2][0] == 1 && flags[2][1] > strlen)
		repeat_char('0', flags[2][1] - strlen);
	ft_putuint(arg);
	if (flags[0][0] == 1)
	{
		if (width > len)
			repeat_char(' ', width - len);
	}
	return (1);

}
