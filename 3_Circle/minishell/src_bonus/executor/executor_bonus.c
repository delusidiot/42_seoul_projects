/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 09:31:13 by jjeon             #+#    #+#             */
/*   Updated: 2022/02/14 13:29:48 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

int	exec_operator(t_user *user, t_operator *operator)
{
	int		status;
	t_ops	prev;

	if (!user || !operator)
		return (FALSE);
	fd_init(user);
	prev = user->oper_state;
	if (user->oper_state == S_NONE)
		user->oper_state = S_FIRST;
	status = exec_ast(user, operator->left);
	if ((operator->type == OPERATOR_AND && status == FALSE) || \
		(operator->type == OPERATOR_OR && status == TRUE))
		user->oper_state = S_FAIL;
	else
		user->oper_state = S_SUCCESS;
	if (prev == S_FAIL)
		user->oper_state = S_FAIL;
	fd_init(user);
	status = exec_ast(user, operator->right);
	if (prev == S_FAIL)
		user->oper_state = S_FAIL;
	else if (user->oper_state == S_FAIL && status)
		user->oper_state = S_SUCCESS;
	return (status);
}

int	exec_ast(t_user *user, t_ast *ast)
{
	int	status;

	if (!user || !ast)
		return (FALSE);
	status = TRUE;
	if (ast->type == COMMAND && ast->data)
		status = exec_command(user, ast->data);
	else if (ast->type == PIPE && ast->data)
		status = exec_pipe(user, ast->data);
	else if (ast->type == REDIRECT && ast->data)
		status = exec_redirect(user, ast->data);
	else if (ast->type == OPERATOR && ast->data)
		status = exec_operator(user, ast->data);
	return (status);
}
