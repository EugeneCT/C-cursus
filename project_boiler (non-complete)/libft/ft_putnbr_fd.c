/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 10:39:04 by cliew             #+#    #+#             */
/*   Updated: 2023/09/29 10:39:06 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	out;
	long	lnum;

	lnum = (long)n;
	if (lnum < 0)
	{
		write(fd, "-", 1);
		lnum *= -1;
	}
	if (lnum < 10)
	{
		out = lnum % 10 + '0';
		write(fd, &out, 1);
		return ;
	}
	else
	{
		ft_putnbr_fd(lnum / 10, fd);
		out = lnum % 10 + '0';
		write(fd, &out, 1);
	}
}
