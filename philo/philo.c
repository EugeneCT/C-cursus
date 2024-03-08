/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 22:39:55 by cliew             #+#    #+#             */
/*   Updated: 2024/03/08 10:42:21 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ms(struct timeval start_time)
{
	struct timeval	end_time;
	long			elapsed_seconds;
	long			elapsed_microseconds;
	long			elapsed_total_milliseconds;

	gettimeofday(&end_time, NULL);
	elapsed_seconds = end_time.tv_sec - start_time.tv_sec;
	elapsed_microseconds = end_time.tv_usec - start_time.tv_usec;
	elapsed_total_milliseconds = (elapsed_seconds * 1000000
			+ elapsed_microseconds) / 1000;
	return (elapsed_total_milliseconds);
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

// Checks if the program input is correct

int	check_valid_args(char **argv)
{
	if (ft_atoi(argv[1]) > 200 || ft_atoi(argv[1]) <= 0
		|| check_arg_content(argv[1]) == 1)
		return ((int)write(2, "Invalid philosophers number\n", 29));
	if (ft_atoi(argv[2]) <= 0 || check_arg_content(argv[2]) == 1)
		return ((int)write(2, "Invalid time to die\n", 21));
	if (ft_atoi(argv[3]) <= 0 || check_arg_content(argv[3]) == 1)
		return ((int)write(2, "Invalid time to eat\n", 21));
	if (ft_atoi(argv[4]) <= 0 || check_arg_content(argv[4]) == 1)
		return ((int)write(2, "Invalid time to sleep\n", 23));
	if (argv[5] && (ft_atoi(argv[5]) < 0 || check_arg_content(argv[5]) == 1))
		return ((int)write(2,
				"Invalid number of times each philosopher must eat\n", 51));
	return (0);
}

int	dead_loop(t_data *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->life == 0)
		return (pthread_mutex_unlock(philo->dead_lock), 1);
	pthread_mutex_unlock(philo->dead_lock);
	return (0);
}

void	print_message(char *str, t_data *data, int id)
{
	pthread_mutex_lock(data->write_lock);
	if (!dead_loop(data))
		printf("MS %zu Philo %d %s\n", ms(data->start_time), id, str);
	pthread_mutex_unlock(data->write_lock);
}

void	think(t_data *data)
{
	pthread_mutex_lock(data->write_lock);
	if (!dead_loop(data))
		printf("MS %zu Philo %d is thinking\n", ms(data->start_time),
			data->philo);
	pthread_mutex_unlock(data->write_lock);
}

void	sleeep(t_data *data)
{
	pthread_mutex_lock(data->write_lock);
	if (!dead_loop(data))
		printf("MS %zu Philo %d is sleeping\n", ms(data->start_time),
			data->philo);
	pthread_mutex_unlock(data->write_lock);
	ft_usleep(data->time_to_sleep * 1000);
}

void	lock_both_mutexes(pthread_mutex_t *mutex1, pthread_mutex_t *mutex2,
		t_data *data)
{
	while (1)
	{
		if (pthread_mutex_lock(mutex1) == 0)
		{
			print_message("has taken a fork", data, data->philo);
			if (pthread_mutex_lock(mutex2) == 0)
			{
				print_message("has taken a fork", data, data->philo);
				return ;
			}
			else
			{
				pthread_mutex_unlock(mutex1);
			}
		}
		ft_usleep(1);
	}
}

void	eat(t_data *data)
{
	if (data->solo_philo == 1)
	{
		pthread_mutex_lock(data->fork_0);
		print_message("has taken a  fork", data, data->philo);
		ft_usleep(data->time_to_die * 1000);
		pthread_mutex_unlock(data->fork_0);
		return ;
	}
	lock_both_mutexes(data->fork_0, data->fork_1, data);
	pthread_mutex_lock(data->eat_lock);
	data->eating = 1;
	data->time_last_eat = ms(data->start_time);
	pthread_mutex_lock(data->write_lock);
	if (!dead_loop(data))
		printf("MS %zu Philo %d is EATing\n", ms(data->start_time),
			data->philo);
	pthread_mutex_unlock(data->write_lock);
	data->meals_ate++;
	data->eating = 0;
	pthread_mutex_unlock(data->eat_lock);
	ft_usleep(data->time_to_eat * 1000);
	pthread_mutex_unlock(data->fork_0);
	pthread_mutex_unlock(data->fork_1);
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
		if (i == 0)
		{
			data[i].fork_0 = &fork[0];
			data[i].fork_1 = &fork[program->numb_philo - 1];
		}
		else
		{
			data[i].fork_0 = &fork[i - 1];
			data[i].fork_1 = &fork[i];
		}
		i++;
	}
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
		printf("fork %d is %lu \n", i, (unsigned long)&fork[i]);
		i++;
	}
}

void	init_program(t_program *program, t_data *data, int numb_philo)
{
	program->life = 1;
	program->data = data;
	program->numb_philo = numb_philo;
	pthread_mutex_init(&program->eat_lock, NULL);
	pthread_mutex_init(&program->write_lock, NULL);
	pthread_mutex_init(&program->dead_lock, NULL);
}

// Thread routine

void	*routine(void *pointer)
{
	t_data	*philo;

	philo = (t_data *)pointer;
	if (philo->philo % 2 == 0)
		ft_usleep(1);
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

int	philosopher_dead(t_data *data, int time_to_die)
{
	pthread_mutex_lock(data->eat_lock);
	if (ms(data->start_time) - data->time_last_eat >= time_to_die
		&& data->eating == 0)
	{
		return (pthread_mutex_unlock(data->eat_lock), 1);
	}
	pthread_mutex_unlock(data->eat_lock);
	return (0);
}

int	check_if_dead(t_data *data, int numb_philo)
{
	int	i;
	int	dead_time;

	dead_time = 0;
	i = 0;
	while (i < numb_philo)
	{
		if (philosopher_dead(&data[i], data[i].time_to_die))
		{
			pthread_mutex_lock((data)[i].eat_lock);
			dead_time = data[i].time_last_eat + (data)[i].time_to_die;
			pthread_mutex_unlock((data)[i].eat_lock);
			pthread_mutex_lock((data)[i].write_lock);
			if (!dead_loop(&data[i]))
				printf("MS %u Philo %d died!\n", dead_time, data[i].philo);
			pthread_mutex_unlock(data->write_lock);
			pthread_mutex_lock(data[0].dead_lock);
			*data->life = 0;
			pthread_mutex_unlock(data[0].dead_lock);
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_if_all_ate(t_data *data, int numb_philo)
{
	int	i;
	int	finished_eating;

	i = 0;
	finished_eating = 0;
	if (data[0].meals_to_eat == -1)
		return (0);
	while (i < numb_philo)
	{
		pthread_mutex_lock(data[i].eat_lock);
		if (data[i].meals_ate >= data[i].meals_to_eat)
			finished_eating++;
		pthread_mutex_unlock(data[i].eat_lock);
		i++;
	}
	if (finished_eating == numb_philo)
	{
		pthread_mutex_lock(data[0].dead_lock);
		*data->life = 0;
		pthread_mutex_unlock(data[0].dead_lock);
		return (1);
	}
	return (0);
}

// Monitor thread routine

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
		return (ft_puterr("Please enter between argument numbers of 4 or 5",
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
