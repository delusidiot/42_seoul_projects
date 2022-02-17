/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_value_analyzer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 09:30:39 by jjeon             #+#    #+#             */
/*   Updated: 2022/02/14 02:43:21 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*get_pipe_op_token(t_token *token, t_source *src)
{
	char		*value;
	t_ast_type	type;

	value = NULL;
	type = OPERATOR;
	if (!ft_strncmp(src->curpos, "&&", 2))
	{
		value = ft_strdup("&&");
		src->curpos++;
	}
	else if (!ft_strncmp(src->curpos, "||", 2))
	{
		value = ft_strdup("||");
		src->curpos++;
	}
	else if (!ft_strncmp(src->curpos, "|", 1))
	{
		type = PIPE;
		value = ft_strdup("|");
	}
	set_token_value(token, src, value, type);
	return (token);
}

char	*get_double_quote(t_source *src, t_user *user)
{
	char	*prev;
	char	*value;
	char	temp[2];

	temp[1] = '\0';
	src->curpos++;
	value = ft_strdup("");
	while ((*src->curpos) != '\"')
	{
		temp[0] = (*src->curpos);
		prev = value;
		value = ft_strjoin(value, temp);
		free(prev);
		src->curpos++;
	}
	src->curpos++;
	prev = str_conversion(user, value);
	free(value);
	return (prev);
}

char	*get_single_quote(t_source *src)
{
	char	*value;
	char	*prev;
	char	temp[2];

	temp[1] = '\0';
	src->curpos++;
	value = ft_strdup("");
	while ((*src->curpos) != '\'')
	{
		temp[0] = (*src->curpos);
		prev = value;
		value = ft_strjoin(value, temp);
		free(prev);
		src->curpos++;
	}
	src->curpos++;
	return (value);
}

char	*get_common_value(t_source *src, t_user *user, char **wilds)
{
	char	*prev;
	char	temp[2];
	char	*value;

	temp[1] = '\0';
	value = ft_strdup("");
	while ((*src->curpos) && \
			(*src->curpos) != '\'' && (*src->curpos) != '\"' && \
			!ft_strchr(" \n\t<>|()", *src->curpos) && \
			ft_strncmp("&&", src->curpos, 2))
	{
		temp[0] = (*src->curpos);
		prev = value;
		value = ft_strjoin(value, temp);
		free(prev);
		src->curpos++;
	}
	prev = remove_whitespace(src, str_conversion(user, value));
	free(value);
	(*wilds) = mark_wildcard(prev);
	return (prev);
}
