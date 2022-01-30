#include "minishell.h"

static int	analyzer_redirect(t_redirect *redirect)
{
	int status;

	status = TRUE;
	if (!redirect->file)
		return (syntax_error("newline"));
	if (redirect->ast->data)
		status = analyzer_ast(redirect->ast);
	else
		return (syntax_error("newline"));
	return (status);
}

static int	analyzer_pipe(t_pipe *pipe)
{
	int status;

	status = TRUE;
	if (pipe->left->data)
		status = analyzer_ast(pipe->left);
	else
		return (syntax_error("|"));
	if (pipe->right->data)
		status =  analyzer_ast(pipe->right);
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
	if (operator->left->data)
		status = analyzer_ast(operator->left);
	else
		return (syntax_error(type));
	if (operator->right->data)
		status  = analyzer_ast(operator->right);
	else
		return (syntax_error(type));
	return (status);
}

int	analyzer_ast(t_AST *AST)
{
	if (AST->type == COMMAND)
		return (TRUE);
	else if(AST->type == REDIRECT)
		return (analyzer_redirect(AST->data));
	else if(AST->type == PIPE)
		return (analyzer_pipe(AST->data));
	else if(AST->type == OPERATOR)
		return (analyzer_operator(AST->data));
	return (TRUE);
}

t_AST	*syntax_analyzer(t_list *token)
{
	t_list	*curr_token;
	t_AST	*AST;

	curr_token = token;
	AST = syntax_AST(&curr_token);
	if (!AST)
		return (NULL); // change free memories
	if (!analyzer_ast(AST))
	{
		free_AST(AST);
		return (NULL);
	}
	ft_lstclear(&token, del_token);
	return (AST);
}