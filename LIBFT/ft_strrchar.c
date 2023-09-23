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

char	*ft_strrchr(const char *s, int c)
{
	int			i;
	const char	*ret;

	ret = s;
	i = ft_strlen(s);
	s = (s + i);
	while (*s != *ret && c != *s)
		s--;
	if (c == *s)
		return ((char *)s);
	return (0);
}
