/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_cmd_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 09:31:56 by jjeon             #+#    #+#             */
/*   Updated: 2022/02/12 09:31:58 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

static int	syntax_arguments(t_cmd *cmd, t_token *token)
{
	t_list	*next;

	if (!cmd->args)
	{
		cmd->args = ft_lstnew(token->value);
		if (!cmd->args)
			return (FALSE);
	}
	else
	{
		next = ft_lstnew(token->value);
		if (!next)
			return (FALSE);
		ft_lstadd_back(&cmd->args, next);
	}
	token->value = NULL;
	return (TRUE);
}

static int	syntax_command(t_cmd **cmd, t_list **token)
{
	(*cmd) = malloc(sizeof(t_cmd));
	if (!(*cmd))
		return (FALSE);
	(*cmd)->cmd = ((t_token *)(*token)->content)->value;
	((t_token *)(*token)->content)->value = NULL;
	(*cmd)->args = NULL;
	(*cmd)->is_last = ((t_token *)(*token)->content)->is_last;
	(*cmd)->cmd_last = ((t_token *)(*token)->content)->cmd_last;
	(*cmd)->brace_level = ((t_token *)(*token)->content)->brace_level;
	return (TRUE);
}

static int	syntax_redirect(t_ast **curr, t_list **token)
{
	t_redirect	*redirect;

	(*curr)->data = malloc(sizeof(t_redirect));
	if (!(*curr)->data)
		return (FALSE);
	(*curr)->type = REDIRECT;
	redirect = (*curr)->data;
	set_redirect_type(redirect, token);
	redirect->ast = malloc(sizeof(t_ast));
	if (!redirect->ast)
		return (FALSE);
	if (!(*token)->next || \
			(((t_token *)((*token)->next->content))->type != COMMAND))
		redirect->file = NULL;
	else
	{
		*token = (*token)->next;
		redirect->file = ((t_token *)(*token)->content)->value;
		((t_token *)(*token)->content)->value = NULL;
	}	
	*curr = redirect->ast;
	return (TRUE);
}

static int	syntax_switch(t_list **token, t_cmd **cmd, t_ast **curr)
{
	if (((t_token *)(*token)->content)->type == COMMAND && !(*cmd))
	{
		if (!syntax_command(cmd, token))
			return (FALSE);
	}
	else if (((t_token *)(*token)->content)->type == COMMAND)
	{
		if (!syntax_arguments(*cmd, (*token)->content))
			return (FALSE);
	}
	else if (((t_token *)(*token)->content)->type == REDIRECT)
	{
		if (!syntax_redirect(curr, token))
			return (FALSE);
	}
	return (TRUE);
}

t_ast	*syntax_cmd(t_user *user, t_list **token)
{
	t_ast	*result;
	t_ast	*curr;
	t_cmd	*cmd;

	result = malloc(sizeof(t_ast));
	if (!result)
		return (NULL);
	curr = result;
	cmd = NULL;
	while (*token && \
		(((t_token *)(*token)->content)->type == COMMAND || \
		((t_token *)(*token)->content)->type == REDIRECT))
	{
		if (!syntax_switch(token, &cmd, &curr))
		{
			free_ast(result);
			return (NULL);
		}
		*token = (*token)->next;
	}
	set_cmd(cmd, user, curr);
	return (result);
}
