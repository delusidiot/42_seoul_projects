/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.seoul42.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 11:59:11 by jjeon             #+#    #+#             */
/*   Updated: 2020/12/21 22:21:14 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *p_s;

	p_s = (unsigned char *)s;
	while (n--)
	{
		if (*p_s == (unsigned char)c)
			return ((void *)(p_s));
		p_s++;
	}
	return (NULL);
}
