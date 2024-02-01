#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "./libft_max/printf/printf.h"
# include "./libft_max/libft/libft.h"
# include "./libft_max/getnextline/gnl.h"

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

// # define STDOUT_FILENO 1

typedef struct s_node
{
	int				val;  //content
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

#endif
