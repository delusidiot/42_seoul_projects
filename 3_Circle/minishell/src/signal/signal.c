#include "minishell.h"

static void	signal_handler(int signo)
{
	pid_t	pid;
	int	status;

	pid = waitpid(-1, &status, WNOHANG);
	if (signo == SIGINT)
	{

	}
	else if (signo == SIGQUIT)
	{

	}
}

void	set_signal(void)
{
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, signal_handler);
}