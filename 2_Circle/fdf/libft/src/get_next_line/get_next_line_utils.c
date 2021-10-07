/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 11:25:26 by jjeon             #+#    #+#             */
/*   Updated: 2021/07/15 16:53:00 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strndup(const char *str, size_t size)
{
	char	*rst;

	rst = malloc(sizeof(char) * (size + 1));
	if (!rst)
		return (NULL);
	rst[size] = '\0';
	while (size > 0)
	{
		rst[size - 1] = str[size - 1];
		size--;
	}
	return (rst);
}
