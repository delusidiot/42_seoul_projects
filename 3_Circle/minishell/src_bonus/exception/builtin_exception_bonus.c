/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exception_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 02:39:22 by gjeon             #+#    #+#             */
/*   Updated: 2022/02/14 02:39:23 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

int	prt_err(char *type, char *content, int flag)
{
	char	*msg;
	char	*pull_msg;

	if (flag < 2 && ft_strncmp(type, "cd", 2) == 0)
	{
		if (flag == 1)
			pull_msg = err_msg_join(type, content, "HOME not set");
		else
			pull_msg = err_msg_join(type, content, "OLDPWD not set");
		flag = 1;
	}
	else if (flag == 1)
		pull_msg = err_msg_join(type, content, "too many arguments");
	else if (flag == 255)
		pull_msg = err_msg_join(type, content, "numeric argument required");
	else
	{
		msg = strerror(errno);
		pull_msg = err_msg_join(type, content, msg);
		flag = 1;
	}
	ft_putstr_fd(pull_msg, STDERR_NO);
	free(pull_msg);
	return (flag);
}
