/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 05:12:54 by jjeon             #+#    #+#             */
/*   Updated: 2021/11/25 05:12:55 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*monitor(void *ptr_philo)
{
	long long	current;
	t_philo		*philo;

	philo = (t_philo *)ptr_philo;
	if (!timestamp(&current))
		pthread_mutex_unlock(&philo->info->meal);
	wait_interval(philo, current, philo->info->time_to_die - 10);
	while (TRUE)
	{
		if (!timestamp(&current))
			pthread_mutex_unlock(&philo->info->meal);
		if (current - philo->current >= (long long)philo->info->time_to_die)
		{
			print_state(DIED, philo);
			pthread_mutex_unlock(&philo->info->meal);
		}
	}
	return (NULL);
}

static void	*routine(void *ptr_philo)
{
	t_philo	*philo;

	philo = (t_philo *)ptr_philo;
	if (!timestamp(&philo->current))
		pthread_mutex_unlock(&philo->info->meal);
	if (philo->index % 2)
		wait_interval(philo, philo->current, 100);
	while (TRUE)
	{
		take_fork(philo);
		philo_eat(philo);
		put_fork_down(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}

void	active_philo(t_info *info, t_philo *philo)
{
	int	 i;

	i = -1;
	if (pthread_mutex_lock(&info->meal)
		|| timestamp(&info->start) == FALSE)
		return ;
	while (++i < info->num_of_philo)
	{
		philo[i].index = i;
		philo[i].info = info;
		philo[i].l = i;
		philo[i].r = (i + 1) % info->num_of_philo;
		if (pthread_create(&philo[i].routine, NULL, routine, &philo[i])
			|| pthread_detach(philo[i].routine))
			return ;
		if (pthread_create(&philo[i].monitor, NULL, monitor, &philo[i])
			|| pthread_detach(philo[i].monitor))
			return ;
	}
	if (pthread_mutex_lock(&info->meal))
		return ;
}