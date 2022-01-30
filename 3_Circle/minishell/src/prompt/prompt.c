#include "minishell.h"

char	*prompt(t_user *user)
{
	char *input;
	char *prompt;

	input = NULL;
	if (user)
		prompt = prompt1(user);
	else
		prompt = prompt2();
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

char	*read_here_doc(int fd)
{
	char	*input;
	char	*prompt;
	
	prompt = prompt2();
	while (TRUE)
	{
		input = readline(prompt);
		if (!ft_strncmp("here", input, ft_strlen("here")))
			break;
		write(fd, input, ft_strlen(input));
		free(input);
	}
	close(fd);
	return (input);
}