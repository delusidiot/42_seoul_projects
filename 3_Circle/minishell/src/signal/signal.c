/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 09:30:08 by jjeon             #+#    #+#             */
/*   Updated: 2022/02/14 12:53:59 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	command_signal_handler(int signo)
{
	if (signo == SIGINT)
	{
		rl_on_new_line();
		rl_replace_line("", 0);
		ft_putstr_fd("\n", STDOUT_NO);
		rl_redisplay();
	}
	else if (signo == SIGQUIT)
		ft_putstr_fd("\b\b  \b\b", STDOUT_NO);
}

static void	exec_signal_handler(int signo)
{
	if (signo == SIGINT)
		ft_putstr_fd("\n", STDOUT_NO);
	else if (signo == SIGQUIT)
		ft_putstr_fd("", STDOUT_NO);
}

void	set_command_signal(void)
{
	signal(SIGINT, command_signal_handler);
	signal(SIGQUIT, SIG_IGN);
}

void	set_exec_signal(void)
{
	signal(SIGINT, exec_signal_handler);
	signal(SIGQUIT, exec_signal_handler);
}

int	status_signal_handler(int status)
{
	int	sig;

	sig = 0;
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	if (WIFSIGNALED(status))
	{
		sig = WTERMSIG(status);
		if (sig == SIGINT)
			return (EOWNERDEAD);
		if (sig == SIGQUIT)
		{
			ft_putstr_fd("Quit\n", STDOUT_NO);
			return (131);
		}
		return (128 + sig);
	}
	return (EPERM);
}
