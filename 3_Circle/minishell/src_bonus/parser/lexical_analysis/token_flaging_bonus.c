/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_flaging_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 06:16:33 by jjeon             #+#    #+#             */
/*   Updated: 2022/02/14 10:50:52 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

void	last_command_check(t_list *lst)
{
	t_token	*curr;
	t_token	*last;

	last = NULL;
	while (lst)
	{
		curr = lst->content;
		if (curr->type == COMMAND && last == NULL)
			last = curr;
		if (curr->type == OPERATOR)
			last = NULL;
		if (curr->type == PIPE && last != NULL)
		{
			last->is_last = TRUE;
			last->cmd_last = TRUE;
			last = NULL;
		}
		lst = lst->next;
	}
	if (last)
	{
		last->is_last = TRUE;
		last->cmd_last = TRUE;
	}
}

static int	get_last_level(t_list *lst)
{
	t_token	*token;

	token = NULL;
	while (lst)
	{
		token = lst->content;
		if (token->type == COMMAND && token->is_last)
			break ;
		lst = lst->next;
	}
	if (token == NULL)
		return (0);
	return (token->brace_level);
}

static void	checking(t_list *check)
{
	t_token	*token;

	while (check)
	{
		token = check->content;
		if (token->type == PIPE)
			break ;
		token->is_last = TRUE;
		check = check->next;
	}
}

void	last_brace_checker(t_list *lst)
{
	t_list	*check;

	while (lst)
	{
		check = NULL;
		if (get_last_level(lst))
		{
			while (lst)
			{
				if (((t_token *)lst->content)->type == LBRACE && \
					((t_token *)lst->content)->brace_level == 1)
					check = lst;
				if (((t_token *)lst->content)->type == PIPE)
				{
					checking(check);
					break ;
				}
				lst = lst->next;
			}
			if (check != NULL)
				checking(check);
		}
		if (lst)
			lst = lst->next;
	}
}
