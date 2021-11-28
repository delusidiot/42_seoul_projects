/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 06:02:31 by jjeon             #+#    #+#             */
/*   Updated: 2021/11/28 09:53:51 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*monitor_complete(void *info_ptr)
{
	int		count;
	t_info	*info;

	count = 0;
	info = (t_info *)info_ptr;
	while (TRUE)
	{
		if (sem_wait(info->sem_full) == _ERROR)
			sem_post(info->sem_meal);
		count++;
		if (count >= info->num_of_philo)
		{
			print_state(COMPLETE, info);
			sem_post(info->sem_meal);
		}
	}
	return (NULL);
}

void	*monitor_died(void *info_ptr)
{
	t_info		*info;
	long long	current;

	info = (t_info *)info_ptr;
	if (!timestamp(&current))
		sem_post(info->sem_meal);
	wait_interval(info, current, info->time_to_die - 10);
	while (TRUE)
	{
		if (!timestamp(&current))
			sem_post(info->sem_meal);
		if (current - info->philo[info->index].current
			> (long long)info->time_to_die)
		{
			print_state(DIED, info);
			sem_post(info->sem_meal);
		}
	}
}

void	*routine(t_info *info)
{
	if (!timestamp(&info->philo[info->index].current))
		sem_post(info->sem_meal);
	if (info->index % 2)
		wait_interval(info, info->philo[info->index].current, 100);
	while (TRUE)
	{
		take_fork(info);
		philo_eat(info);
		put_fork(info);
		philo_sleep(info);
		philo_think(info);
	}
}

void	active_philo(t_info *info)
{
	int	 i;

	i = -1;
	if (pthread_create(&info->thread, NULL, monitor_complete, (void *)info)
		|| pthread_detach(info->thread) || !timestamp(&info->start))
		return ;
	while (++i < info->num_of_philo)
	{
		info->index = i;
		info->philo[i].pid = fork();
		if (info->philo[i].pid == _ERROR)
			return ;
		else if (info->philo[i].pid == 0)
		{
			if (pthread_create(&info->philo[i].thread, \
				NULL, monitor_died, (void *)info)
				|| pthread_detach(info->philo[i].thread))
				sem_post(info->sem_meal);
			routine(info);
			exit(0);
		}
	}
	if (sem_wait(info->sem_meal) == _ERROR)
		return ;
	return ;
}
