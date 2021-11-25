/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.seoul42.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 12:26:33 by jjeon             #+#    #+#             */
/*   Updated: 2020/12/28 13:20:27 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	int		i;
	int		j;
	size_t	dst_len;
	size_t	rst;

	dst_len = ft_strlen(dst);
	rst = ft_strlen(src);
	if (dst_len >= dstsize)
		return (rst + dstsize);
	i = 0;
	j = dst_len;
	while (src[i] && i < (int)(dstsize - dst_len - 1))
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (rst + dst_len);
}
