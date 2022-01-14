#include "minishell.h"

char	*prompt(t_user *user)
{
	char *input;
	char *prompt;

	input = NULL;
	prompt = prompt1(user);
	if (!prompt)
	{
		errno = EIDRM; // change errno num!
		ft_putstr_fd(strerror(errno), STDERR_FILENO);
		return (NULL);
	}
	input = readline(prompt);
	add_history(input);
	free(prompt);
	return (input);
}

// here_doc prompt