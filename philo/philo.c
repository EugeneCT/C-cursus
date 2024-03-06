/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 22:39:55 by cliew             #+#    #+#             */
/*   Updated: 2024/03/06 17:18:41 by cliew            ###   ########.fr       */
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
	struct timeval start_time;

	gettimeofday(&start_time,NULL);
	data->start_time=start_time;
	// printf("fork %d have a mutex of  %lu and %lu \n",data->philo,(unsigned long)data->fork_0,(unsigned long)data->fork_1);

	printf("MS %ld thread %d initiated! \n",ms_since_start(data->start_time),data->philo);
	if (data->philo+1 % 2 == 0)
		ft_usleep(0.1);

	printf("MS %ld thread %d life = %d before lock! \n",ms_since_start(data->start_time),data->philo,data->life);

	pthread_mutex_lock(&data->dead_lock);
	// while ( (ms_since_start(data->start_time)<(data->time_last_eat + data->time_to_die)) && data->life!=0 )
	pthread_mutex_unlock(&data->dead_lock);

	while ( data->life!=0 )
	{
		// pthread_mutex_lock(data->dead_lock);

		lock_both_mutexes(data->fork_0,data->fork_1);
		// printf("MS %ld philo %d have life %d!!\n",ms_since_start(data->start_time),
		// data->philo,data->life);

		pthread_mutex_lock(&data->dead_lock);
		if (data->life!=0)
		{
			printf("MS %ld fork %lu and %lu is taken for by philo %d!!\n",ms_since_start(data->start_time),(unsigned long)data->fork_0,(unsigned long)data->fork_1,data->philo);
			printf("MS %ld philo %d starts to eat!!\n",ms_since_start(data->start_time),data->philo);
			data->time_last_eat=ms_since_start(data->start_time);
			data->dieing_time=data->time_last_eat+data->time_to_die;
		}
		pthread_mutex_unlock(&data->dead_lock);

		// printf("MS %ld philo %d dieing time is %d!!\n",ms_since_start(data->start_time),data->philo,data->dieing_time);

		ft_usleep((data->time_to_eat)*1000);
		data->meals_ate++;
		pthread_mutex_unlock(data->fork_1);

		pthread_mutex_unlock(data->fork_0);
		pthread_mutex_lock(&data->dead_lock);
		if (data->life!=0)
			printf("MS %ld philo %d is sleeping!!\n",ms_since_start(data->start_time),data->philo);
		pthread_mutex_unlock(&data->dead_lock);

		ft_usleep((data->time_to_sleep)*1000);
		pthread_mutex_lock(&data->dead_lock);
		if (data->life!=0)
			printf("MS %ld philo %d is thinking!!\n",ms_since_start(data->start_time),data->philo);
		// pthread_mutex_unlock(data->dead_lock);
		pthread_mutex_unlock(&data->dead_lock);

	}
		// data->life=0;
		// printf("MS %ld philo %d is DEAD!! because time last_eat is %d and time to eat is %d and life is %d\n",ms_since_start(data->start_time),




	return NULL;

	}


// void * observe(void *arg){
// 	t_data *data = (t_data *)arg;

// 	// printf("fork %d have a mutex of  %lu and %lu \n",data->philo,(unsigned long)data->fork_0,(unsigned long)data->fork_1);
// 	int i =0;
// 	while (i<4)
// 	{
//     	printf("In observe function, philo is: %d \n", (data[i].philo));
// 	// printf("In observe function, address of data is philo is: %p \n", (void*)(program->data));
// 	// printf("In observe function, address of program is philo is: %p \n", (void*)(program));
// 	printf("In observe function, address of data is philo is: %p \n", (void*)(data));

// 		i++;
// 	}
// 	return NULL;
// }

