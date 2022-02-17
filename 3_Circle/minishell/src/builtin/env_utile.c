/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 02:38:23 by gjeon             #+#    #+#             */
/*   Updated: 2022/02/14 02:38:24 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	set_env_var(t_user *user, char **envp)
{
	int		i;
	t_env	*env_tmp;

	i = 0;
	while (envp[i])
	{
		env_tmp = env_lts_new(envp[i]);
		if (env_tmp != 0)
			env_lst_add_back(user, env_tmp);
		else
			return (0);
		i++;
	}
	return (1);
}

char	*get_env(t_env *env, char *key)
{
	t_env	*tmp;
	size_t	len;

	tmp = env;
	len = ft_strlen(key);
	while (tmp)
	{
		if (len == ft_strlen(tmp->key))
			if (ft_strncmp(tmp->key, key, len) == 0)
				return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}
