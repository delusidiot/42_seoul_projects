#include "philo.h"

int timestamp(long long *time)
{
	struct timeval  tv;

	if (gettimeofday(&tv, NULL) == _ERROR)
		return (FALSE);
	*time = (long long)(tv.tv_sec * 1000 + tv.tv_usec / 1000);
	return (TRUE);
}

void	wait_interval(t_philo *philo, long long start, long long interval)
{
	long long current;

	while (TRUE)
	{
		if (timestamp(&current) == FALSE)
			pthread_mutex_unlock(&philo->info->meal);
		if (current - start >= interval)
			break;
		if (usleep(10) == _ERROR)
			pthread_mutex_unlock(&philo->info->meal);
	}
}