/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:21:32 by cliew             #+#    #+#             */
/*   Updated: 2023/09/19 15:21:32 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	int		len;
	char	*ret;

	len = 0;
	ret = (char *)str;
	while (str[len])
	{
		len++;
	}
	while (str[len - 1])
	{
		if (str[len] == c)
		{
			return (ret + len);
		}
		len--;
	}
	return (0);
}
