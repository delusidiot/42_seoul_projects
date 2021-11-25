#include "philo_bonus.h"

static void	print_msg(t_state state)
{
	if (state == TAKEN)
	{
		ft_putstr_fd(BYEL, STDOUT_FILENO);
		ft_putendl_fd(TAKEN_MSG, STDOUT_FILENO);
	}
	else if (state == EATING)
	{
		ft_putstr_fd(BRED, STDOUT_FILENO);
		ft_putendl_fd(EATING_MSG, STDOUT_FILENO);
	}
	else if (state == SLEEPING)
	{
		ft_putstr_fd(CYN, STDOUT_FILENO);
		ft_putendl_fd(SLEEPING_MSG, STDOUT_FILENO);
	}
	else if (state == THINKING)
	{
		ft_putstr_fd(BBLU, STDOUT_FILENO);
		ft_putendl_fd(THINKING_MSG, STDOUT_FILENO);
	}
	else if (state == DIED)
	{
		ft_putstr_fd(RED, STDOUT_FILENO);
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
		ft_putstr_fd(BWHT, STDOUT_FILENO);
		ft_putendl_fd(COMPLETE_MSG, STDOUT_FILENO);
	}
	else
	{
		ft_putstr_fd(BWHT, STDOUT_FILENO);
		ft_putnbr_fd(info->index + 1, STDOUT_FILENO);
		print_msg(state);
	}
	ft_putstr_fd(EOC, STDOUT_FILENO);
	if (state == DIED || state == COMPLETE)
		return (FALSE);
	if (sem_post(info->sem_print) == _ERROR)
		return (FALSE);
	return (TRUE);
}
