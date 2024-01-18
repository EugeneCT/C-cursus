/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:58:27 by cliew             #+#    #+#             */
/*   Updated: 2024/01/15 14:07:17 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


size_t	ft_min_sizet(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}
char	*ft_strndup(const char *s, size_t n)
{
	char	*dup;

	if (s == NULL || n <= 0)
		return (NULL);
	n = ft_min_sizet(ft_strlen(s), n);
	dup = (char *)malloc((n + 1) * sizeof(char));
	ft_strlcpy(dup, s, n + 1);
	return (dup);
}


