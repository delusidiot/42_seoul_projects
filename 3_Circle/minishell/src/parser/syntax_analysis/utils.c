/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 18:57:49 by jjeon             #+#    #+#             */
/*   Updated: 2022/02/12 18:57:50 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_cmd(t_cmd *cmd, t_user *user, t_ast *curr)
{
	if (cmd)
	{
		cmd->index = user->cmd_count;
		curr->type = COMMAND;
		curr->data = cmd;
	}
	else
		curr = NULL;
}

void	set_redirect_type(t_redirect *redirect, t_list **token)
{
	if (!ft_strncmp(((t_token *)(*token)->content)->value, "<<", 2))
		redirect->type = REDIRECT_HEREDOC;
	else if (!ft_strncmp(((t_token *)(*token)->content)->value, ">>", 2))
		redirect->type = REDIRECT_APPEND;
	else if (!ft_strncmp(((t_token *)(*token)->content)->value, "<", 1))
		redirect->type = REDIRECT_IN;
	else if (!ft_strncmp(((t_token *)(*token)->content)->value, ">", 1))
		redirect->type = REDIRECT_OUT;
}

int	analyzer_command(t_cmd *command)
{
	int		status;

	status = TRUE;
	if (!command->cmd)
		status = FALSE;
	return (status);
}
