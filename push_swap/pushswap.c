/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew < cliew@student.42singapore.sg>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 19:21:44 by cliew             #+#    #+#             */
/*   Updated: 2024/02/17 14:25:46 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_node	*create_node(int val)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->val = val;
	node->rank = -1;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

t_node	*add_node(t_node *stack, int val)
{
	t_node	*new;

	new = create_node(val);
	if (!new)
		return (NULL);
	if (!stack)
		return (new);
	stack->next = new;
	new->prev = stack;
	return (new);
}

t_node	*find_end_node(t_node *stack, int last_node)
{
	if (!stack)
		return (NULL);
	if (last_node)
	{
		while (stack->next)
			stack = stack->next;
	}
	else
	{
		while (stack->prev)
			stack = stack->prev;
	}
	return (stack);
}

int	print_stack(t_node *stack, int print, char *type)
{
	int	len;

	len = 0;
	stack = find_end_node(stack, 0);
	while (stack)
	{
		if (print && ft_strcmp(type, "val") == 0)
			ft_printf("%d \n", stack->val);
		else if (print && ft_strcmp(type, "rank") == 0)
			ft_printf("%d \n", stack->rank);
		stack = stack->next;
		len++;
	}
	return (len);
}

void	clear_stack(t_node *stack)
{
	t_node	*temp;

	temp = NULL;
	if (!stack)
		return ;
	stack = find_end_node(stack, 0);
	while (stack)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
}

int	check_result(t_node *stack)
{
	int	temp_val;

	stack = find_end_node(stack, 0);
	if (!stack)
		return (0);
	temp_val = stack->val;
	while (stack->next)
	{
		stack = stack->next;
		if (stack->val < temp_val)
			return (1);
		temp_val = stack->val;
	}
	return (0);
}

int	find_min_max(t_node *stack, char *stat)
{
	int	temp_val;
	int	len;
	int	sum;

	sum = 0;
	len = print_stack(stack, 0, "val");
	stack = find_end_node(stack, 0);
	if (!stack)
		return (0);
	temp_val = stack->val;
	while (stack->next)
	{
		stack = stack->next;
		if (ft_strcmp(stat, "min") == 0 && stack->val < temp_val)
			temp_val = stack->val;
		else if (ft_strcmp(stat, "max") == 0 && stack->val > temp_val)
			temp_val = stack->val;
		else
			sum = sum + stack->val;
	}
	if (ft_strcmp(stat, "avg") == 0)
		return (sum / len);
	return (temp_val);
}

t_node	*find_node_by(t_node *stack, char *type, int val)
{
	stack = find_end_node(stack, 0);
	if (!stack)
		return (NULL);
	while (stack->next)
	{
		if (stack->val == val && ft_strcmp(type, "val") == 0)
			return (stack);
		else if (stack->rank == val && ft_strcmp(type, "rank") == 0)
			return (stack);
		stack = stack->next;
	}
	if (stack->val == val && ft_strcmp(type, "val") == 0)
		return (stack);
	else if (stack->rank == val && ft_strcmp(type, "rank") == 0)
		return (stack);
	return (NULL);
}

t_node	*find_next_min(t_node *stack, int min)
{
	int	temp;

	stack = find_end_node(stack, 0);
	while (stack->next && stack->val <= min)
		stack = stack->next;
	temp = stack->val;
	while (stack->next)
	{
		stack = stack->next;
		if (stack->val < temp && stack->val > min)
			temp = stack->val;
	}
	stack = find_end_node(stack, 0);
	if (stack->val == temp)
		return (stack);
	while (stack->next)
	{
		stack = stack->next;
		if (stack->val == temp)
			return (stack);
	}
	return (stack);
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

int	move_rank_top(t_node **stack, int rank, int print)
{
	int	cost_to_top;
	int	cost_to_btm;
	int	count;

	count = 0;
	*stack = find_node_by(*stack, "rank", rank);
	if (!(*stack) || ((*stack)->rank != rank)
		|| (*stack == find_end_node(*stack, 0)))
		return (0);
	cost_to_top = cost_to_end(*stack, 0);
	cost_to_btm = cost_to_end(*stack, 1);
	while (find_end_node(*stack, 0)->rank != rank)
	{
		if (cost_to_btm + 1 > cost_to_top)
		{
			execute(stack, stack, "ra", print);
			count++;
		}
		else if (cost_to_top >= cost_to_btm)
		{
			execute(stack, stack, "rra", print);
			count++;
		}
	}
	return (count);
}

void	push_to_stack_ab_v2(t_node **stack, t_node **to_stack, int rank)
{
	move_rank_top(stack, rank, 1);
	execute(stack, to_stack, "pb", 1);
}

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

int	push_to_stack_ba(t_node **stack, t_node **to_stack, int rank, int print)
{
	int	cost_to_top;
	int	cost_to_btm;
	int	count;

	*stack = find_node_by(*stack, "rank", rank);
	count = 0;
	if (!stack)
		return (0);
	cost_to_top = cost_to_end(*stack, 0);
	cost_to_btm = cost_to_end(*stack, 1);
	while (find_end_node(*stack, 0)->rank != rank)
	{
		if (cost_to_btm + 1 > cost_to_top)
		{
			execute(to_stack, stack, "rb", print);
		}
		else if (cost_to_top >= cost_to_btm)
		{
			execute(to_stack, stack, "rrb", print);
		}
		count++;
	}
	execute(to_stack, stack, "pa", print);
	return (count + 1);
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

int	check_input(int argc, char **argv)
{
	int	i;
	int	argv_i;
	int	j;

	i = 1;
	if (argc == 1)
		return (ft_puterr("", 1));
	while (i < argc)
	{
		argv_i = ft_atoi(argv[i]);
		if (argv_i > INT_MAX || argv_i < INT_MIN || argv[i][0] == '\0'
			|| !ft_isInteger(argv[i]))
		{
			return (ft_puterr("Error \n", 1));
		}
		j = i + 1;
		while (j < argc)
		{
			if (ft_strcmp(argv[i], argv[j]) == 0)
				return (ft_puterr("Error \n", 1));
			j++;
		}
		i++;
	}
	return (0);
}

void	init_stack(t_node **stack_a, t_node **stack_b, int argc, char **argv)
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
	clear_stack(tmp_a);
	clear_stack(tmp_b);
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

int	main(int argc, char **argv)
{
	int		count;
	int		best_chunk;
	t_node	*stack_a;
	t_node	*stack_b;
	int		k;

	count = 0;
	if (check_input(argc, argv) == 1)
		return (1);
	init_stack(&stack_a, &stack_b, argc, argv);
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
