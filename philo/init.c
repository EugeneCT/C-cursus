/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 14:57:05 by cliew             #+#    #+#             */
/*   Updated: 2024/04/14 07:50:57 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_program(t_program *program, t_data *data, int numb_philo)
{
	program->life = 1;
	program->data = data;
	program->numb_philo = numb_philo;
	pthread_mutex_init(&program->eat_lock, NULL);
	pthread_mutex_init(&program->write_lock, NULL);
	pthread_mutex_init(&program->dead_lock, NULL);
}

void	init_mutex(pthread_mutex_t *fork, int numb_philo)
{
	int	i;

	i = 0;
	while (i < numb_philo)
	{
		if (pthread_mutex_init(&fork[i], NULL) != 0)
		{
			printf("Error initializting mutex!");
			return ;
		}
		i++;
	}
}

void	init_philo(t_data *data, t_program *program, pthread_mutex_t *fork)
{
	int	i;

	i = 0;
	while (i < program->numb_philo)
	{
		data[i].philo = i + 1;
		data[i].write_lock = &program->write_lock;
		data[i].dead_lock = &program->dead_lock;
		data[i].eat_lock = &program->eat_lock;
		data[i].life = &program->life;
		data[i].fork_1 = &fork[i];
		if ((i) == 0)
		{
			data[i].fork_0 = &fork[program->numb_philo - 1];
			data[i].fork_1 = &fork[0];
		}
		else
		{
			data[i].fork_0 = &fork[i - 1];
			data[i].fork_1 = &fork[i];
		}
		i++;
	}
}

void	init_input(t_data *data, char **argv)
{
	int				i;
	struct timeval	start_time;

	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		data[i].time_to_die = ft_atoi(argv[2]);
		data[i].time_to_eat = ft_atoi(argv[3]);
		data[i].time_to_sleep = ft_atoi(argv[4]);
		if (argv[5])
			data[i].meals_to_eat = ft_atoi(argv[5]);
		else
			data[i].meals_to_eat = -1;
		data[i].time_last_eat = 0;
		data[i].eating = 0;
		data[i].meals_ate = 0;
		data[i].dieing_time = -1;
		data[i].solo_philo = 0;
		if (ft_atoi(argv[1]) == 1)
			data[i].solo_philo = 1;
		gettimeofday(&start_time, NULL);
		data[i].start_time = start_time;
		i++;
	}
}

void	destory_all(char *str, t_program *program, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	if (str)
	{
		write(2, str, ft_strlen(str));
		write(2, "\n", 1);
	}
	pthread_mutex_destroy(&program->eat_lock);
	pthread_mutex_destroy(&program->write_lock);
	pthread_mutex_destroy(&program->dead_lock);
	while (i < program->numb_philo)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
}
