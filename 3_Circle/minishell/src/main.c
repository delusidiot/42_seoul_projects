#include "minishell.h"

// rl_funtion is only signal

static void *executor(t_user *user, void *result, char **envp)
{
	(void)user;
	(void)result;
	(void)envp;
	/** pipe
	 * // Input/Output redirection
	 * 
	 * //Execution of a function, builtin utility or external command
	 * 
	 * // wait for command's exit status
	 */
	// return error 
	// exit_status put user
	return (NULL);
}

static void	*input_stream(t_user *user)
{
	char *input;

	input = prompt(user);
	if (!input)
		return (NULL);
	printf("%s\n", input);
	free(input);
	// Lexer

	// return Token

	// Parser

	// Parser result return;
	return (input);
}

int main(int argc, char** argv, char **envp)
{
	void	*result;
	t_user	user;

	(void)argv;
	(void)envp;
	init_user(&user);
	while(argc)
	{
		result = input_stream(&user);
		if (!result)
			break;
		if (executor(&user, result, envp)) //
			break;
	}
	free_user(&user);
	return (user.exit_status);
}