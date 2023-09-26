/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eugene <eugene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:31:20 by cliew             #+#    #+#             */
/*   Updated: 2023/09/26 21:22:44 by eugene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_negative(long m)
{
	if (m < 0)
		return (-1);
	else
		return (1);
}

static int	check_len(long n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		n = (n * -1);
		len = len + 1;
	}
	while (n >= 10)
	{
		n = n / 10;
		len++;
	}
	return (len + 2);
}

static int	itoa_helper(char *ret, long n, int i)
{
	while (n >= 10)
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
	long	m;
	size_t	len;
	char	*ret;
	int		i;

	i = 0;
	m = n;
	sign = check_negative(m);
	len = check_len(m);
	ret = (char *)malloc(sizeof(char) * len);
	if (!ret)
		return (NULL);
	if (sign == -1)
	{
		m = m * -1;
		ret[0] = '-';
		i = i + 1;
	}
	i = itoa_helper(ret, m, i);
	ret[i] = '\0';
	return (ret);
}
