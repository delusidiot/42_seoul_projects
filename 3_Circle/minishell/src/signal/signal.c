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
		//test
		exit(0);
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

int		status_signal_handler(int status)
{
	int	sig;

	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	if (WIFSIGNALED(status))
	{
		sig = WTERMSIG(status);
		if (sig == SIGINT)
			return (EOWNERDEAD);
		if (sig == SIGQUIT)
		{
			ft_putstr_fd("Quit\n", STDOUT_FILENO);
			return (ENOTRECOVERABLE);
		}
		if (sig == SIGPIPE)// test
			ft_putstr_fd("PIPE ERROR\n", STDOUT_FILENO);
		return (EKEYREVOKED + sig);
	}
	return (EPERM);
}