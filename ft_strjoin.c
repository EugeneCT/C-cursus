/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 21:34:38 by cliew             #+#    #+#             */
/*   Updated: 2023/09/20 21:34:38 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*ret;
	int		s1_len;
	int		s2_len;

	while (s1[s1_len])
		s1_len++;
	while (s2[s2_len])
		s2_len++;
	ret = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	while (i < s1_len)
	{
		ret[i] = s1[i];
		i++;
	}
	while (j < s2_len)
	{
		ret[i + j] = s2[j];
		j++;
	}
	ret[i + j] = '\0';
	return (ret);
}

// int main(){
//     char str1[]="Hello K";
//     char str2[]="opss d";

//     char* str3 = ft_strjoin(str1,str2);
//     printf(str3);

// }
