/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utile_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 02:38:48 by gjeon             #+#    #+#             */
/*   Updated: 2022/02/14 02:38:49 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

void	env_lst_clear(t_env *env)
{
	t_env	*tmp;

	if (env == 0)
		return ;
	while (env)
	{
		tmp = env->next;
		if (env->key)
			free(env->key);
		if (env->value)
			free(env->value);
		free(env);
		env = tmp;
	}
	env = 0;
}

void	env_lst_add_back(t_user *user, t_env *new)
{
	t_env	*tmp;

	if (new == 0)
		return ;
	if (user->g_env == 0)
		user->g_env = new;
	else
	{
		tmp = user->g_env;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	user->env_size += 1;
}

t_env	*env_lts_new(char *text)
{
	t_env	*new;
	int		flag;

	new = malloc(sizeof(t_env));
	if (new == 0)
		return (0);
	flag = equal_sign_flag(text);
	new->key = ft_strndup(text, flag);
	if (text[flag] == '=')
		new->value = ft_strdup(text + (++flag));
	else
		new->value = 0;
	new->next = 0;
	return (new);
}

int	change_value(int flag, char *str, t_env **env, char **key)
{
	if (str[flag] == '=')
	{
		free((*env)->value);
		(*env)->value = ft_strdup(str + (++flag));
	}
	free(*key);
	return (1);
}

int	same_key_find(t_user *user, char *str)
{
	int		flag;
	char	*key;
	t_env	*tmp;
	int		len;

	flag = equal_sign_flag(str);
	key = ft_strndup(str, flag);
	if (ft_strlen(key) == 0)
	{
		free(key);
		return (1);
	}
	len = ft_strlen(key);
	tmp = user->g_env;
	while (tmp)
	{
		if (len == (int)ft_strlen(tmp->key))
			if (ft_strncmp(key, tmp->key, len) == 0)
				return (change_value(flag, str, &tmp, &key));
		tmp = tmp->next;
	}
	free(key);
	return (0);
}
