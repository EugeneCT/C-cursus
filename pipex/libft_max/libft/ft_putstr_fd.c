/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 10:39:09 by cliew             #+#    #+#             */
/*   Updated: 2024/01/19 12:56:18 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen((char *)s));
}


int	ft_puterr(char const *s)
{
	int	i;

	i=0;
	if (!s)
		return 1;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return 0;
}
