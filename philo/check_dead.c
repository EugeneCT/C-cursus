/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dead.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:58:08 by cliew             #+#    #+#             */
/*   Updated: 2024/03/08 15:59:35 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
int	dead_loop(t_data *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->life == 0)
		return (pthread_mutex_unlock(philo->dead_lock), 1);
	pthread_mutex_unlock(philo->dead_lock);
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
