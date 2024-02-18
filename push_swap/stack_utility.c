/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utility.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew < cliew@student.42singapore.sg>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 23:16:35 by cliew             #+#    #+#             */
/*   Updated: 2024/02/18 23:35:42 by cliew            ###   ########.fr       */
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
