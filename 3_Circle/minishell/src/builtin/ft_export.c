/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 02:39:05 by gjeon             #+#    #+#             */
/*   Updated: 2022/02/14 02:39:05 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	add_export_env(t_user *user, char *tmp_content)
{
	t_env	*env_tmp;

	if (!same_key_find(user, tmp_content))
	{
		env_tmp = env_lts_new(tmp_content);
		if (env_tmp != 0)
			env_lst_add_back(user, env_tmp);
	}
	return (1);
}

int	ft_export(t_user *user, t_list *list)
{
	char	*tmp_content;
	int		status;
	int		flag;

	status = 0;
	flag = 0;
	if (!list)
		return (sort_prt(user));
	while (list)
	{
		tmp_content = ft_strdup((char *)list->content);
		if (ft_strlen(tmp_content) > 0)
		{
			flag = 1;
			if (export_unset_err(tmp_content, 1))
				status = 1;
			if (!status)
				flag = add_export_env(user, tmp_content);
		}
		free(tmp_content);
		list = list->next;
	}
	if (flag == 0)
		return (sort_prt(user));
	return (status);
}
