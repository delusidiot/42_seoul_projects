#include "minishell.h"

void *executor(t_user *user, t_AST *result, char **envp)
{
	int status;
	pid_t pid;

	(void)envp;
	exec_ast(user, result);
	while (1)
	{
		pid = wait(&status);
		errno = status_signal_handler(status);
		if (pid < 0)
			break ;
	}
	free_AST(result);
	return (NULL);
}

static t_AST	*input_stream(t_user *user)
{
	char *input;
	t_list *list;
	t_AST *ast;

	input = prompt(user);
	if (!input)
		input = strdup("exit");
	if (!ft_strncmp(input, "", ft_strlen(input)))
		return (NULL);
	list = lexical_analyzer(input);
	if (!list)
		return (NULL);
	ast = syntax_analyzer(list);
	ft_putstr_fd(MAG, STDOUT_FILENO);
	print_ast(ast);
	ft_putstr_fd(WHT, STDOUT_FILENO);
	ft_putstr_fd(EOC, STDOUT_FILENO);
	return (ast);
}

int main(int argc, char** argv, char **envp)
{
	t_AST	*result;
	t_user	user;

	(void)argv;
	startup_shell(&user);
	user.g_env = envp; // delete...
	while(argc)
	{
		init_user(&user);
		result = input_stream(&user);
		if (result)
			executor(&user, result, envp);
		free_user(&user);
	}
	free_user(&user);
	return (errno);
}