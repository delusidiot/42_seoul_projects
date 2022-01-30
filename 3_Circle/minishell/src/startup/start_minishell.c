#include "minishell.h"

void	startup_shell(t_user *user)
{
	(void)user;
	set_signal();
	errno = EXIT_SUCCESS;
}

void	init_user(t_user *user)
{
	user->username = getenv(ENV_USER);
	if (!user->username)
		user->username = "minishell";
	user->home_dir = getenv(ENV_HOME);
	if (!user->home_dir)
		user->home_dir = "";
	user->pwd = getcwd(NULL, 1024);
	if (!user->pwd)
		exception();
	user->path = getenv(ENV_PATH);
	if (!user->path)
		user->path = "";
	user->pipe_in = STDIN_FILENO;
	user->stdin_fd = 0;
	user->stdout_fd = 0;
}

void	free_user(t_user *user)
{
	(void)user;
	free(user->pwd);
	// pipe_list free...
}