void * observe(void *arg){
	t_program *program = (t_program *)arg;

	// printf("fork %d have a mutex of  %lu and %lu \n",data->philo,(unsigned long)data->fork_0,(unsigned long)data->fork_1);
	int i =0;
	int j=0;
	// int k =0;
	// int mutex_error=0;
	int life =1;
    // pthread_mutex_lock(&(program->dead_lock)); // Use -> instead of .
	// while (j==0){
	while (life)
	{
		i=0;
		while (i<program->data[0].numb_philo)
		{		
			// printf("IM AN OBSERVER ");
			// k=0;

			// 
			pthread_mutex_lock(&program->data[i].dead_lock);

			if (   (program->data[i].dieing_time !=-1) && (program->data[i].dieing_time <ms_since_start(program->data[i].start_time)))
			{		

					printf("MS %ld DEATH triggered! for phili %d because dieing time is %d",
					ms_since_start(program->data[i].start_time),program->data[i].philo,program->data[i].dieing_time);
					while (j<program->data[0].numb_philo)
					{	
						// printf("KILLLL \n");
						program->data[j].life=0;
						life=0;
						j++;
					}
			}
			
			// while (k<program->data[0].numb_philo)
			// {
	
			// 			pthread_mutex_unlock(&program->data[k].dead_lock);
			// 			// printf("UNLOCKED TRHEAD %d and mutex error is %d\n ",k,mutex_error);
			// 			k++;
			// }
			// else
			// pthread_mutex_unlock(&(program->dead_lock)); // Use -> instead of .
		// printf("In observe function, philo is: %d \n", (program->data[i].philo));
			pthread_mutex_unlock(&program->data[i].dead_lock);

			i++;
		}
	}

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
	return NULL;
}

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
	int numb_philo=5;
	int time_to_die=800;
	int time_to_eat=200;
	int time_to_sleep=200;
	int meals_to_eat=5;

	pthread_t philo[numb_philo];
	pthread_t observer;
	pthread_mutex_t fork[numb_philo];

	t_data *data = (t_data *)malloc(numb_philo * sizeof(t_data));
    t_program program;
	


	int i = 0;
	int i2=0;
	int j=0;
	int j2=0;

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
	// if (pthread_mutex_init(&program.dead_lock, NULL) != 0 || pthread_mutex_init(&program.eat_lock, NULL) ||pthread_mutex_init(&program.write_lock, NULL) )
		if (pthread_mutex_init(&program.eat_lock, NULL) ||pthread_mutex_init(&program.write_lock, NULL) )

	{
			printf("Error initializting mutex!");
			return 1;
		}

	// Point program to data
	// data.forks will point to forks array
	// Program.data will point to data arrays

	program.data=data;
    // Create threads
	printf("Address of before data  is: %p \n", (void*)(data));
	printf("Address of before program  is: %p \n", (void*)(program.data));


    while (j < numb_philo)
	{
		data[j].philo=j;
		data[j].numb_philo=numb_philo;
		data[j].time_to_die=time_to_die;
		data[j].time_to_eat=time_to_eat;
		data[j].time_to_sleep=time_to_sleep;
		data[j].meals_to_eat=meals_to_eat;

    	// data[j].fork = (pthread_mutex_t **)malloc(2 * sizeof(pthread_mutex_t *));


 		memset(&data[j].start_time, 0, sizeof(struct timeval));
		
		data[j].time_last_eat=0;
		data[j].meals_ate=0;

		data[j].dieing_time=-1;
		data[j].life=1;

		pthread_mutex_init(&data[j].dead_lock,NULL);
	
		data[j].write_lock=&program.write_lock;
		data[j].eat_lock=&program.eat_lock;



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

		// printf("Philo is : %d \n", program->data[j]->philo);
		// printf("Address of data dead_lock is :%p \n", (void*) program->data[j].dead_lock);
		// printf("Address of program dead_lock is: %p \n", (void*)&(program->dead_lock));

		j++;
	}
	// printf("Address of data  is: %p \n", (void*)(data));
	// printf("Address of program  is: %p \n", (void*)(program.data));

	j=0;
	
   if (pthread_create(&observer, NULL, &observe, (&program)) != 0) {
            printf( "Error creating thread %d\n", j);
            return 1;
        }
	
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
		else
		{
			printf( "done joining thread %d\n", j2);

		}
		j2++;
    }
	if (pthread_join(observer, NULL) != 0) 
	{
            printf( "Error joining thread %d\n", j2);
            return 1;
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

