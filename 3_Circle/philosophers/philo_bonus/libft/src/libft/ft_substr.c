/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 07:16:45 by jjeon             #+#    #+#             */
/*   Updated: 2021/07/01 14:14:54 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*rst;

	if (!s)
		return (NULL);
	rst = (char *)malloc(sizeof(char) * (len + 1));
	if (!rst)
		return (NULL);
	if (ft_strlen(s) <= start)
		start = ft_strlen(s);
	ft_strlcpy(rst, s + start, len + 1);
	return (rst);
}
