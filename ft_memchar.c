/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:20:09 by cliew             #+#    #+#             */
/*   Updated: 2023/09/19 15:20:09 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t	i;
	char	*ret;

	ret = (char *)str;
	i = 0;
	while (ret[i] != '\0' && i < n)
	{
		// printf("%c",ret[i]);
		if (ret[i] == c)
		{
			return (ret + i);
		}
		i++;
	}
	return (0);
}
