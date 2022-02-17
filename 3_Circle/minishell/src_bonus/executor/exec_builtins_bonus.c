/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtins_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 09:31:24 by jjeon             #+#    #+#             */
/*   Updated: 2022/02/13 13:32:53 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

int	exec_builtins(t_user *user, t_cmd *cmd)
{
	int	status;

	status = 0;
	if (!ft_strncmp(cmd->cmd, "cd", ft_strlen(cmd->cmd)))
		status = ft_cd(user, cmd->args);
	else if (!ft_strncmp(cmd->cmd, "echo", ft_strlen(cmd->cmd)))
		status = ft_echo(cmd->args);
	else if (!ft_strncmp(cmd->cmd, "pwd", ft_strlen(cmd->cmd)))
	{
		ft_putstr_fd(user->pwd, STDOUT_NO);
		ft_putstr_fd("\n", STDOUT_NO);
		status = 0;
	}
	else if (!ft_strncmp(cmd->cmd, "env", ft_strlen(cmd->cmd)))
		status = ft_env(user);
	else if (!ft_strncmp(cmd->cmd, "export", ft_strlen(cmd->cmd)))
		status = ft_export(user, cmd->args);
	else if (!ft_strncmp(cmd->cmd, "unset", ft_strlen(cmd->cmd)))
		status = ft_unset(user, cmd->args);
	else if (!ft_strncmp(cmd->cmd, "exit", ft_strlen(cmd->cmd)))
		status = ft_exit(user, cmd->args);
	else
		return (FALSE);
	user->exit_status = status;
	return (status);
}

int	is_builtins(t_cmd *cmd)
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
