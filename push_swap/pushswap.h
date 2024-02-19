/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew < cliew@student.42singapore.sg>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 23:37:26 by cliew             #+#    #+#             */
/*   Updated: 2024/02/19 16:32:09 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "./libft_max/getnextline/gnl.h"
# include "./libft_max/libft/libft.h"
# include "./libft_max/printf/printf.h"
# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				val;
	int				rank;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

/*Stack actions*/
int					swap(t_node **stack);
int					rotate(t_node **stack, int reverse);
int					push(t_node **stack_1, t_node **stack_2);
int					execute(t_node **stack_a, t_node **stack_b, char *line,
						int s_print);
int					check_result(t_node *stack);

/*Stack utility*/
t_node				*create_node(int val);
t_node				*add_node(t_node *stack, int val);
t_node				*find_end_node(t_node *stack, int last_node);
int					print_stack(t_node *stack, int print, char *type);
t_node				*find_node_by(t_node *stack, char *type, int val);

/*Stack utility 2*/
int					find_min_max(t_node *stack, char *stat);
t_node				*find_next_min(t_node *stack, int min);
void				clear_stack(t_node *stack1, t_node *stack2);
int					move_rank_top(t_node **stack, int rank, int print);
int					push_to_stack_ba(t_node **stack, t_node **to_stack,
						int rank, int print);

/*Chunk Simulate*/
t_node				*duplicate_list(t_node *stack);
int					count_chunk_cost(t_node *stack_a, int max_chunk, int argc);
int					find_best_chunk(t_node *stack_a, int argc);
int					find_min_cost_rank(int chunk, int argc, int max_chunk,
						t_node *stack_a);
int					cost_to_end(t_node *stack, int last_node);

/*Sort_helper*/
int					rank_list(t_node **stack, int min, int rank, int argc);
void				sort_three(t_node **stack);
void				sort_ten(t_node **stack_a, t_node **stack_b);
int					chunk_sort_no_print(int max_chunk, t_node **stack_a,
						t_node **stack_b, int argc);
int					chunk_sort(int max_chunk, t_node **stack_a,
						t_node **stack_b, int argc);

/*Main*/
int					ft_freearray(char **s1, int free_pt, int run);
int					check_quote(int *argc, char ***argv);
int					check_input(int argc, char **argv);
int					init(t_node **stack_a, t_node **stack_b, int argc,
						char **argv);

#endif