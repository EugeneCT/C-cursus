/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eugene <eugene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 21:19:42 by cliew             #+#    #+#             */
/*   Updated: 2023/09/24 23:26:55 by eugene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// #include <stdio.h>




char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	i;
	size_t	j;

	if (!s || !(new_str = (char *)malloc(len + 1)))
		return (0);
	i = start;
	j = 0;
	while (i < ft_strlen(s) && j < len)
		new_str[j++] = s[i++];
	new_str[j] = '\0';
	return (new_str);
}

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	int		j;
// 	char	*ret;
// 	unsigned int		max_len;

// 	max_len = start + len;
// 	ret = (char *)malloc((len + 1) * sizeof(char));
// 	if (!ret)
// 		return (NULL);

// 	if (ft_strlen(s) < start)
// 		return ("");
// 	j = 0;
// 	while (start < max_len && s[start]!='\0')
// 	{
// 		ret[j] = s[start];
// 		j++;
// 		start++;
// 	}
// 	ret[j] = '\0';
// 	return (ret);
// }

// int main(){
//     char str1[]="Hello bye";
//     // char *str2 = ft_substr(str1,5,3);
//     // printf(str2);
// 	ft_substr("", 1, 1);
// }
