#include "minishell.h"

int		put_exec_errno(void)
{
	ft_putstr_fd(ERR_PROMPT, STDERR_FILENO);
	ft_putstr_fd(strerror(errno), STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	return (FALSE);
}

int		command_not_found_exception(char *cmd)
{
	ft_putstr_fd(cmd, STDERR_FILENO);
	ft_putstr_fd(": command not found.", STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	errno = EKEYEXPIRED;
	return (FALSE);
}

int		redirect_not_found_exception(char *file)
{
	ft_putstr_fd(ERR_PROMPT, STDERR_FILENO);
	ft_putstr_fd(file, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(strerror(errno), STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	return (FALSE);
}

void	*put_exec_errno_null(void)
{
	put_exec_errno();
	return (NULL);
}

int		exec_malloc_exception(void)
{
	errno = ENOMEM;
	put_exec_errno();
	return (FALSE);
}