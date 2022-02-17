/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 09:30:52 by jjeon             #+#    #+#             */
/*   Updated: 2022/02/12 09:30:53 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	del_token(void *content)
{
	t_token	*token;

	token = content;
	if (!token)
		return ;
	free(token->value);
	free(token);
}

void	print_token(void *content)
{
	t_token	*token;
	char	*type;

	token = content;
	if (token->type == NONE)
		type = "NONE";
	if (token->type == COMMAND)
		type = "COMMAND";
	if (token->type == ARGUMENT)
		type = "ARGUMENT";
	if (token->type == PIPE)
		type = "PIPE";
	if (token->type == REDIRECT)
		type = "REDIRECT";
	if (token->type == FILE_NO)
		type = "FILE_NO";
	if (token->type == OPERATOR)
		type = "OPERATOR";
	if (token->type == LBRACE)
		type = "LBRACE";
	if (token->type == RBRACE)
		type = "RBRACE";
	printf("%s : %s %d\n", type, token->value, token->brace_level);
}

void	skip_whitespaces(t_source *src)
{
	if (!src || !src->input)
		return ;
	while (src->curpos && \
		(*src->curpos == ' ' || *src->curpos == '\v' || *src->curpos == '\f' || \
		*src->curpos == '\r' || *src->curpos == '\n' || *src->curpos == '\t'))
		src->curpos++;
}

t_source	*create_source(char *input)
{
	t_source	*src;

	src = malloc(sizeof(t_source));
	if (!src || !input || *input == '\0')
		return (NULL);
	src->input = input;
	src->curpos = input;
	return (src);
}

t_source	*free_source(t_source *src)
{
	free(src->input);
	free(src);
	return (NULL);
}
