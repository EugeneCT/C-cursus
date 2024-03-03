/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 22:39:55 by cliew             #+#    #+#             */
/*   Updated: 2024/03/03 12:36:30 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
void * thread_function(void *arg){
	t_data *data = (t_data *)arg;
	int i;

	while (&data->fork[i]){
		printf("fork %d have a mutex of  %lu \n",i,(unsigned long)&data->fork[i]);
		i++;

	}
	// if (data->philo == 0)
	// 	{
	// 		data->fork_0= data->fork[0];
	// 		data->fork_1= data->fork[data->philo];
	// 	}
	// 	else
	// 	{
	// 		data->fork[0]= data->fork[data->philo];
	// 		data->fork[1]= data->fork[data->philo-1];
	// 	}

	printf("mutex numb  for philo %d is %lu and %lu!\n",data->philo,(unsigned long)&data->fork_0,(unsigned long)&data->fork_1);

	// printf("mutex numb  for philo %d is %lu and %lu!\n",data->philo,(unsigned long)&data->fork[0],(unsigned long)&data->fork[1]);

	// while (data->meals_ate <data->meals_to_eat )
	// {
	// 	pthread_mutex_lock(&data->fork[0]);
	// 	printf("fork %lu is taken for by philo %d!!\n",(unsigned long)&data->fork[0],data->philo);

	// 	pthread_mutex_lock(&data->fork[1]);
	// 	printf("fork %lu is taken for by philo %d!!\n",(unsigned long)&data->fork[1],data->philo);

	// 	// printf("in thread where j = %d !\n",data->philo);
	// 		printf("j = %d starts to eat!!\n",data->philo);

	// 	// printf("starttime_ms is : %ld!\n",data->start_time.tv_usec);
	// 	// printf("data numb_phil is %d !\n",data->numb_philo);
	// 	ft_usleep((data->time_to_eat)*100000);
	// 	// printf("mutex numb is %lu and %lu!\n",(unsigned long)&data->fork[0],(unsigned long)&data->fork[1]);
	// 	data->meals_ate++;

	// 	pthread_mutex_unlock(&data->fork[0]);
	// 	printf("fork %lu is release for by philo %d!!\n",(unsigned long)&data->fork[0],data->philo);

	// 	pthread_mutex_unlock(&data->fork[1]);
	// 	printf("fork %lu is release for by philo %d!!\n",(unsigned long)&data->fork[1],data->philo);

	// 	printf("j = %d done eat!!\n",data->philo);

	// }



	return NULL;

}

int	main()
{
	int numb_philo=5;
	int time_to_die=10;
	int time_to_eat=10;
	int time_to_sleep=10;
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
		data[j].time_last_eat=1;
		data[j].meals_ate=0;

		data[j].fork=&fork;
		// if (j == 0)
		// {
		// 	data[j].fork[0]= fork[0];
		// 	data[j].fork[1]= fork[numb_philo-1];
		// }
		// else
		// {
		// 	data[j].fork[0]= fork[j];
		// 	data[j].fork[1]= fork[j-1];
		// }

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


