/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 02:38:43 by gjeon             #+#    #+#             */
/*   Updated: 2022/02/14 02:38:44 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	set_env_order2(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i])
	{
		if (str1[i] == str2[i])
			i++;
		else if (str1[i] > str2[i])
			return (1);
		else
			return (0);
	}
	return (0);
}

int	set_env_order(char *str, t_env *env)
{
	t_env	*tmp;
	int		order;

	order = 0;
	tmp = env;
	while (tmp)
	{
		order += set_env_order2(str, tmp->key);
		tmp = tmp->next;
	}
	return (order);
}

void	set_sort_env(t_env *env)
{
	t_env	*tmp;
	int		order;

	if (env == 0)
		return ;
	tmp = env;
	while (tmp)
	{
		order = set_env_order(tmp->key, env);
		tmp->order = order;
		tmp = tmp->next;
	}
}
