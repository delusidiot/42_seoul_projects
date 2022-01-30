#include "minishell.h"

void	print_command(t_cmd *cmd)
{
	t_list	*curr;

	if (!cmd)
		return;
	curr = cmd->args;
	printf("{ \n");
	printf("\tcmd -> \"%s\"\n", cmd->cmd);
	if (cmd->is_last)
		printf("\t\"LAST\"\n");
	printf("\targs -> ");
	while (curr)
	{
		printf("\t \"%s\"\t", (char *)curr->content);
		curr = curr->next;
	}
	printf("}\n");
}

void	print_redirect(t_redirect *redirect)
{
	char *type;

	if (!redirect)
		return;
	printf("{ \n");
	if (redirect->type == REDIRECT_APPEND)
		type = "REDIRECT_APPEND";
	else if (redirect->type == REDIRECT_HEREDOC)
		type = "REDIRECT_HEREDOC";
	else if (redirect->type == REDIRECT_IN)
		type = "REDIRECT_IN";
	else if (redirect->type == REDIRECT_OUT)
		type = "REDIRECT_OUT";
	printf("\tredirect -> %s", type);
	printf("\tfile -> %s", redirect->file);
	if (redirect->ast->data)
		print_ast(redirect->ast);
	printf("}\n");
}

void	print_pipe(t_pipe *pipe)
{
	if (!pipe)
		return ;
	printf("{ \n");
	printf("\tPIPE\n");
	printf("\tleft->\n");
	if (pipe->left->data)
		print_ast(pipe->left);
	else
		printf("\tNULL\n");
	printf("\tright->\n");
	if (pipe->right->data)
		print_ast(pipe->right);
	else
		printf("\tNULL\n");
	printf("}\n");
}

void	print_operator(t_operator *operator)
{
	char *type;

	if (!operator)
		return ;
	if (operator->type == OPERATOR_AND)
		type = "OPERATOR_AND";
	else if (operator->type == OPERATOR_OR)
		type = "OPERATOR_OR";
	printf("{ \n");
	printf("\t%s\n", type);
	printf("\tleft->\n");
	if (operator->left->data)
		print_ast(operator->left);
	else
		printf("\tNULL\n");
	printf("\tright->\n");
	if (operator->right->data)
		print_ast(operator->right);
	else
		printf("\tNULL\n");
	printf("}\n");
}

void	print_ast(t_AST *AST)
{
	if (!AST)
		return ;
	if (AST->type == COMMAND)
		print_command(AST->data);
	else if(AST->type == REDIRECT)
		print_redirect(AST->data);
	else if(AST->type == PIPE)
		print_pipe(AST->data);
	else if(AST->type == OPERATOR)
		print_operator(AST->data);
}