/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:01:53 by cliew             #+#    #+#             */
/*   Updated: 2024/02/01 07:35:50 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
// Existing libft
# include "./libft_max/getnextline/gnl.h"
# include "./libft_max/libft/libft.h"
# include "./libft_max/printf/printf.h"

// Standard
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

// Pipex
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# include <unistd.h>
# include <errno.h>

// Error Handiling
# define ERR_INVALID_PARAMS "pipex: invalid parameters"
# define ERR_INVALID_CMD "\n pipex: command not found \n"
# define STDIN_FILENO 0
# define STDOUT_FILENO 1

// Struc

typedef struct s_params
{
	int		fin;
	int		fout;
	int		argc;
	char	**argv;
	char	**envp;
	int		pipefd[2];
}			t_in;

char		*check_path(char **envp);
char		*locate_cmd(char **paths, char *cmd);
char		*find_env_path(char **envp);
void		free_array(char **v);
char		**find_cmd_paths(char **envp);
char		**ft_split_cmd_args(char *s);
int			run_cmd(char *cmd, char **envp);
int			pipex(t_in in);
#endif
