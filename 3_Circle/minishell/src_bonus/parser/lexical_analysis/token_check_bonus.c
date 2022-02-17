/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_check_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 09:30:49 by jjeon             #+#    #+#             */
/*   Updated: 2022/02/12 19:13:16 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

static int	left_brace_checker(t_user *user, t_list *stack, t_ast_type prev)
{
	t_list	*brace;
	int		*check;

	check = malloc(1);
	if (!check)
		return (token_checker_result(stack, "(", FALSE));
	user->brace_level_count++;
	if (prev != NONE && prev != OPERATOR && prev != PIPE && prev != LBRACE)
		return (token_checker_result(stack, "(", FALSE));
	brace = ft_lstnew(check);
	ft_lstadd_back(&stack, brace);
	return (TRUE);
}

static int	right_brace_checker(t_user *user, t_list *stack, t_ast_type prev)
{
	t_list	*brace;
	int		len;

	brace = ft_lstlast(stack);
	user->brace_level_count--;
	if (prev != COMMAND && prev != RBRACE)
		return (token_checker_result(stack, ")", FALSE));
	if (brace->content)
	{
		len = ft_lstsize(stack);
		ft_lstdelone(brace, free);
		brace = stack;
		while (--len - 1 > 0)
			brace = brace->next;
		brace->next = NULL;
		return (TRUE);
	}
	else
		return (token_checker_result(stack, ")", FALSE));
}

static int	oper_checker(t_token *token, t_list *next, \
		t_list *stack, t_ast_type prev)
{
	if ((prev != COMMAND && prev != RBRACE) || next == NULL)
		return (token_checker_result(stack, token->value, FALSE));
	return (TRUE);
}

static int	token_type_checker(t_user *user, t_list *lst, \
		t_list *stack, t_ast_type prev)
{
	t_token	*token;
	t_list	*next;

	token = lst->content;
	next = lst->next;
	if (token->type == LBRACE && !left_brace_checker(user, stack, prev))
		return (FALSE);
	if (token->type == RBRACE && !right_brace_checker(user, stack, prev))
		return (FALSE);
	if (token->type == OPERATOR && !oper_checker(token, next, stack, prev))
		return (FALSE);
	if (token->type == PIPE)
	{
		token->brace_level = user->brace_level_count;
		if (!pipe_checker(token, next, stack, prev))
			return (FALSE);
	}
	if (token->type == REDIRECT && !redirect_checker(next, stack, prev))
		return (FALSE);
	if (token->type == COMMAND && !command_checker(token, stack, prev))
		return (FALSE);
	return (TRUE);
}

int	token_checker(t_list *lst, t_user *user)
{
	t_ast_type	prev;
	t_token		*token;
	t_list		*stack;

	prev = NONE;
	stack = ft_lstnew(NULL);
	if (!stack)
		return (FALSE);
	while (lst)
	{
		token = lst->content;
		if (!token_type_checker(user, lst, stack, prev))
			return (FALSE);
		prev = token->type;
		token->brace_level = user->brace_level_count;
		lst = lst->next;
	}
	if (ft_lstlast(stack)->content)
		return (token_checker_result(stack, "(", FALSE));
	return (token_checker_result(stack, "(", TRUE));
}
