/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 17:47:13 by jjeon             #+#    #+#             */
/*   Updated: 2021/07/01 14:18:51 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*rst;

	s1_len = 0;
	s2_len = 0;
	if (s1)
		s1_len = ft_strlen(s1);
	if (s2)
		s2_len = ft_strlen(s2);
	rst = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!rst)
		return (NULL);
	ft_memcpy(rst, s1, s1_len);
	ft_memcpy(rst + s1_len, s2, s2_len);
	rst[s1_len + s2_len] = 0;
	return (rst);
}
