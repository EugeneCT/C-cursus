/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:03:47 by cliew             #+#    #+#             */
/*   Updated: 2023/11/01 13:32:37 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // for strerror
#include <unistd.h>

static struct s_fileInfo	fd_info[1024];
char	*get_result(int fd)
{
	int		b_count;
	char	*buffer;
	int		total_nl_count;
	int		buffer_nl;
	total_nl_count = 0;
	buffer = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!buffer)
		return ;
	b_count = 1;
	// printf("pline %p",fd_info[fd].p_line);
	while (b_count > 0)
	{
		b_count = read(fd, buffer, BUFFER_SIZE);
		if (b_count == -1)
		{
			printf("Error message: %s\n", strerror(errno));
			return ;
		}

		buffer_nl=ft_strchr(buffer,'\n',fd_info[fd].nl_count,total_nl_count);
		total_nl_count+=buffer_nl;

		(fd_info[fd]).c_line = ft_strjoin(fd_info[fd].c_line, buffer);
		if (buffer_nl==-1)
			fd_info[fd].end=1;
		if (buffer_nl ==1 || buffer_nl==-1)
			return (fd_info[fd].c_line);
		// fd_info[fd].w_count+=count;
	}
	return (fd_info[fd].c_line);
	printf("fill");
}

char	*get_next_line(int fd)
{
	char	*res;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= 1024)
		return (NULL);

	fd_info[fd].c_line = "";
	if (fd_info[fd].end==1)
		return NULL;
	res = get_result(fd);
	fd_info[fd].nl_count+=1;

	return (res);
}

int	main(void)
{
	int		fd1;
	int		fd2;

	char	*res;
	char	*res2;
	char	*res_f2;

	char	*res3;


	fd1 = open("file1.txt", O_RDONLY);
	if (fd1 == -1)
	{
		perror("Error opening file");
		return (1);
	}

	fd2 = open("file2.txt", O_RDONLY);
	if (fd2 == -1)
	{
		perror("Error opening file");
		return (1);
	}
	printf("loop1\n");
	res = get_next_line(fd1);
	printf(res);

	printf("file2\n");
	res_f2 = get_next_line(fd2);
	printf(res_f2);

	printf("\nloop2\n");
	res2 = get_next_line(fd1);
	printf(res2);
	// res3 = get_next_line(fd);
	// printf(res3);
}

//     char *line;
//     while ((line = get_next_line(fd)) != NULL) {
//         printf("Next line: %s\n", line);
//         free(line); // Don't forget to free the memory
//     }

//     close(fd);
//     return (0);
// }