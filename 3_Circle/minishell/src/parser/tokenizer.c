#include "minishell.h"

t_token	*get_redirect_token(t_token *token, t_source *src)
{
	char *value;
	t_ast_type type;

	type = REDIRECT;
	if (!ft_strncmp(src->curpos, "<<", 2))
	{
		value = ft_strdup("<<");
		token->len++;
		src->curpos++;
	}
	else if (!ft_strncmp(src->curpos, ">>", 2))
	{
		value = ft_strdup(">>");
		token->len++;
		src->curpos++;
	}
	else if (!ft_strncmp(src->curpos, "<", 1))
		value = ft_strdup("<");
	else if (!ft_strncmp(src->curpos, ">", 1))
		value = ft_strdup(">");
	src->curpos++;
	token->len++;
	token->value = value;
	token->type = type;
	return (token);
}

t_token	*get_pipe_op_token(t_token *token, t_source *src)
{
	char *value;
	t_ast_type type;

	value = NULL;
	type = OPERATOR;
	if (!ft_strncmp(src->curpos, "&&", 2))
	{
		value = ft_strdup("&&");
		token->len++;
		src->curpos++;
	}
	else if (!ft_strncmp(src->curpos, "||", 2))
	{
		value = ft_strdup("||");
		token->len++;
		src->curpos++;
	}
	else if (!ft_strncmp(src->curpos, "|", 1))
	{
		type = PIPE;
		value = ft_strdup("|");
	}
	src->curpos++;
	token->len++;
	token->value = value;
	token->type = type;
	return (token);
}

void	get_quotation(t_source *src, char **value, t_token *token)
{
	char	*prev;
	char	temp[2];
	char	*input;

	temp[1] = '\0';
	src->curpos++;
	while ((*src->curpos) != '\"')
	{
		if (!(*src->curpos))
		{
			free_source(src);
			input = prompt(NULL);
			create_source(input);
		}
		if ((*src->curpos) == '\"')
			break;
		temp[0] = (*src->curpos);
		prev = *value;
		*value = ft_strjoin(*value, temp);
		free(prev);
		token->len++;
		src->curpos++;
	}
	src->curpos++;
}

t_token	*get_static_token(t_token *token, t_source *src)
{
	if (ft_strchr("<>", *src->curpos))
		token = get_redirect_token(token, src);		
	else if (ft_strchr("&|", *src->curpos))
		token = get_pipe_op_token(token, src);
	return (token);
}

t_token	*get_token(t_token *token, t_source *src)
{
	char	*value;
	char	*prev;
	char	temp[2];

	temp[1] = '\0';
	value = ft_strdup("");
	while ((*src->curpos) && \
			(!ft_strchr(" \n\t<>|", *src->curpos) && ft_strncmp("&&", src->curpos, 2)))
	{
		if ((*src->curpos) == '\"')
		{
			get_quotation(src, &value, token);
			break;
		}
		else
		{
			temp[0] = *src->curpos;
			prev = value;
			value = ft_strjoin(value, temp);
			free(prev);
			token->len++;
			src->curpos++;
		}
	}
	token->value = value;
	token->type = COMMAND;
	return (token);
}