/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 10:40:49 by cliew             #+#    #+#             */
/*   Updated: 2023/09/29 10:40:57 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned long	i;
	int				j;

	j = 0;
	i = 0;
	if (!*needle)
		return ((char *)haystack);
	while (haystack[i])
	{
		j = 0;
		while (haystack[i] == needle[j] && haystack[i] && i < len)
		{
			i++;
			j++;
		}
		if (!needle[j])
			return ((char *)&haystack[i - j]);
		i = (i - j) + 1;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char str1[] = "This is an apple";
// 	char str2[] = "an";
// 	char str3[] = "";
// 	char str4[] = "lala";
// 	char * empty = (char*)"";
// 	char *ret;

// 	ft_strnstr(empty, "coucou", -1);
// 	// ret = strnstr(str1,str2,12);
// 	// printf(ret);
// 	// ret = strnstr(str1, str2, 12);
// 	// printf(ret);
// }
