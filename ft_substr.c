/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 21:19:42 by cliew             #+#    #+#             */
/*   Updated: 2023/09/20 21:19:42 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// #include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	int		j;
	char	*ret;
	int		max_len;

	max_len = start + len;
	ret = (char *)malloc((len + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	j = 0;
	i = 0;
	while (start < max_len)
	{
		ret[j] = s[start - 1];
		j++;
		start++;
	}
	ret[j] = '\0';
	return (ret);
}

// int main(){
//     char str1[]="Hello bye";
//     char *str2 = ft_substr(str1,5,3);
//     printf(str2);
// }