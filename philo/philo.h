/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 22:35:07 by cliew             #+#    #+#             */
/*   Updated: 2024/03/07 16:02:45 by cliew            ###   ########.fr       */
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

#define MAX_PHILO 250
typedef struct s_data
{
	pthread_mutex_t		*fork_0;
	pthread_mutex_t		*fork_1;
	pthread_mutex_t *dead_lock;
	pthread_mutex_t *write_lock;
	pthread_mutex_t *eat_lock;
	pthread_t		thread;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int meals_to_eat;
	int philo;
	int solo_philo;

	
	struct timeval start_time;
	int time_last_eat;
	int eating;
	int meals_ate ;
	int dieing_time;
	int *life;

}			t_data;

typedef struct s_program
{

	pthread_mutex_t dead_lock;
	pthread_mutex_t write_lock;
	pthread_mutex_t eat_lock;
	int numb_philo;

	int life;
	t_data* data;
} t_program;


void	ft_putstr_fd(char const *s, int fd);
int	ft_puterr(char const *s, int ret);
int	ft_atoi(const char *str);
void ft_usleep( long int microseconds);
void	destory_all(char *str, t_program *program, pthread_mutex_t *forks);
int	ft_strlen(char *str);
#endif