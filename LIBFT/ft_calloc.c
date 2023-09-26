/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eugene <eugene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 21:00:07 by cliew             #+#    #+#             */
/*   Updated: 2023/09/26 21:21:21 by eugene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (count == 0 || size == 0)
		return (malloc(0));
	if (ptr == NULL)
		return (NULL);
	ft_memset((unsigned char *)ptr, 0, count * size);
	return (ptr);
}
