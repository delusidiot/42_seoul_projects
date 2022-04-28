/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 19:19:54 by jjeon             #+#    #+#             */
/*   Updated: 2021/07/01 14:17:29 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*rst;
	size_t			len;
	unsigned int	i;

	if (s == NULL || f == NULL)
		return (NULL);
	len = ft_strlen(s);
	rst = (char *)malloc(sizeof(char) * (len + 1));
	if (!rst)
		return (NULL);
	i = 0;
	while (s[i])
	{
		rst[i] = f(i, s[i]);
		i++;
	}
	rst[i] = 0;
	return (rst);
}
