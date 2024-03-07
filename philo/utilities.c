
#include "philo.h"

void	ft_putstr_fd(char const *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen((char *)s));
}

int	ft_puterr(char const *s, int ret)
{
	ft_putstr_fd(s, 2);
	ft_putstr_fd("\n", 2);
	return (ret);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	num;

	i = 0;
	num = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		sign = sign * -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	num = num * sign;
	return ((int)num);
}

void ft_usleep( long int microseconds) {
    struct timeval start_time, current_time;

    // Get the start time
    gettimeofday(&start_time, NULL);
    gettimeofday(&current_time, NULL);

    while (((((current_time.tv_sec - start_time.tv_sec) * 1000000) + (current_time.tv_usec - start_time.tv_usec))) <= microseconds) {
        // Get the current time
        gettimeofday(&current_time, NULL);
    }
}

int	ft_strlen(char *str)
{
	int	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	destory_all(char *str, t_program *program, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	if (str)
	{
		write(2, str, ft_strlen(str));
		write(2, "\n", 1);
	}
    pthread_mutex_destroy(&program->eat_lock);
	pthread_mutex_destroy(&program->write_lock);
	pthread_mutex_destroy(&program->dead_lock);
	while (i < program->numb_philo)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
}

