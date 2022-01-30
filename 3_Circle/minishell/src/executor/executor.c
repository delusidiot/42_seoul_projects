#include "minishell.h"

int	exec_operator(t_user *user, t_operator *operator)
{
	int	status;

	if (!user || !operator)
		return (FALSE);
	fd_init(user);
	status = exec_ast(user, operator->left);
	if ((operator->type == OPERATOR_AND && status != 0) || \
		(operator->type == OPERATOR_OR && status == 0))
		return (status);
	fd_init(user);
	status = exec_ast(user, operator->right);
	return (TRUE);
}

int	exec_ast(t_user *user, t_AST *ast)
{
	int status;

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