/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 18:59:08 by jjeon             #+#    #+#             */
/*   Updated: 2021/08/09 23:17:16 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void	read_here_doc(int fd, t_pipex *p)
{
	int		i;
	int		rst;
	char	*line;

	while (TRUE)
	{
		i = 0;
		while (++i < p->end_index)
			write(1, "pipe ", 5);
		write(1, "heredoc> ", 9);
		rst = get_next_line(STDIN_FILENO, &line);
		if (rst < 0)
			error_exit("gnl error: ", p);
		rst = ft_strncmp(line, p->infile, ft_strlen(p->infile));
		if (!rst)
			break ;
		else
		{
			write(fd, line, ft_strlen(line));
			write(fd, "\n", 1);
		}
		free(line);
		line = NULL;
	}
	close(fd);
}

void	infile(t_pipex *p)
{
	int	fd;

	close(p->pipe_a[READ]);
	if (p->here_doc)
	{
		fd = open(p->temp, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		read_here_doc(fd, p);
		fd = open(p->temp, O_RDONLY);
		unlink(p->temp);
	}
	else
		fd = open(p->infile, O_RDONLY);
	dup2(fd, STDIN_FILENO);
	close(fd);
	dup2(p->pipe_a[WRITE], STDOUT_FILENO);
	close(p->pipe_a[WRITE]);
	execute(0, p);
}

void	outfile(int index, t_pipex *p)
{
	int	flag;
	int	fd;

	flag = O_WRONLY | O_CREAT | O_TRUNC;
	if (p->here_doc)
		flag = O_WRONLY | O_APPEND | O_CREAT;
	fd = open(p->outfile, flag, 0644);
	if (index & 1)
	{
		close(p->pipe_a[WRITE]);
		dup2(p->pipe_a[READ], STDIN_FILENO);
		close(p->pipe_a[READ]);
	}
	else
	{
		close(p->pipe_b[WRITE]);
		dup2(p->pipe_b[READ], STDIN_FILENO);
		close(p->pipe_b[READ]);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	execute(index, p);
}

void	execute(int index, t_pipex *p)
{
	if (execve(p->cmds[index][0], p->cmds[index], p->envp) < 0)
		error_exit("execve error: ", p);
}
