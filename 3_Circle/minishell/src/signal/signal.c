#include "minishell.h"

static void sigint_handler(int signo)
{
	pid_t	pid;
	int		status;

	pid = waitpid(-1, &status, WNOHANG);
	if (signo == SIGINT && pid == -1)
	{
		rl_on_new_line();
		rl_replace_line("", 0);
		ft_putstr_fd("\n", STDOUT_FILENO);
		rl_redisplay();
	}
}

static void sigquit_handler(int signo)
{
	(void)signo;
	ft_putstr_fd("\b\b  \b\b", STDOUT_FILENO);
	return ;
}

void	set_signal(void)
{
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, sigquit_handler);
}