/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 06:05:22 by jjeon             #+#    #+#             */
/*   Updated: 2021/11/28 11:17:54 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	take_fork(t_info *info)
{
	if (sem_wait(info->sem_fork) == _ERROR
		|| !print_state(TAKEN, info)
		|| sem_wait(info->sem_fork) == _ERROR
		|| !print_state(TAKEN, info))
		sem_post(info->sem_meal);
}

void	put_fork_down(t_info *info)
{
	if (sem_post(info->sem_fork) == _ERROR
		|| sem_post(info->sem_fork) == _ERROR)
		sem_post(info->sem_meal);
}

void	philo_eat(t_info *info)
{
	if (!timestamp(&info->philo[info->index].current)
		|| !print_state(EATING, info))
		sem_post(info->sem_meal);
	wait_time(info, info->philo[info->index].current, info->time_to_eat);
	info->philo[info->index].count++;
	if (info->philo[info->index].count == info->must_eat)
		if (sem_post(info->sem_full) == _ERROR)
			sem_post(info->sem_meal);
}

void	philo_sleep(t_info *info)
{
	long long	cur;

	cur = 0;
	if (!timestamp(&cur)
		|| !print_state(SLEEPING, info))
		sem_post(info->sem_meal);
	wait_time(info, cur, info->time_to_sleep);
}

void	philo_think(t_info *info)
{
	if (!print_state(THINKING, info))
		sem_post(info->sem_meal);
}
