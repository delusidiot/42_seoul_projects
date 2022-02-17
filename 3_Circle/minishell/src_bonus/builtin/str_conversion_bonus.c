/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_conversion_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 02:39:09 by gjeon             #+#    #+#             */
/*   Updated: 2022/02/14 02:39:10 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

char	*change_env(t_user *user, char *env_tmp)
{
	char	*conversion;
	int		len;

	len = ft_strlen(env_tmp);
	if (get_env(user->g_env, env_tmp + 1) != NULL)
		conversion = ft_strdup(get_env(user->g_env, env_tmp + 1));
	else if (ft_strncmp(env_tmp, "$?", len) == 0)
	{
		if (len == 2)
			conversion = ft_itoa(user->exit_status);
		else
			conversion = ft_strdup(env_tmp);
	}
	else
		conversion = ft_strdup("");
	return (conversion);
}

char	*env_conversion(t_user *user, char *content, int *i)
{
	char	*conversion;
	int		isalnum_flag;
	char	*env_tmp;

	conversion = 0;
	if (content[*i])
	{
		isalnum_flag = not_isalnum_flag(content + 1 + *i) + 1;
		env_tmp = ft_strndup(content + *i, isalnum_flag);
		if (content[*i] == '$')
			conversion = change_env(user, env_tmp);
		else
			conversion = ft_strdup(env_tmp + 1);
		free(env_tmp);
		*i += isalnum_flag;
	}
	return (conversion);
}

void	merging_pieces(char **sub_tmp, char **tmp, char **conversion)
{
	char	*piece;

	if (!*conversion)
		*conversion = ft_strdup("");
	if (!*tmp)
		*tmp = ft_strjoin(*sub_tmp, *conversion);
	else
	{
		piece = ft_strjoin(*tmp, *sub_tmp);
		free(*tmp);
		*tmp = ft_strjoin(piece, *conversion);
		free(piece);
	}
	free(*conversion);
	free(*sub_tmp);
}

char	*check_env(t_user *user, char *content)
{
	char	*tmp;
	int		i;
	int		sign_flag;
	char	*sub_tmp;
	char	*conversion;

	tmp = 0;
	i = 0;
	while (content[i])
	{
		sign_flag = dollar_sign_flag(content + i);
		sub_tmp = ft_strndup(content + i, sign_flag);
		i += sign_flag;
		conversion = env_conversion(user, content, &i);
		merging_pieces(&sub_tmp, &tmp, &conversion);
	}
	return (tmp);
}

char	*str_conversion(t_user *user, char *content)
{
	char	*tmp;

	if (content[0] == '~' && ft_strlen(content) == 1)
		tmp = ft_strdup(user->home_dir);
	else
	{
		if (!content[0])
			tmp = ft_strdup("");
		else
			tmp = check_env(user, content);
	}
	return (tmp);
}
