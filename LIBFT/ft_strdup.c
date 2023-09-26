/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eugene <eugene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 21:03:52 by cliew             #+#    #+#             */
/*   Updated: 2023/09/24 23:16:07 by eugene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
char	*ft_strdup(const char *s)
{
	int		len;
	char	*ret;
	int		i;

	len = 0;
	i = 0;
	while (s[len]!='\0')
		len++;
	ret = (char *)malloc((len+1) * sizeof(s));
	while (i < len)
	{
		ret[i] = s[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
