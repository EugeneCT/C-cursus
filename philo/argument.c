/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 10:43:27 by cliew             #+#    #+#             */
/*   Updated: 2024/03/09 08:50:32 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_puterr(int fd, char const *s, int ret)
{
	write(fd, s, ft_strlen((char *)s));
	write(fd, "\n", ft_strlen((char *)"\n"));
	return (ret);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	num;

	i = 0;
	num = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		sign = sign * -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	num = num * sign;
	return ((int)num);
}

int	ft_strlen(char *str)
{
	int	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	check_arg_content(char *arg)
{
	int	i;

	i = 0;
	while (arg[i] != '\0')
	{
		if (arg[i] < '0' || arg[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	check_valid_args(char **argv)
{
	if (ft_atoi(argv[1]) > 200 || ft_atoi(argv[1]) <= 0
		|| check_arg_content(argv[1]) == 1)
		return (ft_puterr(2, "Invalid philosophers number", 1));
	if (ft_atoi(argv[2]) <= 0 || check_arg_content(argv[2]) == 1)
		return (ft_puterr(2, "Invalid time to die", 1));
	if (ft_atoi(argv[3]) <= 0 || check_arg_content(argv[3]) == 1)
		return (ft_puterr(2, "Invalid time to eat", 1));
	if (ft_atoi(argv[4]) <= 0 || check_arg_content(argv[4]) == 1)
		return (ft_puterr(2, "Invalid time to sleep", 1));
	if (argv[5] && (ft_atoi(argv[5]) < 0 || check_arg_content(argv[5]) == 1))
		return (ft_puterr(2,
				"Invalid number of times each philosopher must eat", 1));
	return (0);
}
