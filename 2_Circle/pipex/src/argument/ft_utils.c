/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 18:51:41 by jjeon             #+#    #+#             */
/*   Updated: 2021/08/09 23:16:46 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

char	*join_path(char *prev, char *name)
{
	char	*temp;
	char	*temp2;

	temp = ft_strjoin(prev, "/");
	temp2 = ft_strjoin(temp, name);
	free(temp);
	return (temp2);
}

void	free_env(char *pwd, char **path)
{
	int	i;

	i = -1;
	free(pwd);
	while (path[++i])
		free(path[i]);
	free(path);
}

void	free_pipex(t_pipex *p)
{
	int	i;
	int	j;

	i = -1;
	free(p->infile);
	free(p->outfile);
	while (p->cmds && p->cmds[++i])
	{
		j = -1;
		while (p->cmds[i] && p->cmds[i][++j])
			free(p->cmds[i][j]);
		free(p->cmds[i]);
	}
	free(p->cmds);
}

int	quotes_skip(char **s, int size)
{
	if (**s == '\'')
	{
		(*s)++;
		while (**s != '\'')
		{
			size++;
			(*s)++;
		}
		size--;
	}
	if (**s == '\"')
	{
		(*s)++;
		while (**s != '\"')
		{
			size++;
			(*s)++;
		}
		size--;
	}
	return (size);
}

void	init_pipex(t_pipex *p)
{
	p->envp = NULL;
	p->cmds = NULL;
	p->infile = NULL;
	p->outfile = NULL;
	p->temp = "/tmp/.temp";
	p->here_doc = 0;
}
