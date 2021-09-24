/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 15:44:17 by jjeon             #+#    #+#             */
/*   Updated: 2021/07/27 17:16:14 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

int	set_file_path(int argc, char **argv, char *env_pwd, t_pipex *p)
{
	char	*err_msg;

	if (p->here_doc)
		p->infile = ft_strdup(argv[1]);
	else
	{
		p->infile = get_file_path(env_pwd, argv[1]);
		if (access(p->infile, F_OK))
		{
			err_msg = ft_strjoin(argv[1], " is not file: ");
			perror(err_msg);
			free(err_msg);
			free(p->infile);
			return (FALSE);
		}
	}
	p->outfile = get_file_path(env_pwd, argv[argc - 1]);
	return (TRUE);
}

int	set_cmd_path(int argc, char **argv, char **env_path, t_pipex *p)
{
	char	*err_msg;
	int		i;

	i = 1;
	p->cmds = malloc(sizeof(char **) * (argc - 2));
	if (!p->cmds)
		return (FALSE);
	p->cmds[argc - 3] = NULL;
	while (++i < argc - 1)
	{
		p->cmds[i - 2] = get_cmd_path(env_path, argv[i]);
		if (!p->cmds[i - 2])
		{
			err_msg = ft_strjoin(argv[i], " is not command: ");
			perror(err_msg);
			free(err_msg);
			return (FALSE);
		}
	}
	p->end_index = argc - 3;
	return (TRUE);
}

int	set_param(int argc, char **argv, char **envp, t_pipex *p)
{
	int		i;
	char	*env_pwd;
	char	**env_path;

	i = -1;
	env_pwd = NULL;
	env_path = NULL;
	while (envp[++i])
	{
		if (!strncmp(envp[i], "PWD=", 4))
			env_pwd = get_env_pwd(envp[i]);
		if (!strncmp(envp[i], "PATH=", 5))
			env_path = get_env_path(envp[i]);
	}
	if (!set_file_path(argc, argv, env_pwd, p))
		return (FALSE);
	if (!set_cmd_path(argc, argv, env_path, p))
		return (FALSE);
	p->envp = envp;
	free_env(env_pwd, env_path);
	return (TRUE);
}
