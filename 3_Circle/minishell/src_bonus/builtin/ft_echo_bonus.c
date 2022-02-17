/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 02:38:55 by gjeon             #+#    #+#             */
/*   Updated: 2022/02/14 02:38:55 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

int	check_option_n(t_list *list)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	if (list)
	{
		if (((char *)list->content)[i++] == '-')
		{
			while (((char *)list->content)[i])
			{
				if (((char *)list->content)[i] != 'n')
					return (0);
				flag = 1;
				i++;
			}
		}
	}
	if (flag)
		return (1);
	return (0);
}

int	ft_echo(t_list *list)
{
	t_list	*list_tmp;
	char	*tmp_content;

	list_tmp = list;
	if (check_option_n(list))
		list_tmp = list_tmp->next;
	while (list_tmp)
	{
		tmp_content = ft_strdup((char *)list_tmp->content);
		printf("%s", tmp_content);
		if (list_tmp->next && ft_strlen(tmp_content) != 0)
			printf(" ");
		free(tmp_content);
		list_tmp = list_tmp->next;
	}
	if (!list || !check_option_n(list))
		printf("\n");
	return (0);
}
