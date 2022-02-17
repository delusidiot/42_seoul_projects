/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_check_values.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 09:30:45 by jjeon             #+#    #+#             */
/*   Updated: 2022/02/12 19:30:52 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	token_checker_result(t_list *stack, char *msg, int check)
{
	if (stack)
		ft_lstclear(&stack, free);
	if (!check)
		return (syntax_error(msg));
	return (check);
}

int	pipe_checker(t_token *token, t_list *next, t_list *stack, t_ast_type prev)
{
	if (prev == NONE || next == NULL || \
		prev == LBRACE || token->brace_level != 0)
		return (token_checker_result(stack, token->value, FALSE));
	return (TRUE);
}

int	redirect_checker(t_list *next, t_list *stack, t_ast_type prev)
{
	if (prev != COMMAND && prev != NONE && prev != PIPE)
		return (token_checker_result(stack, "newline", FALSE));
	if (next != NULL && ((t_token *)next->content)->type == REDIRECT)
		return (token_checker_result(stack, \
					((t_token *)next->content)->value, FALSE));
	if (next == NULL || ((t_token *)next->content)->type != COMMAND)
		return (token_checker_result(stack, "newline", FALSE));
	return (TRUE);
}

int	command_checker(t_token *token, t_list *stack, t_ast_type prev)
{
	if (prev == RBRACE)
		return (token_checker_result(stack, token->value, FALSE));
	return (TRUE);
}
