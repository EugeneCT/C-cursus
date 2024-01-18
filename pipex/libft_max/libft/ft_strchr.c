/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:20:36 by cliew             #+#    #+#             */
/*   Updated: 2023/09/19 15:20:36 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int chr)
{
	int				i;
	char			*ret;
	unsigned char	c;

	c = ((unsigned char)chr);
	ret = (char *)str;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
		{
			return (ret + i);
		}
		i++;
	}
	if (str[i] == '\0' && c == '\0')
	{
		return (ret + i);
	}
	return ((char *) NULL);
}


int	ft_strchr_count(const char *s, int c)
{
	int	count;

	if (s == NULL)
		return (0);
	count = 0;
	while (*s)
	{
		if (*s == c)
			count++;
		s++;
	}
	return (count);
}
// int main(){

// 	char *ret;
// 	char s[]="tripouille";

// 	ret=ft_strchr(s, 't' + 256);
// 	printf(ret);

// }
