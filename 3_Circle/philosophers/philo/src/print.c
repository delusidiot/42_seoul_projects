/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 05:12:58 by jjeon             #+#    #+#             */
/*   Updated: 2021/11/26 06:11:32 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	print_messsge(t_state state)
{
	if (state == TAKEN)
		ft_putendl_fd(TAKEN_MSG, STDOUT_FILENO);
	else if (state == EATING)
		ft_putendl_fd(EATING_MSG, STDOUT_FILENO);
	else if (state == SLEEPING)
		ft_putendl_fd(SLEEPING_MSG, STDOUT_FILENO);
	else if (state == THINKING)
		ft_putendl_fd(THINKING_MSG, STDOUT_FILENO);
	else if (state == DIED)
		ft_putendl_fd(DIED_MSG, STDOUT_FILENO);
}

int	print_state(t_state state, t_philo *philo)
{
	long long	current;

	if (pthread_mutex_lock(&philo->info->print)
		|| !timestamp(&current))
		return (FALSE);
	ft_putnbr_fd(current - philo->info->start, STDOUT_FILENO);
	ft_putstr_fd("\t", STDOUT_FILENO);
	if (state == COMPLETE)
		ft_putendl_fd(COMPLETE_MSG, STDOUT_FILENO);
	else
	{
		ft_putnbr_fd(philo->index + 1, STDOUT_FILENO);
		print_messsge(state);
	}
	if (state == DIED || state == COMPLETE)
		return (FALSE);
	if (pthread_mutex_unlock(&philo->info->print))
		return (FALSE);
	return (TRUE);
}
