/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 17:55:37 by jjeon             #+#    #+#             */
/*   Updated: 2021/07/27 17:17:36 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

char	*get_env_pwd(char *pwd)
{
	char	**s;
	char	*temp;
	int		i;

	s = NULL;
	i = -1;
	if (ft_strncmp(pwd, "PWD=", 4))
		return (NULL);
	s = ft_split(pwd, '=');
	temp = ft_strdup(s[1]);
	while (s[++i])
		free(s[i]);
	free(s);
	return (temp);
}

char	*get_file_path(char *pwd, char *name)
{
	char	*file;

	if (!name || !pwd)
		return (NULL);
	file = join_path(pwd, name);
	return (file);
}
