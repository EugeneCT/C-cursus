/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 22:35:07 by cliew             #+#    #+#             */
/*   Updated: 2024/03/09 09:08:04 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h> // memset
# include <sys/time.h>
# include <time.h>
# include <unistd.h>

# define MAX_PHILO 250

typedef struct s_data
{
	pthread_mutex_t	*fork_0;
	pthread_mutex_t	*fork_1;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*eat_lock;
	pthread_t		thread;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	int				meals_to_eat;
	int				philo;
	int				solo_philo;

	struct timeval	start_time;
	size_t			time_last_eat;
	int				eating;
	int				meals_ate;
	size_t			dieing_time;
	int				*life;

}					t_data;

typedef struct s_program
{
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	eat_lock;
	int				numb_philo;

	int				life;
	t_data			*data;
}					t_program;

// utilities.c
void				ft_usleep(size_t microseconds);
size_t				ms(struct timeval start_time);
void				print_message(char *str, t_data *data, int id);
void				lock_both_mutexes(pthread_mutex_t *mutex1,
						pthread_mutex_t *mutex2, t_data *data);
// Argument.c
int					ft_puterr(int fd, char const *s, int ret);
int					ft_atoi(const char *str);
int					ft_strlen(char *str);
int					check_arg_content(char *arg);
int					check_valid_args(char **argv);
// init.c
void				init_program(t_program *program, t_data *data,
						int numb_philo);
void				init_mutex(pthread_mutex_t *fork, int numb_philo);
void				init_philo(t_data *data, t_program *program,
						pthread_mutex_t *fork);
void				init_input(t_data *data, char **argv);
void				destory_all(char *str, t_program *program,
						pthread_mutex_t *forks);
// routine.c
void				sleeep(t_data *data);
void				think(t_data *data);
void				eat(t_data *data);
// check_dead.c
int					philosopher_dead(t_data *data, size_t time_to_die);
int					dead_loop(t_data *philo);
int					check_if_all_ate(t_data *data, int numb_philo);
int					check_if_dead(t_data *data, int numb_philo);
// main
int					join_thread(t_program *program, pthread_mutex_t *forks);
int					create_thread(t_program *program, pthread_mutex_t *forks);
void				*monitor(void *pointer, int numb_philo);
void				*routine(void *pointer);
#endif