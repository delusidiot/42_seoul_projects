/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 18:59:40 by jjeon             #+#    #+#             */
/*   Updated: 2021/07/27 17:37:26 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void	parent_process(int index, t_pipex *p)
{
	if (index == 0)
		close(p->pipe_a[WRITE]);
	else if (index == p->end_index - 1 && (index & 1))
		close(p->pipe_b[WRITE]);
	else if (index == p->end_index - 1 && !(index & 1))
		close(p->pipe_a[WRITE]);
	else
	{
		if (index & 1)
		{
			close(p->pipe_a[READ]);
			close(p->pipe_b[WRITE]);
		}
		else
		{
			close(p->pipe_a[WRITE]);
			close(p->pipe_b[READ]);
		}
	}
}

void	child_process(int index, t_pipex *p)
{
	if (index == 0)
		infile(p);
	else if (index == p->end_index - 1)
		outfile(index, p);
	else
	{
		if (index & 1)
		{
			dup2(p->pipe_a[READ], STDIN_FILENO);
			dup2(p->pipe_b[WRITE], STDOUT_FILENO);
		}
		else
		{
			dup2(p->pipe_b[READ], STDIN_FILENO);
			dup2(p->pipe_a[WRITE], STDOUT_FILENO);
		}
		execute(index, p);
	}
}

void	error_exit(char *message, t_pipex *p)
{
	perror(message);
	free_pipex(p);
	exit(1);
}

void	pipex(t_pipex *p)
{
	pid_t	pid;
	int		i;
	int		*pipe_fd;
	int		status;

	i = -1;
	while (++i < p->end_index)
	{
		pipe_fd = p->pipe_a;
		if (i & 1)
			pipe_fd = p->pipe_b;
		if (pipe(pipe_fd) < 0)
			error_exit("pipe error: ", p);
		pid = fork();
		if (pid < 0)
			error_exit("fork error: ", p);
		if (pid > 0)
			parent_process(i, p);
		else
			child_process(i, p);
	}
	while (wait(&status) > 0);
}
