/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_exception.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 09:31:33 by jjeon             #+#    #+#             */
/*   Updated: 2022/02/12 09:31:34 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	put_exec_cmd_errno(char *cmd)
{
	ft_putstr_fd(ERR_PROMPT, STDERR_NO);
	ft_putstr_fd(cmd, STDERR_NO);
	ft_putstr_fd(": ", STDERR_NO);
	ft_putstr_fd(strerror(errno), STDERR_NO);
	ft_putstr_fd("\n", STDERR_NO);
	return (FALSE);
}

int	put_exec_errno(void)
{
	ft_putstr_fd(ERR_PROMPT, STDERR_NO);
	ft_putstr_fd(strerror(errno), STDERR_NO);
	ft_putstr_fd("\n", STDERR_NO);
	return (FALSE);
}

int	command_not_found_exception(char *cmd)
{
	ft_putstr_fd(cmd, STDERR_NO);
	ft_putstr_fd(": command not found.", STDERR_NO);
	ft_putstr_fd("\n", STDERR_NO);
	return (127);
}

void	*put_exec_errno_null(void)
{
	put_exec_errno();
	return (NULL);
}

int	exec_malloc_exception(void)
{
	errno = ENOMEM;
	put_exec_errno();
	return (FALSE);
}
