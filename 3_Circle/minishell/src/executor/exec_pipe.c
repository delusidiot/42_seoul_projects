#include "minishell.h"

void	parent_process(t_user *user, t_cmd *cmd)
{
	(void)cmd;
	
	if (user->stdin_fd && user->stdout_fd)
	{
		close(user->pipefd[WRITE]);
		close(user->pipefd[READ]);
		if (user->pipe_in != STDIN_FILENO)
			close(user->pipe_in);
		user->pipe_in = STDIN_FILENO;
	}
	else if (user->stdin_fd)
	{
		close(user->pipefd[WRITE]);
		user->pipe_in = user->pipefd[READ];
	}
	else if (user->stdout_fd)
	{
		close(user->pipefd[READ]);
		close(user->pipefd[WRITE]);
		if (user->pipe_in)
			close(user->pipe_in);
		user->pipe_in = STDIN_FILENO;
	}
	else
	{
		close(user->pipefd[WRITE]);
		user->pipe_in = user->pipefd[READ];
	}
}

void	child_process_close(t_user *user, t_cmd *cmd)
{
	(void)user;
	(void)cmd;
	if (user->stdin_fd && user->stdout_fd)
		return ;
	else if (user->stdin_fd)
	{
		close(user->pipefd[READ]);
	}
	else if (user->stdout_fd)
		return ;
	else
	{
		close(user->pipefd[READ]);
	}
}

void	child_process(t_user *user, t_cmd *cmd)
{
	if (user->stdin_fd && user->stdout_fd)
	{
		close(user->pipefd[WRITE]);
		close(user->pipefd[READ]);
		dup2(user->stdin_fd, STDIN_FILENO);
		dup2(user->stdout_fd, STDOUT_FILENO);
	}
	else if (user->stdin_fd)
	{
		close(user->pipefd[READ]);
		dup2(user->stdin_fd, STDIN_FILENO);
		if (user->pipe_in != STDIN_FILENO)
			dup2(user->pipefd[WRITE], STDOUT_FILENO);
		user->stdin_fd = 0;
	}
	else if (user->stdout_fd)
	{
		close(user->pipefd[READ]);
		close(user->pipefd[WRITE]);
		if (user->pipe_in != STDIN_FILENO)
			dup2(user->pipe_in, STDIN_FILENO);
		dup2(user->stdout_fd, STDOUT_FILENO);
	}
	else
	{
		close(user->pipefd[READ]);
		if (user->pipe_in)
			dup2(user->pipe_in, STDIN_FILENO);
		if (!cmd->is_last)
			dup2(user->pipefd[WRITE], STDOUT_FILENO);
	}
}

int	exec_pipe(t_user *user, t_pipe *pipe_ast)
{
	int	status;

	if (!user || !pipe_ast)
		return (FALSE);
	fd_init(user);
	status = exec_ast(user, pipe_ast->left);
	if (status == FALSE)
		return (status);
	fd_init(user);
	status = exec_ast(user, pipe_ast->right);
	return (status);
}