#include "minishell.h"

void	print_commands(char *full, char **args)
{
	int i;

	i = -1;
	ft_putstr_fd(GRN, STDERR_FILENO);
	ft_putstr_fd("exec command: ", STDERR_FILENO);
	ft_putstr_fd(full, STDERR_FILENO);
	ft_putstr_fd(" -> ", STDERR_FILENO);
	while (args[++i])
	{
		ft_putstr_fd(args[i], STDERR_FILENO);
		ft_putstr_fd(" ", STDERR_FILENO);
	}
	ft_putstr_fd("\n", STDERR_FILENO);
	ft_putstr_fd(WHT, STDERR_FILENO);
	ft_putstr_fd(EOC, STDERR_FILENO);
}

int	start_command(t_user *user, t_cmd *cmd)
{
	char	*full_cmd;
	char	**args;

	full_cmd = get_add_env_path(getenv(ENV_PATH), cmd); //change path to env path ..
	if (!full_cmd)
		return (command_not_found_exception(cmd->cmd));
	args = get_args(cmd);
	if (!args)
		return (exec_malloc_exception());
	print_commands(full_cmd, args);
	if (execve(full_cmd, args, user->g_env) < 0)
	{
		free(args);
		return (put_exec_errno());
	}
	return (errno);
}

int	set_command_process(t_user *user, t_cmd *cmd)
{
	pid_t	pid;
	int		status;
	
	pipe(user->pipefd);
	pid = fork();
	status = TRUE;
	if (pid < 0)
		return (put_exec_errno());
	else if (pid > 0)
		parent_process(user, cmd);
	else
	{
		child_process(user, cmd);
		if (is_builtins(cmd))
			status = exec_builtins(user, cmd);
		else
			status = start_command(user, cmd);
		//child_process_close(user, cmd);
		exit(errno);
	}
	return (status);
}

int	exec_command(t_user *user, t_cmd *cmd)
{
	int		status;

	if (!cmd || !user)
		return (FALSE);
	if (is_builtins(cmd) && cmd->is_last)
		status = exec_builtins(user, cmd); // builtin logic
	else
		status = set_command_process(user, cmd);
	(void)status;
	return (TRUE);
}