/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ast_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 09:32:05 by jjeon             #+#    #+#             */
/*   Updated: 2022/02/12 09:32:06 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

void	print_command(t_cmd *cmd)
{
	t_list	*curr;

	if (!cmd)
		return ;
	curr = cmd->args;
	printf("{ \n");
	printf("\tcmd -> \"%s\"\n", cmd->cmd);
	printf("\t\"idx: %d\"", cmd->index);
	printf("\t\"blevel: %d\"\n", cmd->brace_level);
	if (cmd->is_last == TRUE)
		printf("\t\"Last\"\n");
	if (cmd->cmd_last == TRUE)
		printf("\t\"CMD_Last\"\n");
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
	char	*type;

	if (!redirect)
		return ;
	printf("{ \n");
	if (redirect->type == REDIRECT_APPEND)
		type = "REDIRECT_APPEND";
	else if (redirect->type == REDIRECT_HEREDOC)
		type = "REDIRECT_HEREDOC";
	else if (redirect->type == REDIRECT_IN)
		type = "REDIRECT_IN";
	else if (redirect->type == REDIRECT_OUT)
		type = "REDIRECT_OUT";
	else
		type = "NULL";
	printf("\tredirect -> %s", type);
	printf("\tfile -> %s", redirect->file);
	if (redirect->ast)
	{
		if (redirect->ast->type == NONE)
			printf("\tNONE ");
		print_ast(redirect->ast);
	}
	printf("}\n");
}

void	print_pipe(t_pipe *pipe)
{
	if (!pipe)
		return ;
	printf("{ \n");
	printf("\tPIPE\n");
	printf("\tleft->\n");
	if (pipe->left)
		print_ast(pipe->left);
	else
		printf("\tNULL\n");
	printf("\tright->\n");
	if (pipe->right)
		print_ast(pipe->right);
	else
		printf("\tNULL\n");
	printf("}\n");
}

void	print_operator(t_operator *operator)
{
	char	*type;

	if (!operator)
		return ;
	if (operator->type == OPERATOR_AND)
		type = "OPERATOR_AND";
	else if (operator->type == OPERATOR_OR)
		type = "OPERATOR_OR";
	else
		type = "NULL";
	printf("{ \n");
	printf("\t%s\tblevel: %d\n", type, operator->brace_level);
	printf("\tleft->\n");
	if (operator->left)
		print_ast(operator->left);
	else
		printf("\tNULL\n");
	printf("\tright->\n");
	if (operator->right)
		print_ast(operator->right);
	else
		printf("\tNULL\n");
	printf("}\n");
}

void	print_ast(t_ast *ast)
{
	if (!ast)
		return ;
	if (ast->type == COMMAND && ast->data)
		print_command(ast->data);
	else if (ast->type == REDIRECT && ast->data)
		print_redirect(ast->data);
	else if (ast->type == PIPE && ast->data)
		print_pipe(ast->data);
	else if (ast->type == OPERATOR && ast->data)
		print_operator(ast->data);
}
