/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.seoul42.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 11:50:50 by jjeon             #+#    #+#             */
/*   Updated: 2021/01/11 11:04:01 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*p_dst;
	unsigned char	*p_src;

	if (dst == src || len == 0)
		return (dst);
	if (dst < src)
	{
		p_dst = dst;
		p_src = (unsigned char *)src;
		while (len--)
			*p_dst++ = *p_src++;
	}
	else
	{
		p_dst = dst + (len - 1);
		p_src = (unsigned char *)src + (len - 1);
		while (len--)
			*p_dst-- = *p_src--;
	}
	return (dst);
}
