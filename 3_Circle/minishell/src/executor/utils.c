/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 09:31:09 by jjeon             #+#    #+#             */
/*   Updated: 2022/02/12 09:31:11 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*join_path(char *prev, char *name)
{
	char	*temp;
	char	*temp2;

	temp = ft_strjoin(prev, "/");
	temp2 = ft_strjoin(temp, name);
	free(temp);
	return (temp2);
}

void	get_here_doc(int fd, t_redirect *redirect)
{
	char	*input;

	while (TRUE)
	{
		input = readline(">");
		if (!ft_strncmp(input, redirect->file, ft_strlen(redirect->file)))
			break ;
		write(fd, input, ft_strlen(input));
		write(fd, "\n", 1);
		free(input);
		input = NULL;
	}
	free(input);
	close(fd);
}

char	**get_args(t_user *user, t_cmd *cmd)
{
	char	**args;
	t_list	*curr;
	int		i;

	(void)user;
	if (!cmd)
		return (NULL);
	i = 0;
	curr = cmd->args;
	args = malloc(sizeof(char *) * (ft_lstsize(curr) + 2));
	if (!args)
		return (malloc_exception());
	args[i] = cmd->cmd;
	while (curr)
	{
		args[++i] = curr->content;
		curr = curr->next;
	}
	args[i + 1] = NULL;
	return (args);
}

void	fd_init(t_user *user)
{
	if (user->stdin_fd)
		close(user->stdin_fd);
	if (user->stdout_fd)
		close(user->stdout_fd);
	user->stdin_fd = 0;
	user->stdout_fd = 0;
}
