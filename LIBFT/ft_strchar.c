/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:20:36 by cliew             #+#    #+#             */
/*   Updated: 2023/09/19 15:20:36 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"


char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	*ret;

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
	return (0);
}
