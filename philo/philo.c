/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 22:39:55 by cliew             #+#    #+#             */
/*   Updated: 2024/03/08 16:22:37 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *pointer)
{
	t_data	*philo;

	philo = (t_data *)pointer;
	if (philo->philo % 2 == 0)
		ft_usleep(100);
	while (!dead_loop(philo))
	{
		eat(philo);
		sleeep(philo);
		think(philo);
	}
	return (pointer);
}

int	create_thread(t_program *program, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < program->numb_philo)
	{
		if (pthread_create(&program->data[i].thread, NULL, &routine,
				&program->data[i]) != 0)
			destory_all("Failed to create thread!", program, forks);
		i++;
	}
	return (0);
}

int	join_thread(t_program *program, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < program->numb_philo)
	{
		if (pthread_join(program->data[i].thread, NULL) != 0)
			destory_all("Fail to join thread!", program, forks);
		i++;
	}
	return (0);
}

void	*monitor(void *pointer, int numb_philo)
{
	t_data	*data;

	data = (t_data *)pointer;
	while (1)
	{
		if (check_if_dead(data, numb_philo) == 1 || check_if_all_ate(data,
				numb_philo) == 1)
			break ;
		ft_usleep(1);
	}
	return (pointer);
}

int	main(int argc, char **argv)
{
	pthread_mutex_t	*fork;
	t_data			*data;
	t_program		program;

	if (argc != 5 && argc != 6)
		return (ft_puterr(2 , "Please enter between argument numbers of 4 or 5",
				1));
	if (check_valid_args(argv) == 1)
		return (1);
	data = (t_data *)malloc(ft_atoi(argv[1]) * sizeof(t_data));
	fork = (pthread_mutex_t *)malloc(ft_atoi(argv[1])
			* sizeof(pthread_mutex_t));
	init_program(&program, data, ft_atoi(argv[1]));
	init_mutex(fork, ft_atoi(argv[1]));
	init_philo(data, &program, fork);
	init_input(data, argv);
	create_thread(&program, fork);
	monitor(program.data, ft_atoi(argv[1]));
	join_thread(&program, fork);
	free(data);
	free(fork);
}
