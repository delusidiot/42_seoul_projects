/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 02:37:50 by gjeon             #+#    #+#             */
/*   Updated: 2022/02/14 02:39:16 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	find_key_clear(t_user *user, t_env **cur_env, t_env **old_env)
{
	t_env	*tmp;

	if ((*cur_env)->next)
		tmp = (*cur_env)->next;
	else
		tmp = 0;
	free((*cur_env)->key);
	if ((*cur_env)->value)
		free((*cur_env)->value);
	free(*cur_env);
	*cur_env = tmp;
	if (*old_env)
		(*old_env)->next = *cur_env;
	else
		user->g_env = *cur_env;
	user->env_size -= 1;
}

int	same_keys_find(t_user *user, char *key, t_env **cur_env, t_env **old_env)
{
	size_t	len;

	len = ft_strlen((*cur_env)->key);
	if (len == ft_strlen(key))
	{
		if (ft_strncmp((*cur_env)->key, key, len) == 0)
		{
			find_key_clear(user, cur_env, old_env);
			return (1);
		}
	}
	return (0);
}

void	remove_env(t_user *user, char *tmp_content, t_env **old_env)
{
	t_env	*cur_env;

	cur_env = user->g_env;
	while (cur_env)
	{
		if (cur_env && !same_keys_find(user, tmp_content, &cur_env, old_env))
		{
			*old_env = cur_env;
			cur_env = cur_env->next;
		}
		else
			break ;
	}
}

int	ft_unset(t_user *user, t_list *list)
{
	t_env	*old_env;
	char	*tmp_content;
	int		status;

	old_env = 0;
	status = 0;
	while (list)
	{
		tmp_content = ft_strdup((char *)list->content);
		if (!export_unset_err(tmp_content, 2))
			remove_env(user, tmp_content, &old_env);
		else
			status = 1;
		free(tmp_content);
		list = list->next;
	}
	return (status);
}
