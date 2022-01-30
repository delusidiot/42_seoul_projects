#include "minishell.h"

static int	syntax_arguments(t_cmd *cmd, t_list **arg, t_token *token, t_list **list)
{
	if (!cmd->args)
	{
		cmd->args = ft_lstnew(token->value);
		if (!cmd->args)
			return (0);
		*arg = cmd->args;
	}
	else
	{
		(*arg)->next = ft_lstnew(token->value);
		if (!(*arg)->next)
			return (0);
		(*arg) = (*arg)->next;
	}
	if (!(*list)->next)
		cmd->is_last = TRUE;
	token->value = NULL;
	return (1);
}

static int	syntax_command(t_cmd **cmd, t_list **token)
{
	(*cmd) = malloc(sizeof(t_cmd));
	if (!(*cmd))
		return (0);
	(*cmd)->cmd = ((t_token *)(*token)->content)->value;
	(*cmd)->args = NULL;
	if ((*token)->next)
		(*cmd)->is_last = FALSE;
	else
		(*cmd)->is_last = TRUE;
	((t_token *)(*token)->content)->value = NULL;
	return (1);
}

static int	syntax_redirect(t_AST **curr, t_list **token)
{
	t_redirect	*redirect;

	(*curr)->data = malloc(sizeof(t_redirect));
	if (!(*curr)->data)
		return (0);
	redirect = (*curr)->data;
	(*curr)->type = REDIRECT;
	if (!ft_strncmp(((t_token *)(*token)->content)->value, "<<", 2))
		redirect->type = REDIRECT_HEREDOC;
	else if (!ft_strncmp(((t_token *)(*token)->content)->value, ">>", 2))
		redirect->type = REDIRECT_APPEND;
	else if (!ft_strncmp(((t_token *)(*token)->content)->value, "<", 1))
		redirect->type = REDIRECT_IN;
	else if (!ft_strncmp(((t_token *)(*token)->content)->value, ">", 1))
		redirect->type = REDIRECT_OUT;
	*token = (*token)->next;
	if (!(*token))
		return (0);
	redirect->file = ((t_token *)(*token)->content)->value;
	((t_token *)(*token)->content)->value = NULL;
	redirect->ast = malloc(sizeof(t_AST));
	if (!redirect->ast)
		return (0);
	*curr = redirect->ast;
	return (1);
}

static int	syntax_switch (
	t_list **token,
	t_cmd **cmd,
	t_list **arg_curr,
	t_AST **curr)
{
	if (((t_token *)(*token)->content)->type == COMMAND && !(*cmd))
	{
		if (!syntax_command(cmd, token))
			return (0);
	}
	else if (((t_token *)(*token)->content)->type == COMMAND)
	{
		if (!syntax_arguments(*cmd, arg_curr, (*token)->content, token))
			return (0);
	}
	else if (((t_token *)(*token)->content)->type == REDIRECT)
	{
		if (!syntax_redirect(curr, token))
			return (0);
	}
	return (1);
}

t_AST	*syntax_cmd(t_list **token) 
{
	t_AST	*result;
	t_AST	*curr;
	t_list	*arg_curr;
	t_cmd	*cmd;

	result = malloc(sizeof(t_AST));
	if (!result)
		return (malloc_exception());
	curr = result;
	cmd = NULL;
	while (*token && \
		(((t_token *)(*token)->content)->type == COMMAND || \
		((t_token *)(*token)->content)->type == REDIRECT))
	{
		if (!syntax_switch(token, &cmd, &arg_curr, &curr))
			return (malloc_exception()); // change free memories;
		*token = (*token)->next;
	}
	curr->type = COMMAND;
	curr->data = cmd;
	return (result);
}