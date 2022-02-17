/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   underscore.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 02:38:13 by gjeon             #+#    #+#             */
/*   Updated: 2022/02/14 02:38:15 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	export_set(t_user *user, t_list *tmp)
{
	t_env	*env_tmp;
	char	*str;

	str = ft_strdup((char *)tmp->content);
	env_tmp = env_lts_new(str);
	if (ft_strlen(env_tmp->key))
		add_export(user, env_tmp->key, "_=");
	else
		add_export(user, (char *)tmp->content, "_=");
	env_lst_clear(env_tmp);
	free(str);
}

void	underscore(t_user *user, char *type, t_list *list)
{
	t_list	*tmp;

	if (list)
	{
		tmp = ft_lstlast(list);
		if (ft_strncmp(type, "export", ft_strlen(type)) == 0)
			export_set(user, tmp);
		else
			add_export(user, (char *)tmp->content, "_=");
		tmp = 0;
	}
	else
		add_export(user, type, "_=");
	user->underscore_flag = 1;
}
