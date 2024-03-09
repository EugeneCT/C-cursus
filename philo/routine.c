/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:51:55 by cliew             #+#    #+#             */
/*   Updated: 2024/03/09 08:52:58 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	pthread_mutex_unlock(data->fork_1);
	pthread_mutex_unlock(data->fork_0);
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
