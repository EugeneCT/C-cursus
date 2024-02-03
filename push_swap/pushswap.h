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
	int				rank;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

int	swap(t_node **stack);
int	rotate(t_node **stack, int reverse);// ra,rb,rr,rra,rrb,rrr
int push(t_node **stack_1, t_node **stack_2);
int	execute(t_node **stack_a, t_node **stack_b, char *line, int s_print);
#endif