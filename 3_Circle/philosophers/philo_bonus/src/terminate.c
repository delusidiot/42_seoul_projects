/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 06:05:54 by jjeon             #+#    #+#             */
/*   Updated: 2021/11/26 06:05:55 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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

void	kill_process(t_info *info)
{
	int	i;

	i = -1;
	if (info->philo)
	{
		while (info->philo[++i].pid && i < info->num_of_philo)
		{
			kill(info->philo[i].pid, SIGKILL);
			waitpid(info->philo[i].pid, NULL, WNOHANG);
		}
	}
}

int	terminate(t_info *info)
{
	kill_process(info);
	return (0);
}
