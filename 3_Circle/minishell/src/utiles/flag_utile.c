/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_utile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 02:39:56 by gjeon             #+#    #+#             */
/*   Updated: 2022/02/14 02:39:56 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	equal_sign_flag(char *str)
{
	int	flag;

	flag = 0;
	while (str[flag])
	{
		if (str[flag] == '=')
			break ;
		flag++;
	}
	return (flag);
}

int	not_isalnum_flag(char *content)
{
	int	i;

	i = 0;
	while (content[i])
	{
		if (ft_isalnum(content[i]) || content[i] == '?' || content[i] == '_')
			i++;
		else
			break ;
	}
	return (i);
}

int	dollar_sign_flag(char *content)
{
	int	i;

	i = 0;
	while (content[i])
	{
		if (content[i] == '$')
			break ;
		i++;
	}
	return (i);
}
