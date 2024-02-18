/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew < cliew@student.42singapore.sg>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 19:21:44 by cliew             #+#    #+#             */
/*   Updated: 2024/02/18 23:44:29 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	chunk_sort_no_print(int max_chunk, t_node **stack_a, t_node **stack_b,
		int argc)
{
	int	chunk;
	int	repeat;
	int	min_cost_rank;
	int	count;
	int	print;

	print = 0;
	chunk = 1;
	repeat = 0;
	count = 0;
	while (chunk <= max_chunk)
	{
		while (repeat < (argc / max_chunk))
		{
			min_cost_rank = find_min_cost_rank(chunk, argc, max_chunk,
					*stack_a);
			count = count + move_rank_top(stack_a, min_cost_rank, print);
			execute(stack_a, stack_b, "pb", print);
			count++;
			repeat++;
		}
		repeat = 0;
		chunk++;
	}
	return (count);
}

int	chunk_sort(int max_chunk, t_node **stack_a, t_node **stack_b, int argc)
{
	int	chunk;
	int	repeat;
	int	min_cost_rank;
	int	count;
	int	print;

	print = 1;
	chunk = 1;
	repeat = 0;
	count = 0;
	while (chunk <= max_chunk)
	{
		while (repeat < (argc / max_chunk))
		{
			min_cost_rank = find_min_cost_rank(chunk, argc, max_chunk,
					*stack_a);
			count = count + move_rank_top(stack_a, min_cost_rank, print);
			execute(stack_a, stack_b, "pb", print);
			count++;
			repeat++;
		}
		repeat = 0;
		chunk++;
	}
	return (count);
}

int	check_input(int argc, char **argv)
{
	int		i;
	long	argv_i;
	int		j;

	i = 1;
	if (argc == 1)
		return (ft_puterr("", 1));
	while (i < argc)
	{
		argv_i = ft_atoll(argv[i]);
		if (argv_i > INT_MAX || argv_i < INT_MIN || argv[i][0] == '\0'
			|| !ft_isinteger(argv[i]))
			return (ft_puterr("Error", 1));
		j = i + 1;
		while (j < argc)
		{
			if (ft_strcmp(argv[i], argv[j]) == 0)
				return (ft_puterr("Error", 1));
			j++;
		}
		i++;
	}
	return (0);
}

int	init_stack(t_node **stack_a, t_node **stack_b, int argc, char **argv)
{
	int	i;
	int	min;

	i = 1;
	*stack_a = NULL;
	*stack_b = NULL;
	while (i < argc)
	{
		*stack_a = add_node(*stack_a, ft_atoi(argv[i]));
		i++;
	}
	min = find_min_max(*stack_a, "min");
	rank_list(stack_a, min, 1, argc);
	if (check_result(*stack_a) == 0)
	{
		clear_stack(*stack_a);
		clear_stack(*stack_b);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		count;
	int		best_chunk;
	t_node	*stack_a;
	t_node	*stack_b;
	int		k;

	count = 0;
	if (check_input(argc, argv) == 1 || init_stack(&stack_a, &stack_b, argc,
			argv) == 1)
		return (1);
	if (argc == 4)
		sort_three(&stack_a);
	else if (argc <= 11)
		sort_ten(&stack_a, &stack_b);
	else
	{
		best_chunk = find_best_chunk(stack_a, argc);
		count = chunk_sort(best_chunk, &stack_a, &stack_b, argc);
		k = argc;
		while (--k > 0)
			count += push_to_stack_ba(&stack_b, &stack_a, k, 1);
		count = count + move_rank_top(&stack_a, 1, 1);
	}
	clear_stack(stack_a);
	clear_stack(stack_b);
}
