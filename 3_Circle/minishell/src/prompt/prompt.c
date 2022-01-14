#include "minishell.h"

char	*select_prompt(char *input, t_user *user)
{
	char *prompt;

	if (!input)
		prompt = prompt1(user);
	else
		prompt = prompt2(user);
	return (prompt);
}

char	*prompt(t_user *user)
{
	char *input;
	char *prompt;

	input = NULL;
	prompt = select_prompt(input, user);
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