#include "minishell.h"

void	exception(void)
{
	ft_putstr_fd(strerror(errno), STDERR_FILENO);
	exit(errno);
}

void	*malloc_exception(void)
{
	errno = ENOMEM;
	return (NULL);
}

void	put_errorno(void) // free (void *content, void * del) // in parser...
{
	ft_putstr_fd(ERR_PROMPT, STDERR_FILENO);
	ft_putstr_fd(strerror(errno), STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}

// redirect not file error
// operator and pipe left ast not be error
int		syntax_error(char *token_str) 
{
	ft_putstr_fd(ERR_PROMPT, STDERR_FILENO);
	ft_putstr_fd(SYN_ERR, STDERR_FILENO);
	ft_putstr_fd("\'", STDERR_FILENO);
	ft_putstr_fd(token_str, STDERR_FILENO);
	ft_putstr_fd("\'", STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	return (FALSE);
}

void	*end_syntax_error(char *token_str) // opeartor and pipe end(right) error
{
	ft_putstr_fd(ERR_PROMPT, STDERR_FILENO);
	ft_putstr_fd(token_str, STDERR_FILENO);
	ft_putstr_fd(END_SYN_ERR, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	return (NULL);
}