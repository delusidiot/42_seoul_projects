#include "minishell.h"

void	free_command(t_cmd *cmd)
{
	if (cmd)
	{
		if (cmd->cmd)
			free(cmd->cmd);
		ft_lstclear(&cmd->args, free);
		free(cmd);
	}
}

void	free_pipe(t_pipe *pipe)
{
	if (pipe)
	{
		free_AST(pipe->left);
		free_AST(pipe->right);
		free(pipe);
	}
}

void free_operator(t_operator *operator)
{
	if(operator)
	{
		free_AST(operator->left);
		free_AST(operator->right);
		free(operator);
	}
}

void free_redirect(t_redirect *redirect)
{
	if (redirect)
	{
		free_AST(redirect->ast);
		if (redirect->file)
			free(redirect->file);
		free(redirect);
	}
}

void	free_AST(void *data)
{
	t_AST *AST;

	AST = data;
	if (!AST)
		return ;
	if (AST->type == COMMAND && AST->data)
		free_command(AST->data);
	else if(AST->type == PIPE && AST->data)
		free_pipe(AST->data);
	else if(AST->type == OPERATOR && AST->data)
		free_operator(AST->data);
	else if(AST->type == REDIRECT && AST->data)
		free_redirect(AST->data);
	if (AST)
		free(AST);
}