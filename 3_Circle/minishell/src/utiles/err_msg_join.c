/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_msg_join.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 02:39:50 by gjeon             #+#    #+#             */
/*   Updated: 2022/02/14 02:39:51 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*err_msg_join(char *type, char *content, char *msg)
{
	char	*tmp1;
	char	*tmp2;
	char	*tmp3;

	tmp1 = ft_strjoin("minishell: ", type);
	tmp2 = ft_strjoin(": ", content);
	tmp3 = ft_strjoin(tmp1, tmp2);
	free(tmp1);
	free(tmp2);
	if (content)
	{
		tmp1 = ft_strjoin(tmp3, ": ");
		tmp2 = ft_strjoin(tmp1, msg);
		free(tmp1);
	}
	else
		tmp2 = ft_strjoin(tmp3, msg);
	free(tmp3);
	tmp3 = ft_strjoin(tmp2, "\n");
	free(tmp2);
	return (tmp3);
}
