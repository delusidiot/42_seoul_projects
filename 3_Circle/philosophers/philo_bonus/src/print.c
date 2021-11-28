/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 08:36:48 by jjeon             #+#    #+#             */
/*   Updated: 2021/11/28 21:54:32 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	print_messsge(t_state state)
{
	if (state == TAKEN)
	{
		ft_putstr_fd(CYN, STDOUT_FILENO);
		ft_putendl_fd(TAKEN_MSG, STDOUT_FILENO);
	}
	else if (state == EATING)
	{
		ft_putstr_fd(GRN, STDOUT_FILENO);
		ft_putendl_fd(EATING_MSG, STDOUT_FILENO);
	}
	else if (state == SLEEPING)
	{
		ft_putstr_fd(MAG, STDOUT_FILENO);
		ft_putendl_fd(SLEEPING_MSG, STDOUT_FILENO);
	}
	else if (state == THINKING)
	{
		ft_putstr_fd(YEL, STDOUT_FILENO);
		ft_putendl_fd(THINKING_MSG, STDOUT_FILENO);
	}
	else if (state == DIED)
	{
		ft_putstr_fd(BRED, STDOUT_FILENO);
		ft_putendl_fd(DIED_MSG, STDOUT_FILENO);
	}
}

int	print_state(t_state state, t_info *info)
{
	long long	current;

	if (sem_wait(info->sem_print) == _ERROR
		|| !timestamp(&current))
		return (FALSE);
	ft_putnbr_fd(current - info->start, STDOUT_FILENO);
	ft_putstr_fd("\t", STDOUT_FILENO);
	if (state == COMPLETE)
	{
		ft_putstr_fd(WHT, STDOUT_FILENO);
		ft_putendl_fd(COMPLETE_MSG, STDOUT_FILENO);
	}
	else
	{
		ft_putstr_fd(WHT, STDOUT_FILENO);
		ft_putnbr_fd(info->index + 1, STDOUT_FILENO);
		print_messsge(state);
	}
	ft_putstr_fd(EOC, STDOUT_FILENO);
	if (state == DIED || state == COMPLETE)
		return (FALSE);
	if (sem_post(info->sem_print) == _ERROR)
		return (FALSE);
	return (TRUE);
}
