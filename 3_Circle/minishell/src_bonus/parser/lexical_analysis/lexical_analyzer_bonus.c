/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexical_analyzer_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 09:30:55 by jjeon             #+#    #+#             */
/*   Updated: 2022/02/12 09:30:56 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

static t_token	*get_redirect_token(t_token *token, t_source *src)
{
	char		*value;
	t_ast_type	type;

	type = REDIRECT;
	value = NULL;
	if (!ft_strncmp(src->curpos, "<<", 2))
	{
		value = ft_strdup("<<");
		src->curpos++;
	}
	else if (!ft_strncmp(src->curpos, ">>", 2))
	{
		value = ft_strdup(">>");
		src->curpos++;
	}
	else if (!ft_strncmp(src->curpos, "<", 1))
		value = ft_strdup("<");
	else if (!ft_strncmp(src->curpos, ">", 1))
		value = ft_strdup(">");
	set_token_value(token, src, value, type);
	return (token);
}

static t_token	*get_braket(t_token *token, t_source *src)
{
	char		*value;
	t_ast_type	type;

	value = NULL;
	type = NONE;
	if (!ft_strncmp(src->curpos, "(", 1))
	{
		type = LBRACE;
		value = ft_strdup("(");
	}
	else if (!ft_strncmp(src->curpos, ")", 1))
	{
		type = RBRACE;
		value = ft_strdup(")");
	}
	set_token_value(token, src, value, type);
	return (token);
}

static t_token	*get_static_token(t_source *src)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->is_last = FALSE;
	token->cmd_last = FALSE;
	token->brace_level = 0;
	if (!token)
		return (NULL);
	if (ft_strchr("<>", *src->curpos))
		token = get_redirect_token(token, src);
	else if (ft_strchr("&|", *src->curpos))
		token = get_pipe_op_token(token, src);
	else if (ft_strchr("()", *src->curpos))
		token = get_braket(token, src);
	if (!token->value)
	{
		free(token);
		token = NULL;
	}
	return (token);
}

static t_list	*token_lexer(t_source *src, t_user *user)
{
	t_token	*token;
	t_list	*lst;

	skip_whitespaces(src);
	if (ft_strchr("<>|()", *src->curpos) || !ft_strncmp("&&", src->curpos, 2))
	{
		token = get_static_token(src);
		if (!token)
			return (NULL);
		lst = ft_lstnew(token);
	}
	else
		lst = get_token(src, user);
	if (!lst)
	{
		free_source(src);
		return (NULL);
	}
	return (lst);
}

t_list	*lexical_analyzer(char *input, t_user *user)
{
	t_source	*src;
	t_list		*curr;
	t_list		*result;

	src = create_source(input);
	if (!src)
		return (malloc_exception());
	result = token_lexer(src, user);
	if (!result)
		return (malloc_exception());
	curr = result;
	while (*src->curpos)
	{
		while (curr->next)
			curr = curr->next;
		curr->next = token_lexer(src, user);
		if (!curr->next)
		{
			ft_lstclear(&result, del_token);
			free_source(src);
			return (malloc_exception());
		}
	}
	free_source(src);
	return (result);
}
