/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 10:13:07 by cliew             #+#    #+#             */
/*   Updated: 2023/09/23 10:13:07 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	i;

	str = ft_strdup(s);
	if (!str)
	{
		return (NULL);
	}
	i = 0;
	while (str[i])
	{
		str[i] = (*f)(i, str[i]);
		i++;
	}
	return (str);
}
// char	mapi_test(unsigned int i, char c){}

// int main(){

//     char str[]="hello";
//     char *res;
// 	// char *func=*ft_toupper;

//     res=ft_strmapi(str,mapi_test);
// 	printf(res);
// }