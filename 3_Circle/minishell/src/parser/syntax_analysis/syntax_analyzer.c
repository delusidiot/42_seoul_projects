/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_analyzer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 09:32:03 by jjeon             #+#    #+#             */
/*   Updated: 2022/02/12 09:32:03 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	analyzer_redirect(t_redirect *redirect, t_ast_type prev)
{
	int		status;
	char	*type;

	status = TRUE;
	if (prev != REDIRECT)
		type = "newline";
	else if (redirect->type == REDIRECT_APPEND)
		type = ">>";
	else if (redirect->type == REDIRECT_OUT)
		type = ">";
	else if (redirect->type == REDIRECT_HEREDOC)
		type = "<<";
	else if (redirect->type == REDIRECT_IN)
		type = "<";
	else
		type = "NULL";
	if (redirect->ast)
		status = analyzer_ast(redirect->ast, REDIRECT);
	if (!redirect->file && status == TRUE)
		return (syntax_error(type));
	return (status);
}

static int	analyzer_pipe(t_pipe *pipe)
{
	int	status;

	status = TRUE;
	if (pipe->left)
		status = analyzer_ast(pipe->left, PIPE);
	else
		return (syntax_error("|"));
	if (pipe->right)
		status = analyzer_ast(pipe->right, PIPE);
	else
		return (syntax_error("|"));
	return (status);
}

static int	analyzer_operator(t_operator *operator)
{
	char	*type;
	int		status;

	status = TRUE;
	if (operator->type == OPERATOR_AND)
		type = "&&";
	else if (operator->type == OPERATOR_OR)
		type = "||";
	else
		type = "";
	if (operator->left)
		status = analyzer_ast(operator->left, OPERATOR);
	else
		return (syntax_error(type));
	if (operator->right)
		status = analyzer_ast(operator->right, OPERATOR);
	else
		return (syntax_error(type));
	return (status);
}

int	analyzer_ast(t_ast *ast, t_ast_type prev)
{
	if (ast->type == COMMAND)
		return (analyzer_command(ast->data));
	else if (ast->type == REDIRECT)
		return (analyzer_redirect(ast->data, prev));
	else if (ast->type == PIPE)
		return (analyzer_pipe(ast->data));
	else if (ast->type == OPERATOR)
		return (analyzer_operator(ast->data));
	return (TRUE);
}

t_ast	*syntax_analyzer(t_user *user, t_list *token)
{
	t_list	*curr_token;
	t_ast	*ast;

	if (!token)
		return (NULL);
	curr_token = token;
	ast = syntax_ast(user, &curr_token);
	if (!ast)
		return (malloc_exception());
	if (!analyzer_ast(ast, NONE))
	{
		user->exit_status = 2;
		free_ast(ast);
		return (NULL);
	}
	return (ast);
}
