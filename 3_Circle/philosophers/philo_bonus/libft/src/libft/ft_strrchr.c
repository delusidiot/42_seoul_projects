/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 21:37:29 by jjeon             #+#    #+#             */
/*   Updated: 2020/12/22 04:40:17 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*rst;

	rst = NULL;
	while (*s)
	{
		if (*s == (char)c)
			rst = (char *)s;
		s++;
	}
	if (!c)
		return ((char *)s);
	return (rst);
}
