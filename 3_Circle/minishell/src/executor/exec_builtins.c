#include "minishell.h"

int		exec_builtins(t_user *user, t_cmd *cmd)
{
	int	status;

	(void)user;
	if (!ft_strncmp(cmd->cmd, "cd", ft_strlen(cmd->cmd)))
		status = TRUE;
	else if (!ft_strncmp(cmd->cmd, "echo", ft_strlen(cmd->cmd)))
		status = TRUE;
	else if (!ft_strncmp(cmd->cmd, "pwd", ft_strlen(cmd->cmd)))
		status = TRUE;
	else if (!ft_strncmp(cmd->cmd, "env", ft_strlen(cmd->cmd)))
		status = TRUE;
	else if (!ft_strncmp(cmd->cmd, "export", ft_strlen(cmd->cmd)))
		status = TRUE;
	else if (!ft_strncmp(cmd->cmd, "unset", ft_strlen(cmd->cmd)))
		status = TRUE;
	else if (!ft_strncmp(cmd->cmd, "exit", ft_strlen(cmd->cmd)))
		exit(errno);
	printf("exec_builtins : %s\n", cmd->cmd);
	return (status);
}

int		is_builtins(t_cmd *cmd)
{
	if (!ft_strncmp(cmd->cmd, "cd", ft_strlen(cmd->cmd)) || \
		!ft_strncmp(cmd->cmd, "echo", ft_strlen(cmd->cmd)) || \
		!ft_strncmp(cmd->cmd, "pwd", ft_strlen(cmd->cmd)) || \
		!ft_strncmp(cmd->cmd, "env", ft_strlen(cmd->cmd)) || \
		!ft_strncmp(cmd->cmd, "export", ft_strlen(cmd->cmd)) || \
		!ft_strncmp(cmd->cmd, "unset", ft_strlen(cmd->cmd)) || \
		!ft_strncmp(cmd->cmd, "exit", ft_strlen(cmd->cmd)))
		return (TRUE);
	return (FALSE);
}