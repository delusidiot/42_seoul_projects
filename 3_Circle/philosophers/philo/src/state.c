/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 05:13:00 by jjeon             #+#    #+#             */
/*   Updated: 2021/11/25 05:13:01 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork(t_philo *philo)
{
	if (pthread_mutex_lock(&philo->info->fork[philo->l]) || \
		print_state(TAKEN, philo) == false || \
		pthread_mutex_lock(&philo->info->fork[philo->r]) || \
		print_state(TAKEN, philo) == false)
		pthread_mutex_unlock(&philo->info->meal);
}

void	put_fork(t_philo *philo)
{
	if (pthread_mutex_unlock(&philo->info->fork[philo->l]) || \
		pthread_mutex_unlock(&philo->info->fork[philo->r]))
		pthread_mutex_unlock(&philo->info->meal);
}

void	philo_eat(t_philo *philo)
{
	if (timestamp(&(philo->current)) == false || \
		print_state(EATING, philo) == false)
		pthread_mutex_unlock(&philo->info->meal);
	wait_interval(philo, philo->current, philo->info->time_to_eat);
	++(philo->count);
	if (philo->count == philo->info->must_eat)
	{
		++(philo->info->count);
		if (philo->info->count >= philo->info->num_of_philo)
			if (print_state(COMPLETE, philo) == false)
				pthread_mutex_unlock(&philo->info->meal);
	}
}

void	philo_sleep(t_philo *philo)
{
	long long	cur;

	cur = 0;
	if (timestamp(&cur) == false || \
		print_state(SLEEPING, philo) == false)
		pthread_mutex_unlock(&philo->info->meal);
	wait_interval(philo, cur, philo->info->time_to_sleep);
}

void	philo_think(t_philo *philo)
{
	if (print_state(THINKING, philo) == false)
		pthread_mutex_unlock(&philo->info->meal);
}
