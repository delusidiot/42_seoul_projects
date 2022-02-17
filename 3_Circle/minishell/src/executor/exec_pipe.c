/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 09:31:18 by jjeon             #+#    #+#             */
/*   Updated: 2022/02/14 13:29:36 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parent_process(t_user *user, t_cmd *cmd)
{
	int	status;

	status = 0;
	if (user->cmd_count == cmd->index && cmd->cmd_last == TRUE)
		user->last = cmd;
	if (cmd->cmd_last == TRUE)
		close(user->pipe_out[cmd->index]);
	if (user->oper_state != S_NONE)
	{
		waitpid(cmd->pid, &status, 0);
		user->exit_status = status_signal_handler(status);
	}
}

static void	child_process_sub(t_user *user, t_cmd *cmd)
{
	if (user->stdout_fd)
	{
		close(user->pipe_out[cmd->index]);
		dup2(user->pipe_in[cmd->index - 1], STDIN_NO);
		dup2(user->stdout_fd, STDOUT_NO);
		close(user->stdout_fd);
	}
	else
	{
		if (user->pipe_in[cmd->index - 1])
			dup2(user->pipe_in[cmd->index - 1], STDIN_NO);
		if (user->cmd_count != cmd->index && cmd->is_last)
			dup2(user->pipe_out[cmd->index], STDOUT_NO);
		close(user->pipe_out[cmd->index]);
	}
	if (is_builtins(cmd))
		user->exit_status = exec_builtins(user, cmd);
	else
		user->exit_status = start_command(user, cmd);
}

void	child_process(t_user *user, t_cmd *cmd)
{
	close(user->pipe_in[cmd->index]);
	if (user->stdin_fd && user->stdout_fd)
	{
		close(user->pipe_out[cmd->index]);
		dup2(user->stdin_fd, STDIN_NO);
		dup2(user->stdout_fd, STDOUT_NO);
		close(user->stdin_fd);
		close(user->stdout_fd);
	}
	else if (user->stdin_fd)
	{
		dup2(user->stdin_fd, STDIN_NO);
		if (user->cmd_count != cmd->index && cmd->is_last)
			dup2(user->pipe_out[cmd->index], STDOUT_NO);
		user->stdin_fd = 0;
		close(user->pipe_out[cmd->index]);
	}
	child_process_sub(user, cmd);
}

int	exec_pipe(t_user *user, t_pipe *pipe_ast)
{
	int		status;
	t_ops	prev;

	if (!user || !pipe_ast)
		return (FALSE);
	prev = user->oper_state;
	user->oper_state = S_NONE;
	fd_init(user);
	status = exec_ast(user, pipe_ast->left);
	fd_init(user);
	user->oper_state = prev;
	status = exec_ast(user, pipe_ast->right);
	return (status);
}
