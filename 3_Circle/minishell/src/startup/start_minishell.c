#include "minishell.h"

void	startup_shell(t_user *user)
{
	init_user(user);
}

void	init_user(t_user *user)
{
	user->username = getenv(ENV_USER);
	user->home_dir = getenv(ENV_HOME);
	user->pwd = getcwd(NULL, 1024);
	user->path = getenv(ENV_PATH);
	user->exit_status = 0;
}

void	free_user(t_user *user)
{
	(void)user;
	//free(user->pwd);
}