/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 18:06:57 by jjeon             #+#    #+#             */
/*   Updated: 2021/07/27 16:38:17 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

char	**get_env_path(char *path)
{
	char	**s;
	char	*temp;
	int		i;

	s = NULL;
	i = -1;
	if (ft_strncmp(path, "PATH=", 5))
		return (NULL);
	s = ft_split(path, '=');
	temp = s[1];
	while (s[++i])
		if (i != 1)
			free(s[i]);
	free(s);
	s = ft_split(temp, ':');
	free(temp);
	return (s);
}

char	**get_cmd_path(char **path, char *name)
{
	int		i;
	char	**cmd;
	char	*temp;

	i = -1;
	if (!name || !path)
		return (NULL);
	cmd = ft_cmd_split(name, ' ');
	while (path[++i])
	{
		temp = join_path(path[i], cmd[0]);
		if (!(access(temp, F_OK)))
		{
			free(cmd[0]);
			cmd[0] = temp;
			return (cmd);
		}
		free(temp);
	}
	return (NULL);
}
