#include "minishell.h"

t_AST	**syntax_PIPE(t_list **token, t_AST **curr)
{
	t_AST	*result;
	t_pipe	*pipe;

	result = malloc(sizeof(t_AST));
	if(!result)
		return (malloc_exception()); // change free memories
	pipe = malloc(sizeof(t_pipe));
	if (!pipe)
	{
		free(result);
		return (malloc_exception());
	}
	result->type = PIPE;
	result->data = pipe;
	pipe->left = *curr;
	*curr = result;
	*token = (*token)->next;
	return (&pipe->right);
}

t_AST	**syntax_operator(t_list **token, t_AST **curr)
{
	t_AST	*result;
	t_operator	*operator;

	result = malloc(sizeof(t_AST));
	if (!result)
		return (malloc_exception()); // change free memories
	operator = malloc(sizeof(t_operator));
	if (!operator)
	{
		free(result);
		return (malloc_exception());
	}
	result->type = OPERATOR;
	result->data = operator; // result type check;
	if (!ft_strncmp(((t_token *)(*token)->content)->value, "&&", 2))
		operator->type = OPERATOR_AND;
	else if(!ft_strncmp(((t_token *)(*token)->content)->value, "||", 2))
		operator->type = OPERATOR_OR;
	operator->left = *curr;
	*curr = result;
	*token = (*token)->next;
	return (&operator->right);
}

t_AST	**syntax_switch(t_list **token, t_AST **curr)
{
	if (((t_token *)(*token)->content)->type == PIPE)
	{
		curr = syntax_PIPE(token, curr);
		if (!curr)
			return (NULL);// change free memories
	}
	else if (((t_token *)(*token)->content)->type == OPERATOR)
	{
		curr = syntax_operator(token, curr);
		if (!curr)
			return (NULL);// change free memories
	}
	*curr = syntax_cmd(token);
	if (!curr)
		return (NULL); // change free memories
	return (curr);
}

t_AST	*syntax_AST(t_list **token)
{
	t_AST	*result;
	t_AST	**curr;

	result = syntax_cmd(token);
	if (!result)
		return (NULL); // change free memories
	curr = &result;
	while (*token)
	{
		curr = syntax_switch(token, curr);
		if (!*curr)
			return (NULL); // change free memories
	}
	return (result);
}