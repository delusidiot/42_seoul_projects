/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 09:29:53 by jjeon             #+#    #+#             */
/*   Updated: 2022/02/14 13:11:47 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

void	wait_process(t_user *user)
{
	int	status;
	int	i;

	status = 0;
	if (user->last != NULL)
	{
		underscore(user, user->last->cmd, user->last->args);
		waitpid(user->last->pid, &status, 0);
		user->exit_status = status_signal_handler(status);
	}
	i = -1;
	while (++i < user->cmd_count + 1)
	{
		if (user->pipe_in[i])
			close(user->pipe_in[i]);
		if (user->pipe_out[i])
			close(user->pipe_out[i]);
	}
	free(user->pipe_in);
	free(user->pipe_out);
	while (TRUE)
		if (wait(&status) < 0)
			break ;
}

void	*executor(t_user *user, t_ast *result)
{
	user->pipe_in = ft_calloc(user->cmd_count + 1, sizeof(int));
	if (user->pipe_in == NULL)
		return (malloc_exception());
	user->pipe_out = ft_calloc(user->cmd_count + 1, sizeof(int));
	if (user->pipe_out == NULL)
	{
		free(user->pipe_in);
		return (malloc_exception());
	}
	user->oper_state = S_NONE;
	exec_ast(user, result);
	wait_process(user);
	return (NULL);
}

static t_ast	*input_stream(t_user *user)
{
	char	*input;
	t_list	*list;
	t_ast	*ast;

	input = prompt(user);
	if (!input)
		return (NULL);
	list = lexical_analyzer(input, user);
	if (!list)
		return (NULL);
	if (!token_checker(list, user))
	{
		user->exit_status = 2;
		ft_lstclear(&list, del_token);
		return (NULL);
	}
	last_command_check(list);
	last_brace_checker(list);
	ast = syntax_analyzer(user, list);
	ft_lstclear(&list, del_token);
	return (ast);
}

int	main(int argc, char **argv, char **envp)
{
	t_ast	*result;
	t_user	user;

	(void)argv;
	result = NULL;
	startup_shell(&user, envp);
	while (argc)
	{
		set_command_signal();
		init_user(&user);
		result = input_stream(&user);
		set_exec_signal();
		if (result)
			executor(&user, result);
		free_ast(result);
		free_user(&user);
	}
	free_ast(result);
	free_user(&user);
	free(user.home_dir);
	env_lst_clear(user.g_env);
	return (user.exit_status);
}
