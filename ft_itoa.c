/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:31:20 by cliew             #+#    #+#             */
/*   Updated: 2023/09/22 16:31:20 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

// #include <stdio.h>

int	check_negative(int *n)
{
	if (*n < 0)
	{
		*n = (*n) * (-1);
		return (-1);
	}
	else
		return (1);
}

int	check_len(int n)
{
	int	len;

	len = 0;
	while (n >= 10)
	{
		n = n / 10;
		len++;
	}
	return (len + 3);
}

int	itoa_helper(char *ret, int n, int i)
{
	while (n > 10)
	{
		i = itoa_helper(ret, n / 10, i);
		n = n % 10;
	}
	if (n < 10)
	{
		ret[i] = (n + '0');
		i = i + 1;
		return (i);
	}
	return (-1);
}

char	*ft_itoa(int n)
{
	int		sign;
	int		*m;
	size_t	len;
	char	*ret;
	int		i;

	i = 0;
	m = &n;
	sign = check_negative(m);
	len = check_len(n);
	ret = (char *)malloc(sizeof(char) * len);
	if (!ret)
		return (NULL);
	if (sign == -1)
	{
		ret[0] = '-';
		i = i + 1;
	}
	i = itoa_helper(ret, n, i);
	ret[i] = '\0';
	return (ret);
}

// int	main(void)
// {
// 	ft_itoa(-1754);
// }