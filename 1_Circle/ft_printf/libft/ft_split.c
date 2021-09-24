/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 18:13:59 by jjeon             #+#    #+#             */
/*   Updated: 2021/01/11 13:31:18 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_memerr(char **rst)
{
	size_t	i;

	i = 0;
	while (rst[i])
	{
		free(rst[i]);
	}
	free(rst);
	return (NULL);
}

size_t	get_rstlen(char const *s, char c)
{
	size_t	size;

	if (!*s)
		return (0);
	size = 0;
	while (*s && *s == c)
		s++;
	while (*s)
	{
		if (*s == c)
		{
			size++;
			while (*s && *s == c)
				s++;
		}
		else
			s++;
	}
	if (*(s - 1) != c)
		size++;
	return (size);
}

char	*next_str(const char *s, size_t *size, char c)
{
	*size = 0;
	while (*s && *s != c)
	{
		(*size)++;
		s++;
	}
	return ((char *)s + 1);
}

char	**ft_split(char const *s, char c)
{
	char	**rst;
	char	*s_next;
	size_t	s_size;
	size_t	str_len;
	size_t	i;

	if (!s)
		return (NULL);
	s_size = get_rstlen(s, c);
	if (!(rst = (char **)malloc(sizeof(char *) * (s_size + 1))))
		return (NULL);
	rst[s_size] = NULL;
	i = 0;
	while (i < s_size)
	{
		while (*s && *s == c)
			s++;
		s_next = next_str(s, &str_len, c);
		if (!(rst[i] = (char *)malloc(sizeof(char) * (str_len + 1))))
			return (ft_memerr(rst));
		ft_strlcpy(rst[i], s, str_len + 1);
		s = s_next;
		i++;
	}
	return (rst);
}
