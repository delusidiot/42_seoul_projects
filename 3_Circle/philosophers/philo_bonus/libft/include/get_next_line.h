/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 07:32:31 by jjeon             #+#    #+#             */
/*   Updated: 2021/06/29 18:29:36 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5000
# endif
# define _EOF 0
# define _ERROR -1
# define _SUCCESS 1
# define FILE_MAX 256

int		get_next_line(int fd, char **line);
char	*ft_strndup(const char *str, size_t size);

#endif
