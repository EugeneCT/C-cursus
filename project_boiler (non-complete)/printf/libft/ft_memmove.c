/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 10:38:34 by cliew             #+#    #+#             */
/*   Updated: 2023/09/29 10:38:36 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *to, const void *from, size_t numBytes)
{
	size_t	i;

	i = 0;
	if (to > from)
	{
		i = numBytes;
		while (i-- > 0)
		{
			((char *)to)[i] = ((char *)from)[i];
		}
	}
	else
	{
		while (i < numBytes)
		{
			((char *)to)[i] = ((char *)from)[i];
			i++;
		}
	}
	return (to);
}

// int	main(void)
// {
// 	char	*b;

// 	char a[] = "lorem ipsum dolor sit amet";
// 	b = a + 1;
// 	ft_memmove(b, a, 8);
// 	// printf(b);
// }
