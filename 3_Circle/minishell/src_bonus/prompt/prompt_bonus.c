/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 09:30:18 by jjeon             #+#    #+#             */
/*   Updated: 2022/02/12 09:30:20 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

static char	*check_quotation(char *input)
{
	char	*msg;
	t_qtype	type;

	type = is_quotation(input);
	if (type == DOUBLE_QUOTE)
		msg = "\"";
	else if (type == SINGLE_QUOTE)
		msg = "\'";
	else
		msg = "";
	if (type != NORMAL)
	{
		free(input);
		syntax_error(msg);
		return (NULL);
	}
	return (input);
}

static char	*input_arrange(char *input, t_user *user)
{
	char	*trim;

	trim = NULL;
	if (input == NULL)
	{
		ft_putstr_fd("exit\n", STDOUT_NO);
		exit(user->exit_status);
	}
	if (ft_strncmp(input, "", ft_strlen(input)))
		add_history(input);
	trim = ft_strtrim(input, " \t\v\f\r");
	free(input);
	if (!ft_strncmp(trim, "", ft_strlen(trim)))
	{
		free(trim);
		return (NULL);
	}
	return (check_quotation(trim));
}

char	*prompt(t_user *user)
{
	char	*input;
	char	*prompt;

	input = NULL;
	prompt = NULL;
	if (user)
		prompt = prompt1(user);
	else
		prompt = prompt2(NULL);
	if (!prompt)
		input = readline(">");
	else
		input = readline(prompt);
	free(prompt);
	return (input_arrange(input, user));
}
