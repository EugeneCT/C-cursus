/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 14:54:22 by cliew             #+#    #+#             */
/*   Updated: 2024/03/08 15:55:09 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(long int microseconds)
{
	struct timeval	start_time;
	struct timeval	current_time;

	gettimeofday(&start_time, NULL);
	gettimeofday(&current_time, NULL);
	while (((((current_time.tv_sec - start_time.tv_sec) * 1000000)
				+ (current_time.tv_usec - start_time.tv_usec))) <= microseconds-60)
	{
		usleep(10);
		gettimeofday(&current_time, NULL);
	}
}
long	ms(struct timeval start_time)
{
	struct timeval	end_time;
	long			elapsed_seconds;
	long			elapsed_microseconds;
	long			elapsed_total_milliseconds;

	gettimeofday(&end_time, NULL);
	elapsed_total_milliseconds = ((end_time.tv_sec - start_time.tv_sec)*1000000) + ((end_time.tv_usec - start_time.tv_usec)/1000);
	elapsed_seconds = end_time.tv_sec - start_time.tv_sec;
	elapsed_microseconds = end_time.tv_usec - start_time.tv_usec;
	elapsed_total_milliseconds = (elapsed_seconds * 1000000
			+ elapsed_microseconds) / 1000;
	return (elapsed_total_milliseconds);
}

void	print_message(char *str, t_data *data, int id)
{
	pthread_mutex_lock(data->write_lock);
	if (!dead_loop(data))
		printf("MS %zu Philo %d %s\n", ms(data->start_time), id, str);
	pthread_mutex_unlock(data->write_lock);
}
void	lock_both_mutexes(pthread_mutex_t *mutex1, pthread_mutex_t *mutex2,
		t_data *data)
{
	int lock_1;
	int lock_2;
	
	while (1)
	{
		lock_1=pthread_mutex_lock(mutex1);
		if (lock_1 == 0)
		{
			print_message("has taken a fork", data, data->philo);

			lock_2=pthread_mutex_lock(mutex2);
			if (lock_2 == 0)
			{
				print_message("has taken a fork", data, data->philo);
				return ;
			}
			else
			{
				print_message("has FAIL TO TAKE FORK", data, data->philo);
				pthread_mutex_unlock(mutex1);
			}
		}
	}
}