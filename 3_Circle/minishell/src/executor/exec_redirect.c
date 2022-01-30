#include "minishell.h"

static int	redirect_append(t_user *user, t_redirect *redirect)
{
	int flag;

	if (user->stdout_fd)
		close(user->stdout_fd);
	flag = O_WRONLY | O_CREAT | O_APPEND;
	user->stdout_fd = open(redirect->file, flag, 0644);
	if (user->stdout_fd < 0)
		return (FALSE);
	return (TRUE);
}

static int	redirect_out(t_user *user, t_redirect *redirect)
{
	int flag;

	if (user->stdout_fd)
		close(user->stdout_fd);
	flag = O_WRONLY | O_CREAT | O_TRUNC;
	user->stdout_fd = open(redirect->file, flag, 0644);
	if (user->stdout_fd < 0)
		return (FALSE);
	return (TRUE);
}

static int	redirect_heredoc(t_user *user, t_redirect *redirect)
{
	int flag;
	int fd;

	flag = O_WRONLY | O_CREAT | O_TRUNC;
	fd = open(HERE_TEMP, flag, 0644);
	if (fd < 0)
		return (FALSE);
	get_here_doc(fd, redirect);
	if (user->stdin_fd)
		close(user->stdin_fd);
	user->stdin_fd = open(HERE_TEMP, O_RDONLY);
	if (user->stdin_fd < 0)
		return (FALSE);
	return (TRUE);
}

static int	redirect_in(t_user *user, t_redirect *redirect)
{
	int flag;

	if (user->stdin_fd)
		close(user->stdin_fd);
	flag = O_RDONLY;
	user->stdin_fd = open(redirect->file, flag, 0644);
	if (user->stdin_fd < 0)
		return (FALSE);
	return (TRUE);
}

int	exec_redirect(t_user *user, t_redirect *redirect)
{
	int status;

	if (!user || !redirect)
		return (FALSE);
	status = TRUE;
	if (redirect->type == REDIRECT_APPEND)
		status = redirect_append(user, redirect);
	else if (redirect->type == REDIRECT_HEREDOC)
		status = redirect_heredoc(user, redirect);
	else if (redirect->type == REDIRECT_IN)
		status = redirect_in(user, redirect);
	else if (redirect->type == REDIRECT_OUT)
		status = redirect_out(user, redirect);
	if (!status && (user->stdin_fd < 0 || user->stdout_fd < 0))
		return (redirect_not_found_exception(redirect->file));
	if (status && redirect->ast)
		exec_ast(user, redirect->ast);
	return (status);
}