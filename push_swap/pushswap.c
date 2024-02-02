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

int	print_stack(t_node *stack,int print)
{
	int len;
	
	len=0;
	stack = find_end_node(stack, 0);
	while (stack)
	{
		if (print)
			ft_printf("%d \n", stack->val);
		stack = stack->next;
		len++;
	}
	return len;
	// stack = find_end_node(stack, 0);
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

int check_result(t_node *stack){

	int temp_val;
	stack=find_end_node(stack, 0);
	if (!stack)
		return (0);
	temp_val=stack->val;
	while (stack->next){
		stack=stack->next;
		if (stack->val < temp_val)
			return (1);
		temp_val=stack->val;
	}
	return (0);
}
/* Operation Functions */
// sa,sb,ss
int	swap(t_node **stack)
{
	t_node	*temp;
	int		temp_val;
	if (print_stack(*stack,0)<=1)
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
	if (print_stack(*stack,0)<=1)
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
        return 0;
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
int find_min_max(t_node *stack,char* stat){
	
	int temp_val;
	int len;
	int sum;
	
	sum = 0;
	len=print_stack(stack,0);
	stack=find_end_node(stack,0);
	if (!stack)
		return (0);
	temp_val=stack->val;
	while (stack->next)
	{	
		stack=stack->next;
		if (ft_strcmp(stat, "min") == 0 && stack->val < temp_val)
			temp_val=stack->val;
		else if (ft_strcmp(stat, "max") == 0 && stack->val > temp_val)
			temp_val=stack->val;
		else 
			sum=sum+stack->val;
	}
	if (ft_strcmp(stat, "avg") == 0)
		return (sum/len);
	return (temp_val);
}

// int find_median(t_node *stack,int avg){
	
// 	int temp_val;
// 	int len;
// 	t_node *min_node;

// 	len=print_stack(stack,0);
// 	stack=find_end_node(stack,0);
// 	if (!stack)
// 		return (0);
// 	temp_val=stack->val;
// 	while (temp_val!=min)
// 	{
// 		if (stack->next)
// 		{
// 			stack=stack->next;
// 			temp_val=stack->val;
// 		}
// 	}
// 	min_node=stack;

// 	while (stack->next)
// 	{	
// 		stack=stack->next;
// 		if (ft_strcmp(stat, "min") == 0 && stack->val < temp_val)
// 			temp_val=stack->val;

// 	}
// 	return (temp_val);
// }

// t_node *random3 (t_node** stack){
// 	stack=find_end_node(stack,0);



// }

int rank_list(t_node *stack)
{
	t_node *head;
	int rank;

	rank=1;
	head=find_end_node(stack,0);

	head->rank=rank;
	while (head->next)
	{
		head=head->next;
		if head-
	}


// }

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
	int len=print_stack(stack_a,0);
	printf("len is %d",len);
	int min = find_min_max(stack_a,"min");
	int max = find_min_max(stack_a,"max");
	// int mdn = find_min_max(stack_a,"mdn");

	ft_printf("\n min is %d \n",min);
	ft_printf("\n max is %d \n",max);


	// /// 3 Random case
	// if (argc == 4)
	// {


	// }
	// ft_printf("\n mdn is %d \n",mdn);


// 	ft_printf("Stack a : \n");
// 	print_stack(stack_a,1);
// 	ft_printf("Stack b : \n");
//     print_stack(stack_b,1);
// 	ft_printf("------------------------------ \n");

//     execute(&stack_a,&stack_b,"pb", 1);
//     ft_printf("Stack a : \n");
// 	print_stack(stack_a,1);
// 	ft_printf("Stack b : \n");
//     print_stack(stack_b,1);
// 	ft_printf("------------------------------ \n");

//     execute(&stack_a,&stack_b,"ra", 1);
//     ft_printf("Stack a : \n");
// 	print_stack(stack_a,1);
// 	ft_printf("Stack b : \n");
//     print_stack(stack_b,1);
// 	ft_printf("------------------------------ \n");


//     execute(&stack_a,&stack_b,"pb", 1);
//     ft_printf("Stack a : \n");
// 	print_stack(stack_a,1);
// 	ft_printf("Stack b : \n");
//     print_stack(stack_b,1);
// 	ft_printf("------------------------------ \n");

//     execute(&stack_a,&stack_b,"ra", 1);
//     ft_printf("Stack a : \n");
// 	print_stack(stack_a,1);
// 	ft_printf("Stack b : \n");
//     print_stack(stack_b,1);
// 	ft_printf("------------------------------ \n");

//     execute(&stack_a,&stack_b,"sa", 1);
//     ft_printf("Stack a : \n");
// 	print_stack(stack_a,1);
// 	ft_printf("Stack b : \n");
//     print_stack(stack_b,1);
// 	ft_printf("------------------------------ \n");

//     execute(&stack_a,&stack_b,"ra", 1);
//     ft_printf("Stack a : \n");
// 	print_stack(stack_a,1);
// 	ft_printf("Stack b : \n");
//     print_stack(stack_b,1);
// 	ft_printf("------------------------------ \n");

//     execute(&stack_a,&stack_b,"pa", 1);
//     ft_printf("Stack a : \n");
// 	print_stack(stack_a,1);
// 	ft_printf("Stack b : \n");
//     print_stack(stack_b,1);
// 	ft_printf("------------------------------ \n");

//     execute(&stack_a,&stack_b,"pa", 1);   
//     ft_printf("Stack a : \n");
// 	print_stack(stack_a,1);
// 	ft_printf("Stack b : \n");
//     print_stack(stack_b,1);
// 	ft_printf("------------------------------ \n");

// ////////////////////////////////////////////////////////////////////

//     execute(&stack_a,&stack_b,"pb", 1);   
//     ft_printf("Stack a : \n");
// 	print_stack(stack_a,1);
// 	ft_printf("Stack b : \n");
//     print_stack(stack_b,1);
// 	ft_printf("------------------------------ \n");

//     execute(&stack_a,&stack_b,"pb", 1);   
//     ft_printf("Stack a : \n");
// 	print_stack(stack_a,1);
// 	ft_printf("Stack b : \n");
//     print_stack(stack_b,1);
// 	ft_printf("------------------------------ \n");


//     execute(&stack_a,&stack_b,"pb", 1);   
//     ft_printf("Stack a : \n");
// 	print_stack(stack_a,1);
// 	ft_printf("Stack b : \n");
//     print_stack(stack_b,1);
// 	ft_printf("------------------------------ \n");




//     execute(&stack_a,&stack_b,"ss", 1);   
//     ft_printf("Stack a : \n");
// 	print_stack(stack_a,1);
// 	ft_printf("Stack b : \n");
//     print_stack(stack_b,1);
// 	ft_printf("------------------------------ \n");


// 	execute(&stack_a,&stack_b,"rra", 1);   
//     ft_printf("Stack a : \n");
// 	print_stack(stack_a,1);
// 	ft_printf("Stack b : \n");
//     print_stack(stack_b,1);
// 	ft_printf("------------------------------ \n");


//     execute(&stack_a,&stack_b,"ss", 1);   
//     ft_printf("Stack a : \n");
// 	print_stack(stack_a,1);
// 	ft_printf("Stack b : \n");
//     print_stack(stack_b,1);
// 	ft_printf("------------------------------ \n");


// 	execute(&stack_a,&stack_b,"rrr", 1);   
//     ft_printf("Stack a : \n");
// 	print_stack(stack_a,1);
// 	ft_printf("Stack b : \n");
//     print_stack(stack_b,1);
// 	ft_printf("------------------------------ \n");




// 	execute(&stack_a,&stack_b,"rrb", 1);   
//     ft_printf("Stack a : \n");
// 	print_stack(stack_a,1);
// 	ft_printf("Stack b : \n");
//     print_stack(stack_b,1);
// 	ft_printf("------------------------------ \n");




//     ft_printf("After Sort : \n");
//     ft_printf("Stack a : \n");
// 	print_stack(stack_a,1);
// 	ft_printf("Stack b : \n");	
// 	print_stack(stack_b,1);

	// if (check_result(stack_a))
	// 	ft_putstr_fd("Not in order!",2);
	// else
	// 	ft_printf("Sorted succesfully!");
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