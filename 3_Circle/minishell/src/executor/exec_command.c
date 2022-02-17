/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 09:31:22 by jjeon             #+#    #+#             */
/*   Updated: 2022/02/14 13:21:04 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*in_currdir(t_cmd *cmd)
{
	struct stat	buf;

	if (!(stat(cmd->cmd, &buf)))
		return (ft_strdup(cmd->cmd));
	return (NULL);
}

static char	*get_add_env_path(char *path, t_cmd *cmd)
{
	int			i;
	char		*temp;
	char		**paths;
	struct stat	buf;

	i = -1;
	paths = ft_split(path, ':');
	if (!paths)
		return (NULL);
	while (paths[++i])
	{
		temp = join_path(paths[i], cmd->cmd);
		if (!(stat(temp, &buf)))
		{
			while (paths[i])
				free(paths[i++]);
			free(paths);
			return (temp);
		}
		free(paths[i]);
		free(temp);
	}
	free(paths);
	return (in_currdir(cmd));
}

int	start_command(t_user *user, t_cmd *cmd)
{
	char	*full_cmd;
	char	**args;
	char	**envp;
	char	*path;

	path = get_env(user->g_env, ENV_PATH);
	if (!path)
		full_cmd = ft_strdup(cmd->cmd);
	else
	{
		full_cmd = get_add_env_path(path, cmd);
		if (!full_cmd)
			return (command_not_found_exception(cmd->cmd));
	}
	args = get_args(user, cmd);
	if (!args)
		return (exec_malloc_exception());
	envp = change_lst_to_arr(user);
	if (execve(full_cmd, args, envp) < 0)
	{
		free(full_cmd);
		free(args);
		return (put_exec_cmd_errno(cmd->cmd));
	}
	return (errno);
}

int	set_command_process(t_user *user, t_cmd *cmd)
{
	pid_t	pid;
	int		pipefd[2];

	if (user->oper_state == S_NONE || user->oper_state == S_FIRST)
	{
		pipe(pipefd);
		user->pipe_in[cmd->index] = pipefd[READ];
		user->pipe_out[cmd->index] = pipefd[WRITE];
	}
	pid = fork();
	cmd->pid = pid;
	if (pid < 0)
		return (put_exec_errno());
	else if (pid > 0)
		parent_process(user, cmd);
	else
	{
		if (user->oper_state == S_FAIL)
			exit(user->exit_status);
		child_process(user, cmd);
		exit(user->exit_status);
	}
	if (!user->exit_status)
		return (TRUE);
	return (FALSE);
}

int	exec_command(t_user *user, t_cmd *cmd)
{
	int		status;

	if (!cmd || !user)
		return (FALSE);
	status = TRUE;
	if (is_builtins(cmd) && user->cmd_count == 1)
	{
		status = exec_builtins(user, cmd);
		underscore(user, cmd->cmd, cmd->args);
	}
	else
		status = set_command_process(user, cmd);
	return (status);
}
