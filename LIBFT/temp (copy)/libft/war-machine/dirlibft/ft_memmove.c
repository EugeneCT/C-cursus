/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:20:28 by cliew             #+#    #+#             */
/*   Updated: 2023/09/19 15:20:28 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *to, const void *from, size_t numBytes)
{
	size_t	i;

	i = 0;
	while (i < numBytes)
	{
		((unsigned char *)to)[i] = ((unsigned char *)from)[i];
		i++;
	}
	((unsigned char *)to)[i] = '\0';
	return (to);
}
