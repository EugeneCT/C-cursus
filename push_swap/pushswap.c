#include "pushswap.h"

/* Node Functions */
t_node	*create_node(int val)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->val = val;
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

void	print_stack(t_node *stack)
{
	stack = find_end_node(stack, 0);
	while (stack)
	{
		ft_printf("%d \n", stack->val);
		stack = stack->next;
	}
	stack = find_end_node(stack, 0);
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

/* Operation Functions */
// sa,sb,ss
int	swap(t_node **stack)
{
	t_node	*temp;
	int		temp_val;

	*stack = find_end_node(*stack, 0);
	temp = (*stack)->next;
	temp_val = temp->val;
	temp->val = (*stack)->val;
	(*stack)->val = temp_val;
	return (0);
}
// ra,rb,rr,rra,rrb,rrr
int	rotate(t_node **stack, int reverse)
{
	t_node	*head;
	t_node	*tail;

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
    return (0);
}
int push(t_node **stack_1, t_node **stack_2) {
    t_node *head_1;
    t_node *head_2;

    head_2 = find_end_node(*stack_2, 0);
    if (!head_2)
        return 1;

    head_1 = find_end_node(*stack_1, 0);
    if (!head_1) {
        printf("destination isempty!");
        (*stack_2) = (*stack_2)->next;
        (*stack_1) = head_2;
        (*stack_2)->prev = NULL;
        (*stack_1)->prev = NULL;
        (*stack_1)->next = NULL;
        return 0;
    }
    (*stack_2) = (*stack_2)->next;
    head_2->prev = NULL;
    head_2->next = head_1;
    head_1->prev = head_2;
    (*stack_2)->prev = NULL;
    return 0;
}

int	execute(t_node **stack_a, t_node **stack_b, char *line, int s_print)
{
	if (!s_print)
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
		return (rotate(stack_a, 1) && rotate(stack_b, 1));
	return (0);
}
int	main(int argc, char **argv)
{
	int i;
	t_node *stack_a;
	t_node *stack_b;

	i = 1;
	stack_a = NULL;
	stack_b = NULL;

	while (i < argc)
	{
		stack_a = add_node(stack_a, ft_atoi(argv[i]));
		i++;
	}
	ft_printf("Stack a : \n");
	print_stack(stack_a);
	ft_printf("Stack b : \n");
    print_stack(stack_b);

    execute(&stack_a,&stack_b,"pb", 1);
    ft_printf("pb \n");
    ft_printf("Stack a : \n");
	print_stack(stack_a);
	ft_printf("Stack b : \n");
    print_stack(stack_b);

    execute(&stack_a,&stack_b,"ra", 1);
    ft_printf("ra \n");
    ft_printf("Stack a : \n");
	print_stack(stack_a);
	ft_printf("Stack b : \n");
    print_stack(stack_b);


    execute(&stack_a,&stack_b,"pb", 1);
    ft_printf("pb \n");
    ft_printf("Stack a : \n");
	print_stack(stack_a);
	ft_printf("Stack b : \n");
    print_stack(stack_b);

    execute(&stack_a,&stack_b,"ra", 1);
    ft_printf("ra \n");
    ft_printf("Stack a : \n");
	print_stack(stack_a);
	ft_printf("Stack b : \n");
    print_stack(stack_b);

    execute(&stack_a,&stack_b,"sa", 1);
     ft_printf("sa \n");
    ft_printf("Stack a : \n");
	print_stack(stack_a);
	ft_printf("Stack b : \n");
    print_stack(stack_b);

    execute(&stack_a,&stack_b,"ra", 1);
    ft_printf("ra \n");
    ft_printf("Stack a : \n");
	print_stack(stack_a);
	ft_printf("Stack b : \n");
    print_stack(stack_b);

    execute(&stack_a,&stack_b,"pa", 1);
    ft_printf("pa \n");
    ft_printf("Stack a : \n");
	print_stack(stack_a);
	ft_printf("Stack b : \n");
    print_stack(stack_b);
    execute(&stack_a,&stack_b,"pa", 1);   
    ft_printf("pa \n");
    ft_printf("Stack a : \n");
	print_stack(stack_a);
	ft_printf("Stack b : \n");
    print_stack(stack_b);


    ft_printf("After Sort : \n");
    ft_printf("Stack a : \n");
	print_stack(stack_a);
	ft_printf("Stack b : \n");	
    // swap(&stack_a);
	// ft_printf("After swap Stack a : \n");
	// print_stack(stack_a);
	// print_stack(stack_b);

	// // rotate(stack_a,0); // ra
	// // ft_printf("After rotate Stack a : \n");
	// // print_stack(stack_a);
	// // print_stack(stack_b);
	// rotate(&stack_a, 0); // ra

	// ft_printf("After reverese rotate Stack a : \n");
	// print_stack(stack_a);
	// print_stack(stack_b);

    // push(&stack_b,&stack_a); // ra

	// ft_printf("After push ra : \n");
    // ft_printf("Stack a : \n");
	// print_stack(stack_a);
    // ft_printf("Stack b : \n");
	// print_stack(stack_b);

	// char *stack_a;
	// char *stack_b;

	// int i=0;
	// int j=0;
	// stack_a= (char *)malloc((argc-1) * sizeof(char));
	// stack_b= (char *)malloc((argc-1) * sizeof(char));

	// // Check if memory allocation was successful
	// if (stack_a == NULL) {
	//     fprintf(stderr, "Memory allocation failed\n");
	//     return (1); // Return an error code
	// }
	// if (stack_b == NULL) {
	//     fprintf(stderr, "Memory allocation failed\n");
	//     return (1); // Return an error code
	// }
	// if (argv == NULL) {
	//     fprintf(stderr, "Memory allocation failed for argv\n");
	//     return (1); // Return an error code
	// }

	// while (i < argc)
	// {
	//     stack_a[i] = (*argv[i]);
	//     printf("i of %d is %c\n",i,stack_a[i]);

	//     i++;
	// }

	//     while (j < argc)
	// {
	//     // stack_b[j] = ft_atoi(argv[j]);
	//     printf("j of %d is %d\n",j,stack_b[j]);
	//     j++;
	// }
}