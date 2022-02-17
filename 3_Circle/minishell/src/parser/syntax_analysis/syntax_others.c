/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_others.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 06:16:56 by jjeon             #+#    #+#             */
/*   Updated: 2022/02/14 06:17:06 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_ast	**syntax_PIPE(t_user *user, t_list **token, t_ast **curr)
{
	t_ast	*result;
	t_pipe	*pipe;

	result = malloc(sizeof(t_ast));
	if (!result)
		return (malloc_exception());
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
	user->cmd_count++;
	return (&pipe->right);
}

t_ast	**syntax_operator(t_list **token, t_ast **curr)
{
	t_ast		*result;
	t_operator	*operator;

	result = malloc(sizeof(t_ast));
	if (!result)
		return (malloc_exception());
	operator = malloc(sizeof(t_operator));
	if (!operator)
	{
		free(result);
		return (malloc_exception());
	}
	result->type = OPERATOR;
	result->data = operator;
	if (!ft_strncmp(((t_token *)(*token)->content)->value, "&&", 2))
		operator->type = OPERATOR_AND;
	else if (!ft_strncmp(((t_token *)(*token)->content)->value, "||", 2))
		operator->type = OPERATOR_OR;
	operator->brace_level = ((t_token *)(*token)->content)->brace_level;
	operator->left = *curr;
	*curr = result;
	*token = (*token)->next;
	return (&operator->right);
}
