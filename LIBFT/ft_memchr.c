/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:20:09 by cliew             #+#    #+#             */
/*   Updated: 2023/09/19 15:20:09 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*s;
	unsigned char	character;

	s = (unsigned char *)str;
	character = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (*s == character)
		{
			return (s);
		}
		s++;
		i++;
	}
	return (NULL);
}

