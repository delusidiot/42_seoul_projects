/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_lst_to_arr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 02:39:43 by gjeon             #+#    #+#             */
/*   Updated: 2022/02/14 02:39:44 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	clear_change_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

char	*join_key_value(char *key, char *value)
{
	char	*str1;
	char	*str2;

	str1 = ft_strjoin(key, "=");
	str2 = ft_strjoin(str1, value);
	free(str1);
	return (str2);
}

char	**change_lst_to_arr(t_user *user)
{
	int		j;
	t_env	*tmp;
	char	**arr;

	arr = (char **)malloc(sizeof(char *) * (user->env_size + 1));
	if (arr == 0)
		return (0);
	arr[user->env_size] = 0;
	tmp = user->g_env;
	j = 0;
	while (j < user->env_size)
	{
		arr[j++] = join_key_value(tmp->key, tmp->value);
		tmp = tmp->next;
	}
	return (arr);
}
