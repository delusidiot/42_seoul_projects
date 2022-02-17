/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_ast_bonus_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 09:32:00 by jjeon             #+#    #+#             */
/*   Updated: 2022/02/14 06:12:12 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

t_ast	*syntax_switch(t_user *user, t_list **token, t_ast *curr)
{
	t_ast	**right;

	right = NULL;
	if (((t_token *)(*token)->content)->type == PIPE)
	{
		right = syntax_PIPE(user, token, &curr);
		if (!right)
			return (NULL);
	}
	else if (((t_token *)(*token)->content)->type == OPERATOR)
	{
		right = syntax_operator(token, &curr);
		if (!curr)
			return (NULL);
	}
	if (((t_token *)(*token)->content)->type == COMMAND || \
		((t_token *)(*token)->content)->type == REDIRECT)
		*right = syntax_cmd(user, token);
	else if (((t_token *)(*token)->content)->type == LBRACE)
	{
		*token = (*token)->next;
		*right = syntax_ast(user, token);
	}
	return (curr);
}

t_ast	*create_root_ast(t_user *user, t_list **token)
{
	t_ast	*root;

	root = NULL;
	if (((t_token *)(*token)->content)->type == LBRACE)
	{
		*token = (*token)->next;
		root = syntax_ast(user, token);
	}
	else
		root = syntax_cmd(user, token);
	return (root);
}

t_ast	*syntax_ast(t_user *user, t_list **token)
{
	t_ast	*root;
	t_ast	*curr;

	if (!(*token))
		return (NULL);
	root = create_root_ast(user, token);
	while (*token)
	{
		if (((t_token *)(*token)->content)->type == RBRACE)
		{
			*token = (*token)->next;
			break ;
		}
		else
		{
			curr = syntax_switch(user, token, root);
			if (!curr)
			{
				free_ast(root);
				return (NULL);
			}
			root = curr;
		}
	}
	return (root);
}
