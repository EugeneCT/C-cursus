/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 23:34:22 by cliew             #+#    #+#             */
/*   Updated: 2024/02/19 15:31:35 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort_three(t_node **stack)
{
	t_node	*max;
	int		max_val;

	max_val = find_min_max(*stack, "max");
	max = find_node_by(*stack, "val", max_val);
	*stack = find_end_node(*stack, 0);
	if (check_result(*stack) == 0)
		return ;
	if (*stack == max)
	{
		execute(stack, stack, "ra", 1);
	}
	else if ((*stack)->next == max)
	{
		execute(stack, stack, "rra", 1);
	}
	*stack = find_end_node(*stack, 0);
	if ((*stack)->rank > (*stack)->next->rank)
	{
		execute(stack, stack, "sa", 1);
	}
}

void	sort_ten(t_node **stack_a, t_node **stack_b)
{
	int	len;
	int	i;

	i = 4;
	len = print_stack(*stack_a, 0, "rank");
	while (i <= len)
	{
		move_rank_top(stack_a, i, 1);
		execute(stack_a, stack_b, "pb", 1);
		i++;
	}
	len = print_stack(*stack_a, 0, "rank");
	if (len == 3)
		sort_three(stack_a);
	while (*stack_b)
	{
		execute(stack_a, stack_b, "pa", 1);
	}
	move_rank_top(stack_a, 1, 1);
}

int	rank_list(t_node **stack, int min, int rank, int argc)
{
	t_node	*next_min_node;

	if (rank < argc)
	{
		next_min_node = find_node_by(*stack, "val", min);
		if (next_min_node)
			(*stack) = next_min_node;
		else
			*stack = find_end_node(*stack, 1);
		(*stack)->rank = rank;
		rank_list(stack, find_next_min(*stack, min)->val, ++rank, argc);
	}
	return (1);
}
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
