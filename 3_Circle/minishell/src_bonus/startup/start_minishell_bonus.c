/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_minishell_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 09:30:03 by jjeon             #+#    #+#             */
/*   Updated: 2022/02/13 13:45:22 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

void	startup_shell(t_user *user, char **envp)
{
	(void)user;
	errno = EXIT_SUCCESS;
	user->g_env = 0;
	user->env_size = 0;
	user->underscore_flag = 0;
	user->exit_status = 0;
	set_env_var(user, envp);
	user->home_dir = ft_strdup(get_env(user->g_env, ENV_HOME));
	if (!user->home_dir)
		user->home_dir = ft_strdup("");
}

void	init_user(t_user *user)
{
	user->username = get_env(user->g_env, ENV_USER);
	if (!user->username)
		user->username = "minishell";
	user->pwd = getcwd(NULL, 1024);
	if (!user->pwd)
	{
		user->pwd = ft_strdup("");
		exception();
	}
	user->pipe_in = NULL;
	user->cmd_count = 1;
	user->stdin_fd = 0;
	user->stdout_fd = 0;
	user->brace_level_count = 0;
	user->last = NULL;
	user->oper_state = S_NONE;
}

void	free_user(t_user *user)
{
	(void)user;
	free(user->pwd);
}
