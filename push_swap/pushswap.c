/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew < cliew@student.42singapore.sg>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 19:21:44 by cliew             #+#    #+#             */
/*   Updated: 2024/02/19 16:32:40 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_freearray(char **s1, int free_pt, int run)
{
	int	i;

	i = 0;
	if (run)
	{
		while ((s1[i]) != NULL && *s1)
		{
			free(s1[i]);
			i++;
		}
		if (free_pt)
			free(s1);
	}
	return (i);
}

int	check_input(int argc, char **argv)
{
	int		i;
	long	argv_i;
	int		j;

	i = 1;
	if (argc == 1)
		return (ft_puterr("", 1));
	while (i < argc)
	{
		argv_i = ft_atoll(argv[i]);
		if (argv_i > INT_MAX || argv_i < INT_MIN || argv[i][0] == '\0'
			|| !ft_isinteger(argv[i]))
			return (ft_puterr("Error\n", 1));
		j = i + 1;
		while (j < argc)
		{
			if (ft_strcmp(argv[i], argv[j]) == 0)
				return (ft_puterr("Error\n", 1));
			j++;
		}
		i++;
	}
	return (0);
}

int	init(t_node **stack_a, t_node **stack_b, int argc, char **argv)
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
	if (check_result(*stack_a) == 0)
	{
		clear_stack(*stack_a, *stack_b);
		return (1);
	}
	return (0);
}

int	check_quote(int *argc, char ***argv)
{
	int		array_len;
	char	**quote_array;
	int		i;

	i = 0;
	quote_array = NULL;
	array_len = 0;
	if (*argc == 2 && (*argv)[1][0] != '\0')
	{
		if (!ft_isinteger((*argv)[1]))
		{
			quote_array = ft_split((*argv)[1], ' ');
			while (quote_array != NULL && (quote_array)[array_len] != NULL)
				array_len++;
			*argc = array_len + 1;
			while (++i < *argc)
				(*argv)[i] = ft_strdup(quote_array[i - 1]);
			(*argv)[i] = NULL;
			ft_freearray(quote_array, 1, 1);
			return (1);
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		count;
	int		best_chunk;
	t_node	*s_a;
	t_node	*s_b;
	int		k;

	count = 0;
	k = check_quote(&argc, &argv);
	if (check_input(argc, argv) == 1 || init(&s_a, &s_b, argc, argv) == 1)
		return (1);
	ft_freearray(argv + 1, 0, k);
	if (argc == 4)
		sort_three(&s_a);
	else if (argc <= 11)
		sort_ten(&s_a, &s_b);
	else
	{
		best_chunk = find_best_chunk(s_a, argc);
		count = chunk_sort(best_chunk, &s_a, &s_b, argc);
		k = argc;
		while (--k > 0)
			count += push_to_stack_ba(&s_b, &s_a, k, 1);
		count = count + move_rank_top(&s_a, 1, 1);
	}
	clear_stack(s_a, s_b);
}
