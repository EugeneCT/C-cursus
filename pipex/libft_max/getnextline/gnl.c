/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew < cliew@student.42singapore.sg>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 09:27:41 by cliew             #+#    #+#             */
/*   Updated: 2023/12/12 17:33:29 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

void	ft_free(char **s1, char **s2, int *s3)
{
	if (s1)
	{
		free(*s1);
		*s1 = NULL;
	}
	if (s2)
	{
		free(*s2);
		*s2 = NULL;
	}
	if (s3)
	{
		*s3 = 0;
	}
}

char	*ft_strchr_mini(const char *s, int c)
{
	while (*s != (unsigned char)c)
		if (!*s++)
			return (0);
	return ((char *)s);
}

char	*read_file(int fd, struct s_fileInfo *fd_i, char **buffer, char **n_b)
{
	int	b_count;
	int	eol;

	b_count = 1;
	eol = 0;
	while (b_count >= 0 && eol == 0)
	{
		b_count = read(fd, *buffer, BUFFER_SIZE);
		if (b_count == 0)
		{
			fd_i[fd].file_end = 1;
			ft_free(buffer, n_b, 0);
			return (fd_i[fd].c_line);
		}
		if (b_count == -1)
		{
			fd_i[fd].file_end = 2;
			ft_free(buffer, n_b, 0);
			return (NULL);
		}
		ft_free(n_b, 0, 0);
		*n_b = ft_strncpm(*buffer, b_count, 0);
		eol = ft_strchar_mod(*n_b, '\n', fd, fd_i);
	}
	return (fd_i[fd].c_line);
}

char	*get_result(int fd, struct s_fileInfo *fd_i)
{
	char	*buffer;
	char	*new_buffer;
	char	*result;

	buffer = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!buffer)
		return (NULL);
	new_buffer = NULL;
	if (fd_i[fd].p_line != NULL)
	{
		fd_i[fd].c_line = ft_strncpm(fd_i[fd].p_line, 1, 1);
		ft_free(&(fd_i[fd].p_line), 0, 0);
	}
	result = read_file(fd, fd_i, &buffer, &new_buffer);
	ft_free(&buffer, &new_buffer, 0);
	return (result);
}

char	*get_next_line(int fd)
{
	static struct s_fileInfo	fd_i[1024];
	char						*res;
	char						*str;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= 1024)
		return (NULL);
	if (fd_i[fd].c_line)
		fd_i[fd].c_line = NULL;
	if (fd_i[fd].file_end == 1)
	{
		ft_free(&(fd_i[fd].c_line), &(fd_i[fd].p_line), &fd_i[fd].file_end);
		return (NULL);
	}
	if (fd_i[fd].p_line && ft_strchr_mini(fd_i[fd].p_line, '\n'))
	{
		str = ft_strncpm(fd_i[fd].p_line, 1, 1);
		ft_strchar_mod(str, '\n', fd, fd_i);
		free(str);
		return (fd_i[fd].c_line);
	}
	res = get_result(fd, fd_i);
	if (res == NULL)
		ft_free(&(fd_i[fd].c_line), &(fd_i[fd].p_line), &fd_i[fd].file_end);
	return (res);
}
