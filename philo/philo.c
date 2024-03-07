/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 22:39:55 by cliew             #+#    #+#             */
/*   Updated: 2024/03/07 17:22:16 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long ms_since_start(struct timeval start_time)
{
	struct timeval  end_time;
	long elapsed_seconds;
	long elapsed_microseconds;
	long elapsed_total_milliseconds;
	
	gettimeofday(&end_time,NULL);

	elapsed_seconds = end_time.tv_sec - start_time.tv_sec;
    elapsed_microseconds = end_time.tv_usec - start_time.tv_usec;
    elapsed_total_milliseconds = (elapsed_seconds * 1000000 + elapsed_microseconds)/1000;
	elapsed_total_milliseconds=(elapsed_total_milliseconds/100)*100;
	return elapsed_total_milliseconds;
}

// void lock_both_mutexes(pthread_mutex_t *mutex1, pthread_mutex_t *mutex2) {
//     while (1) {
//         // Attempt to lock mutex1
//         if (pthread_mutex_lock(mutex1) == 0) {
//             // Mutex1 locked successfully, attempt to lock mutex2
//             if (pthread_mutex_lock(mutex2) == 0) {
//                 // Both mutexes locked successfully, break the loop
//                 return;
//             } else {
//                 // Unable to lock mutex2, release mutex1 and retry
//                 pthread_mutex_unlock(mutex1);
//             }
//         }
//         // Introduce a small delay to avoid busy waiting
//         ft_usleep(1000);
//     }
// }


// // Thread function to lock a mutex
// void* lock_mutex(void* arg) {
//     pthread_mutex_t* mutex = (pthread_mutex_t*)arg;
// 	// printf("Mutex Address in lock all: %p\n", mutex);

//     pthread_mutex_lock(mutex);
//     return NULL;
// }

// void* unlock_mutex(void* arg) {
//     pthread_mutex_t* mutex = (pthread_mutex_t*)arg;
//     pthread_mutex_unlock(mutex);
//     return NULL;
// }

// // Function to lock all mutexes simultaneously
// void lock_all_mutexes(t_data* data, int n) {
//     pthread_t threads[n];
//     int i = 0;

//     // Create threads to lock each mutex
//     while (i < n) {
//         pthread_create(&threads[i], NULL, lock_mutex, &(data[i].dead_lock));
//         i++;
//     }

//     // Wait for all threads to finish
//     i = 0;
//     while (i < n) {
//         pthread_join(threads[i], NULL);
//         i++;
//     }
// }

// void unlock_all_mutexes(t_data* data, int n) {
//     pthread_t threads[n];
//     int i = 0;

//     // Create threads to lock each mutex
//     while (i < n) {
//         pthread_create(&threads[i], NULL, unlock_mutex, &(data[i].dead_lock));
//         i++;
//     }

//     // Wait for all threads to finish
//     i = 0;
//     while (i < n) {
//         pthread_join(threads[i], NULL);
//         i++;
//     }
// }
// // int	dead_loop(t_philo *philo)
// // {
// // 	pthread_mutex_lock(philo->dead_lock);
// // 	if (*philo->dead == 1)
// // 		return (pthread_mutex_unlock(philo->dead_lock), 1);
// // 	pthread_mutex_unlock(philo->dead_lock);
// // 	return (0);
// // }

// void * thread_function(void *arg){
// 	t_data *data = (t_data *)arg;
// 	struct timeval start_time;

// 	pthread_mutex_lock(&data->dead_lock);

// 	gettimeofday(&start_time,NULL);
// 	data->start_time=start_time;
// 	// printf("fork %d have a mutex of  %lu and %lu \n",data->philo,(unsigned long)data->fork_0,(unsigned long)data->fork_1);

// 	printf("MS %ld thread %d initiated! \n",ms_since_start(data->start_time),data->philo);
// 	if (data->philo+1 % 2 == 0)
// 		ft_usleep(0.1);


// 	// while ( (ms_since_start(data->start_time)<(data->time_last_eat + data->time_to_die)) && data->life!=0 )
// 	pthread_mutex_unlock(&data->dead_lock);
// 	// printf("Mutex Address of pphilo %d is: %p\n", data->philo,(void*)&data->dead_lock);


// 	while ( 1)
// 	{	printf("MS %ld thread %d life = %d before lock! \n",ms_since_start(data->start_time),data->philo,data->life);

// 		pthread_mutex_lock(&data->dead_lock);
// 		if (data->life==0)
// 		{
// 			pthread_mutex_unlock(&data->dead_lock);
// 			break;
// 		}
// 		else 
// 			pthread_mutex_unlock(&data->dead_lock);

// 		// pthread_mutex_lock(data->dead_lock);

// 		// printf("MS %ld philo %d have life %d!!\n",ms_since_start(data->start_time),
// 		// data->philo,data->life);

// 		pthread_mutex_lock(&data->dead_lock);
// 		if (data->life!=0)
// 		{
// 			lock_both_mutexes(data->fork_0,data->fork_1);

// 			printf("MS %ld fork %lu and %lu is taken for by philo %d!!\n",ms_since_start(data->start_time),(unsigned long)data->fork_0,(unsigned long)data->fork_1,data->philo);
// 			printf("MS %ld philo %d starts to eat!!\n",ms_since_start(data->start_time),data->philo);
// 			data->time_last_eat=ms_since_start(data->start_time);
// 			data->dieing_time=data->time_last_eat+data->time_to_die;
// 		}
// 		// pthread_mutex_unlock(&data->dead_lock);

// 		// printf("MS %ld philo %d dieing time is %d!!\n",ms_since_start(data->start_time),data->philo,data->dieing_time);
// 		// pthread_mutex_lock(&data->dead_lock);
// 		ft_usleep((data->time_to_eat)*1000);
// 		data->meals_ate++;
// 		// pthread_mutex_unlock(&data->dead_lock);

// 		pthread_mutex_unlock(data->fork_1);
// 		pthread_mutex_unlock(data->fork_0);
		
// 		if (data->life!=0)
// 			printf("MS %ld philo %d is sleeping!!\n",ms_since_start(data->start_time),data->philo);
// 		pthread_mutex_unlock(&data->dead_lock);

// 		ft_usleep((data->time_to_sleep)*1000);
// 		pthread_mutex_lock(&data->dead_lock);
// 		if (data->life!=0)
// 			printf("MS %ld philo %d is thinking!!\n",ms_since_start(data->start_time),data->philo);
// 		// pthread_mutex_unlock(data->dead_lock);
// 		pthread_mutex_unlock(&data->dead_lock);

// 	}
// 		// data->life=0;
// 		// printf("MS %ld philo %d is DEAD!! because time last_eat is %d and time to eat is %d and life is %d\n",ms_since_start(data->start_time),




// 	return NULL;

// 	}


// // void * observe(void *arg){
// // 	t_data *data = (t_data *)arg;

// // 	// printf("fork %d have a mutex of  %lu and %lu \n",data->philo,(unsigned long)data->fork_0,(unsigned long)data->fork_1);
// // 	int i =0;
// // 	while (i<4)
// // 	{
// //     	printf("In observe function, philo is: %d \n", (data[i].philo));
// // 	// printf("In observe function, address of data is philo is: %p \n", (void*)(program->data));
// // 	// printf("In observe function, address of program is philo is: %p \n", (void*)(program));
// // 	printf("In observe function, address of data is philo is: %p \n", (void*)(data));

// // 		i++;
// // 	}
// // 	return NULL;
// // }





// void * observe(void *arg){
// 	t_program *program = (t_program *)arg;

// 	// printf("fork %d have a mutex of  %lu and %lu \n",data->philo,(unsigned long)data->fork_0,(unsigned long)data->fork_1);
// 	int i =0;
// 	int j=0;
// 	// int k =0;
// 	// int mutex_error=0;
// 	int life =1;
// 	int numb_philo=program->data[0].numb_philo;
//     // pthread_mutex_lock(&(program->dead_lock)); // Use -> instead of .
// 	// while (j==0){
// 	while (life)
// 	{
// 		i=0;
// 		while (i<numb_philo)
// 		{		
// 			printf("IM AN OBSERVER and is =  %d \n",i);
// 			// k=0;

// 			// 
// 			pthread_mutex_lock(&program->data[i].dead_lock);

// 			if (   (program->data[i].dieing_time !=-1) && (program->data[i].dieing_time <ms_since_start(program->data[i].start_time)))
// 			{		

// 					printf("MS %ld DEATH triggered! for phili %d because dieing time is %d",
// 					ms_since_start(program->data[i].start_time),program->data[i].philo,program->data[i].dieing_time);
// 					program->data[i].life=0;
// 					pthread_mutex_unlock(&program->data[i].dead_lock);

// 					// lock_all_mutexes(program->data,numb_philo);

// 					while (j<numb_philo && j!=i)
// 					{	
// 						pthread_mutex_lock(&program->data[j].dead_lock);

// 						printf("KILLLL %d \n",j);
// 						program->data[j].life=0;
// 						life=0;
// 						pthread_mutex_unlock(&program->data[j].dead_lock);

// 						j++;
// 					}
// 					// unlock_all_mutexes(program->data,numb_philo);

// 					// while (j<program->data[0].numb_philo && j != i)
// 					// {	
// 					// 	printf("KILLLL %d \n",j);
// 					// 	pthread_mutex_lock(&program->data[j].dead_lock);

// 					// 	program->data[j].life=0;
// 					// 	pthread_mutex_unlock(&program->data[j].dead_lock);
// 					// 	life=0;
// 					// 	j++;
// 					// }
// 			}
// 			else
// 				pthread_mutex_unlock(&program->data[i].dead_lock);

// 			// while (k<program->data[0].numb_philo)
// 			// {
	
// 			// 			pthread_mutex_unlock(&program->data[k].dead_lock);
// 			// 			// printf("UNLOCKED TRHEAD %d and mutex error is %d\n ",k,mutex_error);
// 			// 			k++;
// 			// }
// 			// else
// 			// pthread_mutex_unlock(&(program->dead_lock)); // Use -> instead of .
// 		// printf("In observe function, philo is: %d \n", (program->data[i].philo));

// 			i++;
// 		}
// 	}

	// int l = 0;
	// int l2=0;
	// while (l<10)
	// {
	// 	l2=0;
	// 		while (l2<program->data[0].numb_philo)
	// 		{
	
	// 					mutex_error=pthread_mutex_unlock(&program->data[l2].dead_lock);
	// 					printf("UNLOCKED TRHEAD %d and mutex error is %d\n ",l2,mutex_error);
	// 					l2++;
	// 		}
	// 	l++;
	// }
// 	return NULL;
// }







	// 			ft_usleep((data->time_to_eat)*1000);
	// 			data->meals_ate++;
	// 			pthread_mutex_unlock(data->fork_1);

	// 			pthread_mutex_unlock(data->fork_0);
	// 			printf("MS %ld philo %d is sleeping!!\n",ms_since_start(data->start_time),data->philo);
	// 			ft_usleep((data->time_to_sleep)*1000);
	// 			printf("MS %ld philo %d is thinking!!\n",ms_since_start(data->start_time),data->philo);

	// 		}
	// 		else
	// 		{				
	// 			pthread_mutex_unlock(data->fork_1);

	// 			pthread_mutex_unlock(data->fork_0);
	// 			printf("MS %ld left mutex for thread %d released! \n",ms_since_start(data->start_time),data->philo);

	// 		}
	// 	}

	// }
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
		return ((int)write(2, "Invalid number of times each philosopher must eat\n",
				51));
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
	// size_t	time;

	pthread_mutex_lock(data->write_lock);

	if (!dead_loop(data))
		printf("MS %zu Philo %d %s\n", ms_since_start(data->start_time), id, str);
	pthread_mutex_unlock(data->write_lock);
}



void	think(t_data *data)
{
	pthread_mutex_lock(data->write_lock);
	if (!dead_loop(data))
		printf("MS %zu Philo %d is thinking\n", ms_since_start(data->start_time), data->philo);
	pthread_mutex_unlock(data->write_lock);
		// print_message("is thinking", data, data->philo);
	// pthread_mutex_unlock(data->write_lock);

}


// Dream routine funtion

void	sleeep(t_data *data)
{
	pthread_mutex_lock(data->write_lock);
	if (!dead_loop(data))
		printf("MS %zu Philo %d is sleeping\n", ms_since_start(data->start_time), data->philo);
	pthread_mutex_unlock(data->write_lock);
	// print_message("is sleeping", data, data->philo);
	ft_usleep(data->time_to_sleep*1000);
}
void lock_both_mutexes(pthread_mutex_t *mutex1, pthread_mutex_t *mutex2,t_data *data) {
    while (1) {
        // Attempt to lock mutex1
        if (pthread_mutex_lock(mutex1) == 0) {
			print_message("has taken a fork", data, data->philo);

            // Mutex1 locked successfully, attempt to lock mutex2
            if (pthread_mutex_lock(mutex2) == 0) {
				print_message("has taken a fork", data, data->philo);

                // Both mutexes locked successfully, break the loop
                return;
            } else {
                // Unable to lock mutex2, release mutex1 and retry
                pthread_mutex_unlock(mutex1);
            }
        }
        // Introduce a small delay to avoid busy waiting
        ft_usleep(10);
    }
}
// Eat routine funtion
void	eat(t_data *data)
{
	// pthread_mutex_lock(data->fork_1);
	// print_message("has taken a fork", data, data->philo);
	if (data->solo_philo == 1)
	{		
		pthread_mutex_lock(data->fork_0);
		print_message("has taken a  fork", data, data->philo);

		ft_usleep(data->time_to_die*1000);
		pthread_mutex_unlock(data->fork_0);
		return ;
	}
	lock_both_mutexes( data->fork_0,data->fork_1,data);

	// pthread_mutex_lock(data->fork_0);

	pthread_mutex_lock(data->eat_lock);
	data->eating = 1;

	print_message("is EATING", data, data->philo);
	data->time_last_eat = ms_since_start(data->start_time);
	data->meals_ate++;
	data->eating = 0;

	pthread_mutex_unlock(data->eat_lock);

	ft_usleep(data->time_to_eat*1000);
	pthread_mutex_unlock(data->fork_0);
	pthread_mutex_unlock(data->fork_1);
}

// void	eat(t_data *data)
// {
// 	pthread_mutex_lock(data->fork_1);
// 	pthread_mutex_lock(data->write_lock);
// 	if (!dead_loop(data))
// 		printf("MS%zu  Philo %d took fork %d\n", ms_since_start(data->start_time), data->philo,data->philo-1);
// 	pthread_mutex_unlock(data->write_lock);
// 	// if (data->num_of_philos == 1)
// 	// {
// 	// 	ft_usleep(data->time_to_die);
// 	// 	pthread_mutex_unlock(data->r_fork);
// 	// 	return ;
// 	// }
// 	pthread_mutex_lock(data->fork_0);
// 	pthread_mutex_lock(data->write_lock);
// 	if (!dead_loop(data))
// 		printf("MS%zu  Philo %d took fork %d\n", ms_since_start(data->start_time), data->philo,data->philo);
// 	pthread_mutex_unlock(data->write_lock);
// 	data->eating = 1;
// 	pthread_mutex_lock(data->write_lock);
// 	if (!dead_loop(data))
// 		printf("MS%zu  Philo %d is eating!\n", ms_since_start(data->start_time), data->philo);
// 	pthread_mutex_unlock(data->write_lock);
// 	pthread_mutex_lock(data->eat_lock);
// 	data->time_last_eat = ms_since_start(data->start_time);
// 	data->meals_ate++;
// 	pthread_mutex_unlock(data->eat_lock);
// 	ft_usleep(data->time_to_eat*1000);
// 	data->eating = 0;
// 	pthread_mutex_unlock(data->fork_0);
// 	pthread_mutex_unlock(data->fork_1);
// }




void init_input(t_data* data, char **argv)
{
	int i;

	i=0;
	while (i < ft_atoi(argv[1]))
	{
	

		data[i].time_to_die = ft_atoi(argv[2]);
		data[i].time_to_eat = ft_atoi(argv[3]);
		data[i].time_to_sleep = ft_atoi(argv[4]);
		if (argv[5])
			data[i].meals_to_eat = ft_atoi(argv[5]);
		else
			data[i].meals_to_eat = -1;
	
		i++;
	}
}

void init_philo(t_data* data,t_program* program,pthread_mutex_t *fork)
{
	int i;
	struct timeval start_time;

	i=0;
	while (i < program->numb_philo)
	{
		data[i].philo=i+1;
		data[i].write_lock = &program->write_lock;
		data[i].dead_lock = &program->dead_lock;
		data[i].eat_lock = &program->eat_lock;
		gettimeofday(&start_time, NULL);
		data[i].start_time = start_time;
		data[i].time_last_eat = 0;
		data[i].eating = 0;

		data[i].meals_ate = 0;
		data[i].dieing_time = -1;
		data[i].life=&program->life;
		data[i].fork_1= &fork[i];
		if (program->numb_philo==1)
			data[i].solo_philo=1;
		else			
			data[i].solo_philo=0;

		if (i == 0)
		{
			data[i].fork_0= &fork[0];
			data[i].fork_1= &fork[program->numb_philo-1];
		}
		else
		{
			data[i].fork_0= &fork[i-1];
			data[i].fork_1= &fork[i];
		}
		// if (i == 0)	
		// 	data[i].fork_0= &fork[program->numb_philo-1];
		// else
		// 	data[i].fork_0= &fork[i-1];
		// printf("fork %lu and %lu is taken for by philo %d!!\n",(unsigned long)data[i].fork_0,(unsigned long)data[i].fork_1,i);

		i++;
	}
}

void init_mutex(pthread_mutex_t *fork,int numb_philo)
{
	int i;
	
	i=0;
	while (i < numb_philo){
		if (pthread_mutex_init(&fork[i], NULL) != 0)
		{
			printf("Error initializting mutex!");
			return ;
		}
		printf("fork %d is %lu \n",i,(unsigned long)&fork[i]);
		i++;
	}
}

void	init_program(t_program *program, t_data *data,int numb_philo)
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
	// pthread_t	observer;
	int			i;

	// if (pthread_create(&observer, NULL, &monitor, program->philos) != 0)
	// 	destory_all("Thread creation error", program, forks);
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
	int			i;

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
	if (ms_since_start(data->start_time)- data->time_last_eat >= time_to_die
		&& data->eating == 0)
		return (pthread_mutex_unlock(data->eat_lock), 1);
	pthread_mutex_unlock(data->eat_lock);
	return (0);
}

// Check if any philo died

int	check_if_dead(t_data *data,int numb_philo)
{
	int	i;

	i = 0;
	while (i < numb_philo)
	{
		if (philosopher_dead(&data[i], data[i].time_to_die))
		{
			// printf("time to die of philo %d is %d",i+1,data[i].time_to_die);
			pthread_mutex_lock(data->write_lock);

			if (!dead_loop(data))
				printf("MS %u Philo %d died!\n", data->time_last_eat+data->time_to_die, data[i].philo);
			pthread_mutex_unlock(data->write_lock);


			// print_message("died", &data[i], data[i].philo);
			pthread_mutex_lock(data[0].dead_lock);
			*data->life = 0;
			pthread_mutex_unlock(data[0].dead_lock);
			return (1);
		}
		i++;
	}
	return (0);
}

// Checks if all the philos ate the num_of_meals

int	check_if_all_ate(t_data *data,int numb_philo)
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

void	*monitor(void *pointer,int numb_philo)
{
	t_data	*data;

	data = (t_data *)pointer;
	// printf("start monitor!");
	while (1)
	{
		// printf("time is %ld",ms_since_start(data->start_time));
		if (check_if_dead(data,numb_philo) == 1 || check_if_all_ate(data,numb_philo) == 1)
			break ;
		// ft_usleep(1);
	}
	return (pointer);
}

int	main(int argc, char**argv)
{
	pthread_mutex_t *fork;
	t_data *data;
	t_program program;
	

	if (argc != 5 && argc != 6)
		return ft_puterr("Please enter between argument numbers of 4 or 5",1);
	if (check_valid_args(argv) == 1)
		return (1);

	data = (t_data *)malloc(ft_atoi(argv[1]) * sizeof(t_data));
	fork = (pthread_mutex_t *)malloc(ft_atoi(argv[1]) * sizeof(pthread_mutex_t));

	init_program(&program,data,ft_atoi(argv[1]));
	init_mutex(fork,ft_atoi(argv[1]));
	init_philo(data,&program,fork);
	init_input(data,argv);
	create_thread(&program,fork);
	monitor(program.data,ft_atoi(argv[1]));
	join_thread(&program,fork);

	free(data);
	free(fork);
	printf("Done initi!");
	// int i = 0;
	// int i2=0;
	// int i=0;
	// int j2=0;

	// while (i < numb_philo)
	// {
	// 	if (pthread_mutex_init(&fork[i], NULL) != 0)
	// 	{
	// 		printf("Error initializting mutex!");
	// 		return 1;
	// 	}
	// 	printf("fork %d is %lu \n",i,(unsigned long)&fork[i]);

	// 	i++;
	// }
	// // if (pthread_mutex_init(&program.dead_lock, NULL) != 0 || pthread_mutex_init(&program.eat_lock, NULL) ||pthread_mutex_init(&program.write_lock, NULL) )
	// 	if (pthread_mutex_init(&program.eat_lock, NULL) ||pthread_mutex_init(&program.write_lock, NULL) )

	// {
	// 		printf("Error initializting mutex!");
	// 		return 1;
	// 	}

	// Point program to data
	// data.forks will point to forks array
	// Program.data will point to data arrays

	// program.data=data;
    // Create threads
	// printf("Address of before data  is: %p \n", (void*)(data));
	// printf("Address of before program  is: %p \n", (void*)(program.data));

}
//     while (j < numb_philo)
// 	{
// 		data[j].philo=j;
// 		data[j].numb_philo=numb_philo;
// 		data[j].time_to_die=time_to_die;
// 		data[j].time_to_eat=time_to_eat;
// 		data[j].time_to_sleep=time_to_sleep;
// 		data[j].meals_to_eat=meals_to_eat;

//     	// data[j].fork = (pthread_mutex_t **)malloc(2 * sizeof(pthread_mutex_t *));


//  		memset(&data[j].start_time, 0, sizeof(struct timeval));
		
// 		data[j].time_last_eat=0;
// 		data[j].meals_ate=0;

// 		data[j].dieing_time=-1;
// 		data[j].life=1;

// 		pthread_mutex_init(&data[j].dead_lock,NULL);
	
// 		data[j].write_lock=&program.write_lock;
// 		data[j].eat_lock=&program.eat_lock;



// 		if (j == 0)
// 		{
			
// 			data[j].fork_0= &fork[0];
// 			data[j].fork_1= &fork[numb_philo-1];
// 		}
// 		else
// 		{
// 			data[j].fork_0= &fork[j-1];
// 			data[j].fork_1= &fork[j];
// 		}

// 		// printf("Philo is : %d \n", program->data[j]->philo);
// 		// printf("Address of data dead_lock is :%p \n", (void*) program->data[j].dead_lock);
// 		// printf("Address of program dead_lock is: %p \n", (void*)&(program->dead_lock));

// 		j++;
// 	}
// 	// printf("Address of data  is: %p \n", (void*)(data));
// 	// printf("Address of program  is: %p \n", (void*)(program.data));

// 	j=0;
	
//    if (pthread_create(&observer, NULL, &observe, (&program)) != 0) {
//             printf( "Error creating thread %d\n", j);
//             return 1;
//         }
	
//     while (j < numb_philo){
//         if (pthread_create(&philo[j], NULL, &thread_function, &(data[j])) != 0) {
//             printf( "Error creating thread %d\n", j);
//             return 1;
//         }
// 		j++;
//     }


//     // Wait for threads to finish
//     while (j2 < numb_philo)
// 	{
//         if (pthread_join(philo[j2], NULL) != 0) {
//             printf( "Error joining thread %d\n", j2);
//             // Handle error as needed
//             return 1;
//         }
// 		else
// 		{
// 			printf( "done joining thread %d\n", j2);

// 		}
// 		j2++;
//     }
// 	if (pthread_join(observer, NULL) != 0) 
// 	{
//             printf( "Error joining thread %d\n", j2);
//             return 1;
// 	}
// 	int times=0;
// 	while (times < numb_philo)
// 	{
// 		printf("times aten by thread %d is %d\n",times,data[times].meals_ate);
// 		times++;
// 	}

//  	while (i2 < numb_philo)
// 	{
// 		if (pthread_mutex_destroy(&fork[i2]) != 0)
// 		{
// 			printf("Error initializting mutex!");
// 			return 1;
// 		}
// 		i2++;
// 	}


// }      


// 	// int main(){

// 	// struct timeval start_time, end_time;

// 	// gettimeofday(&start_time,NULL);
// 	// printf("time of day is before execute in msec %ld \n",start_time.tv_usec);
// 	// printf("time of day is before execute in sec %ld \n",start_time.tv_sec);


// 	// ft_usleep(3000);

// 	// gettimeofday(&end_time,NULL);

// 	// printf("time of day is after execute in msec %ld \n",end_time.tv_usec);
// 	// printf("time of day is after execute in sec %ld \n",end_time.tv_sec);

// 	// long elapsed_seconds = end_time.tv_sec - start_time.tv_sec;
//     // long elapsed_microseconds = end_time.tv_usec - start_time.tv_usec;
//     // long elapsed_total_microseconds = elapsed_seconds * 1000000 + elapsed_microseconds;
// 	// printf("Elapsed time: %ld microseconds\n", elapsed_total_microseconds);
// 	// printf("Elapsed time: %ld ms\n", elapsed_total_microseconds/1000);


// 	// }

