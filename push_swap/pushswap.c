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


void print_stack(t_node *stack)
{

    stack=find_end_node(stack,0);
    while (stack)
    {
        ft_printf("%d \n",stack->val);
        stack=stack->next;
    }

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
t_node *swap(t_node *stack)
{
    t_node *temp;
    int temp_val;

    stack=find_end_node(stack,0);
    temp=stack->next;
    temp_val=temp->val;
    temp->val=stack->val;
    stack->val=temp_val;
    return stack;
}
// ra,rb,rr,rra,rrb,rrr
void rotate(t_node *stack,int reverse)
{
    t_node *head;
    t_node *tail;

    head=find_end_node(stack,0);
    tail=find_end_node(stack,1);

    if (reverse==0)
    {
        tail->next=head;
        head->prev=tail;
        // tail->next=head;
        head->next=NULL;
    }
    else
    {
        tail=find_end_node(stack,0);
        tail->prev=NULL;
        tail->next=head;
        head->prev=tail;
    }
    find_end_node(stack,0);


}





int	main(int argc, char **argv)
{
	int i;
	t_node *stack_a;
	t_node	*stack_b;

	i = 1;
	stack_a = NULL;
	stack_b = NULL;

	while (i < argc)
	{
		stack_a = add_node(stack_a,ft_atoi(argv[i]));
		i++;
	}
    ft_printf("Stack a : \n");
    print_stack(stack_a);
    ft_printf("Stack b : \n");

    // swap(stack_a);
    // ft_printf("After swap Stack a : \n");
    // print_stack(stack_a);
    // print_stack(stack_b);

    rotate(stack_a,0); // ra
    ft_printf("After rotate Stack a : \n");
    print_stack(stack_a);
    print_stack(stack_b);





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