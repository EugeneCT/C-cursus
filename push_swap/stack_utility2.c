/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utility2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew < cliew@student.42singapore.sg>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 23:20:46 by cliew             #+#    #+#             */
/*   Updated: 2024/02/19 16:09:46 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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

void	clear_stack(t_node *stack1, t_node *stack2)
{
	t_node	*temp;

	temp = NULL;
	if (!stack1)
		return ;
	stack1 = find_end_node(stack1, 0);
	while (stack1)
	{
		temp = stack1->next;
		free(stack1);
		stack1 = temp;
	}
	if (!stack1)
		return ;
	stack2 = find_end_node(stack2, 0);
	while (stack2)
	{
		temp = stack2->next;
		free(stack2);
		stack2 = temp;
	}
}
