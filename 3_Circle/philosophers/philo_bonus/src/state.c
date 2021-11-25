#include "philo_bonus.h"

void	take_fork(t_info *info)
{
	if (sem_wait(info->sem_fork) == _ERROR
		|| print_state(TAKEN, info) == false
		|| sem_wait(info->sem_fork) == _ERROR
		|| print_state(TAKEN, info) == false)
		sem_post(info->sem_meal);
}

void	put_fork(t_info *info)
{
	if (sem_post(info->sem_fork) == _ERROR
		|| sem_post(info->sem_fork) == _ERROR)
		sem_post(info->sem_meal);
}

void	philo_eat(t_info *info)
{
	if (timestamp(&info->philo[info->index].current) == false
		|| print_state(EATING, info) == false)
		sem_post(info->sem_meal);
	wait_interval(info, info->philo[info->index].current, info->time_to_eat);
	++(info->philo[info->index].count);
	if (info->philo[info->index].count == info->num_of_philo)
		if (sem_post(info->sem_full) == _ERROR)
			sem_post(info->sem_meal);
}

void	philo_sleep(t_info *info)
{
	long long	cur;

	cur = 0;
	if (timestamp(&cur) == false || \
		print_state(SLEEPING, info) == false)
		sem_post(info->sem_meal);
	wait_interval(info, cur, info->time_to_sleep);
}

void	philo_think(t_info *info)
{
	if (print_state(THINKING, info) == false)
		sem_post(info->sem_meal);
}