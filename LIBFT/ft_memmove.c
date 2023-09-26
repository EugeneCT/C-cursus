/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eugene <eugene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:20:28 by cliew             #+#    #+#             */
/*   Updated: 2023/09/24 18:10:28 by eugene           ###   ########.fr       */
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
