/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 12:19:21 by jjeon             #+#    #+#             */
/*   Updated: 2021/07/27 17:05:52 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

char	**ft_cmd_memerr(char **rst)
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

size_t	get_cmd_rstlen(char const *s, char c)
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
			quotes_skip((char **)&s, size);
		}
		else
			s++;
	}
	if (*(s - 1) != c)
		size++;
	return (size);
}

char	*next_cmd_str(const char *s, size_t *size, char c)
{
	*size = 0;
	while (*s && *s != c)
	{
		*size = quotes_skip((char **)&s, *size);
		(*size)++;
		s++;
	}
	return ((char *)s + 1);
}

char	**set_cmd_split(char *s, char c, char **rst, size_t s_size)
{
	char	*s_next;
	size_t	i;
	size_t	str_len;

	i = 0;
	while (i < s_size)
	{
		while (*s && *s == c)
			s++;
		s_next = next_cmd_str(s, &str_len, c);
		rst[i] = (char *)malloc(sizeof(char) * (str_len + 1));
		if (!rst[i])
			return (ft_cmd_memerr(rst));
		if (*s == '\'' || *s == '\"')
			s++;
		ft_strlcpy(rst[i], s, str_len + 1);
		s = s_next;
		i++;
	}
	return (rst);
}

char	**ft_cmd_split(char const *s, char c)
{
	char	**rst;
	size_t	s_size;

	if (!s)
		return (NULL);
	s_size = get_cmd_rstlen(s, c);
	rst = (char **)malloc(sizeof(char *) * (s_size + 1));
	if (!rst)
		return (NULL);
	rst[s_size] = NULL;
	rst = set_cmd_split((char *)s, c, rst, s_size);
	if (!rst)
		return (NULL);
	return (rst);
}
