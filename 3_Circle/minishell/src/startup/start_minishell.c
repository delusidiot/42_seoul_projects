#include "minishell.h"

void	init_user(t_user *user)
{
	user->username = getenv("USER");
	user->home_dir = getenv("HOME");
	user->pwd = getcwd(NULL, 1024);
	user->exit_status = 0;
}

void	free_user(t_user *user)
{
	(void)user;
	//free(user->pwd);
}