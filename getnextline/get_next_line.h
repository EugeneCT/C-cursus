#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif
struct		s_fileInfo
{
    char    *c_line;
    int     nl_count;
    int     w_count;
    int     end;
};
char	*get_next_line(int fd);
// void	to_assign(char **storage, char *hold, char **res);
// char	*to_save(char *hold);
// char	*to_print(char *hold);
// void	to_retrieve(int fd, char **storage, char **hold);
void	ft_free(char **s1, char **s2, char **s3);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strjoin(char *s1, char *s2);
int 	ft_strchr(char *str, int chr,int nl_num,int total_nl);
int		ft_strcmp(char *s1, char *s2);
// char	*ft_strdup(char *s);
// int		is_there_nl(char *s);

#endif