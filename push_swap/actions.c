/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 19:42:40 by cliew             #+#    #+#             */
/*   Updated: 2024/02/05 15:56:57 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
/* Operation Functions */
// sa,sb,ss
int	swap(t_node **stack)
{
	t_node	*temp;
	int		temp_val;
	if (print_stack(*stack,0,"val")<=1)
		return (1);
	*stack = find_end_node(*stack, 0);
	temp = (*stack)->next;
	temp_val = temp->val;
	temp->val = (*stack)->val;
	(*stack)->val = temp_val;
	return (1);
}
// ra,rb,rr,rra,rrb,rrr
int	rotate(t_node **stack, int reverse)
{
	t_node	*head;
	t_node	*tail;
	if (print_stack(*stack,0,"val")<=1)
		return (1);
	*stack = find_end_node(*stack, 0);
	head = *stack;
	tail = find_end_node(*stack, 1);
	if (reverse == 0)
	{
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		tail->next = head;
		head->prev = tail;
		head->next = NULL;
	}
	else
	{
		*stack = tail->prev;
		tail->next = head;
		tail->prev = NULL;
		head->prev = tail;
		(*stack)->next = NULL;
	}
    return (1);
}
int push(t_node **stack_1, t_node **stack_2) {
    t_node *head_1;
    t_node *head_2;

    head_2 = find_end_node(*stack_2, 0);
    if (!head_2)
        return 1;
    head_1 = find_end_node(*stack_1, 0);
    if (!head_1) {
        (*stack_2)=(head_2)->next;
        (*stack_1) = head_2;
		if  (*stack_2)
        	(*stack_2)->prev = NULL;
        (*stack_1)->prev = NULL;
        (*stack_1)->next = NULL;
        return 1;
    }
	(*stack_2) = (head_2)->next;

    head_2->prev = NULL;
    head_2->next = head_1;
    head_1->prev = head_2;
	if (*stack_2)
    	(*stack_2)->prev = NULL;
    return 0;
}

int	execute(t_node **stack_a, t_node **stack_b, char *line, int s_print)
{
	if (s_print)
		ft_printf("%s\n", line);
	if (ft_strcmp(line, "sa") == 0)
		return (swap(stack_a));
	else if (ft_strcmp(line, "sb") == 0)
		return (swap(stack_b));
	else if (ft_strcmp(line, "ss") == 0)
		return (swap(stack_a) && swap(stack_b));
	else if (ft_strcmp(line, "pa") == 0)
		return (push(stack_a, stack_b));
	else if (ft_strcmp(line, "pb") == 0)
		return (push(stack_b, stack_a));
	else if (ft_strcmp(line, "ra") == 0)
		return (rotate(stack_a, 0));
	else if (ft_strcmp(line, "rb") == 0)
		return (rotate(stack_b, 0));
	else if (ft_strcmp(line, "rr") == 0)
		return (rotate(stack_a, 0) && rotate(stack_b, 0));
	else if (ft_strcmp(line, "rra") == 0)
		return (rotate(stack_a, 1));
	else if (ft_strcmp(line, "rrb") == 0)
		return (rotate(stack_b, 1));
	else if (ft_strcmp(line, "rrr") == 0)
		return ((rotate(stack_b, 1)) && (rotate(stack_a, 1)));
	return (0);
}


int	multi_execute(t_node **stack_a, t_node **stack_b, char *line, int n)
{
	while (n--)
	{
		if (!execute(stack_a, stack_b, line, 1))
			return (1);
	}
	return (0);
}