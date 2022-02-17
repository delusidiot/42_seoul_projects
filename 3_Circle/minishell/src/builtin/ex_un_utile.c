/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_un_utile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 02:38:31 by gjeon             #+#    #+#             */
/*   Updated: 2022/02/14 02:41:56 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*env_content_join(char *content)
{
	int		len;
	char	*tmp;

	len = ft_strlen(content);
	tmp = malloc(sizeof(char) * (len + 3));
	if (tmp == 0)
		return (0);
	ft_strlcpy(tmp + 1, content, len + 1);
	tmp[len + 2] = '\0';
	tmp[0] = '`';
	tmp[len + 1] = '\'';
	return (tmp);
}

int	check_char(char *key, int flag, int division)
{
	int		disit_flag;

	disit_flag = ft_isdigit(key[0]);
	if (division == 1)
	{
		if (disit_flag || key[flag] == '=')
			return (1);
	}
	else
	{
		if (!disit_flag && ft_isalpha(key[flag]))
			return (2);
	}
	if (key[0] == '$')
		if (ft_strlen(key) == 1)
			return (1);
	return (0);
}

int	export_unset_err(char *key, int flag)
{
	char	*pull_msg;
	char	*content;
	char	*msg;

	if (!ft_strlen(key) || check_char(key, equal_sign_flag(key), 1))
	{
		if (flag == 1 && check_char(key, 0, 2) == 2)
			return (0);
		msg = ft_strdup("not a valid identifier");
		content = env_content_join(key);
		if (flag == 1)
			pull_msg = err_msg_join("export", content, msg);
		else
			pull_msg = err_msg_join("unset", content, msg);
		ft_putstr_fd(pull_msg, STDERR_NO);
		free(content);
		free(pull_msg);
		free(msg);
		return (1);
	}
	return (0);
}

void	add_export(t_user *user, char *str, char *key)
{
	char	*content;

	if (str)
		content = ft_strjoin(key, str);
	else
		content = ft_strdup(key);
	add_export_env(user, content);
	free(content);
}
