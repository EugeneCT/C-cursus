/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 22:39:55 by cliew             #+#    #+#             */
/*   Updated: 2024/03/03 19:04:34 by cliew            ###   ########.fr       */
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

	return elapsed_total_milliseconds;
}
void lock_both_mutexes(pthread_mutex_t *mutex1, pthread_mutex_t *mutex2) {
    while (1) {
        // Attempt to lock mutex1
        if (pthread_mutex_lock(mutex1) == 0) {
            // Mutex1 locked successfully, attempt to lock mutex2
            if (pthread_mutex_lock(mutex2) == 0) {
                // Both mutexes locked successfully, break the loop
                return;
            } else {
                // Unable to lock mutex2, release mutex1 and retry
                pthread_mutex_unlock(mutex1);
            }
        }
        // Introduce a small delay to avoid busy waiting
        ft_usleep(1000);
    }
}
void * thread_function(void *arg){
	t_data *data = (t_data *)arg;

	// printf("fork %d have a mutex of  %lu and %lu \n",data->philo,(unsigned long)data->fork_0,(unsigned long)data->fork_1);

	printf("MS %ld thread %d initiated! \n",ms_since_start(data->start_time),data->philo);

	while ( (ms_since_start(data->start_time)<(data->time_last_eat + data->time_to_die)))
	{
		lock_both_mutexes(data->fork_0,data->fork_1);
		printf("MS %ld while loop for thread %d activated! \n",ms_since_start(data->start_time),data->philo);

		
			printf("MS %ld left mutex for thread %d activated! \n",ms_since_start(data->start_time),data->philo);

				printf("MS %ld fork %lu and %lu is taken for by philo %d!!\n",ms_since_start(data->start_time),(unsigned long)data->fork_0,(unsigned long)data->fork_1,data->philo);
				printf("MS %ld philo %d starts to eat!!\n",ms_since_start(data->start_time),data->philo);
				data->time_last_eat=ms_since_start(data->start_time);

				ft_usleep((data->time_to_eat)*1000);
				data->meals_ate++;
				pthread_mutex_unlock(data->fork_1);

				pthread_mutex_unlock(data->fork_0);
				printf("MS %ld philo %d is sleeping!!\n",ms_since_start(data->start_time),data->philo);
				ft_usleep((data->time_to_sleep)*1000);
				printf("MS %ld philo %d is thinking!!\n",ms_since_start(data->start_time),data->philo);


		}
		data->life=0;
		printf("MS %ld philo %d is DEAD!! because time last_eat is %d and time to eat is %d \n",ms_since_start(data->start_time),
		data->philo,data->time_last_eat,data->time_to_die);




	return NULL;

	}




// data->meals_ate <data->meals_to_eat &&
	// while ( data->meals_ate <data->meals_to_eat && (ms_since_start(data->start_time)<(data->time_last_eat + data->time_to_die)))
	// {
	// 	printf("MS %ld while loop for thread %d activated! \n",ms_since_start(data->start_time),data->philo);

	// 	if (pthread_mutex_lock(data->fork_0)==0 )
	// 	{
	// 		printf("MS %ld left mutex for thread %d activated! \n",ms_since_start(data->start_time),data->philo);

	// 		if(pthread_mutex_lock(data->fork_1) ==0)
	// 		{
	// 			printf("MS %ld fork %lu and %lu is taken for by philo %d!!\n",ms_since_start(data->start_time),(unsigned long)data->fork_0,(unsigned long)data->fork_1,data->philo);
	// 			printf("MS %ld philo %d starts to eat!!\n",ms_since_start(data->start_time),data->philo);
	// 			data->time_last_eat=ms_since_start(data->start_time);

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


int	main()
{
	int numb_philo=4;
	int time_to_die=310;
	int time_to_eat=200;
	int time_to_sleep=100;
	int meals_to_eat=5;

	pthread_t philo[numb_philo];
	pthread_mutex_t fork[numb_philo];
	
	t_data *data = (t_data *)malloc(numb_philo * sizeof(t_data));
    
	struct timeval start_time;


	int i = 0;
	int i2=0;
	int j=0;
	int j2=0;

	gettimeofday(&start_time,NULL);
	while (i < numb_philo)
	{
		if (pthread_mutex_init(&fork[i], NULL) != 0)
		{
			printf("Error initializting mutex!");
			return 1;
		}
		printf("fork %d is %lu \n",i,(unsigned long)&fork[i]);

		i++;
	}
	// data.fork=fork;



    // Create threads


    while (j < numb_philo)
	{
		data[j].philo=j;
		data[j].numb_philo=numb_philo;
		data[j].time_to_die=time_to_die;
		data[j].time_to_eat=time_to_eat;
		data[j].time_to_sleep=time_to_sleep;
		data[j].meals_to_eat=meals_to_eat;

    	// data[j].fork = (pthread_mutex_t **)malloc(2 * sizeof(pthread_mutex_t *));

		data[j].start_time=start_time;
		data[j].time_last_eat=0;
		data[j].meals_ate=0;
		data[j].life=1;

		if (j == 0)
		{
			
			data[j].fork_0= &fork[0];
			data[j].fork_1= &fork[numb_philo-1];
		}
		else
		{
			data[j].fork_0= &fork[j-1];
			data[j].fork_1= &fork[j];
		}
		j++;
	}
	j=0;
	
    while (j < numb_philo){
        if (pthread_create(&philo[j], NULL, &thread_function, &(data[j])) != 0) {
            printf( "Error creating thread %d\n", j);
            return 1;
        }
		j++;
    }


    // Wait for threads to finish
    while (j2 < numb_philo)
	{
        if (pthread_join(philo[j2], NULL) != 0) {
            printf( "Error joining thread %d\n", j2);
            // Handle error as needed
            return 1;
        }
		j2++;
    }

	int times=0;
	while (times < numb_philo)
	{
		printf("times aten by thread %d is %d\n",times,data[times].meals_ate);
		times++;
	}

 	while (i2 < numb_philo)
	{
		if (pthread_mutex_destroy(&fork[i2]) != 0)
		{
			printf("Error initializting mutex!");
			return 1;
		}
		i2++;
	}


}      


	// int main(){

	// struct timeval start_time, end_time;

	// gettimeofday(&start_time,NULL);
	// printf("time of day is before execute in msec %ld \n",start_time.tv_usec);
	// printf("time of day is before execute in sec %ld \n",start_time.tv_sec);


	// ft_usleep(3000);

	// gettimeofday(&end_time,NULL);

	// printf("time of day is after execute in msec %ld \n",end_time.tv_usec);
	// printf("time of day is after execute in sec %ld \n",end_time.tv_sec);

	// long elapsed_seconds = end_time.tv_sec - start_time.tv_sec;
    // long elapsed_microseconds = end_time.tv_usec - start_time.tv_usec;
    // long elapsed_total_microseconds = elapsed_seconds * 1000000 + elapsed_microseconds;
	// printf("Elapsed time: %ld microseconds\n", elapsed_total_microseconds);
	// printf("Elapsed time: %ld ms\n", elapsed_total_microseconds/1000);


	// }

