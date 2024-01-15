/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 09:27:41 by cliew             #+#    #+#             */
/*   Updated: 2024/01/10 23:00:22 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*res;
	size_t	n;
	size_t	i;

	n = nmemb * size;
	res = malloc(n);
	if (res)
	{
		i = 0;
		while (i < n)
		{
			((unsigned char *)res)[i] = 0;
			i++;
		}
	}
	return (res);
}

char	*ft_strjoin_nconst(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (0);
	i = 0;
	while (s1[i])
		i++;
	j = 0;
	while (s2[j])
		j++;
	res = ft_calloc(i + j + 1, 1);
	if (!res)
		return (NULL);
	i = -1;
	j = -1;
	while (s1[++i])
		res[i] = s1[i];
	while (s2[++j])
		res[i + j] = s2[j];
	return (res);
}

char	*ft_strncpy_mod(char *src, size_t n, int full_cpy)
{
	size_t	i;
	size_t	len;
	char	*dest;

	len = 0;
	while (src[len])
		len++;
	if (full_cpy == 1)
		n = len;
	dest = (char *)ft_calloc(n + 1, 1);
	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		++i;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

int	find_length(char *str, int chr, int *i, int *eol)
{
	int	end_current;

	end_current = -1;
	while (str[*i] != '\0')
	{
		if (str[*i] != chr && *eol == 0)
			end_current = *i + 1;
		if (str[*i] == chr)
		{
			if (*eol == 0 && end_current == -1)
				end_current = 0;
			*eol = 1;
		}
		(*i)++;
	}
	return (end_current);
}

int	ft_strchar_mod(char *str, int chr, int fd, struct s_fileInfo *fd_i)
{
	int		i;
	int		end_current;
	int		eol;
	char	*temp_cur;
	char	*temp_join;

	eol = 0;
	i = 0;
	end_current = find_length(str, chr, &i, &eol);
	if (!fd_i[fd].c_line)
		fd_i[fd].c_line = ft_strncpy_mod(str, end_current + 1, 0);
	else
	{
		temp_cur = ft_strncpy_mod(str, end_current + 1, 0);
		temp_join = ft_strjoin_nconst(fd_i[fd].c_line, temp_cur);
		ft_free(&(fd_i[fd].c_line), &temp_cur, 0);
		fd_i[fd].c_line = temp_join;
	}
	if (fd_i[fd].p_line)
		free(fd_i[fd].p_line);
	if (i - (end_current + 1) > 0 && fd_i[fd].file_end != 1)
		fd_i[fd].p_line = ft_strncpy_mod(str + end_current + 1, i - end_current, 0);
	else
		fd_i[fd].p_line = NULL;
	return (eol);
}
