/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 10:39:42 by cliew             #+#    #+#             */
/*   Updated: 2024/01/15 14:02:54 by cliew            ###   ########.fr       */
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
	while (s[len] != '\0')
		len++;
	ret = (char *)malloc((len + 1) * sizeof(char));
	if (!ret)
		return (0);
	while (i < len)
	{
		ret[i] = s[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*ft_strdup_ignore(const char *s, char ignore)
{
	char	*dup;
	size_t	slen;
	size_t	i;

	slen = ft_strlen(s);
	i = ft_strchr_count(s, ignore);
	dup = (char *)malloc((slen - i + 1) * sizeof(char));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != ignore)
		{
			dup[i] = *s;
			i++;
		}
		s++;
	}
	dup[i] = 0;
	return (dup);
}
