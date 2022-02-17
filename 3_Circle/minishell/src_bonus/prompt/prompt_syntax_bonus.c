/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_syntax_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 09:30:12 by jjeon             #+#    #+#             */
/*   Updated: 2022/02/12 09:30:15 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

t_qtype	is_quotation(char *input)
{
	t_qtype	flag;

	flag = NORMAL;
	while (*input)
	{
		if (flag == NORMAL)
		{
			if (*input == '\"')
				flag = DOUBLE_QUOTE;
			else if (*input == '\'')
				flag = SINGLE_QUOTE;
		}
		else if ((flag == DOUBLE_QUOTE && *input == '\"') || \
				(flag == SINGLE_QUOTE && *input == '\''))
			flag = NORMAL;
		input++;
	}
	return (flag);
}

int	is_nextline(char *input)
{
	int		i;

	i = 0;
	while (input[i])
		i++;
	if (i != 1)
	{
		if (i > 1 && (!ft_strncmp(input + i - 2, "&&", 2) || \
				!ft_strncmp(input + i - 2, "||", 2)))
			return (TRUE);
		else if (i > 0 && (!ft_strncmp(input + i - 1, "|", 1)))
			return (TRUE);
	}
	return (FALSE);
}

char	*add_input(char *input, t_qtype qtype)
{
	char	*nextline;
	char	*result;

	nextline = readline("> ");
	if (nextline == NULL)
		return (unexpected_end_quote(input, qtype));
	result = ft_strjoin(input, "\n");
	free(input);
	input = result;
	result = ft_strjoin(input, nextline);
	free(input);
	free(nextline);
	return (result);
}
