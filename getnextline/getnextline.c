#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

typedef struct s_fd_storage
{
	int		fd;
	char	*storage;
	char	*hold;
}			t_fd_storage;

void	to_retrieve(t_fd_storage *fd_storage)
{
	char	*buffer;
	int		rd;

	buffer = calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return ;
	rd = 1;
	while (rd > 0)
	{
		rd = read(fd_storage->fd, buffer, BUFFER_SIZE);
		if (rd == -1)
		{
			free(buffer);
			return ;
		}
		buffer[rd] = '\0';
		fd_storage->hold = strdup(fd_storage->storage);
		free(fd_storage->storage);
		fd_storage->storage = strjoin(fd_storage->hold, buffer);
		free(fd_storage->hold);
		if (is_there_nl(fd_storage->storage))
			break ;
	}
	free(buffer);
}

char	*to_print(char *hold)
{
	char	*res;
	int		i;

	i = 0;
	while (hold[i] != '\n' && hold[i])
		i++;
	if (hold[i] == '\n')
		i++;
	res = calloc(i + 1, sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (hold[i] != '\n' && hold[i])
	{
		res[i] = hold[i];
		i++;
	}
	if (hold[i] && hold[i] == '\n')
		res[i] = hold[i];
	return (res);
}

char	*to_save(char *hold)
{
	char	*store;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (hold[i] != '\n' && hold[i])
		i++;
	if (hold[i] == '\n')
		i++;
	while (hold[j])
		j++;
	store = calloc(j - i + 1, sizeof(char));
	if (!store)
		return (NULL);
	j = 0;
	while (hold[i + j])
	{
		store[j] = hold[i + j];
		j++;
	}
	return (store);
}

void	to_assign(t_fd_storage *fd_storage, char *hold, char **res)
{
	fd_storage->storage = to_save(hold);
	*res = to_print(hold);
	free(hold);
}

char	*get_next_line(int fd)
{
	static t_fd_storage	fd_storage[1024];
	char				*res;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= 1024)
		return (NULL);
	fd_storage[fd].fd = fd;
	fd_storage[fd].hold = NULL;
	fd_storage[fd].storage = NULL;
	to_retrieve(&fd_storage[fd]);
	if (fd_storage[fd].storage && *(fd_storage[fd].storage))
	{
		fd_storage[fd].hold = strdup(fd_storage[fd].storage);
		free(fd_storage[fd].storage);
		to_assign(&fd_storage[fd], fd_storage[fd].hold, &res);
	}
	if (!res || !*res)
	{
		free(fd_storage[fd].storage);
		free(fd_storage[fd].hold);
		return (NULL);
	}
	return (res);
}

void	ft_free(char **s1, char **s2, char **s3)
{
	if (s1 && *s1)
	{
		free(*s1);
		*s1 = NULL;
	}
	if (s2 && *s2)
	{
		free(*s2);
		*s2 = NULL;
	}
	if (s3 && *s3)
	{
		free(*s3);
		*s3 = NULL;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*p;
	void			*res;
	size_t			len;

	len = nmemb * size;
	res = malloc(len);
	if (!res)
		return (NULL);
	p = res;
	while (len)
	{
		*(p++) = 0;
		len--;
	}
	return (res);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	i = 0;
	while (s1[i])
		i++;
	j = 0;
	while (s2[j])
		j++;
	res = calloc(i + j + 1, sizeof(char));
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

char	*ft_strdup(char *s)
{
	char	*res;
	int		i;

	if (!s)
		return (ft_strdup(""));
	i = 0;
	while (s[i])
		i++;
	res = calloc(i + 1, sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (s[i])
	{
		res[i] = s[i];
		i++;
	}
	return (res);
}

int	is_there_nl(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}