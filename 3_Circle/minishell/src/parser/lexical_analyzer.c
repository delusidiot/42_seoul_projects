#include "minishell.h"

t_token *token_lexer(t_source *src)
{
	t_token *token;

	token = malloc(sizeof(t_token));
	if (!token)
		return (malloc_exception());
	token->len = 0;
	if (ft_strchr("<>|", *src->curpos) || !ft_strncmp("&&", src->curpos, 2))
		token = get_static_token(token, src);
	else
		token = get_token(token, src);
	return (token);
}

static t_list	*check_token_lexer(t_source *src)
{
	t_token *token;
	t_list	*lst;

	token = token_lexer(src);
	if (!token)
		return (NULL);
	lst = ft_lstnew(token);
	if (!lst)
	{
		free(token->value);
		free(token);
		return (malloc_exception());
	}
	return (lst);
}

t_list	*lexical_analyzer(char *input)
{
	t_source	*src;
	t_list		*curr;
	t_list		*result;

	src = create_source(input);
	if (!src)
		return (malloc_exception());
	skip_whitespaces(src);
	result = check_token_lexer(src);
	if (!result)
		return (NULL);
	curr = result;
	while (*src->curpos)
	{
		skip_whitespaces(src);
		if (!(*src->curpos))
			break;
		curr->next = check_token_lexer(src);
		if (!curr->next)
			return (NULL);
		curr = curr->next;
	}
	free_source(src);
	return (result);
}