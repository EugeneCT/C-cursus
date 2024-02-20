/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew < cliew@student.42singapore.sg>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 10:37:27 by cliew             #+#    #+#             */
/*   Updated: 2024/02/18 23:45:26 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	else
		return (0);
}

int	ft_isinteger(char *number)
{
	int	i;

	i = 0;
	if (number[0] == '-')
		i = 1;
	if (number[0] == '0' && number[1] != '\0')
		return (0);
	if (number[0] == '-' && number[1] == '0')
		return (0);
	if (number[0] == '-' && number[1] == '\0')
		return (0);
	while (number[i] != '\0')
	{
		if (!ft_isdigit(number[i]))
			return (0);
		i++;
	}
	return (1);
}
