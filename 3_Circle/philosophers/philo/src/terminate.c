/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 05:13:03 by jjeon             #+#    #+#             */
/*   Updated: 2021/11/25 05:13:04 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	usage(void)
{
	ft_putstr_fd("usage : ./philo number_of_philosophers ", STDERR_FILENO);
	ft_putstr_fd("time_to_die time_to_eat time_to_sleep ", STDERR_FILENO);
	ft_putstr_fd("[number_of_times_each_philosopher_must_eat]\n", STDERR_FILENO);
}

int	put_error(char *str)
{
	ft_putstr_fd(str, STDERR_FILENO);
	return (FALSE);
}

int	abnormal_terminate(t_info *info, t_philo *philo, char *str)
{
	destroy_mutex(info, philo);
	return (put_error(str));
}

void	destroy_mutex(t_info *info, t_philo *philo)
{
	int	i;

	if (info->fork)
	{
		i = -1;
		while (++i < info->num_of_philo)
			pthread_mutex_destroy(&info->fork[i]);
		free(info->fork);
	}
	if (philo)
		free(philo);
	pthread_mutex_destroy(&info->meal);
	pthread_mutex_destroy(&info->print);
}