/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 02:38:40 by gjeon             #+#    #+#             */
/*   Updated: 2022/02/14 02:38:41 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	export_print(t_env *tmp)
{
	printf("declare -x %s", tmp->key);
	if (tmp->value)
		printf("=\"%s\"\n", tmp->value);
	else
		printf("\n");
}

void	env_order_print(t_user *user)
{
	t_env	*tmp;
	int		order;

	order = 0;
	tmp = user->g_env;
	while (tmp)
	{
		if (tmp->order == order)
		{
			if (ft_strncmp(tmp->key, "_", ft_strlen(tmp->key)) == 0)
			{
				if (user->underscore_flag == 0)
					export_print(tmp);
			}
			else
				export_print(tmp);
			order++;
			tmp = user->g_env;
		}
		else
			tmp = tmp->next;
	}
}

int	sort_prt(t_user *user)
{
	set_sort_env(user->g_env);
	env_order_print(user);
	return (0);
}
