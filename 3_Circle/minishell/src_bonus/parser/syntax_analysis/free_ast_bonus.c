/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ast_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 09:32:08 by jjeon             #+#    #+#             */
/*   Updated: 2022/02/12 09:32:09 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

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
		free_ast(pipe->left);
		free_ast(pipe->right);
		free(pipe);
	}
}

void	free_operator(t_operator *operator)
{
	if (operator)
	{
		free_ast(operator->left);
		free_ast(operator->right);
		free(operator);
	}
}

void	free_redirect(t_redirect *redirect)
{
	if (redirect)
	{
		free_ast(redirect->ast);
		if (redirect->file)
			free(redirect->file);
		free(redirect);
	}
}

void	free_ast(void *data)
{
	t_ast	*ast;

	ast = data;
	if (!ast)
		return ;
	if (ast->type == COMMAND && ast->data)
		free_command(ast->data);
	else if (ast->type == PIPE && ast->data)
		free_pipe(ast->data);
	else if (ast->type == OPERATOR && ast->data)
		free_operator(ast->data);
	else if (ast->type == REDIRECT && ast->data)
		free_redirect(ast->data);
	if (ast)
		free(ast);
}
