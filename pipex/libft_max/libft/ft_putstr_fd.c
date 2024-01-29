/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 10:39:09 by cliew             #+#    #+#             */
/*   Updated: 2024/01/29 12:47:50 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen((char *)s));
}


int	ft_puterr(char const *s,int ret)
{

	ft_putstr_fd(s, 2);
	ft_putstr_fd("\n", 2);
	return (ret);
}
