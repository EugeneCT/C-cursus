/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_simulate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew < cliew@student.42singapore.sg>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 23:14:37 by cliew             #+#    #+#             */
/*   Updated: 2024/02/19 16:09:39 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_node	*duplicate_list(t_node *stack)
{
	t_node	*new_stack;
	t_node	*old_stack_head;
	int		len;
	int		i;
	int		min;

	new_stack = NULL;
	len = print_stack(stack, 0, "rank");
	old_stack_head = find_end_node(stack, 0);
	i = 0;
	while (i < len)
	{
		new_stack = add_node(new_stack, old_stack_head->val);
		i++;
		old_stack_head = old_stack_head->next;
	}
	min = find_min_max(new_stack, "min");
	rank_list(&new_stack, min, 1, len + 1);
	return (new_stack);
}

int	cost_to_end(t_node *stack, int last_node)
{
	int	count;

	count = 0;
	if (!stack)
		return (0);
	if (last_node)
	{
		while (stack->next)
		{
			count++;
			stack = stack->next;
		}
	}
	else
	{
		while (stack->prev)
		{
			count++;
			stack = stack->prev;
		}
	}
	return (count);
}

int	count_chunk_cost(t_node *stack_a, int max_chunk, int argc)
{
	t_node	*tmp_a;
	t_node	*tmp_b;
	int		count;
	int		k;

	tmp_a = NULL;
	tmp_b = NULL;
	tmp_a = duplicate_list(stack_a);
	count = chunk_sort_no_print(max_chunk, &tmp_a, &tmp_b, argc);
	k = argc - 1;
	while (k > 0)
	{
		count = count + push_to_stack_ba(&tmp_b, &tmp_a, k, 0);
		k--;
	}
	clear_stack(tmp_a, tmp_b);
	return (count);
}

int	find_best_chunk(t_node *stack_a, int argc)
{
	int	min_count;
	int	max_chunk;
	int	best_chunk;
	int	count;

	min_count = -1;
	max_chunk = 1;
	best_chunk = 1;
	while (max_chunk <= (argc / 4))
	{
		if ((argc - 1) % max_chunk == 0)
		{
			count = count_chunk_cost(stack_a, max_chunk, argc);
			if (min_count == -1)
				min_count = count;
			else if (count < min_count)
			{
				min_count = count;
				best_chunk = max_chunk;
			}
		}
		max_chunk++;
	}
	return (best_chunk);
}

int	find_min_cost_rank(int chunk, int argc, int max_chunk, t_node *stack_a)
{
	int	j;
	int	min_cost;
	int	min_cost_rank;

	j = 1 + ((chunk - 1) * argc / max_chunk);
	min_cost = argc + 100;
	while (j <= (chunk) * (argc / max_chunk))
	{
		if (find_node_by(stack_a, "rank", j))
		{
			if (cost_to_end(find_node_by(stack_a, "rank", j), 0) < min_cost)
			{
				min_cost = cost_to_end(find_node_by(stack_a, "rank", j), 0);
				min_cost_rank = j;
			}
			if (cost_to_end(find_node_by(stack_a, "rank", j), 1) + 1 < min_cost)
			{
				min_cost = cost_to_end(find_node_by(stack_a, "rank", j), 1) + 1;
				min_cost_rank = j;
			}
		}
		j++;
	}
	return (min_cost_rank);
}
