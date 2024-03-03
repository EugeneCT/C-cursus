
#include "philo.h"

void ft_usleep( long int microseconds) {
    struct timeval start_time, current_time;

    // Get the start time
    gettimeofday(&start_time, NULL);

    while (((current_time.tv_sec - start_time.tv_sec) * 1000000 + (current_time.tv_usec - start_time.tv_usec)) < microseconds) {
        // Get the current time
        gettimeofday(&current_time, NULL);
    }
}
