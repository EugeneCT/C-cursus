#ifndef PIPEX
# define PIPEX
// Existing libft
# include "./libft_max/printf/printf.h"
# include "./libft_max/libft/libft.h"
# include "./libft_max/getnextline/gnl.h"

// Standard
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

// Pipex
# include <stdio.h>
# include <sys/wait.h>
# include <unistd.h>
# include <fcntl.h>
// Error Handiling
# define ERR_INVALID_PARAMS "pipex: invalid parameters"
# define ERR_INVALID_FILE "pipex: no such file or directory"
# define ERR_INVALID_CMD "pipex: command not found"
# define ERR_SOMETHING_WENT_WRONG "pipex: something went wrong"
# define ERR_PIPE "pipex: pipe error"
# define ERR_FORK "pipex: fork error"

// Struc

struct		cmd_store
{
	char	*input;
    int valid;
	char	*flags;
};
// typedef struct s_params
// {
// 	int		fin;
// 	int		fout;
// 	char	**argv;
// 	char	**envp;
// 	int		pipefd[2];
// }	t_params;
#endif
