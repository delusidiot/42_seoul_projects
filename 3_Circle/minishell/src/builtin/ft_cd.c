/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 02:38:52 by gjeon             #+#    #+#             */
/*   Updated: 2022/02/14 02:38:52 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_err(t_user *user, int e_flag, char *content)
{
	if (e_flag != 0)
	{
		add_export(user, NULL, "OLDPWD");
		prt_err("cd", content, errno);
		return (1);
	}
	else
	{
		add_export(user, user->pwd, "OLDPWD=");
		free(user->pwd);
		user->pwd = getcwd(NULL, 1024);
		add_export(user, user->pwd, "PWD=");
		return (0);
	}
}

int	check_home(t_user *user, t_list *list_tmp, char **tmp_content, int len)
{
	if (len == 1 && *tmp_content[0] == '-')
	{
		free(*tmp_content);
		if (get_env(user->g_env, "OLDPWD") != NULL)
			*tmp_content = ft_strdup(get_env(user->g_env, "OLDPWD"));
		else
			return (prt_err("cd", NULL, 0));
	}
	else if (len == 0)
	{
		free(*tmp_content);
		if (!list_tmp->next && get_env(user->g_env, "HOME") != NULL)
			*tmp_content = ft_strdup(get_env(user->g_env, "HOME"));
		else if (!list_tmp->next)
			return (prt_err("cd", NULL, 1));
		else
			*tmp_content = 0;
	}
	return (0);
}

int	ft_cd(t_user *user, t_list *list)
{
	t_list	*list_tmp;
	char	*tmp_content;
	int		status;

	if (!list)
		return (check_err(user, chdir(user->home_dir), user->home_dir));
	list_tmp = list;
	while (list_tmp)
	{
		tmp_content = ft_strdup((char *)list_tmp->content);
		status = check_home(user, list_tmp, &tmp_content, \
			ft_strlen(tmp_content));
		if (status)
			return (status);
		if (tmp_content)
		{
			status = check_err(user, chdir(tmp_content), tmp_content);
			break ;
		}
		list_tmp = list_tmp->next;
	}
	free(tmp_content);
	return (status);
}
