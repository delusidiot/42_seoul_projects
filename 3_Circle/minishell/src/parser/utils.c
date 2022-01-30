#include "minishell.h"

void	del_token(void *content)
{
	t_token *token;

	token = content;
	free(token->value);
	free(token);
}

void	print_token(void *content)
{
	t_token *token;

	token = content;
	printf("%s\n", token->value);
}