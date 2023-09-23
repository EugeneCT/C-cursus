/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:21:19 by cliew             #+#    #+#             */
/*   Updated: 2023/09/19 15:21:19 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	lil;
	size_t	lil_len;

	lil_len = 0;
	i = 0;
	lil = 0;
	while (little[lil_len])
		lil_len++;
	while (i < len && i + lil < len && lil != lil_len)
	{
		if (big[i + lil] == little[lil])
			lil++;
		else
		{
			i++;
			lil = 0;
		}
	}
	if (lil_len == 0)
		return ((char *)big);
	else if (lil == lil_len)
		return ((char *)big + i);
	else
		return ((char *)(NULL));
}

// int	main(void)
// {
// 	char str1[] = "This is an apple";
// 	char str2[] = "an";
// 	char str3[] = "";
// 	char str4[] = "lala";

// 	char *ret;
// 	// ret = strnstr(str1,str2,12);
// 	// printf(ret);
// 	ret = strnstr(str1, str2, 12);
// 	printf(ret);
// }
