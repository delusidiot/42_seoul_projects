/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 07:30:48 by jjeon             #+#    #+#             */
/*   Updated: 2021/07/27 16:29:45 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	read_next_line(char **storage, char **line, char *temp)
{
	char	*next;
	int		result;

	result = _EOF;
	if (temp)
	{
		*line = ft_strndup(*storage, temp - *storage);
		next = ft_strndup(temp + 1, ft_strlen(temp + 1));
		free(*storage);
		*storage = next;
		result = _SUCCESS;
	}
	else if (*storage)
	{
		*line = *storage;
		*storage = NULL;
	}
	else
		*line = NULL;
	return (result);
}

char	*stored_line(char **storage, char *buf, ssize_t byte)
{
	char	*temp;

	buf[byte] = '\0';
	if (*storage)
	{
		temp = ft_strjoin(*storage, buf);
		free(*storage);
	}
	else
		temp = ft_strndup(buf, byte);
	*storage = temp;
	return (temp);
}

int	get_next_line(int fd, char **line)
{
	static char	*storage[FILE_MAX + 1];
	char		*temp;
	char		buf[BUFFER_SIZE + 1];
	ssize_t		byte;

	if (fd < 0 || fd > FILE_MAX || !line || BUFFER_SIZE <= 0)
		return (_ERROR);
	byte = 1;
	if (!storage[fd])
		storage[fd] = ft_strndup("", 0);
	temp = NULL;
	while (!temp && byte)
	{
		temp = ft_strchr(storage[fd], '\n');
		if (temp)
			break ;
		byte = read(fd, buf, BUFFER_SIZE);
		if (!byte)
			break ;
		stored_line(&storage[fd], buf, byte);
	}
	if (byte < 0)
		return (_ERROR);
	return (read_next_line(&storage[fd], line, temp));
}
