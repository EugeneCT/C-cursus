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

int	print_stack(t_node *stack,int print,char *type)
{
	int len;
	
	len=0;
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


int find_min_max(t_node *stack,char* stat){
	
	int temp_val;
	int len;
	int sum;
	
	sum = 0;
	len=print_stack(stack,0,"val");
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

t_node* find_node_by(t_node *stack,char*type, int val)
{
	stack=find_end_node(stack,0);
	if (!stack)
		return NULL;
	while (stack->next)
	{
		if (stack->val == val && ft_strcmp(type, "val") == 0 )
			return stack;

		else if (stack->rank == val && ft_strcmp(type, "rank") == 0 )
			return stack;
		stack=stack->next;
	}
	if (stack->val == val && ft_strcmp(type, "val") == 0 )
		return stack;

	else if (stack->rank == val && ft_strcmp(type, "rank") == 0 )
			return stack;
	return NULL;

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
t_node* find_next_min(t_node *stack,int min)
{
	int temp;

	stack=find_end_node(stack,0);
	while (stack->next && stack -> val <= min)
		stack=stack->next;
	temp=stack->val;
	while (stack->next)
	{
		stack=stack->next;
		if (stack->val <temp && stack->val > min)
			temp=stack->val;
	}
	stack=find_end_node(stack,0);
	if (stack->val ==temp)
		return stack;
	while (stack->next)
	{
		stack=stack->next;
		if (stack->val==temp)
			return stack;
	}
	return stack;
}


int rank_list(t_node **stack,int min,int rank,int argc)
{
	// t_node *head;
	t_node *next_min_node;
	// int sec_min;

	if (rank < argc)
	{
		next_min_node=find_node_by(*stack,"val",min);
		if (next_min_node)
			(*stack)=next_min_node;
		else
			*stack=find_end_node(*stack,1);
		(*stack)->rank=rank;
		rank_list(stack,find_next_min(*stack,min)->val,++rank,argc);
		}
		
	

	return 1;

}


int cost_to_end(t_node* stack,int last_node)
{
	int count;

	count=0;
	if (!stack)
		return 0;
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


// void push_to_stack_ab(t_node** stack,t_node** to_stack,int rank)
// {
// 	int cost_to_top;
// 	int cost_to_btm;
// 	// int move;
// 	// int stack_top_rank;

// 	// move=0;
// 	*stack=find_node_by(*stack,"rank",rank);
// 	if (!(*stack) ||((*stack)->rank != rank ) )

// 		return ;
// 	if (*stack==find_end_node(*stack,0))
// 	{
// 		execute(stack,to_stack,"pb",1);
// 		return ;
// 	}
// 	/* First 1 is to handle if rank is not in stack, so find node by will not return the correct rank*/

// 	cost_to_top=cost_to_end(*stack,0);
// 	cost_to_btm=cost_to_end(*stack,1);

// 	while(find_end_node(*stack,0)->rank!=rank){
// 		while (find_end_node(*stack,0)->rank > rank){
// 				execute(stack,to_stack,"pb",1);
// 				cost_to_top=cost_to_top-1;
// 		}

// 		if (cost_to_btm+1>cost_to_top){	
// 		// while (move <cost_to_top)
// 			execute(stack,to_stack,"ra",1);
	
		
// 		// multi_execute(stack,to_stack,"ra", cost_to_top);
// 		}	
// 		else if (cost_to_top>=cost_to_btm)
// 		{

// 				execute(stack,to_stack,"rra",1);
// 		}
// 		// multi_execute(stack,to_stack,"rra", cost_to_btm+1);
// 	}
// 	execute(stack,to_stack,"pb",1);
// }

int check_swap(t_node** stack, char* seq,char* s_type,int print)
{
	t_node *stack_top;
	t_node *stack_sec;

	stack_top=find_end_node(*stack,0);
	if (!stack_top)
		return 0;
	if (stack_top->next)
		stack_sec=stack_top->next;
	else
		return 0;
	
	if (ft_strcmp(seq, "asc") == 0)
	{
		if (stack_sec->rank<stack_top->rank)
		{
			execute(stack,stack,s_type,print);
			return 1;
		}

	}
	else if (ft_strcmp(seq, "dsc") == 0)
	{
		if (stack_sec->rank>stack_top->rank)
		{
			execute(stack,stack,s_type,print);
			return 1;

		}
	}
	return 0;
	
}

int move_rank_top(t_node**  stack,int rank,int print)
{

	int cost_to_top;
	int cost_to_btm;
	int count;
	count = 0;
	*stack=find_node_by(*stack,"rank",rank);
	if (!(*stack) ||((*stack)->rank != rank ) ||(*stack==find_end_node(*stack,0) ))

		return 0 ;

	cost_to_top=cost_to_end(*stack,0);
	cost_to_btm=cost_to_end(*stack,1);

	while(find_end_node(*stack,0)->rank!=rank){
	if (cost_to_btm+1>cost_to_top){	
			execute(stack,stack,"ra",print);
			count++;
		}	
		else if (cost_to_top>=cost_to_btm)
		{
			execute(stack,stack,"rra",print);
			count++;
		}

	}
	return count;

}
void push_to_stack_ab_v2(t_node** stack,t_node** to_stack,int rank)
{
	move_rank_top(stack,rank);
	execute(stack,to_stack,"pb",1);


}

// void push_to_stack_ab_v2(t_node** stack,t_node** to_stack,int rank)
// {
// 	int cost_to_top;
// 	int cost_to_btm;
// 	int swap_a=0;
// 	int swap_b=0;
// 	// int move;
// 	// int stack_top_rank;

// 	// move=0;
// 	*stack=find_node_by(*stack,"rank",rank);
// 	if (!(*stack) ||((*stack)->rank != rank ) )

// 		return ;
// 	if (*stack==find_end_node(*stack,0))
// 	{
// 		execute(stack,to_stack,"pb",1);
// 		return ;
// 	}
// 	/* First 1 is to handle if rank is not in stack, so find node by will not return the correct rank*/

// 	cost_to_top=cost_to_end(*stack,0);
// 	cost_to_btm=cost_to_end(*stack,1);

// 	while(find_end_node(*stack,0)->rank!=rank){
// 		while (find_end_node(*stack,0)->rank > rank){
// 				execute(stack,to_stack,"pb",1);
// 			if (find_end_node(*stack,0)->rank < rank)
// 			{
// 				swap_a=check_swap(stack,"asc","sa",0);
// 			}

// 			swap_b= check_swap(to_stack,"dsc","sb",0);
// 			if (swap_a && swap_b)
// 				ft_printf("ss\n");
// 			else if (swap_a)
// 				ft_printf("sa\n");
// 			else if (swap_b)
// 				ft_printf("sb\n");





// 			cost_to_top=cost_to_top-1;
// 			swap_a=0;
// 			swap_b=0;
// 		}

// 		if (cost_to_btm+1>cost_to_top){	
// 		// while (move <cost_to_top)
// 			execute(stack,to_stack,"ra",1);
		
// 		// multi_execute(stack,to_stack,"ra", cost_to_top);
// 		}	
// 		else if (cost_to_top>=cost_to_btm)
// 		{

// 			execute(stack,to_stack,"rra",1);


// 		}
// 		// multi_execute(stack,to_stack,"rra", cost_to_btm+1);
// 	}
// 	execute(stack,to_stack,"pb",1);
// 				if (find_end_node(*stack,0)->rank < rank)
// 			{
// 				swap_a=check_swap(stack,"asc","sa",0);
// 			}

// 			swap_b= check_swap(to_stack,"dsc","sb",0);
// 			if (swap_a && swap_b)
// 				ft_printf("ss\n");
// 			else if (swap_a)
// 				ft_printf("sa\n");
// 			else if (swap_b)
// 				ft_printf("sb\n");


// }

int push_to_stack_ba(t_node** stack,t_node** to_stack,int rank,int print)
{
	int cost_to_top;
	int cost_to_btm;
	int count;
	*stack=find_node_by(*stack,"rank",rank);

	if (!stack)
		return 0;
	cost_to_top=cost_to_end(*stack,0);
	cost_to_btm=cost_to_end(*stack,1);

	/**Swap multi execute to while loop, then put in print*/
	if (cost_to_btm+1>cost_to_top)
	{
		multi_execute(to_stack,stack,"rb", cost_to_top);
		count=cost_to_top;
	}
	else if (cost_to_top>=cost_to_btm)
	{
		multi_execute(to_stack,stack,"rrb", cost_to_btm+1);
		count=cost_to_btm+1;
	}
	execute(to_stack,stack,"pa",1);
	return count+1;

}

// t_node* arrange_stack_ab(t_node* stack,t_node* to_stack,int max_rank)
// {
// 	t_node* stack_top;
// 	int next_rank;
// 	int cost_to_btm;
// 	int cost_to_top;
// 	int move;

// 	move= 0;
	
// 	stack_top=find_end_node(stack,0);
// 	next_rank=stack_top->rank+1;

// 	if (next_rank>=max_rank)
// 	{
// 		execute(&stack,&to_stack,"ra",1);
// 		return stack;
// 	}
// 	stack=find_node_by(stack,"rank",next_rank);
// 	while (stack_top->next == stack)
// 	{
// 		execute(&stack,&to_stack,"ra",1);
	
// 		stack_top=find_end_node(stack,0);
// 		next_rank=stack_top->rank+1;
// 		if (next_rank>=max_rank)
// 		{
// 			execute(&stack,&to_stack,"ra",1);
// 			return stack;
// 		}
// 		stack=find_node_by(stack,"rank",next_rank);

// 	}
// 	cost_to_top=cost_to_end(stack,0)+1;
// 	cost_to_btm=cost_to_end(stack,1)+2;
// 	execute(&stack,&to_stack,"pb",1);
// 	if (cost_to_btm>cost_to_top)
// 	{	
// 		while (move++ < cost_to_top-2)
// 			execute(&stack,&to_stack,"ra",1);
// 	}

//     else if (cost_to_top>cost_to_btm)
// 	{	
// 		while (move++ < cost_to_btm-1)
// 			execute(&stack,&to_stack,"rra",1);
		
// 	}
// 		execute(&stack,&to_stack,"pa",1);
// 		execute(&stack,&to_stack,"ra",1);

// 	return stack;
// }

// t_node* arrange_stack_ab_v2(t_node* stack,t_node* to_stack,int max_rank)
// {
// 	t_node* stack_top;
// 	int next_rank;
// 	int cost_to_btm;
// 	int cost_to_top;
// 	// int rank;

	
// 	stack_top=find_end_node(stack,0);
// 	next_rank=stack_top->rank+1;

// 	if (next_rank>=max_rank)
// 		next_rank=1;
// 	stack=find_node_by(stack,"rank",next_rank);

// 	/*Handle if already sorted*/
// 	while (stack_top->next == stack && stack_top->rank !=1 && check_result(stack)!=0)
// 	{
// 		execute(&stack,&to_stack,"ra",1);
	
// 		stack_top=find_end_node(stack,0);
// 		// rank=stack_top->rank;
// 		next_rank=stack_top->rank+1;
// 		if (next_rank>=max_rank)
// 		{
// 				next_rank=1;
// 		}
// 		stack=find_node_by(stack,"rank",next_rank);
// 	}

// 	if (check_result(stack)==0)
// 		return stack;
// 	cost_to_top=cost_to_end(stack,0);
// 	cost_to_btm=cost_to_end(stack,1);

// 	while(find_end_node(stack,0)->rank!=next_rank){
	
// 		if (cost_to_btm+1>cost_to_top)
// 			execute(&stack,&to_stack,"ra",1);
	
// 		else if (cost_to_top>=cost_to_btm)
// 			execute(&stack,&to_stack,"rra",1);
// 	}
// 	execute(&stack,&to_stack,"pb",1);

// 	cost_to_top=cost_to_end(stack_top,0);
// 	cost_to_btm=cost_to_end(stack_top,1);

// 	while(find_end_node(stack,1)->rank!=stack_top->rank){
	
// 		if (cost_to_btm+1>cost_to_top)
// 			execute(&stack,&to_stack,"ra",1);
	
// 		else if (cost_to_top>=cost_to_btm)
// 			execute(&stack,&to_stack,"rra",1);
// 	}
// 	execute(&stack,&to_stack,"pa",1);

// 	return stack;
// }


// int push_to_top(t_node* stack,t_node* to_stack,int rank)
// {
// 	// t_node* stack_top;
// 	int cost_to_btm;
// 	int cost_to_top;
// 	int move;

// 	move= 0;
// 	// stack_top=find_end_node(stack,0);
// 	stack=find_node_by(stack,"rank",rank);
// 	cost_to_top=cost_to_end(stack,0);
// 	cost_to_btm=cost_to_end(stack,1);
// 	// execute(&stack,&to_stack,"pb",1);
// 	if (cost_to_btm>cost_to_top)
// 	{	
// 		while (move++ < cost_to_top-1)
// 			execute(&stack,&to_stack,"ra",1);

// 	}

//     else if (cost_to_top>cost_to_btm)
// 	{	
	
// 		while (move++ < cost_to_btm+1)
// 			execute(&stack,&to_stack,"rra",1);
		
// 	}
// 		// execute(&stack,&to_stack,"pa",1);
// 		// execute(&stack,&to_stack,"ra",1);

// 	return stack;
// }




// t_node* arrange_stack_ba(t_node* stack,t_node* to_stack,int max_rank)
// {
// 	t_node* stack_top;
// 	int next_rank;
// 	int cost_to_btm;
// 	int cost_to_top;
// 	int move;

// 	move= 0;
// 	stack_top=find_end_node(stack,0);
// 	next_rank=stack_top->rank+1;
// 	if (next_rank>max_rank)
// 		execute(stack,to_stack,"ra",1);
// 	stack=find_node_by(stack,"rank",next_rank);
// 	cost_to_top=cost_to_end(stack,0)+2;
// 	cost_to_btm=cost_to_end(stack,1)+3;
// 	execute(stack,to_stack,"pb",1);
// 	if (cost_to_btm>cost_to_top)
// 	{	
// 		while (move < cost_to_top-1)
// 			execute(stack,to_stack,"ra",1);
// 	}

//     else if (cost_to_top>cost_to_btm)
// 	{	
// 		while (move < cost_to_top-1)
// 			execute(stack,to_stack,"ra",1);
		
// 	}
// 		execute(stack,to_stack,"pa",1);
// 	return stack;
// }



int	main(int argc, char **argv)
{
	int i;
	int count;
	t_node *stack_a;
	t_node *stack_b;
	count=0;
	i = 1;
	stack_a = NULL;
	stack_b = NULL;


	/* Convert ARGC to linked list*/
	while (i < argc)
	{
		stack_a = add_node(stack_a, ft_atoi(argv[i]));
		i++;
	}
	// int len=print_stack(stack_a,0,"val");
	// printf("len is %d",len);
	int min = find_min_max(stack_a,"min");
	// ft_printf("\n min is %d \n",min);
	// ft_printf("\n max is %d \n",max);

	/* Rank list */
	rank_list(&stack_a,min,1,argc);
	
	/*Chunk*/
	int MAX_CHUNK;
	int chunk_1=5;
	int chunk_2=15;
	if ((argc-1) <=250)
	{
		while (chunk_1>=2)
		{
			if ((argc -1) % chunk_1 ==0)
			{
				MAX_CHUNK = chunk_1;
				break;
			}
			chunk_1--;
		}

	}

	if ((argc-1) >250)
	{
		while (chunk_2>=10)
		{
			if ((argc -1) % chunk_2 ==0)
			{
				MAX_CHUNK = chunk_2;
				break;
			}
			chunk_2--;
		}

	}
	// MAX_CHUNK=5;

	int CHUNK=1;
	int max_repeat = argc/MAX_CHUNK;
	int repeat=0;
	int min_cost=argc+100;

	while(CHUNK <= MAX_CHUNK)
	{
		// int j = 0+ ((CHUNK-1) * argc/MAX_CHUNK);
		while (repeat<=max_repeat){
			int j = 1+ ((CHUNK-1) * argc/MAX_CHUNK);
			min_cost=argc+100;

			while (j <=(CHUNK)*(argc/MAX_CHUNK))
			{	
				t_node *node= find_node_by(stack_a,"rank",j);
				if (!node)
				{
					j++;
					continue ;
				}
				int cost_to_top= cost_to_end(node,0);
				int cost_to_btm= cost_to_end(node,1) +1;
				if (cost_to_top<min_cost)
					min_cost=cost_to_top;
				if (cost_to_btm<min_cost)
					min_cost=cost_to_btm;
				j++;
			}
			j = 1+ ((CHUNK-1) * argc/MAX_CHUNK);
			while (j <=CHUNK* (argc/MAX_CHUNK))
			{	
				t_node *node= find_node_by(stack_a,"rank",j);
				if (!node)
				{
					j++;
					continue;
				}
				int cost_to_top= cost_to_end(node,0);
				int cost_to_btm= cost_to_end(node,1) +1;
				if (cost_to_top == min_cost || cost_to_btm == min_cost)
				{
					count=count+move_rank_top(&node,j,1);
					printf("%d \n",count);

					execute(&stack_a,&stack_b,"pb",1);
					count++;
					printf("%d \n",count);

					break;

				}
				j++;
			}
		repeat++;
		}
		repeat=0;
		min_cost=argc+100;
		CHUNK++;

	}
	int k=argc-1;
	printf("%d \n",count);
	while (k>0){
		count=count+push_to_stack_ba(&stack_b,&stack_a,k,1);
		k--;
	}
	// int j ;
	// int k ;
	// int a_max;
	// int k_max;
	// if (argc % 2 ==1)
	// {
	// 	j =(argc/2)+1;
	// 	k_max=argc/2;


	// }
	// else{
	// 	j =(argc/2);
	// 	k_max=(argc/2)-1;

	// }
	// k =argc-1;
	// a_max=j;
	// while (j<(argc)){
		
	// 	push_to_stack_ab_v2(&stack_a,&stack_b,j);

	// 	j++;
	// }

	// /*Arrange Stack A*/
	// while (check_result(stack_a)!=0)
	// 	stack_a=arrange_stack_ab_v2(stack_a,stack_b,a_max);

	// 	// stack_a=arrange_stack_ab(stack_a,stack_b,a_max);
	// /*Arrange Stack B*/

	// while (k>(k_max)){
	// 	push_to_stack_ba(&stack_b,&stack_a,k);
	// 	k--;
	// }



	// /*Prepare Stack A for Stack B*/

	// stack_a=push_to_top(&stack_a,&stack_b,1);


	count=count+move_rank_top(&stack_a,1);
	if (check_result(stack_a)==0)
	{
	ft_printf("%d",count);

	}
	// ft_puterr(ft_itoa(count),2);


	// /* End of v1*/















	// if (check_result(stack_a)==0)
	// {
	// 	print_stack(stack_a,1,"rank");
	// 	ft_printf("----------------------- \n");
	// 	ft_printf("Arrange succesfully! \n");


	// }
	// ft_printf("----------------------- \n");
	// ft_printf("Stack a After push : \n");
	// print_stack(stack_a,1,"val");
	// ft_printf("\nStack b After push : \n");
	// print_stack(stack_b,1,"val");

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