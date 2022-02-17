/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 18:57:41 by jjeon             #+#    #+#             */
/*   Updated: 2022/02/13 10:52:53 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_token_value(t_token *token, \
		t_source *src, \
		char *value, \
		t_ast_type type)
{
	src->curpos++;
	token->value = value;
	token->type = type;
}

char	*remove_whitespace(t_source *src, char *value)
{
	char	*str;
	char	*rst;
	char	*input;
	int		i;

	if (!value)
		return (value);
	rst = NULL;
	str = ft_strtrim(value, " ");
	free(value);
	value = str;
	i = 0;
	while (*str && !ft_strchr(" \v\f\r\n\t", *str))
	{
		str++;
		i++;
	}
	rst = ft_strndup(value, i);
	input = src->input;
	src->input = ft_strjoin(str, src->curpos);
	src->curpos = src->input;
	free(input);
	free(value);
	return (rst);
}

char	*mark_wildcard(char *value)
{
	char	*wilds;
	int		i;

	i = -1;
	wilds = ft_calloc(ft_strlen(value), sizeof(char));
	while (value[++i])
	{
		if (value[i] == '*')
			wilds[i] = '*';
	}
	return (wilds);
}
