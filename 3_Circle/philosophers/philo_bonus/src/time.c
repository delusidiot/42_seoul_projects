/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 08:36:39 by jjeon             #+#    #+#             */
/*   Updated: 2021/11/28 11:16:44 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	timestamp(long long *time)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == _ERROR)
		return (FALSE);
	*time = (long long)(tv.tv_sec * 1000 + tv.tv_usec / 1000);
	return (TRUE);
}

void	wait_time(t_info *info, long long start, long long interval)
{
	long long	current;

	while (TRUE)
	{
		if (timestamp(&current) == FALSE)
			sem_post(info->sem_meal);
		if (current - start >= interval)
			break ;
		if (usleep(10) == _ERROR)
			sem_post(info->sem_meal);
	}
}
