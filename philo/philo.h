/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 22:35:07 by cliew             #+#    #+#             */
/*   Updated: 2024/03/03 15:43:23 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>

# include <unistd.h>
# include <stdio.h>
#include <string.h>  // memset
#include <sys/time.h>
#include <time.h>

typedef struct s_params
{
	pthread_mutex_t		**fork;
	pthread_mutex_t		*fork_0;
	pthread_mutex_t		*fork_1;


	int numb_philo;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int meals_to_eat;
	int philo;
	
	struct timeval start_time;
	int time_last_eat;
	int awake;
	int meals_ate ;
	int life;

}			t_data;



void ft_usleep( long int microseconds);
#endif