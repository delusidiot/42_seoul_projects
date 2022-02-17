/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 02:38:59 by gjeon             #+#    #+#             */
/*   Updated: 2022/02/14 02:38:59 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

int	ft_env(t_user *user)
{
	t_env	*tmp;

	tmp = user->g_env;
	while (tmp)
	{
		if (tmp->value)
		{
			if (ft_strncmp(tmp->key, "_", ft_strlen(tmp->key)) == 0)
			{
				ft_putstr_fd(tmp->key, STDOUT_NO);
				ft_putstr_fd("=", STDOUT_NO);
				ft_putstr_fd("env\n", STDOUT_NO);
			}
			else
			{
				ft_putstr_fd(tmp->key, STDOUT_NO);
				ft_putstr_fd("=", STDOUT_NO);
				ft_putstr_fd(tmp->value, STDOUT_NO);
				ft_putstr_fd("\n", STDOUT_NO);
			}
		}
		tmp = tmp->next;
	}
	return (0);
}
