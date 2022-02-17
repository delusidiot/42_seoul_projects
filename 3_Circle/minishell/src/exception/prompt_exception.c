/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_exception.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 09:31:35 by jjeon             #+#    #+#             */
/*   Updated: 2022/02/12 09:31:36 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*unexpected_end_of_file(void)
{
	ft_putstr_fd(ERR_PROMPT, STDERR_NO);
	ft_putstr_fd(LINE_EOF_ERR_MSG, STDERR_NO);
	ft_putstr_fd("\n", STDERR_NO);
	return (NULL);
}

void	*unexpected_end_quote(char *input, t_qtype qtype)
{
	char	*msg;

	msg = NULL;
	free(input);
	if (qtype == DOUBLE_QUOTE)
		msg = "\"";
	else if (qtype == SINGLE_QUOTE)
		msg = "\'";
	ft_putstr_fd(ERR_PROMPT, STDERR_NO);
	ft_putstr_fd(QUOTE_ERR_MSG, STDERR_NO);
	ft_putstr_fd("`", STDERR_NO);
	ft_putstr_fd(msg, STDERR_NO);
	ft_putstr_fd("\'", STDERR_NO);
	ft_putstr_fd("\n", STDERR_NO);
	return (unexpected_end_of_file());
}
