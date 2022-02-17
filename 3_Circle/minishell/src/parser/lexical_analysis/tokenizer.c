/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 09:30:36 by jjeon             #+#    #+#             */
/*   Updated: 2022/02/14 02:45:15 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_token	*join_values(t_token *token, char *value)
{
	char	*prev;

	if (!value)
	{
		free(token->value);
		free(token);
		return (NULL);
	}
	prev = token->value;
	token->value = ft_strjoin(prev, value);
	if (!token->value)
	{
		free(token);
		return (NULL);
	}
	free(value);
	free(prev);
	return (token);
}

static t_token	*init_cmd_token(void)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->is_last = FALSE;
	token->cmd_last = FALSE;
	token->brace_level = 0;
	token->type = COMMAND;
	token->value = ft_strdup("");
	if (!token->value)
	{
		free(token);
		token = NULL;
	}
	return (token);
}

static t_token	*write_token_value(t_token *token, t_source *src, \
	t_user *user, char **wilds)
{
	char	*temp;
	char	*next_wilds;
	char	*prev;

	next_wilds = NULL;
	if ((*src->curpos) == '\"')
		temp = get_double_quote(src, user);
	else if ((*src->curpos) == '\'')
		temp = get_single_quote(src);
	else
		temp = get_common_value(src, user, &next_wilds);
	prev = *wilds;
	(*wilds) = ft_calloc(ft_strlen(token->value) + ft_strlen(temp), \
		sizeof(char));
	if (prev != NULL)
		ft_memcpy((*wilds), prev, ft_strlen(token->value));
	if (next_wilds != NULL)
		ft_memcpy((*wilds) + ft_strlen(token->value), next_wilds, \
			ft_strlen(temp));
	free(prev);
	free(next_wilds);
	if (!join_values(token, temp))
		return (NULL);
	return (token);
}

t_list	*get_token(t_source *src, t_user *user)
{
	t_token	*token;
	char	*wilds;

	token = init_cmd_token();
	if (!token)
		return (NULL);
	wilds = NULL;
	while ((*src->curpos) && \
			(!ft_strchr(" \n\t<>|()", *src->curpos) && \
			ft_strncmp("&&", src->curpos, 2)))
	{
		token = write_token_value(token, src, user, &wilds);
		if (!token)
		{
			free(wilds);
			return (NULL);
		}
	}
	return (get_wildcard_files(token, wilds, user));
}
