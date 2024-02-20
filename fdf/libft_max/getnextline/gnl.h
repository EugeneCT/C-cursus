/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew < cliew@student.42singapore.sg>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 14:14:38 by cliew             #+#    #+#             */
/*   Updated: 2024/01/30 17:37:54 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

struct		s_fileInfo
{
	char	*c_line;
	char	*p_line;
	int		file_end;
};

void		*ft_calloc(size_t nmemb, size_t size);
char		*ft_strjoin_nconst(char *s1, char *s2);
char		*ft_strncpm(char *src, size_t n, int full_cpy);
int			find_length(char *str, int chr, int *i, int *eol);
int			ft_strchar_mod(char *str, int chr, int fd, struct s_fileInfo *fd_i);
void		ft_free(char **s1, char **s2, int *s3);
char		*ft_strchr_mini(const char *s, int c);
char		*read_file(int fd, struct s_fileInfo *fd_i, char **buffer,
				char **n_b);
char		*get_result(int fd, struct s_fileInfo *fd_i);
char		*get_next_line(int fd);

#endif