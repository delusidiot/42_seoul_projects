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

char	*read_here_doc(int fd, t_user *user)
{
	char	*input;
	char	*prompt;
	
	prompt = prompt2(user);
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