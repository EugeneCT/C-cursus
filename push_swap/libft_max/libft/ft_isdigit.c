/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew < cliew@student.42singapore.sg>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 10:37:27 by cliew             #+#    #+#             */
/*   Updated: 2024/02/15 13:41:25 by cliew            ###   ########.fr       */
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


int ft_isInteger(char *number)
{
    int i;
	i = 0;

    //checking for negative numbers
    if (number[0] == '-')
    {
		i = 1;
	}
	while (number[i]!='\0')
    {
        //if (number[i] > '9' || number[i] < '0')
        if (!ft_isdigit(number[i]))
            return 0;
		i++;
    }
    return 1;
}