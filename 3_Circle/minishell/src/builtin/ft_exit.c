/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 02:39:02 by gjeon             #+#    #+#             */
/*   Updated: 2022/02/14 02:39:02 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_digit(char *tmp_content, int len)
{
	int	i;

	i = 0;
	if (len > 1)
		if (tmp_content[i] == '-' || tmp_content[i] == '+')
			i++;
	while (tmp_content[i])
		if (!ft_isdigit(tmp_content[i++]))
			return (1);
	return (0);
}

void	check_the_exit_error(t_user *user, t_list *list_tmp, char *tmp_content)
{
	int	len;

	len = ft_strlen(tmp_content);
	if (len)
	{
		if (len > 19 || check_digit(tmp_content, len))
			user->exit_status = prt_err("exit", tmp_content, 255);
		if (list_tmp->next && user->exit_status != 255)
			user->exit_status = prt_err("exit", NULL, 1);
		else if (user->exit_status != 255)
			user->exit_status = ft_atoi(tmp_content);
	}
}

int	ft_exit(t_user *user, t_list *list)
{
	t_list	*list_tmp;
	char	*tmp_content;

	printf("exit\n");
	list_tmp = list;
	while (list_tmp)
	{
		tmp_content = ft_strdup((char *)list_tmp->content);
		check_the_exit_error(user, list_tmp, tmp_content);
		free(tmp_content);
		if (user->exit_status)
			break ;
		list_tmp = list_tmp->next;
	}
	if (user->exit_status == 1 && list && list_tmp->next)
		return (user->exit_status);
	exit(user->exit_status);
	return (user->exit_status);
}
